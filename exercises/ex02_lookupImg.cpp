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
		    " Usage: ex01 <image_name>\n"
		    << endl;
		return 0;
	}
	// declares all required variables
	Mat A, C;
	A = cv::imread( argv[1]);

	Mat D (A, Rect(50, 50, 2, 2) ); // using a rectangle
	Mat E = A(Range::all(), Range(1,1000)); // using row and column boundaries

	cv::imshow("ex01", E);
	cv::waitKey( 0 );

	// Mat initialization as matrix
	// http://docs.opencv.org/3.1.0/d6/d6d/tutorial_mat_the_basic_image_container.html
	Mat M(2,2, CV_8UC3, Scalar(0,0,255));
	cout << "M = " << endl << " " << M << endl << endl;

	// Formatting output for matlab (default)
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));

	cout << "R (default) = " << endl << R << endl << endl;
	// Formatting output for python (example)
	cout << "R (python)  = " << endl << format(R, Formatter::FMT_PYTHON) << endl << endl;
	// Formatting output for CSV (example)
	cout << "R (csv)     = " << endl << format(R, Formatter::FMT_CSV ) << endl << endl;
	// Formatting output for numpy (example)
	cout << "R (numpy)     = " << endl << format(R, Formatter::FMT_NUMPY ) << endl << endl;


	// output other common items
	vector<Point2f> vPoints(20);
	for (size_t i = 0; i < vPoints.size(); ++i)
		vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
	cout << "A vector of 2D Points = " << vPoints << endl << endl;

	cout << "A = " << endl << " " << D << endl << endl;

	return 0;
}

