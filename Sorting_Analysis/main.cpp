#include <iostream>
#include "SelectionSort.h"
#include "QuickSort.h"


const string DATASET_PATH = "/Users/eliasmann/Desktop/Algorithms/21s-pa02-EliasLMann/Sorting_Analysis/Datasets";

int main() {
    QuickSort test;
    test.Load(DATASET_PATH);
    test.Execute();
    return 0;
}
