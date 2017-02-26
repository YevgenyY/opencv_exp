#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>
using namespace std;
using namespace cv;

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

	return 0;
}


