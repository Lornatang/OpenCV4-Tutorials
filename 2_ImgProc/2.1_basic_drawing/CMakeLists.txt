cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(draw)

find_package(OpenCV REQUIRED)       


INCLUDE_DIRECTORIES(/usr/local/include/opencv4)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4/opencv2)
INCLUDE_DIRECTORIES(/usr/local/include)


add_executable(draw Drawing_2.cc)
target_link_libraries(draw ${TORCH_LIBRARIES} ${OpenCV_LIBS}) 
set_property(TARGET draw PROPERTY CXX_STANDARD 17)