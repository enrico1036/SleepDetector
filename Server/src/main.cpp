
#include <iostream>
#include <opencv2/opencv.hpp>
#include "detector.h"
#include "sleepdetector.h"
#include "BlueFoxCam.h"
#include "LPF.h"
#include "Streamer/streamserver.h"
#include <thread>
#include <chrono>

using namespace cv;
using namespace std;

#define WIDTH 752
#define HEIGHT 480
#define BLUR_FRAME
#define SCALEFACTOR 0.55 //0.25 original value
#define SRV_ADDR "0.0.0.0"
#define SRV_PORT "4567"

int main(int argc, const char * argv[]) {
    
//    VideoCapture cap(1); // open the default camera
//    if(!cap.isOpened())  // check if we succeeded
//        return -1;

#ifdef ENABLE_BLUEFOX
    BlueFoxCam* cam = new BlueFoxCam();
#else	//default opencv camera
    CvCapture* capture = cvCreateCameraCapture(-1);
    if (!capture)
        return -1;
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, WIDTH);
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);
    cvSetCaptureProperty( capture, CV_CAP_PROP_FPS, 60);
#endif

    LowPassFilter* lpf = new LowPassFilter(100, 0);
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
//    namedWindow("Acquisition");
//    namedWindow("Elaboration", WINDOW_NORMAL);
//    resizeWindow("Elaboration", WIDTH, HEIGHT);
//    namedWindow("Debug", WINDOW_NORMAL);
    //resizeWindow("Debug", 300, 300);
    
    Face prevface;
    //prevface.eyes.push_back(Rect(0,0,0,0));
    
    VideoStreamServer vss(SRV_ADDR, SRV_PORT);
    
    
    for(;;)
    {
    	#ifdef BLUEFOX_CAM
	    try{
        	cam->getImage(frame.data);
            }catch(runtime_error e){
        	cout << e.what() << endl;
            }
	#else	//default opencv camera
	    frame = cvarrToMat(cvQueryFrame(capture), true);
	#endif //BLUEFOX_CAM
        
        detector->prepareImage(frame, scaled, prevface.face);
        
        
        if(prevface.eye.x){	//eye already detected, so perform track only
            //detector.display(prevface, frame);
            if(prevface.eyeOpen == 2){
            	this_thread::sleep_for(std::chrono::milliseconds(100));
            	if(lpf->Perform_digital(sd.isOpen(prevface.eyetpl, SleepDetector::SD_ADAPTIVE_THRESHOLDING)? 2 : 0) == 0){
            		cout << "Beep!----------------------------------------------------" << endl;
            	}
           	}else
           		prevface.eyeOpen = lpf->Perform_digital(sd.isOpen(prevface.eyetpl, SleepDetector::SD_ADAPTIVE_THRESHOLDING)? 2 : 0);
           	
            sd.display(frame, prevface.eye.tl());
            //imshow("Elaboration", prevface.eyetpl);
            detector->trackEye(scaled, prevface);
        }
        else	//eye not yet detected
        {
        	lpf->Perform_analog(1);
            detector->detect(scaled, prevface);
        }


        detector->display(prevface, frame);
//        imshow("Aquisition", frame);
        if(vss.isRunning()){
        	vss.queueFrame(frame);
        }
        	
        if(waitKey(10) >= 0) break;
    }
    vss.stop();

    // deinitialize camera
#ifdef ENABLE_BLUEFOX
    delete cam;
#endif
    
    delete detector;
    delete lpf;
    return 0;
}
