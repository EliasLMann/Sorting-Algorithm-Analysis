//
// Created by Elias Mann on 3/20/21.
//

#ifndef SORTING_ANALYSIS_INSERTIONSORT_H
#define SORTING_ANALYSIS_INSERTIONSORT_H

#include "AlgorithmStrategy.h"
class InsertionSort: public AlgorithmStrategy{
public:
    void Execute();
private:
    void Sort(int *arr, int size);
};


#endif //SORTING_ANALYSIS_INSERTIONSORT_H
