#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <list>

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
//#include "opencv2/world.hpp"

class MultiBandBlender {
private:
	cv::Mat _img1, _img2, _imgResult, _subA, _subB, _mask;
	int _numBands, _overlapWidth;
	int _resWidth, _resHeight;
	cv::Size _resSize;
	//std::string _edgeFlag;
	bool _flagHalf;

	void PreProcess();
	void ProcessNumBands();
	void PrepImages();

	std::vector<cv::Mat> LaplacianPyramid(const cv::Mat& inImg);

public:
	MultiBandBlender(const cv::Mat& img1, const cv::Mat& img2, int bands);
	MultiBandBlender(const cv::Mat& img1, const cv::Mat& img2, int bands, int overlap);
	
	~MultiBandBlender() {}

	cv::Mat GetMask() { return _mask; }

};