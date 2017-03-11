//
// d3-key-macro/function-test-proj/main.cpp

// c++
#include <iostream>

// opencv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// set opencv related fields
#if _DEBUG
#define OPENCV_LIB_POSTFIX "d"
#else
#define OPENCV_LIB_POSTFIX ""
#endif

// additional link libraries
#pragma comment(lib, "opencv_core2413" OPENCV_LIB_POSTFIX)
#pragma comment(lib, "opencv_highgui2413" OPENCV_LIB_POSTFIX)
#pragma comment(lib, "opencv_imgproc2413" OPENCV_LIB_POSTFIX)


int main(int argc, char* argv[])
{
	cv::Mat image(500, 500, CV_8UC3);
	return 0;
}