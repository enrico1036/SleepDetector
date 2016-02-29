#ifndef STREAMCLIENT_H
#define STREAMCLIENT_H

#include <iostream>
#include <inetclientstream.hpp>
#include <inetserverdgram.hpp>
#include <exception.hpp>
#include <opencv2/opencv.hpp>
#include "protocol.h"
#include "common.h"
#include "framebuilder.h"

class VideoStreamClient
{
public:
    VideoStreamClient(std::string local_interface, std::string local_port);
    VideoStreamClient(std::string local_interface, std::string local_port, std::string remote_interface, std::string remote_port);

    bool connect(std::string host, std::string port);
    void disconnect();

    cv::Mat requestFrame();

    bool isConnected();

private:
    libsocket::inet_stream tcp_sock;
    libsocket::inet_dgram_server* udp_sock;
    bool connected;
    uint block_size;
};

#endif // STREAMCLIENT_H
