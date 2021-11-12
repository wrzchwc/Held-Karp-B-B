cmake_minimum_required(VERSION 3.20)
project(2)

set(CMAKE_CXX_STANDARD 23)

add_executable(2 main.cpp adjacency_matrix/AdjacencyMatrix.h adjacency_matrix/AdjacencyMatrix.cpp
        held_karp/HeldKarp.cpp held_karp/HeldKarp.h utility/Utility.h utility/Utility.cpp branch_bound/Node.cpp branch_bound/Node.h)
