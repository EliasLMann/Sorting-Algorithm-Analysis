# Project 2 - Sorting Analysis
This program was made  by Elias Mann

In this project, I am comparing the execution time of 6 diffferent sorting algorithms: Selection Sort, Insertion Sort, Quick Sort, Heap Sort, Merge Sort, and Radix Sort.
These algorithms are tested on datasets that are: randomly sorted integers, reverse sorted integers, randomly sorted integers where 20% percent of the data is unique, and a 30% randomly sorted integers.
The algorithms are tested on datasets of all of the previously mentioned types, with dataset sizes of :10, 1000, 10000, 100000, and 1000000.
## Analysis Report
### Randomly Sorted Data
![Random_Data_Table](https://user-images.githubusercontent.com/70070619/111926156-b195ea00-8a79-11eb-8366-8caa244f7216.png)
![Rand_Data_Graph](https://user-images.githubusercontent.com/70070619/111926772-2e29c800-8a7c-11eb-9dcd-e9dc59c6b9d9.png)

The y-axis of the graph is in log scale.

As the dataset sizes increase the sorting time is much slower for insertion and selection sort than it is for the rest of the algorithms. This is becuase the time complexity for selection and insertion sort are O(n^2) while the other sorting algorithms have time complexities of O(nlog(n)). Interestingly, insertion sort has the fastest of all sorting times until the dataset size reaches about 750 elements. On the other hand, quick sort and radix sort and significantly slower than the other algorithms for small datasets. This is because radix sort and quick sort require complex function calls which are innefficient for small dataset sizes. Radix sort is the slowest algorithm for the dataset of size 10 but it is the fastest for the rest of the dataset sizes. Interestingly its sort time barely changes between size 10 and size 1000. This shows how its complexity does pay off in terms of speed as dataset sizes increase.

### Reverse Sorted Data
![Rev_Sort_Table](https://user-images.githubusercontent.com/70070619/111927755-d7be8880-8a7f-11eb-94a4-3ed6b64fb421.png)
![Rev_Sort_Graph](https://user-images.githubusercontent.com/70070619/111927760-dd1bd300-8a7f-11eb-8cd1-502219e11eeb.png)

The y-axis of the graph is in log scale.

A similar trend is evident in the reverse sorted dataset where as the dataset sizes increase, the sorting time is much slower for insertion and selection sort than for the rest of the algorithms. All of the algorithms have similar sort times for the dataset of size 10 except for selection sort which is slower. At the. largest dataset size, insertion is the slowest algorithm. This is because, since every element needs to be moved, reverse sorted order is the worst case for insertion sort. While it is faster than selection sort and insertion sort, heap sort is the slowest of the O(nlog(n)) algorithms by an increasingly large margin as dataset size. increases.

### Randomly Sorted With 20% Unique Elements
![Unique20_Table](https://user-images.githubusercontent.com/70070619/111928432-929b5600-8a81-11eb-89c0-381ab7e54eb8.png)
![Unique20_Graph](https://user-images.githubusercontent.com/70070619/111928439-962edd00-8a81-11eb-9479-178a98f0a101.png)

The y-axis of the graph is in log scale.


### 30% Randonly Sorted Data
![Rand30_Table](https://user-images.githubusercontent.com/70070619/111928603-1a816000-8a82-11eb-9c34-9263efdae908.png)
![Unique20_Graph](https://user-images.githubusercontent.com/70070619/111928613-22d99b00-8a82-11eb-8056-da2a3b8d7ad0.png)

The y-axis of the graph is in log scale.

The first 70% of the dataset is sorted and theremaining 30% o fthe data is randomly sorted.


