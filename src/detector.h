#ifndef DETECTOR
#define DETECTOR

#include <opencv2/opencv.hpp>
#include <stdexcept>
using namespace cv;
using namespace std;

typedef struct{
    Rect face;
    Rect eye;
    Mat eyetpl;
    bool eyeOpen;
}Face;

class Detector{
private:
    CascadeClassifier face_cascade, eye_cascade, profile_cascade;
    float ds;
    float us;
    float zoom;
public:
    Detector();
    Detector(std::string frontface, std::string eyes, std::string profileface, float scalefactor);
    void load(std::string frontface, std::string eyes, std::string profileface);
    bool detect(Mat &image, Face &face);
    void display(Face face, Mat &image);
    void trackEye(Mat im, Face &face);
    void prepareImage(Mat &image, Mat &dst, Rect &face);
    Mat calculateZoom(Mat image, Mat &dst, Rect face);
    float getUpScale();


//void detectAndDisplay(Mat image);
};
#endif // DETECTOR
