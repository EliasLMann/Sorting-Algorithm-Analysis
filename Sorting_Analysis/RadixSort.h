//
// Created by Elias Mann on 3/20/21.
//

#ifndef SORTING_ANALYSIS_RADIXSORT_H
#define SORTING_ANALYSIS_RADIXSORT_H
#include "AlgorithmStrategy.h"

class RadixSort: public AlgorithmStrategy {
public:
    RadixSort():AlgorithmStrategy(){sortTitle = "RADIX SORT";}
    void Execute(int* dataSet,int size, string name);
private:
    int getMax(int arr[], int n);
    void countSort(int arr[], int n, int exp);
    void Sort(int arr[], int n);
};


#endif //SORTING_ANALYSIS_RADIXSORT_H
