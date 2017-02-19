#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv) {
	Mat img = imread(argv[1], -1);

	if(img.empty())
		return -1;

	namedWindow( "Example 1", WINDOW_AUTOSIZE );
	imshow( "Example 1", img);

	waitKey( 0 );
	destroyWindow( "Exapmle 1" );

	return 0;
}
