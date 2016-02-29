#ifndef FRAMESERIALIZER_H
#define FRAMESERIALIZER_H
#include "common.h"
#include <opencv2/opencv.hpp>

class FrameSerializer
{
public:
    struct Block{
        uint length;
        byte* addr;
    };
    static FrameSerializer fromCvMat(const cv::Mat& mat);

public:
    FrameSerializer(const byte* image, uint width, uint height, uint channels);
    ~FrameSerializer();

    // Returns total data length
    uint getLength();
    uint getCurrLength();

    const Block nextBlock();

    void setBlockSize(uint size);
    uint getBlockSize();

    bool hasNext();

public:
    const uint width;
    const uint height;
    const uint channels;

private:
    byte* image;
    uint curr_offset;
    uint block_size;

};

#endif // FRAMESERIALIZER_H
