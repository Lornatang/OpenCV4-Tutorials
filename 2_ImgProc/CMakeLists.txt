cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(Morphology_2)

find_package(OpenCV REQUIRED)       


INCLUDE_DIRECTORIES(/usr/local/include/opencv4)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4/opencv2)
INCLUDE_DIRECTORIES(/usr/local/include)


add_executable(Morphology_2 Morphology_2.cc)
target_link_libraries(Morphology_2 ${TORCH_LIBRARIES} ${OpenCV_LIBS}) 
set_property(TARGET Morphology_2 PROPERTY CXX_STANDARD 17)