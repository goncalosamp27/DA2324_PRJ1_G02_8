cmake_minimum_required(VERSION 3.27)
project(DA2324_PRJ1_G02_8)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA2324_PRJ1_G02_8 main.cpp
        City.h
        City.cpp
        Pipes.h
        Reservoir.h
        Reservoir.cpp
        Stations.h
        Stations.cpp
        Pipes.cpp
        DataStructures/Graph.h
        DataStructures/MutablePriorityQueue.h)
