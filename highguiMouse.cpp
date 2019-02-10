#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat source;

Point center, circumference;

/*使用setMouseCallback()時要一個函式名當參數，
且這個函式要有一定的引數格式(int event, int x, int y, int flags, void* param)，
名稱則可以自己定義。
*/
void drawCircle(int Event, int x, int y, int flags, void* userdata) {
	if (Event == EVENT_LBUTTONDOWN) {
		center = Point(x, y);
		circle(source, center, 2, Scalar(255, 255, 0), 1, CV_AA);
		imshow("Window", source);
	}
	else if (Event == EVENT_LBUTTONUP) {
		circumference = Point(x, y);
		float radius = sqrt(pow(center.x - circumference.x, 2) + pow(center.y - circumference.y, 2));
		circle(source, center, radius, Scalar(255, 0, 255), 2, CV_AA);
		imshow("Window", source);
	}
}

int main() {

	source = imread("../../data/images/sample.jpg");
	
	namedWindow("Window");
	imshow("Window", source);

	setMouseCallback("Window", drawCircle);

	waitKey(0);
	return 0;
}