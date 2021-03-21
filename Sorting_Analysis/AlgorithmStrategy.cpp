//
// Created by Elias Mann on 3/19/21.
//

#include "AlgorithmStrategy.h"
#include <filesystem>
#include <iostream>
#include <fstream>
namespace fs = std::filesystem;

AlgorithmStrategy::AlgorithmStrategy(){}

AlgorithmStrategy::~AlgorithmStrategy() {
    for(int i  = 0; i < mDatasets.size(); i++){
        delete[] mDatasets.at(i).data;
    }
    mDatasets.clear();
}


void AlgorithmStrategy::Load(string path) {
    //iterating through my directory of dataset csv's
    for (fs::directory_iterator iter(path), end; iter !=end; ++iter){
        string fileName = iter->path().c_str();
        ifstream currDataset;
        currDataset.open(fileName);

        if(currDataset.is_open()){
            //extracting name and dataset size
            string currName;
            string setSizeStr;
            getline(currDataset, currName,',');
            getline(currDataset, setSizeStr,',');
            int dSetSize = stoi(setSizeStr);

            //declaring array of Integers with its correct size in heap
            int* data = new int[dSetSize];

            //adding each number from file to array
            for(int i = 0; !currDataset.eof() && i < dSetSize; i++) {
                string numStr;
                getline(currDataset, numStr,',');
                int currNum = stoi(numStr);
                data[i] = currNum;
            }
            //creating a dataset info pack for current dataset and adding to vector
            DSPack currData(currName, dSetSize, data);
            mDatasets.push_back(currData);
        }else{
            cout << "ERROR: FILE: "<< fileName << " NOT FOUND" << endl;
        }
    }
}

void AlgorithmStrategy::Stats() {
    map<string, const float>::iterator sortTimeIter;

    //printing title of given sorting algorithm
    cout << sortTitle <<endl << endl;

    //printing all sizes of randomly sorted elements
    cout << "Randomly Sorted Integers:" <<endl;
    sortTimeIter = mSortTimes.find("10Rand");
    cout << "10 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000Rand");
    cout << "1,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("10000Rand");
    cout << "10,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("100000Rand");
    cout << "100,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000000Rand");
    //only prints the 1,000,000 element sort time if it was executed for the given  algorithm
    if(sortTimeIter != mSortTimes.end()){
        cout << "1,000,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    }

    //printing all sizes of reverse sorted elements
    cout << endl << "Reverse Sorted Integers: " << endl;
    sortTimeIter = mSortTimes.find("10RevSorted");
    cout << "10 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000RevSorted");
    cout << "1,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("10000RevSorted");
    cout << "10,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("100000RevSorted");
    cout << "100,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000000RevSorted");
    //only prints the 1,000,000 element sort time if it was executed for the given  algorithm
    if(sortTimeIter != mSortTimes.end()){
        cout << "1,000,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    }

    //printing all sizes of randomly sorted elements where 20% of the elements are unique
    cout << endl << "Randomly Sorted Where Only 20% Of Integers are Unique: " << endl;
    sortTimeIter = mSortTimes.find("10Unique20");
    cout << "10 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000Unique20");
    cout << "1,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("10000Unique20");
    cout << "10,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("100000Unique20");
    cout << "100,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000000Unique20");
    //only prints the 1,000,000 element sort time if it was executed for the given  algorithm
    if(sortTimeIter != mSortTimes.end()){
        cout << "1,000,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    }

    //printing all sizes of datasets with 30% random and 70% sorted Integers
    cout << endl << "70% Sorted and 30% Randomized Integers: " << endl;
    sortTimeIter = mSortTimes.find("10Sort30");
    cout << "10 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000Sort30");
    cout << "1,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("10000Sort30");
    cout << "10,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("100000Sort30");
    cout << "100,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    sortTimeIter = mSortTimes.find("1000000Sort30");
    //only prints the 1,000,000 element sort time if it was executed for the given  algorithm
    if(sortTimeIter != mSortTimes.end()){
        cout << "1,000,000 Integers: " << sortTimeIter->second << " seconds" << endl;
    }
    cout << endl;
}

void AlgorithmStrategy::ExecuteAll() {
    //calls execute of every dataset
    for(int i = 0; i < mDatasets.size() ; i++){
        Execute(mDatasets.at(i).data,mDatasets.at(i).size,mDatasets.at(i).name);
    }
}

void AlgorithmStrategy::Handoff(AlgorithmStrategy *nextAlgo, int dataSize) {
    for(int i; i <mDatasets.size(); i++){
        if(mDatasets.at(i).size == 1000){
            int first[1000-dataSize];
            int second[dataSize];

        }
    }
}

