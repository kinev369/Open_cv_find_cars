#include "Blob.h"
#include "Header.h"
#include <iostream>
#include <stdint.h>
#include<conio.h>           
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>


#define SHOW_STEPS            
using namespace std;
using namespace cv;

void display(Mat &im, Mat &bbox) {
	int n = bbox.rows;
	for (int i = 0; i < n; i++) {
		line(im, Point2i(bbox.at<float>(i, 0), bbox.at<float>(i, 1)), Point2i(bbox.at<float>((i + 1) % n, 0), bbox.at<float>((i + 1) % n, 1)), Scalar(255, 0, 0), 3);
	}
	imshow("Result", im);
}
int main()
{
	VideoCapture cap(0);
	Mat frame;
	Dict* frames= new Dict();
	QRCodeDetector qrDecoder = QRCodeDetector::QRCodeDetector();
	Mat bbox, rectifiedImage;
	string data2 = "";
	while (true) {
		cap>>frame;
		string data = qrDecoder.detectAndDecode(frame,bbox,rectifiedImage);

		if (data.length() > 0&& data != data2) {
				display(frame, bbox);
				data2 = data;
				//rectifiedImage.convertTo(rectifiedImage, CV_8UC3);
				frames->Finder(atoi(data.c_str()));
				//imshow("Rectified QRCode", rectifiedImage);
		}
		imshow("image", frame);
		waitKey(1);
	}
	return 0;
}

