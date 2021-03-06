#ifndef SLEEPDETECTOR_H
#define SLEEPDETECTOR_H

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <time.h>

using namespace cv;
using namespace std;

class SleepDetector
{
private:
    float us;
    float ds;
    vector<Vec3f> circles;
    Mat converted;

public:

    enum Method{
        SD_CIRCLES_FINDING = 1,
        SD_THRESHOLDING = 2,
        SD_ADAPTIVE_THRESHOLDING = 3,
        SD_VARIANCE = 4
    };

    SleepDetector(float scalefactor);
    bool isOpen(Mat &src, Method method);
    void waitMillis(int millis);
    void display(Mat &image, Point offset);
};

#endif // SLEEPDETECTOR_H
