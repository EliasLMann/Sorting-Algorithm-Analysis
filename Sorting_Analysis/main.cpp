#include <iostream>
#include "SelectionSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"

const string DATASET_PATH = "/Users/eliasmann/Desktop/Algorithms/21s-pa02-EliasLMann/Sorting_Analysis/Datasets";

int main() {
    HeapSort test;
    test.Load(DATASET_PATH);
    test.Execute();
    return 0;
}
