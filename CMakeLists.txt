cmake_minimum_required(VERSION 3.26)
project(3term_Alg_laba1)

set(CMAKE_CXX_STANDARD 17)

add_executable(3term_Alg_laba1 main.cpp
        fun.cpp
        fun.h
        FloydWarshall.cpp
        FloydWarshall.h
        Dijkkstra.cpp
        Dijkkstra.h
        BellmanFord.cpp
        BellmanFord.h
        alg_Kruskala.cpp
        Prima.cpp
        Prima.h)
