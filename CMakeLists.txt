cmake_minimum_required(VERSION 2.8.4)
project(Decoder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp menu.cpp decode.cpp encode.cpp)
add_executable(Decoder ${SOURCE_FILES})