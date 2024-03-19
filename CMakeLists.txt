cmake_minimum_required(VERSION 3.27)
project(DA2324_PRJ1_G02_8)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA2324_PRJ1_G02_8 main.cpp
        src/h/City.h
        src/cpp/City.cpp
        src/h/Pipes.h
        src/h/Reservoir.h
        src/cpp/Reservoir.cpp
        src/h/Stations.h
        src/cpp/Station.cpp
        src/cpp/Pipes.cpp
        DataStructures/Graph.h
        DataStructures/MutablePriorityQueue.h
        src/h/parser.h
        src/cpp/parser.cpp
        src/h/WManager.h
        src/cpp/WManager.cpp
        src/h/Menu.h
        src/cpp/Menu.cpp)
