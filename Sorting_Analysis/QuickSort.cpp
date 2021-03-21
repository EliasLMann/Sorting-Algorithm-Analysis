//
// Created by Elias Mann on 3/20/21.
//
//
// Code taken from https://www.geeksforgeeks.org/cpp-program-for-quicksort/
#include "QuickSort.h"
#include "Swap.h"
#include <cstdlib>

void QuickSort::Execute() {
    //sorting and saving the time elapsed for every dataset
    for(int i = 0; i < mDatasets.size() ; i++){
        //saving the time before sorting occurs
        tmr::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        Sort(mDatasets.at(i).data, mDatasets.at(i).size);
        //saving  time after sorting occurs
        tmr::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
        //subtracting start time from end time to find thee time elapsed
        tmr::duration<float> timeElapsed = tmr::duration_cast<tmr::duration<float>>(stop-start);
        //add the name of the given dataset and the time taken to sort to a vector
        mSortTimes.push_back(make_pair(mDatasets.at(i).name, timeElapsed.count()));
    }
}

//calls quicksort function setting low and high
void QuickSort::Sort(int *arr, int size) {
    quickSort(arr, 0, size - 1);
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int QuickSort::partition(int *arr, int low, int high) {
        //chooses random index for pivot
        int pivotIndex;
        pivotIndex = rand() % (high - low) + low;
        int pivot = arr[pivotIndex];    // pivot
        int i = (low - 1);  // Index of smaller element
        for (int j = low; j <= high - 1; j++){
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                Swap(&arr[i], &arr[j]);
            }
        }
        Swap(&arr[i + 1], &arr[high]);
        return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void QuickSort::quickSort(int *arr, int low, int high) {
    if (low < high){
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
