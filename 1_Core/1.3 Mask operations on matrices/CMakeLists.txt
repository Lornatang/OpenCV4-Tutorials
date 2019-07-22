cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(OpenCV4)

find_package(OpenCV REQUIRED)       # find OpenCV


INCLUDE_DIRECTORIES(/usr/local/include/opencv4)
INCLUDE_DIRECTORIES(/usr/local/include/opencv4/opencv2)
INCLUDE_DIRECTORIES(/usr/local/include)

add_executable(mat_mask_operations mat_mask_operations.cc)
target_link_libraries(mat_mask_operations ${TORCH_LIBRARIES} ${OpenCV_LIBS}) 
set_property(TARGET mat_mask_operations PROPERTY CXX_STANDARD 17)