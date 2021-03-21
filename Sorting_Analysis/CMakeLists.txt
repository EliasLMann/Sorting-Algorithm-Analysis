cmake_minimum_required(VERSION 3.16)
project(Sorting_Analysis)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra")
set(CMAKE_CXX_FLAG_RELEASE "03")

set(CMAKE_CXX_STANDARD 17)
add_executable(Sorting_Analysis src/main.cpp src/AlgorithmStrategy.cpp src/AlgorithmStrategy.h src/SelectionSort.cpp src/SelectionSort.h src/Swap.cpp src/Swap.h src/QuickSort.cpp src/QuickSort.h src/InsertionSort.cpp src/InsertionSort.h src/HeapSort.cpp src/HeapSort.h src/MergeSort.cpp src/MergeSort.h src/RadixSort.cpp src/RadixSort.h)