#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main() {
	VideoCapture video(0);
	CascadeClassifier facedetect;
	Mat img;
	
    facedetect.load("../haarcascade_frontalface_default.xml");
    
    while (true) {
        video.read(img);
        vector<Rect> faces;
        facedetect.detectMultiScale(img, faces, 1.3, 5);

        cout << faces.size() << " face(s) found" << endl;

        for (int i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
        }

        rectangle(img, Point(0, 0), Point(200, 40), Scalar(255, 255, 255), FILLED);

        int fontFace = FONT_HERSHEY_SIMPLEX;
        double fontScale = 0.7;
        int thickness = 1;

        putText(img, "Faces: " + to_string(faces.size()), Point(10, 30), fontFace, fontScale, Scalar(0, 0, 0), thickness);

        imshow("Frame", img);
        waitKey(1);
    }
}
