//
// Created by Elias Mann on 3/19/21.
//

#ifndef SORTING_ANALYSIS_ALGORITHMSTRATEGY_H
#define SORTING_ANALYSIS_ALGORITHMSTRATEGY_H

#include <filesystem>
#include <utility>
#include <vector>

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
    virtual void Execute() = 0;
    void Stats();
protected:
    vector<pair<string, const float>> mSortTimes;
    vector<DSPack> mDatasets;
};

#endif //SORTING_ANALYSIS_ALGORITHMSTRATEGY_H
