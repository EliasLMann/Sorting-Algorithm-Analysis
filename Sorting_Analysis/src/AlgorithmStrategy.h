//
// Created by Elias Mann on 3/19/21.
//

#ifndef SORTING_ANALYSIS_ALGORITHMSTRATEGY_H
#define SORTING_ANALYSIS_ALGORITHMSTRATEGY_H

#include <filesystem>
#include <utility>
#include <vector>
#include <map>

using namespace std;
namespace tmr = std::chrono;

//struct that stores information about datasets
struct DSPack{
    DSPack(): data(nullptr), size(0){}

    DSPack(string inName, int inSize, int* inData):
        name(inName),size(inSize), data(inData){}

    ~DSPack(){}

    string name;
    int size;
    int* data;
};

class AlgorithmStrategy {
public:
    AlgorithmStrategy();
    ~AlgorithmStrategy();
    void Load(string path);
    void ExecuteAll();
    virtual void Execute(int* dataSet,int size, string name) = 0;
    void Stats();
    void Handoff(AlgorithmStrategy* nextAlgo, int dataSize);
protected:
    string sortTitle;
    map<string, const float> mSortTimes;
    vector<DSPack> mDatasets;
};

#endif //SORTING_ANALYSIS_ALGORITHMSTRATEGY_H
