CC=g++
CFLAGS=-O0 -g -std=gnu++11
INCLUDE_PATH=-I libsocket
LIBS_OPENCV=-lopencv_video -lopencv_core -lopencv_objdetect -lopencv_imgproc -lopencv_highgui -lopencv_calib3d -lopencv_gpu
LIBS_SOCKET=-lsocket++
EXEC_NAME=client

all: objects
	@echo "Build complete."
	sudo ./$(EXEC_NAME) 192.168.1.2 9999
	
objects: client.o
	$(CC) -o $(EXEC_NAME) *.o $(LIBS_OPENCV) $(LIBS_SOCKET)

client.o: *.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c *.cpp

clean:
	rm *.o $(EXEC_NAME)

