#include <iostream>
#include "SelectionSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "RadixSort.h"

const string DATASET_PATH = "/Users/eliasmann/Desktop/Algorithms/21s-pa02-EliasLMann/Sorting_Analysis/Datasets";

int main() {
    RadixSort test;
    test.Load(DATASET_PATH);
    test.Execute();
    test.Stats();
    return 0;
}
