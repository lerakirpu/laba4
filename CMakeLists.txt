cmake_minimum_required(VERSION 3.10)
project(SepiaEffect)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

add_executable(SepiaEffect main.cpp)
target_link_libraries(SepiaEffect ${OpenCV_LIBS})
