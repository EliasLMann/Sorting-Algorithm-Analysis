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
    //a vector of all sorting algorithms

    //creating pointers to each sorting object allocated in the heap
    SelectionSort* selection = new SelectionSort;
    InsertionSort* insertion = new InsertionSort;
    HeapSort* heap = new HeapSort;
    QuickSort* quick = new QuickSort;
    RadixSort* radix = new RadixSort;
    MergeSort* merge = new MergeSort;

    //adding all sorting algorithm pointers to an array
    AlgorithmStrategy* sortingAlgos[6];
    sortingAlgos[0] = selection;
    sortingAlgos[1] = insertion;
    sortingAlgos[2] = heap;
    sortingAlgos[3] = quick;
    sortingAlgos[4] = radix;
    sortingAlgos[5] = merge;

    //executes all algorithms
    for(int i = 0; i < 6; i++){
        sortingAlgos[i]->Load(DATASET_PATH);
        sortingAlgos[i]->ExecuteAll();
        sortingAlgos[i]->Stats();
    }

    quick->Handoff(insertion,50);

    return 0;
}
