all: b_detect_carnum_in_image

CFLAGS = -g -O0 -I /usr/local 
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs
	        
b_detect_carnum_in_image: detect_carnum_in_image.cpp
	g++ detect_carnum_in_image.cpp -o b_detect_carnum_in_image ${CFLAGS} ${LDFLAGS} 
