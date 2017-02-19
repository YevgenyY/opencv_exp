all: playvideo
	        
tracker:
	g++ tracker.cpp -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core

capture:
	g++ videocapture.cpp -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core
showimg:
	g++ showimg.cpp -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_core

playvideo:
	g++ -g -O0 playvideo.cpp -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_core
