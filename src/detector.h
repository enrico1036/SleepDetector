#ifndef DETECTOR
#define DETECTOR

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

typedef struct{
    Rect face;
    Rect eye;
    Mat eyetpl;
}Face;

class Detector{
private:
    CascadeClassifier face_cascade, eye_cascade, profile_cascade;
    float ds;
    float us;
public:
    Detector();
    Detector(std::string frontface, std::string eyes, std::string profileface, float scalefactor);
    void load(std::string frontface, std::string eyes, std::string profileface);
    Face detect(Mat &image);
    void display(Face face, Mat &image);
    void trackEye(Mat im, Face &face);
    void prepareImage(Mat &image, Mat &dst);
    float getUpScale();


//void detectAndDisplay(Mat image);
};
#endif // DETECTOR
