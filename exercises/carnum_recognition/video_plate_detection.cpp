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
String window_name = "Capture - Face detection";
int main( int argc, const char** argv )
{
    //plate_cascade_name = parser.get<string>("plate_cascade");
    plate_cascade_name  = "/usr/local/share/OpenCV/haarcascades/haarcascade_russian_plate_number.xml";
    VideoCapture capture;
    Mat frame;
    //-- 1. Load the cascades
    if( !plate_cascade.load( plate_cascade_name ) )
    {
        printf("--(!)Error loading plate cascade\n");
        return -1;
    };
    //-- 2. Read the video stream
    capture.open( argv[1] );
    if ( ! capture.isOpened() )
    {
        printf("--(!)Error opening video capture\n");
        return -1;
    }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        //-- 3. Apply the classifier to the frame
        detectAndDisplay( frame );
        char c = (char)waitKey(10);
        if( c == 27 )
        {
            break;    // escape
        }
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
        //ellipse( frame, center, Size( plates[i].width/2, plates[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        Point pt1 (plates[i].x, plates[i].y);
        Point pt2 (plates[i].x + plates[i].width, plates[i].y + plates[i].height);
        rectangle( frame, pt1, pt2, Scalar(255, 0, 255), 3, 8, 0 );

        Mat plateROI = frame_gray( plates[i] );
    }
    //-- Show what you got
    imshow( window_name, frame );
}

