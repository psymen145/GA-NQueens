#ifndef population_h
#define population_h

#include "individual.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Population{
public:
    Population(int populationSize, bool initialize);
    void saveIndividual(int index, Individual indiv);
    Individual getIndividual(int index);
    Individual getFittest();
private:
    vector<Individual> individuals;
};

#endif

