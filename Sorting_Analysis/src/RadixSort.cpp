//
// Created by Elias Mann on 3/20/21.
//
//Code from: https://www.geeksforgeeks.org/radix-sort/

#include "RadixSort.h"
void RadixSort::Execute(int* dataSet,int size, string name) {
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

int RadixSort::getMax(int *arr, int n) {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
}

void RadixSort::countSort(int *arr, int n, int exp) {
    int output[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort::Sort(int *arr, int n) {
        // Find the maximum number to know number of digits
        int m = getMax(arr, n);

        // Do counting sort for every digit. Note that instead
        // of passing digit number, exp is passed. exp is 10^i
        // where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, n, exp);
}