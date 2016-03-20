#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "common.h"
#include <iostream>

// Protocol messages
#define CP_STOP        0xFF
#define CP_START       0x1
#define CP_ACK         0x2
#define CP_REQ_FRAME   0x3
#define CP_FRAME_INFO  0x4

#define TCP_TO_SEC 5
#define UDP_TO_SEC 1
#define TCP_TO_USEC 100000
#define UDP_TO_USEC 100000

// TCP packet structure
struct ControlPacket{
    byte id;
    byte channels;
    unsigned short extra;
    unsigned int width;
    unsigned int height;
    unsigned int block_size;
};


// Utility that prints a control packet in a readable form
using namespace std;
static void print_cp(const ControlPacket p, string caller){

    cout << caller << ":" << endl;
    cout << "\t" << "ID: " << (uint)p.id << endl;
    cout << "\t" << "CH: " << (uint)p.channels << endl;
    cout << "\t" << "WI: " << p.width << endl;
    cout << "\t" << "HE: " << p.height << endl;
    cout << "\t" << "BS: " << p.block_size << endl;
    cout << "\t" << "EX: " << p.extra << endl;
}

#endif // PROTOCOL_H

