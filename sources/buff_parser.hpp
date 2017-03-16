//
// d3-key-macro/buff_parser.hpp

#ifndef D3_KEY_MACRO_BUFF_PARSER_HPP_
#define D3_KEY_MACRO_BUFF_PARSER_HPP_

// c++
#include <stdexcept>
#include <map>
#include <vector>
#include <sstream>

// opencv
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace d3km {

class buff_parser {
public: 
	buff_parser()
	{
		std::string const resolution_1920x1080("1920x1080");
		cv::Size const size_1920x1080_01(50, 49);
		cv::Size const size_1920x1080_02(49, 49);
		std::vector<int> const width_spaces{ 5, 2, 3, 3, 3, 2, 5 };
		std::size_t const how_many_in_one_line = width_spaces.size() + 1;
		cv::Point start(664, 909);
		std::vector<cv::Rect> buffs;
		for (std::size_t i = 0; i < how_many_in_one_line; ++i) {
			cv::Rect buff_loc;
			buff_loc.x = start.x;
			buff_loc.y = start.y;

			if (i >= 3 && i < 5) {
				buff_loc.width = size_1920x1080_02.width;
				buff_loc.height = size_1920x1080_02.height;
			}
			else {
				buff_loc.width = size_1920x1080_01.width;
				buff_loc.height = size_1920x1080_01.height;
			}			

			buffs.emplace_back(buff_loc);

			if (i < width_spaces.size()) {
				start.x += (buff_loc.width + width_spaces[i]);
			}
		}


		buff_loc_by_resolution_.emplace(resolution_1920x1080, buffs);
	}

	// accessors
	auto buff_locations() const { return buff_loc_by_resolution_; }

	// methods
	std::vector<cv::Mat> buff_images(cv::Mat const& image)
	{
		// get image resolution
		std::ostringstream oss;
		oss << image.cols << "x" << image.rows;
		std::string const resolution = oss.str();
		auto cm_it = buff_loc_by_resolution_.find(resolution);
		if (cm_it == buff_loc_by_resolution_.cend()) {
			throw std::runtime_error("Wrong resolution input!!");
		}

		std::vector<cv::Rect> const& buff_loc = cm_it->second;

		std::vector<cv::Mat> buff_images;
		for (auto const& r : buff_loc) {
			cv::Mat cropped(image, r);
			buff_images.emplace_back(cropped.clone());
		}

		return buff_images;
	}
private:
	// define buff locations according to their screen resolutions
	std::map<std::string, std::vector<cv::Rect>> buff_loc_by_resolution_;
};	// class buff_parser

}	// namespace d3km
#endif	// buff_parser.hpp
