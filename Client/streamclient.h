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

/*
    Creates sockets and provides the interface for receiving camera frames from server. 
    The first one, tcp_sock, is a TCP socket used for reliable communication.
    The second one, udp_sock, is the UDP socket on which the actual image is transmitted.
*/

class VideoStreamClient
{
public:
    // Binds udp_socket on local_interface at the local_port
    VideoStreamClient(std::string local_interface, std::string local_port);
    // Same as above, but in addition connects tcp_sock to specified remote host and port
    VideoStreamClient(std::string local_interface, std::string local_port, std::string remote_interface, std::string remote_port);

    // Connects tcp_sock to host:port
    bool connect(std::string host, std::string port);

    // Disconnects both udp and tcp sockets
    void disconnect();

    // Returns the image received from server as an opencv matrix
    cv::Mat requestFrame();

    // True if both sockets are connected
    bool isConnected();

private:
    libsocket::inet_stream tcp_sock;
    libsocket::inet_dgram_server* udp_sock;
    bool connected;
    uint block_size;
};

#endif // STREAMCLIENT_H
