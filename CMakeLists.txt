cmake_minimum_required(VERSION 3.24)
project(part3)

set(CMAKE_CXX_STANDARD 20)

add_executable(part3 main.cpp Worker.cpp Worker.h WorkerArray.cpp WorkerArray.h MyMatrix.cpp MyMatrix.h)
