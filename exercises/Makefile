all: bex01

CFLAGS = -g -O0 -I /usr/local 
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs
	        
bex01: ex01_Matobject.cpp
	g++ ex01_Matobject.cpp -o bex01 ${CFLAGS} ${LDFLAGS} 


