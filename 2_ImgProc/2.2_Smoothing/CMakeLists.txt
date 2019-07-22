cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(Smoothing)

find_package(OpenCV REQUIRED)       


INCLUDE_DIRECTORIES(/usr/local/include/opencv4)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4/opencv2)
INCLUDE_DIRECTORIES(/usr/local/include)


add_executable(Smoothing Smoothing.cc)
target_link_libraries(Smoothing ${TORCH_LIBRARIES} ${OpenCV_LIBS}) 
set_property(TARGET Smoothing PROPERTY CXX_STANDARD 17)