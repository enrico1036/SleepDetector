CC=g++
CFLAGS=-O3 -g -std=gnu++11
INCLUDE_PATH=-I /opt/mvIMPACT_Acquire
LIB_PATH=-L /opt/mvIMPACT_Acquire/lib/armhf/ -L ../libs/
LIBS_MVIMPACT=-lmvDeviceManager -lmvBlueFOX
LIBS_OPENCV=-lopencv_video -lopencv_core -lopencv_objdetect -lopencv_imgproc -lopencv_highgui -lopencv_calib3d -lopencv_gpu
EXEC_NAME=sleep_detector

all: sleep_detector
	@echo "Build complete."
	sudo ./$(EXEC_NAME)
	
sleep_detector: main.o BlueFoxCam.o detector.o sleepdetector.o
	$(CC) -o $(EXEC_NAME) main.o BlueFoxCam.o detector.o sleepdetector.o $(LIB_PATH) $(LIBS_MVIMPACT) $(LIBS_OPENCV)  

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c main.cpp

BlueFoxCam.o: BlueFoxCam.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c BlueFoxCam.cpp
	
detector.o: detector.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c detector.cpp
	
sleepdetector.o: sleepdetector.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c sleepdetector.cpp

clean:
	rm *.o $(EXEC_NAME)

