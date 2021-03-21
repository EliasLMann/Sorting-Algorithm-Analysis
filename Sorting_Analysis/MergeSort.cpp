//
// Created by Elias Mann on 3/20/21.
//
// Found at https://www.geeksforgeeks.org/merge-sort/
// C++ program for Merge Sort

#include "MergeSort.h"

void MergeSort::Execute(int* dataSet,int size, string name) {
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


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void MergeSort::merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temp arrays back into arr[l..r]
    // Initial index of first subarray
    int i = 0;
    // Initial index of second subarray
    int j = 0;
    // Initial index of merged subarray
    int k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void MergeSort::mergeSort(int *arr, int l, int r) {
    if (l < r){

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Driver code
void MergeSort::Sort(int *arr, int size) {
    mergeSort(arr, 0, size - 1);
}
