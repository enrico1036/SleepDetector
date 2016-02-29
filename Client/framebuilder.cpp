#include "framebuilder.h"


FrameBuilder::FrameBuilder(uint width, uint height, uint channels) :
    width(width), height(height), channels(channels), block_size(65507), curr_offset(0)
{
    image = new byte[getLength()];
}

FrameBuilder::~FrameBuilder()
{
    if(image){
        delete image;
        image = 0;
    }
}

uint FrameBuilder::getLength()
{
    return width * height * channels;
}

uint FrameBuilder::getCurrLength()
{
    return curr_offset;
}

FrameBuilder::Block FrameBuilder::nextBlock()
{
    Block block = {0};
    if(!hasNext())
        return block;

    block.addr = &image[curr_offset];
    block.length = min(block_size, getLength() - getCurrLength());
    curr_offset += block.length;

    return block;
}

void FrameBuilder::setBlockSize(uint size)
{
    block_size = size;
}

uint FrameBuilder::getBlockSize()
{
    return block_size;
}

bool FrameBuilder::hasNext()
{
    return (getCurrLength() < getLength());
}

const byte *FrameBuilder::getImage()
{
    return image;
}


