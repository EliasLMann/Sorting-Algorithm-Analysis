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

            //declaring array of numbers with its correct size in heap
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

}
