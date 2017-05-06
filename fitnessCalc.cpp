
#include "fitnessCalc.h"
#include <string>

string fitnessCalc::solution = "";

void fitnessCalc::setSolution(string newSolution) {
    
    solution = newSolution;
}

int fitnessCalc::getFitness(Individual individual) {
    
    int fitness = 0;
    
    for (int i = 0; i < individual.getSize() && i < solution.size(); i++) {
        if (individual.getGene(i) == solution.at(i)) {
            fitness++;
        }
    }
    return fitness;
}


int fitnessCalc::getMaxFitness() {
    
    int maxFitness = solution.size();
    return maxFitness;
}
