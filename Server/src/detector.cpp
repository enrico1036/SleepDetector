#include "detector.h"

Detector::Detector(){
    ds = 0.3;
    us = 1/ds;
}

Detector::Detector(std::string frontface, std::string eyes, std::string profileface, float scalefactor){
    ds = scalefactor;
    us = 1/ds;
    load(frontface, eyes, profileface);
}

void Detector::load(std::string frontface, std::string eyes, std::string profileface){
    // Load cascade files
    if(!face_cascade.load(frontface)){
        throw std::runtime_error("Error loading face cascade!");
    }
    if(!profile_cascade.load(eyes)){
        throw std::runtime_error("Error loading face cascade!");
    }
    if(!eye_cascade.load(profileface)){
        throw std::runtime_error("Error loading face cascade!");
    }
}

bool Detector::detect(Mat &image, Face &face){
    vector<Rect> faces;
    vector<Rect> eyes;
    Mat resizedFace;
    //Face face;

    //imshow("Elaboration", image);
    //face detection
    face_cascade.detectMultiScale(image, faces, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE);

// profile detection if front face not detected
//    if(!faces.size()){
//        profile_cascade.detectMultiScale(image, faces, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE);
//    }
    

    if(!faces.size()){
        //  no face detected
        face.face = Rect(0,0,0,0);
        return false;
    }
    //  eye detection if face detected
    //only a eye is detected because if a person sleeps, he usually closes both eyes
    face.face = faces[0];
    resizedFace = image(faces[0]-=Size(0,faces[0].height/2));
    //resize(resizedFace, resizedFace, Size(100, 100));
    eye_cascade.detectMultiScale(resizedFace, eyes, 1.1, 3);
    if(!eyes.size()){
        //  no eye detected
        face.eye = Rect(0,0,0,0);
        return true;
    }
    // set eye area
    face.eye=eyes[0]+Point(face.face.x, face.face.y);
    // save eye image
    face.eyetpl = image(face.eye);

    return true;
}

void Detector::display(Face face, Mat &image){
    //face rect
    rectangle(image, Rect(face.face.x*us, face.face.y*us,
                          face.face.width*us, face.face.height*us), Scalar(0,255,0), 5);
    //eye rect
    if(face.eye.x)
        rectangle(image, Rect(face.eye.x*us, face.eye.y*us,
                face.eye.width*us, face.eye.height*us), Scalar(0,0,255), 3);
}

void Detector::trackEye(Mat im, Face &face){
    Rect window(face.eye.x-face.eye.width, face.eye.y-face.eye.height, face.eye.width*2, face.eye.height*2);

    window &=  Rect(0, 0, im.cols, im.rows);
    
    Mat dst(window.width - face.eyetpl.rows + 1, window.height - face.eyetpl.cols + 1, CV_32FC1);

    matchTemplate(im(window), face.eyetpl, dst, CV_TM_SQDIFF_NORMED);
    
    double minval, maxval;
    Point minloc, maxloc;
    minMaxLoc(dst, &minval, &maxval, &minloc, &maxloc);
    //DEBUG cout << "minval: " << minval << "maxval: " << maxval << endl;
    if (minval <= 0.006)//was 0.005
    {
        face.eye.x = window.x + minloc.x;
        face.eye.y = window.y + minloc.y;
        face.eyetpl = im(face.eye);
    }
    else    // no matching template found
        face.eye.x = 0;
}

void Detector::prepareImage(Mat &image, Mat &dst, Rect &face){

    resize(image, dst, Size(0,0), ds, ds, CV_INTER_AREA);
    cvtColor(dst, dst, CV_RGB2GRAY);
    calculateZoom(dst, dst, face);
    
    GaussianBlur(dst, dst, Size(5, 5), 1.2, 1.2);
    //Mat dst2(dst);
    //bilateralFilter(dst2, dst, 5, 5, 5);
}

Mat Detector::calculateZoom(Mat image, Mat &dst, Rect face){
    //  calculate the next zoom factor based on the previous face size
    //zoom = image.cols*image.rows/(face.size().area()*pow(us,2));
    //cout << "x: " << face.x << " y: " << face.y << " width: " << face.width << " height: " << face.height << endl;
    //cout << "x new: " << face.x - face.width*0.1/2 << " y new: " << (int)(face.y - face.height*0.1/2) << endl;

    if(face.x) {
        Rect window((face.x - face.width*0.1/2), (face.y - face.height*0.1/2), (face.width*1.1), (face.height*1.1));
        window &= Rect(0, 0, image.cols, image.rows);
        dst = image(window);
        resize(dst, dst, Size(image.rows, image.rows), 0, 0, INTER_CUBIC);
//        imshow("Elaboration", dst);
    }
    else
        cout << "face not yet detected" << endl;
    return dst = image;
}

float Detector::getUpScale(){
    return us;
}
