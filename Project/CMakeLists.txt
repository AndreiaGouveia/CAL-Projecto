cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

link_libraries(ws2_32 wsock32)

add_executable(Project
        src/main.cpp
        src/Graph.h
        src/Truck.cpp src/Truck.h
        src/Node.cpp src/Node.h
        src/MutablePriorityQueue.h
        src/Container.h src/Container.cpp
        src/Station.cpp src/Station.h
        src/Loader.cpp src/Loader.h
        src/FullGraph.cpp src/FullGraph.h
        src/Utils.h
        src/connection.cpp src/connection.h
        src/edgetype.h
        src/graphviewer.cpp src/graphviewer.h
        src/GraphViewerController.jar)
