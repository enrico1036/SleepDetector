#include "sleepdetector.h"

SleepDetector::SleepDetector(float scalefactor){
    ds = scalefactor;
    us = 1/ds;
}

bool SleepDetector::isOpen(Mat &src, Method method){
    vector<vector<Point> > contours;
    Mat image(src);
    //resize(src, image, Size(20, 20)); TODO: adapt drawing circle to the resized image
    bool isOpen = false;

    switch (method){
        case SD_CIRCLES_FINDING:
    //    1st try: Looking for circle method
            HoughCircles(image, circles, CV_HOUGH_GRADIENT, 2, 1);
            cout << circles.size() << endl;
            break;

        case SD_THRESHOLDING:
    //    2nd try: thresholding and blob detection
            equalizeHist(image, converted);
            threshold(converted, converted, 240, 255, THRESH_BINARY_INV|THRESH_OTSU);
            //resize(converted, converted, Size(0,0), ds, ds);
            // Find all contours

            findContours(converted.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

            // Fill holes in each contour
            drawContours(converted, contours, -1, CV_RGB(255,255,255), -1);
            for (int i = 0; i < contours.size(); i++)
            {
                double area = contourArea(contours[i]); // Blob area
                Rect rect = boundingRect(contours[i]);  // Bounding box
                int radius = rect.width/2;              // Approximate radius

                // Look for round shaped blob
                if (area >= 1 &&
                    abs(1 - ((double)rect.width / (double)rect.height)) <= 0.2 &&
                    abs(1 - (area / (CV_PI * pow(radius, 2)))) <= 0.2)
                {
                	isOpen = true;
                    cout << "Found pupil!  " << i << endl;
                    circles.push_back(Vec3f((rect.x + radius), (rect.y + radius), radius));
                    cout << "x: " << rect.x << " y: " << rect.y << " radius: " << radius << endl;
                }
            }
            resize(converted, converted, Size(0,0), us, us);
//            imshow("Debug", converted);
            break;

        case SD_ADAPTIVE_THRESHOLDING:
            equalizeHist(image, converted);
            //GaussianBlur(converted, converted, Size(3,3), 1, 1);
            adaptiveThreshold(converted, converted, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 7, 18);
            // Find all contours
            //vector<vector<Point> > contours;
            findContours(converted.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

            // Fill holes in each contour
            drawContours(converted, contours, -1, CV_RGB(255,255,255), -1);
            
            for (int i = 0; i < contours.size(); i++)
            {
                double area = contourArea(contours[i]); // Blob area
                Rect rect = boundingRect(contours[i]);  // Bounding box
                int radius = rect.width/2;              // Approximate radius

                // Look for round shaped blob

                if (area >= 4 &&
                    abs(1 - ((double)rect.width / (double)rect.height)) <= 0.4 &&
                    abs(1 - (area / (CV_PI * pow(radius, 2)))) <= 0.9)
                {
                	isOpen = true;
                    cout << "Found pupil!  " << i << endl;
                    cout << area << endl;
                    circles.push_back(Vec3f((rect.x + radius), (rect.y + radius), radius));
                    cout << "x: " << rect.x << " y: " << rect.y << " radius: " << radius << endl;
                }
            }
            resize(converted, converted, Size(0,0), us, us);
//            imshow("Debug", converted);
            break;

    case SD_VARIANCE:
        Scalar mean;
        Scalar stddev;
        equalizeHist(image, converted);
//        imshow("Debug", converted);
        meanStdDev(converted, mean, stddev);
        cout << stddev.val[0] << endl;
        break;
    }
    return isOpen;
}

void SleepDetector::waitMillis(int millis){
    int goal = clock() + millis*CLOCKS_PER_SEC/1000;
    while (clock() < goal);
}

void SleepDetector::display(Mat &image, Point offset){
    while(circles.size()){
        circle(image, (Point(cvRound(circles.front()[0]), cvRound(circles.front()[1]))+offset)*us, cvRound(circles.front()[2]*us), Scalar(255,0,0), 3);
        circles.erase(circles.begin());
    }
}


