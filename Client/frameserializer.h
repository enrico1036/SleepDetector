#ifndef FRAMESERIALIZER_H
#define FRAMESERIALIZER_H
#include "common.h"
#include <opencv2/opencv.hpp>


/*
    Class capable of, given an image in form of byte array, split it into blocks
    of specified size.
 */
class FrameSerializer
{
public:
    // Single block structure
    struct Block{
        uint length;
        byte* addr;
    };
    static FrameSerializer fromCvMat(const cv::Mat& mat);

public:
    // Image as array of bytes, its width, height and channels (1 for grayscale, 3 for RGB ecc);
    FrameSerializer(const byte* image, uint width, uint height, uint channels);
    ~FrameSerializer();

    // Returns total data length
    uint getLength();
    uint getCurrLength();

    // Returns the next block to be split
    const Block nextBlock();

    void setBlockSize(uint size);
    uint getBlockSize();

    // Returns true if it still has something to split
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
