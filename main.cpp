#include <highgui.h>
#include <cv.h>
#include <iostream>

using namespace std;
using namespace cv;

Mat redFilter(const Mat& src)
{
    assert(src.type() == CV_8UC3);
	
    Mat redOnly;
    inRange(src, Scalar(0, 0, 0), Scalar(0, 0, 255), redOnly);
	
    return redOnly;
}

Mat greenFilter(const Mat& src)
{
    assert(src.type() == CV_8UC3);
	
    Mat greenOnly;
    inRange(src, Scalar(0, 0, 0), Scalar(0, 255, 0), greenOnly);
	
    return greenOnly;
}

Mat blueFilter(const Mat& src)
{
    assert(src.type() == CV_8UC3);
	
    Mat blueOnly;
    inRange(src, Scalar(0, 0, 0), Scalar(255, 0, 0), blueOnly);
	
    return blueOnly;
}



int main(int argc, char** argv)
{
    Mat input = imread("colored_squares.png");
	
    imshow("input", input);
    waitKey();
	
    Mat redOnly = redFilter(input);
	
    imshow("redOnly", redOnly);
    waitKey();
	
	
    Mat greenOnly = greenFilter(input);
	
    imshow("greenOnly", greenOnly);
    waitKey();
	
	
    Mat blueOnly = blueFilter(input);
	
    imshow("blueOnly", blueOnly);
    waitKey();


	
    // detect squares after filtering...
	
    return 0;
}