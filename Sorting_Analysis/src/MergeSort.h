//
// Created by Elias Mann on 3/20/21.
//
#include "AlgorithmStrategy.h"
#ifndef SORTING_ANALYSIS_MERGESORT_H
#define SORTING_ANALYSIS_MERGESORT_H


class MergeSort: public AlgorithmStrategy {
public:
    MergeSort():AlgorithmStrategy(){sortTitle = "MERGE SORT";}
    void Execute(int* dataSet,int size, string name);
private:
    void merge(int arr[], int l, int m, int r);
    void mergeSort(int arr[], int l, int r);
    void Sort(int* arr, int size);
};


#endif //SORTING_ANALYSIS_MERGESORT_H
