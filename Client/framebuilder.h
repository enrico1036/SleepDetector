#ifndef FRAMEBUILDER_H
#define FRAMEBUILDER_H
#include "common.h"

class FrameBuilder
{

public:
    struct Block{
        uint length;
        byte* addr;
    };

    FrameBuilder(uint width, uint height, uint channels);
    ~FrameBuilder();

    // Returns total data length
    uint getLength();
    uint getCurrLength();

    Block nextBlock();

    void setBlockSize(uint size);
    uint getBlockSize();

    bool hasNext();

    const byte* getImage();

public:
    const uint width;
    const uint height;
    const uint channels;

private:
    byte* image;
    uint curr_offset;
    uint block_size;

};

#endif // FRAMEBUILDER_H
