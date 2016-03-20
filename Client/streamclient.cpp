#include "streamclient.h"
#include "sstream"

VideoStreamClient::VideoStreamClient(std::string local_interface, std::string local_port) : connected(false), block_size(65507)
{
    udp_sock = new libsocket::inet_dgram_server(local_interface, local_port, LIBSOCKET_BOTH);

    // Set timeout in order to avoid being stuck on blocking read calls if something goes wrong
    libsocket::setReadTimeout(tcp_sock.getfd(), TCP_TO_SEC, TCP_TO_USEC);
    libsocket::setReadTimeout(udp_sock->getfd(), UDP_TO_SEC, UDP_TO_USEC);
}

VideoStreamClient::VideoStreamClient(std::string local_interface, std::string local_port, std::string remote_interface, std::string remote_port) :
    VideoStreamClient(local_interface, local_port)
{
    connect(remote_interface, remote_port);
}

bool VideoStreamClient::connect(std::string host, std::string port)
{
    ControlPacket p;

    try {
       tcp_sock.connect(host, port, LIBSOCKET_BOTH);

        // Send CP_START with udp server port
        std::stringstream ss;
        ss << udp_sock->getport();
        p.id = CP_START;
        ss >> p.extra;
        p.block_size = string_to_ip(udp_sock->gethost());

        tcp_sock.snd(&p, sizeof(p));
        tcp_sock.rcv(&p, sizeof(p));

    } catch (libsocket::socket_exception& e) {
        return false;
    }

    if(p.id != CP_ACK)
        return false;

    return (connected = true);
}

void VideoStreamClient::disconnect()
{
    // Send CP_STOP
    ControlPacket p;
    p.id = CP_STOP;
    tcp_sock.snd(&p, sizeof(p));

    // Destroy
    tcp_sock.destroy();
    if(udp_sock){
        udp_sock->destroy();
        delete udp_sock;
        udp_sock = NULL;
    }
    connected = false;
}

cv::Mat VideoStreamClient::requestFrame()
{
    cv::Mat mat;

    ControlPacket p;
    FrameBuilder* fb;

    // Fill CP_REQ_FRAME with desired block_size
    p.id = CP_REQ_FRAME;
    p.block_size = block_size;
    try {
        // Send CP_REQ_FRAME
        tcp_sock.snd(&p, sizeof(p));
        // Receive CP_FRAME_INFO
        tcp_sock.rcv(&p, sizeof(p));

        if(!CP_FRAME_INFO)
            return mat;

        // Create instance of FrameBuilder
        fb = new FrameBuilder(p.width, p.height, p.channels);
        fb->setBlockSize(p.block_size);

    } catch (libsocket::socket_exception& e) {
        // Handle timeout
        return mat;
    }

    std::string rcv_host, rcv_port;
    // start udp receive cycle
    while(fb->hasNext()){
        FrameBuilder::Block block = fb->nextBlock();
        ssize_t read;
        do{
        try {
            // Receive block from server
            read = udp_sock->rcvfrom(block.addr, block.length, rcv_host, rcv_port);
            std::cout << "CLN: received: " << read << " vs " << block.length << std::endl;

            // Send back ack with n. of bytes read
            memset(&p, 0, sizeof(p));
            p.id = CP_ACK;
            p.extra = (unsigned short)read;
            udp_sock->sndto(&p, sizeof(p), rcv_host, rcv_port);
        } catch (libsocket::socket_exception& e) {
            // Handle timeout
            delete fb;
            return mat;
        }
        } while(read != block.length);
    }


    mat = cv::Mat(fb->height,fb->width, CV_8UC3);
    std::cout << mat.cols << " " << mat.rows << " " << mat.channels() << std::endl;
    std::copy(fb->getImage(), fb->getImage()+fb->getLength(), mat.data);
    delete fb;
    return mat;
}


bool VideoStreamClient::isConnected()
{
    return connected;
}
