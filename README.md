# Project 2 - Sorting Analysis
This program was made  by Elias Mann

In this project, I am comparing the execution time of 6 diffferent sorting algorithms: Selection Sort, Insertion Sort, Quick Sort, Heap Sort, Merge Sort, and Radix Sort.
These algorithms are tested on datasets that are: randomly sorted integers, reverse sorted integers, randomly sorted integers where 20% percent of the data is unique, and a 30% randomly sorted integers.
The algorithms are tested on datasets of all of the previously mentioned types, with dataset sizes of :10, 1000, 10000, 100000, and 1000000.
I am also tesing a Handoff function where the beginning of the datasets are sorted using quick sort, then the last 50 elements are sorted using insertion sort. This is tested for all dataset types with sizes: 1000, 10000, 100000, and 1000000.
This algorithm is compared to a standard quick sort algorithm.


## Analysis Report
### Randomly Sorted Data
![Random_Data_Table](https://user-images.githubusercontent.com/70070619/111926156-b195ea00-8a79-11eb-8366-8caa244f7216.png)
![Rand_Data_Graph](https://user-images.githubusercontent.com/70070619/111926772-2e29c800-8a7c-11eb-9dcd-e9dc59c6b9d9.png)

The y-axis of the graph is in log scale.

As the dataset sizes increase the sorting time is much slower for insertion and selection sort than it is for the rest of the algorithms. This is becuase the time complexity for selection and insertion sort are O(n^2) while the other sorting algorithms have time complexities of O(nlog(n)). Interestingly, insertion sort has the fastest of all sorting times until the dataset size reaches about 750 elements. On the other hand, quick sort and radix sort are significantly slower than the other algorithms for small datasets. This is because radix sort and quick sort require complex function calls which are inefficient for small dataset sizes. Radix sort is the slowest algorithm for the dataset of size 10 but it is the fastest for the rest of the dataset sizes. Interestingly its sort time barely changes between size 10 and size 1000. This shows how its complexity does pay off in terms of speed as dataset sizes increase.

### Reverse Sorted Data
![Rev_Sort_Table](https://user-images.githubusercontent.com/70070619/111927755-d7be8880-8a7f-11eb-94a4-3ed6b64fb421.png)
![Rev_Sort_Graph](https://user-images.githubusercontent.com/70070619/111927760-dd1bd300-8a7f-11eb-8cd1-502219e11eeb.png)

The y-axis of the graph is in log scale.

A similar trend is evident in the reverse sorted dataset where as the dataset sizes increase, the sorting time is much slower for insertion and selection sort than for the rest of the algorithms. All of the algorithms have similar sort times for the dataset of size 10 except for selection sort which is slower. At the largest dataset size, insertion is the slowest algorithm. This is because, since every element needs to be moved, reverse sorted order is the worst case for insertion sort. While it is faster than selection sort and insertion sort, heap sort is the slowest of the O(nlog(n)) algorithms by an increasingly large margin as dataset size. increases.

### Randomly Sorted With 20% Unique Elements
![Unique20_Table](https://user-images.githubusercontent.com/70070619/111928432-929b5600-8a81-11eb-89c0-381ab7e54eb8.png)
![Unique20_Graph](https://user-images.githubusercontent.com/70070619/111928439-962edd00-8a81-11eb-9479-178a98f0a101.png)

The y-axis of the graph is in log scale.

This data looks very similar to the data for the fully random datasets, except radix and quick sort are not significantly slower for the smallest dataset. The smaller amount of unique data requires less function calling and overhead so these fucntions are still practical for small datasets. Nevertheless, the selection sort and insertion sort still had the fastest sort time for the smallest dataset due to their simplicity. Otherwise we see a similar trend as in the other datasets where the O(nlog(n)) algorithms are significantly faster than selection sort and insertions sort as dataset size increases.

### 30% Randomly Sorted Data
![Rand30_Table](https://user-images.githubusercontent.com/70070619/111928603-1a816000-8a82-11eb-9c34-9263efdae908.png)
![Unique20_Graph](https://user-images.githubusercontent.com/70070619/111928613-22d99b00-8a82-11eb-8056-da2a3b8d7ad0.png)

The y-axis of the graph is in log scale.

The first 70% of the dataset is sorted and the remaining 30% of the data is randomly sorted. In this dataset, insertion sort deviates from the trends seen in the previous datasets. Insertion sort is the fastest sorting algorithm for the dataset size of 1000 and is in the ballpark of sort times with the O(nlog(n)) algorithms for the dataset size of 10000 for the first time. While insertion sort has had very similar sorting times to selection sort in all of the other dataset types, it is significantly faster than selection sort in this dataset type. This is because insertion sort is at its best case sorting time complexity for sorted data which is O(n). Selection sort always has a sorting time complexiy of O(n^2). The other algorithms follow the same trend as in previous datasets for sorting time as dataset size increases.

### Handoff

For the handoff algorithm, the first portion of the dataset is sorted using quick sort. Then last 50 elements are appended to the sorted array and then insertion sort is called on the entire array. Insertion sort was chosen because it is at its best case sorting time for the already sorted portion of the array while selection sort is a constant sort time complexity of O(n^2).

The following data represents a quick sort algorithm where the final 50 elements are sorted using insertion sort compared to a standard quick sort algorithm:

#### Random
![Handoff_Rand_Graph](https://user-images.githubusercontent.com/70070619/111929770-57028b00-8a85-11eb-9d51-11be02b2f7cd.png)
![Handoff_Rand_Table](https://user-images.githubusercontent.com/70070619/111929780-5cf86c00-8a85-11eb-8352-33134d037deb.png)

The sorting time is always quicker for the handoff algorithm. As the dataset size increases, the difference betweeen the two algorithms also increases at a significant rate. It seems that the difference would be less significant as the dataset size increases because the portion that is handed off is proportionally smaller. This is not the case because of quick sort's recursive, divide and conquer nature. The greater the dataset size, the more the last 50 elements effect its speed because of increasing layers of recursive function calling. As we previously observed, insertion sort is the fastest algorithm for sorting small datasets.

#### Reverse Sorted
![Handoff_Rev_Graph](https://user-images.githubusercontent.com/70070619/111929846-84e7cf80-8a85-11eb-9fb9-7694ab67efc7.png)
![Handoff_Rev_Table](https://user-images.githubusercontent.com/70070619/111929865-8e713780-8a85-11eb-9393-dbed6fe7431a.png)

While the handoff algorithm is still always faster than the quick sort algorithm, the difference is much less significant. This is because reverse sorted order is the worst case time complexity for insertion sort. Quick sort also had its fistes sort times for the reverse sorted dataset. Nevertheless, the recursive nature of quick sort still causes the difference between the sorting times to increase as dataset size increasees.

#### Randomly Sorted With 20% Unique Elements
![Handoff_20_Graph](https://user-images.githubusercontent.com/70070619/111929882-9df08080-8a85-11eb-8b29-56c3f220c6f0.png)
![Handoff_20_Table](https://user-images.githubusercontent.com/70070619/111929878-992bcc80-8a85-11eb-8e7b-1a4dcfa74045.png)

In this dataset, the data is randomly sorted with 20% unique values.

Although it is not by much, the most significant difference between the two algorithms is with this dataset. The sort times for quick sort in the dataset are not much different than the fully random dataset. The sort times for the handoff function are slightly faster for this dataset than for the fully random dataset. This is mosy likely due to the slight decrease in recursive overhead required from quick sort.

#### 30% Randomly Sorted Data	
![Handoff_30_Graph](https://user-images.githubusercontent.com/70070619/111929895-a9dc4280-8a85-11eb-89c1-33efa53ba631.png)
![Handoff_30_Table](https://user-images.githubusercontent.com/70070619/111929898-ac3e9c80-8a85-11eb-8b6f-cbf697c1c653.png)

In this dataset the first 70% of the dataset is sorted in order and the remaining 30% of the data is randomly sorted.

Insertion sort performed the best for this type of dataset in our previous analysis. Regardless, the handoff algorithm performed similarly to previous tests. This is because the entire dataset passed over to insertion sort is random for the dataset sizes tested. The gap between handoff and quick sort was less than in the random and 20% unique datasets becuase quick sort performed faster than it did for those datsets.
