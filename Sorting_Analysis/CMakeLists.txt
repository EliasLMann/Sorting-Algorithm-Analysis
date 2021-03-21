cmake_minimum_required(VERSION 3.16)
project(Sorting_Analysis)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorting_Analysis main.cpp AlgorithmStrategy.cpp AlgorithmStrategy.h SelectionSort.cpp SelectionSort.h Swap.cpp Swap.h QuickSort.cpp QuickSort.h InsertionSort.cpp InsertionSort.h)