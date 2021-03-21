//
// Created by Elias Mann on 3/20/21.
//

#ifndef SORTING_ANALYSIS_HEAPSORT_H
#define SORTING_ANALYSIS_HEAPSORT_H
#include "AlgorithmStrategy.h"

class HeapSort: public AlgorithmStrategy {
public:
    HeapSort():AlgorithmStrategy(){sortTitle = "HEAP SORT: ";}
    void Execute(int* dataSet,int size, string name);
private:
    void Sort(int *arr, int n);
    void heapify(int *arr, int n, int i);
};


#endif //SORTING_ANALYSIS_HEAPSORT_H
