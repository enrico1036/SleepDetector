#include "streamserver.h"
#include <sstream>

VideoStreamServer::VideoStreamServer() : queue_locked(false), max_queue_size(MAX_QUEUE_LENGHT)
{
    running = false;
    max_block_size = 150000;
}

VideoStreamServer::VideoStreamServer(std::string interface, std::string port) : VideoStreamServer()
{
    if (!this->start(interface, port))
        exit(1);
}

VideoStreamServer::~VideoStreamServer()
{
    this->stop();
}

bool VideoStreamServer::start(std::string interface, std::string port)
{
    try {
        tcp_serv_sock.setup(interface, port, LIBSOCKET_BOTH);
        libsocket::setReadTimeout(tcp_serv_sock.getfd(), TCP_TO_SEC, TCP_TO_USEC);

    } catch (libsocket::socket_exception& e) {
        std::cerr << e.mesg << std::endl;
        tcp_serv_sock.destroy();
        return false;
    }

    running = true;
    srv_thread = new std::thread(&VideoStreamServer::loop, this);

    return true;
}

void VideoStreamServer::stop()
{
    running = false;
    if (srv_thread) {
        if (srv_thread->joinable())
            srv_thread->join();
        delete srv_thread;
        srv_thread = NULL;
    }
    std::cout << "THREAD ENDED" << std::endl;

    tcp_serv_sock.destroy();
    if(udp_sock){
        udp_sock->destroy();
        delete udp_sock;
        udp_sock = NULL;
    }

}

void VideoStreamServer::queueFrame(cv::Mat &src)
{
	cv::Mat img;
	
	resize(src, img, cv::Size(0, 0), 0.3, 0.3);
    while(queue_locked) { cout << "while" << endl; }
    queue_locked = true;
    {
        if(out_queue.size() >= max_queue_size){
            delete out_queue.front();
            out_queue.pop();
        }
        FrameSerializer* fs = new FrameSerializer(img.data, img.cols, img.rows, img.channels());
        out_queue.push(fs);
    }
    queue_locked = false;
}

void VideoStreamServer::queueFrame(FrameSerializer *fs)
{
    //out_queue.push(fs);
}

void VideoStreamServer::emptyQueue()
{
    while(out_queue.size() > 0){
        FrameSerializer* fs = out_queue.front();
        if(fs) delete fs;
        out_queue.pop();
    }
}

bool VideoStreamServer::isRunning()
{
    return running;
}

bool VideoStreamServer::isStreaming()
{
    return isRunning();
}

void VideoStreamServer::loop()
{
    ControlPacket p;    // Packet for communication

    while(running){
        // Accept incoming connection
        libsocket::inet_stream* tcp_sock = NULL;
        tcp_sock = tcp_serv_sock.accept();
        if(!tcp_sock)
            continue;
            
        

        // Enter streaming cycle
        bool conn_alive = true;
        while(conn_alive){

            // Read control packet
            try{
            
            	memset(&p, 0, sizeof(p));
                tcp_sock->rcv(&p, sizeof(p));
            } catch (libsocket::socket_exception& e){
                // Handle timeout
                std::cout << "error while receiving" << endl;
                conn_alive = false;
                break;
            }

            // Switch based on packet ID
            switch (p.id) {
            // Client wants to start connection
            case CP_START:
            {
                std::cout << "Start" << std::endl;
                // Client udp server port
                std::stringstream ss;
                ss << p.extra;
                // Create udp socket
                std::cout << "connessione stabilita con: " << ip_to_string(p.block_size) << " - " << ss.str() << endl;
                try {
                    udp_sock = new libsocket::inet_dgram_client(ip_to_string(p.block_size), ss.str(), LIBSOCKET_BOTH);
                    libsocket::setReadTimeout(udp_sock->getfd(), UDP_TO_SEC, UDP_TO_USEC);
                }catch (libsocket::socket_exception& e) {
                    // Handle creation error
                    std::cerr << e.mesg;
                    conn_alive = false;
                    break;
                }
                // Send connection ACK
                p.id = CP_ACK;
                tcp_sock->snd(&p, sizeof(p));
            }
            break;

            // Client wants to interrupt connection
            case CP_STOP:
            {
                conn_alive = false;
                break;
            }

            // Client requests a frame
            case CP_REQ_FRAME:
            {
                // Retrieve FrameSerializer from queue
                while(queue_locked || out_queue.size() <= 0) { };
                queue_locked = true;
                    FrameSerializer* fs = out_queue.front();
                    out_queue.pop();
                queue_locked = false;

                fs->setBlockSize(min(p.block_size, max_block_size));
                // Send client frame information
                p.id = CP_FRAME_INFO;
                p.width = fs->width;
                p.height = fs->height;
                p.channels = fs->channels;
                p.block_size = fs->getBlockSize();
                tcp_sock->snd(&p, sizeof(p));
                memset(&p, 0, sizeof(p));
                // Send frame through udp socket
                try {
                    sendFrame(fs);
                } catch (libsocket::socket_exception& e) {
                    // Handle timeout
                    std::cerr << e.mesg;
                    conn_alive = false;
                }
                // Destroy frame
                delete fs;
            }
            break;

            default: {
            	conn_alive = false;
            }
            break;
            }
        }

        tcp_sock->shutdown();
        tcp_sock->destroy();
        delete tcp_sock;

        if(udp_sock){
            udp_sock->destroy();
            delete udp_sock;
        }
    }
}

void VideoStreamServer::sendFrame(FrameSerializer* fs)
{
    ControlPacket p;
    while(fs->hasNext()){
        FrameSerializer::Block block = fs->nextBlock();
        // Repeat same block until client has received
        // Send block data
        do {
        
        udp_sock->snd(block.addr, block.length);
        udp_sock->rcv(&p, sizeof(p));
        }
        while(p.id != CP_ACK);
    }
}











