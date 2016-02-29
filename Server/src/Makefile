CC=g++
CFLAGS=-O0 -g -std=gnu++11
INCLUDE_PATH=-I /opt/mvIMPACT_Acquire -I ../libs/*
LIB_PATH=-L /opt/mvIMPACT_Acquire/lib/armhf/
LIBS_MVIMPACT=-lmvDeviceManager -lmvBlueFOX
LIBS_OPENCV=-lopencv_video -lopencv_core -lopencv_objdetect -lopencv_imgproc -lopencv_highgui -lopencv_calib3d -lopencv_gpu
LIBS_SOCKET=-lsocket++
EXEC_NAME=sleep_detector

all: objects
	@echo "Build complete."
	sudo ./$(EXEC_NAME)
	
objects: SleepDetector.o Streamer.o
	$(CC) -o $(EXEC_NAME) *.o $(LIB_PATH) $(LIBS_MVIMPACT) $(LIBS_OPENCV) $(LIBS_SOCKET)

SleepDetector.o: *.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c *.cpp
	
Streamer.o: Streamer/*.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c Streamer/*.cpp
	
clean:
	rm *.o $(EXEC_NAME)

