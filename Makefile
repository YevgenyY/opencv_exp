all: capture playvideo tracker pyrdown
	        
tracker: tracker.cpp
	g++ tracker.cpp -o tracker -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core

capture: videocapture.cpp
	g++ videocapture.cpp -o capture -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core
showimg:
	g++ showimg.cpp -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_core

playvideo: playvideo.cpp
	g++ -g -O0 playvideo.cpp -o playvideo -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_core

pyrdown: pyrdown.cpp
	g++ -g -O0 pyrdown.cpp -o pyrdown -I /usr/local -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_core
