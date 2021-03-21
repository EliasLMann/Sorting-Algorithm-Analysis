//
// Created by Elias Mann on 3/20/21.
//

#ifndef SORTING_ANALYSIS_QUICKSORT_H
#define SORTING_ANALYSIS_QUICKSORT_H
#include "AlgorithmStrategy.h"

class QuickSort : public AlgorithmStrategy{
public:
    QuickSort():AlgorithmStrategy(){sortTitle = "QUICK SORT";}
    void Execute(int* dataSet,int size, string name);
private:
    void Sort(int* arr, int size);
    int partition(int arr[], int low, int high);
    void quickSort(int arr[], int low, int high);
};


#endif //SORTING_ANALYSIS_QUICKSORT_H
