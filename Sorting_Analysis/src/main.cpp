#include <iostream>
#include "SelectionSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "RadixSort.h"

//global const for the direct path to the Datasets
const string DATASET_PATH = "/Users/eliasmann/Desktop/Algorithms/21s-pa02-EliasLMann/Sorting_Analysis/Datasets";


int main() {
    //creating pointers to each sorting object allocated in the heap
    SelectionSort selection;
    InsertionSort insertion;
    HeapSort heap;
    QuickSort quick;
    RadixSort radix;
    MergeSort merge;

    //adding all sorting algorithm pointers to an array
    AlgorithmStrategy* sortingAlgos[6];
    sortingAlgos[0] = &selection;
    sortingAlgos[1] = &insertion;
    sortingAlgos[2] = &heap;
    sortingAlgos[3] = &quick;
    sortingAlgos[4] = &radix;
    sortingAlgos[5] = &merge;

    //executes all algorithms
    for(int i = 0; i < 6; i++){
        sortingAlgos[i]->Load(DATASET_PATH);
        sortingAlgos[i]->ExecuteAll();
        sortingAlgos[i]->Stats();
    }

    //running handoff
    quick.Handoff(&insertion,50);

    return 0;
}
