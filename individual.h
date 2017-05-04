#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

class Individual {
public:
    Individual();
    void generateIndividual();
    void setGene(int index, char value);
    char getGene(int index);
    int getSize();
    int getFitness();
    static void setDefaultGeneLength(int length);
private:
    string genes;
    int fitness = 0;
    static int defaultGeneLength;
};
#endif
