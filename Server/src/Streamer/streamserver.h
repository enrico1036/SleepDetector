#ifndef STREAMSERVER_H
#define STREAMSERVER_H
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include "protocol.h"
#include "common.h"

#include <inetserverstream.hpp>
#include <inetserverdgram.hpp>
#include <inetclientdgram.hpp>
#include <exception.hpp>
#include "frameserializer.h"

#define MAX_QUEUE_LENGHT 2

class VideoStreamServer
{
public:
    VideoStreamServer();
    VideoStreamServer(std::string interface, std::string port);
    ~VideoStreamServer();

    bool start(std::string interface, std::string port);
    void stop();

    void queueFrame(cv::Mat& src);
    void queueFrame(FrameSerializer* fs);
    void emptyQueue();

    bool isRunning();
    bool isStreaming();


private:
    std::queue<FrameSerializer*> out_queue;
    bool queue_locked;
    int max_queue_size;
    libsocket::inet_stream_server tcp_serv_sock;
    libsocket::inet_dgram_client* udp_sock;
    std::thread* srv_thread;
    bool running;
    int max_block_size;

    void loop();
    void sendFrame(FrameSerializer *fs);
};



#endif // STREAMSERVER_H
