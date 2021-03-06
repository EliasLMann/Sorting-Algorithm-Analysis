//
// Created by Elias Mann on 3/20/21.
//
// Code from https://www.geeksforgeeks.org/insertion-sort/
// C++ program for insertion sort
#include "InsertionSort.h"

void InsertionSort::Execute(int* dataSet,int size, string name) {
    if(size < 1000000){
        //saving the time before sorting occurs
        tmr::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        Sort(dataSet, size);
        //saving  time after sorting occurs
        tmr::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        //subtracting start time from end time to find the time elapsed
        tmr::duration<float> timeElapsed = tmr::duration_cast<tmr::duration<float>>(stop-start);
        //add the name of the given dataset and the time taken to sort to a vector
        mSortTimes.emplace(name, timeElapsed.count());
    }
}

/* Function to sort an array using insertion sort*/
void InsertionSort::Sort(int *arr, int size) {
    int i, key, j;

    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// This is code is contributed by rathbhupendra