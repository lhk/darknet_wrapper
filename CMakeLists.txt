cmake_minimum_required(VERSION 2.8.3)
project(wrapper)
add_compile_options(-std=c++14 -Werror=return-type -Wall)

set (CMAKE_BUILD_TYPE  DEBUG)
set (OpenCV_DIR /opt/opencv320/share/OpenCV)

find_package(OpenCV 3.2.0 EXACT REQUIRED)
find_package(CUDA REQUIRED)


include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIRS}
    src
    darknet/include
)

link_directories(
    /usr/local/cuda/lib
    /usr/local/cuda/lib64
    darknet
)



add_executable(main
        main.cpp
        darknet_wrapper/wrapper_cpp.cpp
        darknet_wrapper/wrapper_cpp.h
        darknet/src/wrapper_c.h)

target_link_libraries(main ${OpenCV_LIBS} cuda cudart cublas curand darknet)
