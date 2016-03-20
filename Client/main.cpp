#include "exception.hpp"
#include <exception>
#include "streamclient.h"
#include <opencv2/opencv.hpp>
#include "frameserializer.h"
#include "stdio.h"

#define SRV_ADDR "192.168.1.2"
#define SRV_PORT "9999"

int main(int argc, char** argv)
{
    VideoStreamClient vsc("192.168.1.2", "4569");
    vsc.connect(argv[1], argv[2]);

    while(vsc.isConnected()) {
        cv::Mat sentframe = vsc.requestFrame();
        if(sentframe.empty())
            continue;

        cv::imshow("Sent", sentframe);
        cv::waitKey(1000 / 25);
    }

    vsc.disconnect();
    return 0;
}


