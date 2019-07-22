cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(HitMiss)

find_package(OpenCV REQUIRED)       


INCLUDE_DIRECTORIES(/usr/local/include/opencv4)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4/opencv2)
INCLUDE_DIRECTORIES(/usr/local/include)


add_executable(HitMiss HitMiss.cc)
target_link_libraries(HitMiss ${TORCH_LIBRARIES} ${OpenCV_LIBS}) 
set_property(TARGET HitMiss PROPERTY CXX_STANDARD 17)