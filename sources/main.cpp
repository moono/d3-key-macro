//
// d3-key-macro/function-test-proj/main.cpp

// c++
#include <iostream>
#include <string>
#include <memory>

// opencv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "buff_parser.hpp"

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
	
	std::string const image_dir("D:/git-repos/d3-key-macro/data");
	std::string image_01_fn("/Screenshot040.jpg");
	std::string image_02_fn("/Screenshot043.jpg");

	cv::Mat image_01 = cv::imread(image_dir + image_01_fn);
	cv::Mat image_02 = cv::imread(image_dir + image_02_fn);


	std::shared_ptr<d3km::buff_parser> buffs_parser = std::make_shared<d3km::buff_parser>();

	try {
		
		std::vector<cv::Mat> buff_images_01 = buffs_parser->buff_images(image_01);
		std::vector<cv::Mat> buff_images_02 = buffs_parser->buff_images(image_02);

		std::cout << "" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}