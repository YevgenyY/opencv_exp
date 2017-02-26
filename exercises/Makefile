all: bex01 bex02 bex03

CFLAGS = -g -O0 -I /usr/local 
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs
	        
bex01: ex01_Matobject.cpp
	g++ ex01_Matobject.cpp -o bex01 ${CFLAGS} ${LDFLAGS} 
bex02: ex02_lookupImg.cpp
	g++ ex02_lookupImg.cpp -o bex02 ${CFLAGS} ${LDFLAGS} 
bex03: ex03_kernel_matrix.cpp
	g++ ex03_kernel_matrix.cpp -o bex03 ${CFLAGS} ${LDFLAGS} 


