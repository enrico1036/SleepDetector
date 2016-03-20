#ifndef COMMON_H
#define COMMON_H
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <string>
#include <sstream>

// These functions are custom additions to libsocket library
namespace libsocket{
    static void setReadTimeout(int fd, int sec, int usec){
        timeval t;
        t.tv_sec = sec;
        t.tv_usec = usec;

        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t));
    }

    static void setSendTimeout(int fd, int sec, int usec){
        timeval t;
        t.tv_sec = sec;
        t.tv_usec = usec;

        setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &t, sizeof(t));
    }

    static void setIOTimeout(int fd, int sec, int usec){
        setSendTimeout(fd, sec, usec);
        setReadTimeout(fd, sec, usec);
    }

    static bool SetSocketBlockingEnabled(int fd, bool blocking)
    {
       if (fd < 0) return false;
       int flags = fcntl(fd, F_GETFL, 0);
       if (flags < 0) return false;
       flags = blocking ? (flags&~O_NONBLOCK) : (flags|O_NONBLOCK);
       return (fcntl(fd, F_SETFL, flags) == 0) ? true : false;
    }
}

typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;

template <typename T1, typename T2>
static inline T1 min(const T1 a, const T2 b){
    return (a <= (T1)b) ? a : (T1)b;
}

// Returns 4-bytes form of a string representing an ipv4 address
static unsigned int string_to_ip(std::string str){
    int ip[4];

    for( int i=0; i<4; i++) {
        auto pos = str.find_first_of('.');
        std::stringstream ss;
        ss << str.substr(0, pos);
        ss >> ip[i];
        str.erase(0, pos+1);
    }

    return (unsigned int)   (ip[0] << 24) & 0xFF000000 |
                            (ip[1] << 16) & 0x00FF0000 |
                            (ip[2] << 8)  & 0x0000FF00 |
                            (ip[3])       & 0x000000FF ;
}

// Returns readable string form of 4-bytes ipv4 address
static std::string ip_to_string(unsigned int ip){
    std::stringstream ss;

    ss << ((ip & 0xFF000000) >> 24) << ".";
    ss << ((ip & 0x00FF0000) >> 16) << ".";
    ss << ((ip & 0x0000FF00) >> 8) << ".";
    ss << (ip & 0x000000FF);

    return ss.str();
}


#endif // COMMON_H

