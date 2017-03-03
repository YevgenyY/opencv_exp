all: bex01 bex02 bex03 bex04 bex05 bex06 bex07

CFLAGS = -g -O0 -I /usr/local 
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs
	        
bex01: ex01_Matobject.cpp
	g++ ex01_Matobject.cpp -o bex01 ${CFLAGS} ${LDFLAGS} 
bex02: ex02_lookupImg.cpp
	g++ ex02_lookupImg.cpp -o bex02 ${CFLAGS} ${LDFLAGS} 
bex03: ex03_kernel_matrix.cpp
	g++ ex03_kernel_matrix.cpp -o bex03 ${CFLAGS} ${LDFLAGS} 
bex04: ex04_adding_images.cpp
	g++ ex04_adding_images.cpp -o bex04 ${CFLAGS} ${LDFLAGS} 
bex05: ex05_bright_contrast.cpp
	g++ ex05_bright_contrast.cpp -o bex05 ${CFLAGS} ${LDFLAGS} 
bex06: ex06_basic_drawing.cpp
	g++ ex06_basic_drawing.cpp -o bex06 ${CFLAGS} ${LDFLAGS} 

bex07: ex07_dft.cpp
	g++ ex07_dft.cpp -o bex07 ${CFLAGS} ${LDFLAGS} 

