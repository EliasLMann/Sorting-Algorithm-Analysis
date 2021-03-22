#Created by Elias Mann
#03/19/2021

import random

def create_dataset(size):
    sizeList = list()
    percent20List = list()
    file_base = "/Users/eliasmann/Desktop/Algorithms/21s-pa02-EliasLMann/Sorting_Analysis/Datasets/" + str(size)

    #creating  list of unique values that is 20% of the dataset size
    for x in range(int(size * .2)):
        percent20List.append(x)

    #creating list of unique values that is the size of the dataset
    for x in range(size):
        sizeList.append(x);

    #creating a csv file with 70% of the size sorted and 30% percent randomized
    rand_30= open(file_base + "Sort30.csv", "w")

    #writing filename and size of file
    rand_30.write(str(size)+ "Sort30"+",");
    rand_30.write(str(size)+",");

    for x in range(int(size * .7)):
        rand_30.write(str(x)+",")
    for y in range(int(size * .3)):
        rand_30.write(str(random.randint(0,(size * 10)))+",")
    rand_30.close

    #reversing thelist of unique values and printing to a csv file
    sizeList.reverse()
    rev_sorted = open(file_base + "RevSorted.csv", "w")

    #writing filename and size of file
    rev_sorted.write(str(size)+ "RevSorted"+",");
    rev_sorted.write(str(size)+",");

    for x in sizeList:
        rev_sorted.write(str(x)+",")
    rev_sorted.close()

    #creating a csv file of random numbers of the given dataset size
    rand = open(file_base + "Rand.csv", "w")

    #writing filename and size of file
    rand.write(str(size)+ "Rand"+",");
    rand.write(str(size)+",");

    for x in range(size):
        rand.write(str(random.randint(0,(size * 10)))+",")
    rand.close()

    #creating a csv file with random numbers of the given dataset size from a list of unique numbers that is 
    #20% the size of the dataset
    percent_20 = open(file_base + "Unique20.csv", "w")

    #writing filename and size of file
    percent_20.write(str(size)+ "Unique20"+",");
    percent_20.write(str(size)+",");

    for x in range(5):
        random.shuffle(percent20List)
        for element in percent20List:
            percent_20.write(str(element)+",")
    percent_20.close()

#calling function for all dataset sizes
create_dataset(10)
create_dataset(1000)
create_dataset(10000)
create_dataset(100000)
create_dataset(1000000)