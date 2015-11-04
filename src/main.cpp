#include <iostream>
#include <opencv2/opencv.hpp>
#include "detector.h"
#include "sleepdetector.h"
#include "BlueFoxCam.h"
#include <thread>
#include <chrono>
//#include <libusb.h>

using namespace cv;
using namespace std;

#define WIDTH 752
#define HEIGHT 480
#define BLUR_FRAME
#define SCALEFACTOR 0.55 //0.25 original value

int main(int argc, const char * argv[]) {
    
//    VideoCapture cap(1); // open the default camera
//    if(!cap.isOpened())  // check if we succeeded
//        return -1;

//    CvCapture* capture = cvCreateCameraCapture(-1);
//    if (!capture)
//        return -1;
//    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640);
//    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480);
//    cvSetCaptureProperty( capture, CV_CAP_PROP_FPS, 110);
	BlueFoxCam* cam = new BlueFoxCam();
	
    Detector* detector;

    try{
    	detector = new Detector("../haarcascades/haarcascade_frontalface_alt.xml",
        	"../haarcascades/haarcascade_profileface.xml", "../haarcascades/haarcascade_eye.xml", SCALEFACTOR);
     }catch(runtime_error e){
        cout << e.what() << endl;
     }

    SleepDetector sd(SCALEFACTOR);
    Mat frame(HEIGHT, WIDTH, CV_8UC3);
    Mat scaled;
    namedWindow("Acquisition");
    namedWindow("Elaboration", WINDOW_NORMAL);
    resizeWindow("Elaboration", WIDTH, HEIGHT);
    namedWindow("Debug", WINDOW_NORMAL);
    //resizeWindow("Debug", 300, 300);
    
    Face prevface;
    //prevface.eyes.push_back(Rect(0,0,0,0));
    for(;;)
    {
        ////frame = cvarrToMat(cvQueryFrame(capture), true);
        try{
        	cam->getImage(frame.data);
        }catch(runtime_error e){
        	cout << e.what() << endl;
        }
        
        detector->prepareImage(frame, scaled, prevface.face);
        
        
        if(prevface.eye.x){	//eye already detected, so perform track only
            //detector.display(prevface, frame);
            if(prevface.eyeOpen){
            	//sd.waitMillis(50);
            	this_thread::sleep_for(std::chrono::milliseconds(50));
            	if(!sd.isOpen(prevface.eyetpl, SleepDetector::SD_ADAPTIVE_THRESHOLDING)){
            		cout << "Beep!----------------------------------------------------" << endl;
            	}
           	}
           	prevface.eyeOpen = sd.isOpen(prevface.eyetpl, SleepDetector::SD_ADAPTIVE_THRESHOLDING);
            sd.display(frame, prevface.eye.tl());
            //imshow("Elaboration", prevface.eyetpl);
            detector->trackEye(scaled, prevface);
        }
        else	//eye not yet detected
            detector->detect(scaled, prevface);
            // at least a face detected so can be calculated next zoom
            //detector.calculateZoom(frame, prevface.face);


        detector->display(prevface, frame);
        imshow("Aquisition", frame);
        if(waitKey(30) >= 0) break;
    }
    // deinitialize camera
    //delete cam;
    delete detector;
    return 0;
}
