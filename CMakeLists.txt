cmake_minimum_required(VERSION 2.8)
project( coinDetection )
find_package( OpenCV REQUIRED )
add_executable( coinDetection coinDetection.cpp )
target_link_libraries( coinDetection ${OpenCV_LIBS} )

