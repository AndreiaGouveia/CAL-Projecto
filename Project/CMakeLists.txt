cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(Project
        src/main.cpp src/Graph.h src/Truck.cpp src/Truck.h src/Node.cpp src/Node.h src/MutablePriorityQueue.h)
