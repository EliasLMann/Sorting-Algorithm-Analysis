//
// Created by Elias Mann on 3/20/21.
//

#ifndef SORTING_ANALYSIS_SELECTIONSORT_H
#define SORTING_ANALYSIS_SELECTIONSORT_H
#include "AlgorithmStrategy.h"

class SelectionSort: public AlgorithmStrategy {
public:
    SelectionSort():AlgorithmStrategy(){sortTitle = "SELECTION SORT";}
    void Execute(int* dataSet,int size, string name);
private:
    void Sort(int* arr, int size);
};


#endif //SORTING_ANALYSIS_SELECTIONSORT_H
