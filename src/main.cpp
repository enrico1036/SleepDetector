#include <iostream>
#include <opencv2/opencv.hpp>
#include "detector.h"
#include "sleepdetector.h"
#include "../libs/ps3eye.h"
#include <libusb.h>

using namespace cv;
using namespace std;
using namespace ps3eye;

#define WIDTH 752
#define HEIGHT 480
#define BLUR_FRAME
#define SCALEFACTOR 0.25

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    VideoCapture cap(1); // open the default camera
//    if(!cap.isOpened())  // check if we succeeded
//        return -1;

    CvCapture* capture = cvCreateCameraCapture(-1);
    if (!capture)
        return -1;
//    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640);
//    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480);
//    cvSetCaptureProperty( capture, CV_CAP_PROP_FPS, 110);


    
    //TODO Add try catch
    Detector detector("../haarcascades/haarcascade_frontalface_alt.xml",
        "../haarcascades/haarcascade_profileface.xml", "../haarcascades/haarcascade_eye.xml", SCALEFACTOR);

    SleepDetector sd(SCALEFACTOR);
    Mat frame;//(HEIGHT, WIDTH, CV_8UC3);
    Mat scaled;
    namedWindow("Acquisition");
    namedWindow("Elaboration", WINDOW_NORMAL);
    resizeWindow("Elaboration", 300, 300);
    namedWindow("Debug", WINDOW_NORMAL);
    resizeWindow("Debug", 300, 300);
    
    Face prevface;
    //prevface.eyes.push_back(Rect(0,0,0,0));
    for(;;)
    {
        //cap >> frame; // get a new frame from camera
        frame = cvarrToMat(cvQueryFrame(capture), true);
        detector.prepareImage(frame, scaled);
        //GaussianBlur(frame, frame, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        
        if(prevface.eye.x){
            //detector.display(prevface, frame);
            sd.isOpen(prevface.eyetpl, SleepDetector::SD_ADAPTIVE_THRESHOLDING);
            sd.display(frame, prevface.eye.tl());
            imshow("Elaboration", prevface.eyetpl);
            detector.trackEye(scaled, prevface);
        }
        else
            prevface=detector.detect(scaled);

        detector.display(prevface, frame);

        /*if(prevface.eye.tl() != Point(0,0)){
            //Canny(prevface.eyetpl, prevface.eyetpl, 100, 70, 3);
            sd.isOpen(prevface.eyetpl);
            sd.display(frame, prevface.eye.tl());
            imshow("Elaboration", prevface.eyetpl);
        }*/

        imshow("Aquisition", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
