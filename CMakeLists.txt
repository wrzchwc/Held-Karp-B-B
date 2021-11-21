cmake_minimum_required(VERSION 3.19)
project(2)

set(CMAKE_CXX_STANDARD 20)

add_executable(2 src/main.cpp src/adjacency_matrix/AdjacencyMatrix.h src/adjacency_matrix/AdjacencyMatrix.cpp
        src/held_karp/HeldKarp.cpp src/held_karp/HeldKarp.h src/utility/Utility.h src/utility/Utility.cpp
        src/branch_bound/Node.cpp src/branch_bound/Node.h src/branch_bound/SpaceStateTree.cpp
        src/branch_bound/SpaceStateTree.h src/branch_bound/BranchBound.cpp src/branch_bound/BranchBound.h)

