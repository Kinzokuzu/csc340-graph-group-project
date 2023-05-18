cmake_minimum_required(VERSION 3.25)
project(csc340_graph_group_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(csc340_graph_group_project
        DesignDoc.h
        Graph.cpp
        Graph.h
        main.cpp
        UnitTest.h)
