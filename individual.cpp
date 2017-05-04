#include "individual.h"
#include "fitnessCalc.h"

Individual::Individual() {}

int Individual::defaultGeneLength = 64;

void Individual::generateIndividual() {
    
    srand(time(NULL));
    
    for (int i = 0; i < genes.size(); i++) {
        if (rand() % 2 == 0) {
            genes[i] = '0';
        }
        else {
            genes[i] = '1';
        }
    }
}

void Individual::setGene(int index, char value) {
    
    genes[index] = value;
    fitness = 0;
}

char Individual::getGene(int index) {
    
    return genes[index];
}

int Individual::getSize() {
    
    return genes.length();
}

int Individual::getFitness() {
    
    if (fitness == 0) {
        fitness = fitnessCalc::getFitness(this);
    }
    
    return fitness;
}

void Individual::setDefaultGeneLength(int length) {
    defaultGeneLength = length;
}
