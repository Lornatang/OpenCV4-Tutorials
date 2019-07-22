cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(OpenCV4)

find_package(OpenCV REQUIRED)       # find OpenCV

INCLUDE_DIRECTORIES(/usr/local/include)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4/opencv2)

add_executable(BasicLinearTransforms BasicLinearTransforms.cc)
target_link_libraries(BasicLinearTransforms ${TORCH_LIBRARIES} ${OpenCV_LIBS}) 
set_property(TARGET BasicLinearTransforms PROPERTY CXX_STANDARD 17)