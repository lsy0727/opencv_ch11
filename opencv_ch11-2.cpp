//1
/*
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
	Mat rect = getStructuringElement(MORPH_RECT, Size(3, 3));	//사각형 모양의 구조 요소
	Mat cross = getStructuringElement(MORPH_CROSS, Size(3, 3));	//십자가 모양의 구조 요소
	Mat ellipse = getStructuringElement(MORPH_ELLIPSE, Size(5, 3));	//타원 모양의 구조 요소

	cout << "MORPH_RECT" << endl;
	cout << rect << endl;
	cout << "MORPH_CROSS" << endl;
	cout << cross << endl;
	cout << "MORPH_ELLIPSE" << endl;
	cout << ellipse << endl;

	return 0;
}
*/

//2
/*
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("letterj.png");

	Mat gray, bin, er;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	threshold(gray, bin, 100, 255, THRESH_BINARY);
	morphologyEx(bin, er, MORPH_OPEN, Mat());	//MORPH_OPEN : 수축 -> 팽창
	morphologyEx(er, er, MORPH_CLOSE, Mat(), Point(-1, -1), 2);	//MORPH_CLOSE : 팽창 -> 수축 (2번 반복 : 팽창 -> 팽창 -> 수축 -> 수축)

	imshow("src", src);
	imshow("bin", bin);
	imshow("erode", er);
	waitKey();

	return 0;
}
*/

//3
/*
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("letterj2.png");

	Mat gray, bin, edge;
	cvtColor(src, gray, COLOR_BGR2GRAY);	//그레이 변환
	threshold(gray, bin, 100, 255, THRESH_BINARY);	//이진화
	morphologyEx(bin, edge, MORPH_GRADIENT, Mat());	// MORPH_GRADIENT : 팽창 - 수축

	imshow("src", src);
	imshow("bin", bin);
	imshow("edge", edge);
	waitKey();

	return 0;
}
*/

//4
/*
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("car.jpg");

	namedWindow("이진화 영상");
	int pos = 0;	//이진화 영상의 임계값
	createTrackbar("threshold", "이진화 영상", &pos, 255);

	while (true) {
		imshow("src", src);

		Mat gray, blurring, dx;
		cvtColor(src, gray, COLOR_BGR2GRAY);	//그레이 변환
		blur(gray, blurring, Size(5, 5));	//5x5 블러링
		Sobel(blurring, dx, CV_32FC1, 1, 0);	//x축 방향 편미분
		dx.convertTo(dx, CV_8UC1);	//8비트 1채널 영상으로 변환
		imshow("x축 방향 소벨", dx);

		Mat bin;
		threshold(dx, bin, pos, 255, THRESH_BINARY);	//이진화
		imshow("이진화 영상", bin);

		Mat close;
		Mat rect = getStructuringElement(MORPH_RECT, Size(32, 5));	//5행 32열의 사각형 구조 요소
		morphologyEx(bin, close, MORPH_CLOSE, rect);	//닫힘 연산
		imshow("닫힘 연산", close);

		waitKey(1);
	}

	return 0;
}
*/