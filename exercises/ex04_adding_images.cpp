#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>
using namespace std;
using namespace cv;

int main( int argc, char** argv ) {
	double alpha = 0.5;
	double beta;
	double input;

	Mat src1, src2, dst;
	std::cout<<" Simple Linear Blender "<<std::endl;
	std::cout<<"-----------------------"<<std::endl;
	std::cout<<"* Enter alpha [0-1]: ";
	std::cin>>input;
	if( input >= 0.0 && input <= 1.0 )
	{
		alpha = input;
	}

	// images must be the same size
	src1 = imread("wallhaven-386671.jpg");
	src2 = imread("ubuntu.jpg");

	if( !src1.data || !src2.data)
   	{
		printf("Error loading src1 or src2\n");
		return -1;
	}

	namedWindow("Linear blend", 1);

	beta = ( 1.0 - alpha );
	addWeighted( src1, alpha, src2, beta, 0.0, dst);

	imshow( "Linear blend", dst );

	waitKey(0);

	return 0;
}


