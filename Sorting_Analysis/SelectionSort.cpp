//
// Created by Elias Mann on 3/20/21.
//

#include "SelectionSort.h"
#include "Swap.h"


void SelectionSort::Execute() {
    //sorting and saving the time elapsed for every dataset (except those with size of 1,000,000 to a vector)
    for(int i = 0; mDatasets.size() ; i++){
        if(mDatasets.at(i).size < 1000000){
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
}

void SelectionSort::Sort(int *arr, int size) {
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        Swap(&arr[min_idx], &arr[i]);
    }
}
