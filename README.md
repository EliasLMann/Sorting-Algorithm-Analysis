# Project 2 - Sorting Analysis
This program was made  by Elias Mann

In this project, I am comparing the execution time of 6 diffferent sorting algorithms: Selection Sort, Insertion Sort, QUick Sort, Heap Sort, Merge Sort, and Radix Sort.
These algorithms are tested on datasets that are: randomly sorted integers, reverse sorted integers, randomly sorted integers where 20% percent of the data is unique, and a 30% randomly sorted integers.
The algorithms are tested on datasets of all of the previously mentioned types, with dataset sizes of :10, 1000, 10000, 100000, and 1000000.
## Analysis Report
### Randomly Sorted Data
![Random_Data_Table](https://user-images.githubusercontent.com/70070619/111926156-b195ea00-8a79-11eb-8366-8caa244f7216.png)
![Rand_Data_Graph](https://user-images.githubusercontent.com/70070619/111926772-2e29c800-8a7c-11eb-9dcd-e9dc59c6b9d9.png)

he y-axis of the graph is in log scale and 1,000,000.
As the dataset sizes increase there is the sorting time is much slower for insertion and selection sort than it is for the rest of the algorithms. This is becuase the time complexity for selection and insertion sort are O(n^2) while the other sorting algorithms have time complexities of O(nlog(n)). Interestingly, insertion sort has the fastest of all sorting times until the dataset size reaches about 750 elements. On the other hand, quick sort and radix sort and significantly slower than the other algorithms for small datasets. This is because radix sort and quick sort require complex function calls which are innefficient for small dataset sizes. Radix sort is the slowest algorithm for the dataset of size 10 but it is the fastest for the rest of the dataset sizes. Interestingly its sort time barely changes between size 10 and size 1000. This shows how its complexity does pay off in terms of speed as dataset sizes increase.

