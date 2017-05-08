CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
project(wrapper)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_definitions(-DGPU)

set (OpenCV_DIR /opt/opencv320/share/OpenCV)

find_package(OpenCV 3.2.0 EXACT REQUIRED)
find_package(CUDA REQUIRED)

# Pass options to NVCC
set(
        CUDA_NVCC_FLAGS
        ${CUDA_NVCC_FLAGS};
        -O3 -gencode arch=compute_52,code=sm_52
)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${CUDA_INCLUDE_DIRS}
        example
        wrapper
)

link_directories(
        /usr/local/cuda/lib
        /usr/local/cuda/lib64
        /home/lars/programming/rebase/darknet
)

message(${CUDA_LIBRARIES})

SET(SOURCES
        example/main.cpp

        wrapper/wrapper_cpp.cpp
        wrapper/wrapper_cpp.h
        wrapper/wrapper_c.h)

cuda_add_executable(wrapper ${SOURCES})
target_link_libraries(wrapper ${OpenCV_LIBS} cuda cudart cublas curand darknet)