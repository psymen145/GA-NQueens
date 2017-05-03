#ifndef fitnessCalc_h
#define fitnessCalc_h

#include "individual.h"
#include <vector>

using namespace std;

class Individual;

class fitnessCalc{
public:
    static int getFitness(Individual individual);
    static void setSolution(vector<int8_t> newSolution);
    static int getMaxFitness();
    void setSolution(string newSolution);
private:
    static vector<int8_t> solution;
};

#endif



