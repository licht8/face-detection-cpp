cmake_minimum_required(VERSION 3.0)
project (FaceDetection)
# FIND_PACKAGE( OpenCV REQUIRED )                              
	
set( OpenCV_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include" )
set( OpenCV_LIB_DIR "${CMAKE_SOURCE_DIR}/lib" )

link_directories( ${OpenCV_LIB_DIR} )
include_directories( ${OpenCV_INCLUDE_DIR} )

add_executable(fDetection faceDetection.cpp)

target_link_libraries(fDetection
	opencv_world480d.lib
	opencv_world480.lib
)

file(COPY "haarcascade_frontalface_default.xml" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
