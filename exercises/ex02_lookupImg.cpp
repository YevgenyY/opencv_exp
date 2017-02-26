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
	Mat I, J;
	I = cv::imread( argv[1], CV_LOAD_IMAGE_COLOR);

	int divideWith;

	// read divideWith
	stringstream s;
	s << argv[2];
	s >> divideWith;

	if ( !I.data || !divideWith ) 
	{
		cout << "The image " << argv[1] << " could not be loaded" << endl;
		cout << "Usage bex02 image_filename divideWith" << endl;
	}

	// create reducion table
	cout << "Print color reduction table" << endl;
	uchar table[256];
	for ( int i = 0; i < 256; ++i) 
	{
		table[i] = divideWith * (i/divideWith);
		printf("%04x ", table[i]);
	}


	Mat lookupTable(1, 256, CV_8U);
	uchar *p = lookupTable.ptr();

	for( int i = 0; i < 256; ++i ) 
		p[i] = table[i];

	// The fastest function for image color reduction
	LUT(I, lookupTable, J);
	cv::imshow("Ex02", J);

	cv::waitKey(0);


	return 0;
}

