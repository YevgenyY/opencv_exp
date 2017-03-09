#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
void detectAndDisplay( Mat frame );
String plate_cascade_name;
CascadeClassifier plate_cascade;
String window_name = "Capture - Car plate detection";
int main( int argc, const char** argv )
{
	CommandLineParser parser(argc, argv,
	                         "{help h||}"
	                         "{plate_cascade|../../data/haarcascades/haarcascade_frontalplate_alt.xml|}"
	                         "{eyes_cascade|../../data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|}");
	cout << "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
	     "You can use Haar or LBP features.\n\n";
	parser.printMessage();
	//plate_cascade_name = parser.get<string>("plate_cascade");
	plate_cascade_name = "/usr/local/share/OpenCV/haarcascades/haarcascade_russian_plate_number.xml";
	Mat frame;
	//-- 1. Load the cascades
	if( !plate_cascade.load( plate_cascade_name ) )
	{
		printf("--(!)Error loading plate cascade\n");
		return -1;
	};
	//-- 2. Read the image
	frame = cv::imread( std::string(argv[1]) );
	if( frame.empty() )
	{
		printf(" --(!) No captured frame -- Break!");
		return -1;
	}
	//-- 3. Apply the classifier to the frame
	detectAndDisplay( frame );
	char c = (char)waitKey(10);
	if( c == 27 )
	{
		return 0;    // escape
	}
	return 0;
}

void detectAndDisplay( Mat frame )
{
	std::vector<Rect> plates;
	Mat frame_gray;
	cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
	equalizeHist( frame_gray, frame_gray );
	//-- Detect plates
	plate_cascade.detectMultiScale( frame_gray, plates, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
	for ( size_t i = 0; i < plates.size(); i++ )
	{
		Point center( plates[i].x + plates[i].width/2, plates[i].y + plates[i].height/2 );
		Point pt1 (plates[i].x, plates[i].y);
		Point pt2 (plates[i].x + plates[i].width, plates[i].y + plates[i].height);
		//ellipse( frame, center, Size( plates[i].width/2, plates[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
		rectangle( frame, pt1, pt2, Scalar(255, 0, 255), 3, 8, 0 );
		Mat plateROI = frame_gray( plates[i] );
		std::vector<Rect> eyes;

		Mat P ( frame, Rect(plates[i].x, plates[i].y, plates[i].width, plates[i].height) );
		imshow( "plate", P );

		cout << "point[i]: " << plates[i] << endl;
		//-- In each plate, detect eyes
#if 0
		eyes_cascade.detectMultiScale( plateROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );
		for ( size_t j = 0; j < eyes.size(); j++ )
		{
			Point eye_center( plates[i].x + eyes[j].x + eyes[j].width/2, plates[i].y + eyes[j].y + eyes[j].height/2 );
			int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
			circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
		}
#endif
	}
	//-- Show what you got
	imshow( window_name, frame );
	cv::waitKey(0);
}
