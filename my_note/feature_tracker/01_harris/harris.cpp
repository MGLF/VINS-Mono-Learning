#include <iostream>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


int main ( int argc, char** argv )
{
    cv::Mat image_color = cv::imread("house.jpg", cv::IMREAD_COLOR);
 
    //使用灰度图像进行角点检测
	cv::Mat image_gray;
	cv::cvtColor(image_color, image_gray, cv::COLOR_BGR2GRAY);
 
	//设置角点检测参数
	std::vector<cv::Point2f> corners;
	int max_corners = 500;
	double quality_level = 0.01;
	double min_distance = 3.0;
	int block_size = 3;
	bool use_harris = false;
	double k = 0.04;
 
	//角点检测
	cv::goodFeaturesToTrack(image_gray, 
		corners, 
		max_corners, 
		quality_level, 
		min_distance, 
		cv::Mat(), 
		block_size, 
		use_harris, 
		k);
        
	//将检测到的角点绘制到原图上
	for (int i = 0; i < corners.size(); i++)
	{    
                cout<<corners[i]<<endl;
		cv::circle(image_color, corners[i], 1, cv::Scalar(0, 0, 255), 2, 8, 0);
	}
        cout<<"提取harris角点总数："<<endl;
        cout<<corners.size()<<endl;
	cv::imshow("house corner", image_color);
	cv::waitKey(0);
        return 0;
}

