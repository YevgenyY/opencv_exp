#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>
using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
	double alpha = 0.5;
	double beta;

	Mat image, new_image;

	image = imread( argv[1] );
	new_image = Mat::zeros( image.size(), image.type() );

	std::cout<<" Basic Linear transform "<<std::endl;
	std::cout<<"-----------------------"<<std::endl;
	std::cout<<"* Enter alpha [0-1]: ";
	std::cin>>alpha;
	std::cout<<"* Enter beta [0-1]: ";
	std::cin >> beta;

	for( int y = 0; y < image.rows; y++ )
	{
		for( int x = 0; x < image.cols; x++ )
		{
			// perform the operation g(i,j)=α⋅f(i,j)+β we will access to each
			// pixel in image. Since we are operating with BGR images, we will
			// have three values per pixel (B, G and R), so we will also
			// access them separately
			for( int c = 0; c < 3; c++ )
			{
				// Since the operation α⋅p(i,j)+β can give values out of range
				// or not integers (if α is float), we use cv::saturate_cast to
				// make sure the values are valid.
				new_image.at<Vec3b>(y,x)[c] =
				    saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + \
				                          beta );
			}
		}
	}

	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	imshow("Original Image", image);
	imshow("New Image", new_image);

	waitKey(0);

	return 0;
}


