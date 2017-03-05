all: bex01 bex02 bex03 bex04 bex05 bex06 bex07 bex08

CFLAGS = -g -O0 -I /usr/local 
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs
	        
bex01: ex01_laplacian_edges.cpp
	g++ ex01_laplacian_edges.cpp -o bex01 ${CFLAGS} ${LDFLAGS} 
bex02: ex02_sobel_operator.cpp
	g++ ex02_sobel_operator.cpp -o bex02 ${CFLAGS} ${LDFLAGS} 
bex03: ex03_borders.cpp
	g++ ex03_borders.cpp -o bex03 ${CFLAGS} ${LDFLAGS} 
bex04: ex04_basic_thresholding.cpp
	g++ ex04_basic_thresholding.cpp -o bex04 ${CFLAGS} ${LDFLAGS} 
bex05: ex05_simple_filter_kernel.cpp
	g++ ex05_simple_filter_kernel.cpp -o bex05 ${CFLAGS} ${LDFLAGS} 
bex06: ex06_extract_lines.cpp
	g++ ex06_extract_lines.cpp -o bex06 ${CFLAGS} ${LDFLAGS} 
bex07: ex07_hough_circles.cpp
	g++ ex07_hough_circles.cpp -o bex07 ${CFLAGS} ${LDFLAGS} 
bex08: ex08_affine_transform.cpp
	g++ ex08_affine_transform.cpp -o bex08 ${CFLAGS} ${LDFLAGS} 


