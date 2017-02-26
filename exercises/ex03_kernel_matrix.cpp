#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>
using namespace std;
using namespace cv;

void Sharpen(const Mat& myImage, Mat& Result)
{
	CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
	Result.create(myImage.size(), myImage.type());
	const int nChannels = myImage.channels();
	for(int j = 1; j < myImage.rows - 1; ++j)
	{
		const uchar* previous = myImage.ptr<uchar>(j - 1);
		const uchar* current  = myImage.ptr<uchar>(j    );
		const uchar* next     = myImage.ptr<uchar>(j + 1);
		uchar* output = Result.ptr<uchar>(j);
		for(int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)
		{
			*output++ = saturate_cast<uchar>(5 * current[i]
			                                 -current[i - nChannels] - current[i + nChannels] - previous[i] - next[i]);
		}
	}
	Result.row(0).setTo(Scalar(0));
	Result.row(Result.rows - 1).setTo(Scalar(0));
	Result.col(0).setTo(Scalar(0));
	Result.col(Result.cols - 1).setTo(Scalar(0));
}

int main( int argc, char** argv ) {
	// show help
	if(argc<2) {
		cout<<
		    " Usage: ex02 <image_name> divideWith\n"
		    << endl;
		return 0;
	}
	// declares all required variables
	Mat I, J, K;
	I = cv::imread( argv[1], CV_LOAD_IMAGE_COLOR);

	Mat kern = (Mat_<char>(3,3) <<  0, -1, 0,
	            -1, 5, -1,
	            0, -1, 0);
	filter2D( I, K, I.depth(), kern );

	cv::imshow("Ex03", K);
	cv::waitKey(0);

	// do the same manually
	Sharpen(I, J);
	cv::imshow("Ex03-1", J);
	cv::waitKey(0);

	return 0;
}


