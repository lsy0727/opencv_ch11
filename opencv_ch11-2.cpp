//1
/*
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main() {
	Mat rect = getStructuringElement(MORPH_RECT, Size(3, 3));	//�簢�� ����� ���� ���
	Mat cross = getStructuringElement(MORPH_CROSS, Size(3, 3));	//���ڰ� ����� ���� ���
	Mat ellipse = getStructuringElement(MORPH_ELLIPSE, Size(5, 3));	//Ÿ�� ����� ���� ���

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
	morphologyEx(bin, er, MORPH_OPEN, Mat());	//MORPH_OPEN : ���� -> ��â
	morphologyEx(er, er, MORPH_CLOSE, Mat(), Point(-1, -1), 2);	//MORPH_CLOSE : ��â -> ���� (2�� �ݺ� : ��â -> ��â -> ���� -> ����)

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
	cvtColor(src, gray, COLOR_BGR2GRAY);	//�׷��� ��ȯ
	threshold(gray, bin, 100, 255, THRESH_BINARY);	//����ȭ
	morphologyEx(bin, edge, MORPH_GRADIENT, Mat());	// MORPH_GRADIENT : ��â - ����

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

	namedWindow("����ȭ ����");
	int pos = 0;	//����ȭ ������ �Ӱ谪
	createTrackbar("threshold", "����ȭ ����", &pos, 255);

	while (true) {
		imshow("src", src);

		Mat gray, blurring, dx;
		cvtColor(src, gray, COLOR_BGR2GRAY);	//�׷��� ��ȯ
		blur(gray, blurring, Size(5, 5));	//5x5 ����
		Sobel(blurring, dx, CV_32FC1, 1, 0);	//x�� ���� ��̺�
		dx.convertTo(dx, CV_8UC1);	//8��Ʈ 1ä�� �������� ��ȯ
		imshow("x�� ���� �Һ�", dx);

		Mat bin;
		threshold(dx, bin, pos, 255, THRESH_BINARY);	//����ȭ
		imshow("����ȭ ����", bin);

		Mat close;
		Mat rect = getStructuringElement(MORPH_RECT, Size(32, 5));	//5�� 32���� �簢�� ���� ���
		morphologyEx(bin, close, MORPH_CLOSE, rect);	//���� ����
		imshow("���� ����", close);

		waitKey(1);
	}

	return 0;
}
*/