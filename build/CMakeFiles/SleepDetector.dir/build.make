# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Enrico/Desktop/SleepDetector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Enrico/Desktop/SleepDetector/build

# Include any dependencies generated for this target.
include CMakeFiles/SleepDetector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SleepDetector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SleepDetector.dir/flags.make

CMakeFiles/SleepDetector.dir/src/detector.cpp.o: CMakeFiles/SleepDetector.dir/flags.make
CMakeFiles/SleepDetector.dir/src/detector.cpp.o: ../src/detector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Enrico/Desktop/SleepDetector/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SleepDetector.dir/src/detector.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SleepDetector.dir/src/detector.cpp.o -c /Users/Enrico/Desktop/SleepDetector/src/detector.cpp

CMakeFiles/SleepDetector.dir/src/detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SleepDetector.dir/src/detector.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Enrico/Desktop/SleepDetector/src/detector.cpp > CMakeFiles/SleepDetector.dir/src/detector.cpp.i

CMakeFiles/SleepDetector.dir/src/detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SleepDetector.dir/src/detector.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Enrico/Desktop/SleepDetector/src/detector.cpp -o CMakeFiles/SleepDetector.dir/src/detector.cpp.s

CMakeFiles/SleepDetector.dir/src/detector.cpp.o.requires:
.PHONY : CMakeFiles/SleepDetector.dir/src/detector.cpp.o.requires

CMakeFiles/SleepDetector.dir/src/detector.cpp.o.provides: CMakeFiles/SleepDetector.dir/src/detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/SleepDetector.dir/build.make CMakeFiles/SleepDetector.dir/src/detector.cpp.o.provides.build
.PHONY : CMakeFiles/SleepDetector.dir/src/detector.cpp.o.provides

CMakeFiles/SleepDetector.dir/src/detector.cpp.o.provides.build: CMakeFiles/SleepDetector.dir/src/detector.cpp.o

CMakeFiles/SleepDetector.dir/src/main.cpp.o: CMakeFiles/SleepDetector.dir/flags.make
CMakeFiles/SleepDetector.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Enrico/Desktop/SleepDetector/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SleepDetector.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SleepDetector.dir/src/main.cpp.o -c /Users/Enrico/Desktop/SleepDetector/src/main.cpp

CMakeFiles/SleepDetector.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SleepDetector.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Enrico/Desktop/SleepDetector/src/main.cpp > CMakeFiles/SleepDetector.dir/src/main.cpp.i

CMakeFiles/SleepDetector.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SleepDetector.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Enrico/Desktop/SleepDetector/src/main.cpp -o CMakeFiles/SleepDetector.dir/src/main.cpp.s

CMakeFiles/SleepDetector.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/SleepDetector.dir/src/main.cpp.o.requires

CMakeFiles/SleepDetector.dir/src/main.cpp.o.provides: CMakeFiles/SleepDetector.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SleepDetector.dir/build.make CMakeFiles/SleepDetector.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/SleepDetector.dir/src/main.cpp.o.provides

CMakeFiles/SleepDetector.dir/src/main.cpp.o.provides.build: CMakeFiles/SleepDetector.dir/src/main.cpp.o

CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o: CMakeFiles/SleepDetector.dir/flags.make
CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o: ../src/sleepdetector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Enrico/Desktop/SleepDetector/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o -c /Users/Enrico/Desktop/SleepDetector/src/sleepdetector.cpp

CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Enrico/Desktop/SleepDetector/src/sleepdetector.cpp > CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.i

CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Enrico/Desktop/SleepDetector/src/sleepdetector.cpp -o CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.s

CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.requires:
.PHONY : CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.requires

CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.provides: CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.requires
	$(MAKE) -f CMakeFiles/SleepDetector.dir/build.make CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.provides.build
.PHONY : CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.provides

CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.provides.build: CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o

# Object files for target SleepDetector
SleepDetector_OBJECTS = \
"CMakeFiles/SleepDetector.dir/src/detector.cpp.o" \
"CMakeFiles/SleepDetector.dir/src/main.cpp.o" \
"CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o"

# External object files for target SleepDetector
SleepDetector_EXTERNAL_OBJECTS =

SleepDetector: CMakeFiles/SleepDetector.dir/src/detector.cpp.o
SleepDetector: CMakeFiles/SleepDetector.dir/src/main.cpp.o
SleepDetector: CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o
SleepDetector: CMakeFiles/SleepDetector.dir/build.make
SleepDetector: /usr/local/lib/libopencv_videostab.a
SleepDetector: /usr/local/lib/libopencv_videoio.a
SleepDetector: /usr/local/lib/libopencv_video.a
SleepDetector: /usr/local/lib/libopencv_ts.a
SleepDetector: /usr/local/lib/libopencv_superres.a
SleepDetector: /usr/local/lib/libopencv_stitching.a
SleepDetector: /usr/local/lib/libopencv_shape.a
SleepDetector: /usr/local/lib/libopencv_photo.a
SleepDetector: /usr/local/lib/libopencv_objdetect.a
SleepDetector: /usr/local/lib/libopencv_ml.a
SleepDetector: /usr/local/lib/libopencv_imgproc.a
SleepDetector: /usr/local/lib/libopencv_imgcodecs.a
SleepDetector: /usr/local/lib/libopencv_highgui.a
SleepDetector: /usr/local/lib/libopencv_hal.a
SleepDetector: /usr/local/lib/libopencv_flann.a
SleepDetector: /usr/local/lib/libopencv_features2d.a
SleepDetector: /usr/local/lib/libopencv_core.a
SleepDetector: /usr/local/lib/libopencv_calib3d.a
SleepDetector: /usr/local/lib/libopencv_features2d.a
SleepDetector: /usr/local/lib/libopencv_ml.a
SleepDetector: /usr/local/lib/libopencv_highgui.a
SleepDetector: /usr/local/lib/libopencv_videoio.a
SleepDetector: /usr/local/lib/libopencv_imgcodecs.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/liblibjpeg.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/liblibwebp.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/liblibpng.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/liblibtiff.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/liblibjasper.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/libIlmImf.a
SleepDetector: /usr/local/lib/libopencv_flann.a
SleepDetector: /usr/local/lib/libopencv_video.a
SleepDetector: /usr/local/lib/libopencv_imgproc.a
SleepDetector: /usr/local/lib/libopencv_core.a
SleepDetector: /usr/local/lib/libopencv_hal.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/libzlib.a
SleepDetector: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
SleepDetector: CMakeFiles/SleepDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SleepDetector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SleepDetector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SleepDetector.dir/build: SleepDetector
.PHONY : CMakeFiles/SleepDetector.dir/build

CMakeFiles/SleepDetector.dir/requires: CMakeFiles/SleepDetector.dir/src/detector.cpp.o.requires
CMakeFiles/SleepDetector.dir/requires: CMakeFiles/SleepDetector.dir/src/main.cpp.o.requires
CMakeFiles/SleepDetector.dir/requires: CMakeFiles/SleepDetector.dir/src/sleepdetector.cpp.o.requires
.PHONY : CMakeFiles/SleepDetector.dir/requires

CMakeFiles/SleepDetector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SleepDetector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SleepDetector.dir/clean

CMakeFiles/SleepDetector.dir/depend:
	cd /Users/Enrico/Desktop/SleepDetector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Enrico/Desktop/SleepDetector /Users/Enrico/Desktop/SleepDetector /Users/Enrico/Desktop/SleepDetector/build /Users/Enrico/Desktop/SleepDetector/build /Users/Enrico/Desktop/SleepDetector/build/CMakeFiles/SleepDetector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SleepDetector.dir/depend
