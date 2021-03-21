//
// Created by Elias Mann on 3/20/21.
//
// Code from https://www.geeksforgeeks.org/heap-sort/
#include "Swap.h"
#include "HeapSort.h"

void HeapSort::Execute(int* dataSet,int size, string name) {
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

// main function to do heap sort
void HeapSort::Sort(int *arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--){
        // Move current root to end
        Swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void HeapSort::heapify(int *arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i){
        Swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
