all: b_detect_carnum_in_image b_video_plate_detection b_adaptive_thresholding

CFLAGS = -g -O0 -I /usr/local
LDFLAGS = -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_tracking -lopencv_videoio -lopencv_core -lopencv_imgcodecs \
		  -ltesseract
	        
b_detect_carnum_in_image: detect_carnum_in_image.cpp
	g++ detect_carnum_in_image.cpp -o b_detect_carnum_in_image ${CFLAGS} ${LDFLAGS} 
b_video_plate_detection: video_plate_detection.cpp
	g++ video_plate_detection.cpp -o b_video_plate_detection ${CFLAGS} ${LDFLAGS} 

b_adaptive_thresholding: adaptive_thresholding.cpp
	g++ adaptive_thresholding.cpp -o b_adaptive_thresholding ${CFLAGS} ${LDFLAGS} 


clean:
	rm ./b*
