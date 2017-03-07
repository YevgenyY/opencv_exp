#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
using namespace cv;
/* @function main */
int main ( int argc, char** argv )
{
	Mat src, dst;
	Mat kernel;
	Point anchor;
	double delta;
	int ddepth;
	int kernel_size;
	char* window_name = "filter2D Demo";
	int c;

	src = imread( argv[1] );
	if( !src.data )
	{
		return -1;
	}
	namedWindow( window_name, WINDOW_AUTOSIZE );
	anchor = Point( -1, -1 );
	delta = 0;
	ddepth = -1;
	int ind = 0;
	while( true )
	{
		c = waitKey(500);
		if( (char)c == 27 )
		{
			break;
		}
		kernel_size = 3 + 2*( ind%5 );
		kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
		filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
		imshow( window_name, dst );
		ind++;
	}

	return 0;
}

