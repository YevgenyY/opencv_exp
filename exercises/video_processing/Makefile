all: bex01 bex02

CFLAGS = -g -O0 -I /usr/local 
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs
	        
bex01: ex01_extract_rgb.cpp
	g++ ex01_extract_rgb.cpp -o bex01 ${CFLAGS} ${LDFLAGS} 
bex02: ex02_face_detection.cpp
	g++ ex02_face_detection.cpp -o bex02 ${CFLAGS} ${LDFLAGS} 
