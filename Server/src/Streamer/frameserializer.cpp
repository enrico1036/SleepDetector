#include "frameserializer.h"
#include <string.h>
#include <algorithm>
#include <iostream>

FrameSerializer FrameSerializer::fromCvMat(const cv::Mat &mat)
{

}

FrameSerializer::FrameSerializer(const byte *image, uint width, uint height, uint channels) :
    width(width), height(height), channels(channels), curr_offset(0)
{
    this->image = new byte[getLength()];
    std::copy(image, image + getLength(), this->image);
}

FrameSerializer::~FrameSerializer()
{
    if(image){
        delete[] image;
        image = NULL;
    }
}

uint FrameSerializer::getLength()
{
    return width * height * channels * sizeof(byte);
}

uint FrameSerializer::getCurrLength()
{
    return this->getLength() - curr_offset;
}

const FrameSerializer::Block FrameSerializer::nextBlock()
{
    Block b = {0,0};
    if(!hasNext())
        return b;

    b.length = min(getCurrLength(), block_size);
    b.addr = &image[curr_offset];
    curr_offset += b.length;

    return b;
}

void FrameSerializer::setBlockSize(uint size)
{
    block_size = size;
}

uint FrameSerializer::getBlockSize()
{
    return block_size;
}

bool FrameSerializer::hasNext()
{
    return (getCurrLength() > 0);
}

