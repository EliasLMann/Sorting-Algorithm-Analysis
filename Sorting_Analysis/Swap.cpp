//
// Created by Elias Mann on 3/20/21.
//

#include "Swap.h"
// A utility function to swap two elements
void Swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}