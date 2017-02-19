#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char **argv) {
	cv::namedWindow( "Example 2", cv::WINDOW_AUTOSIZE );
	cv::VideoCapture cap;
	cap.open( std::string(argv[1]) );

	cv::Mat frame;

	for(;;) {
		cap >> frame;
		if( frame.empty() ) {
			printf("Frame empty\n");	
			break;
		}
		cv::imshow( "Example 2", frame);

		if( cv::waitKey(3000) >= 0 ) {
			printf("break pressed\n");
			break;
		}
	}

	return 0;
}
