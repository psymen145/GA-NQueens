#include "population.h"

Population::Population(int populationSize, bool initialize) {
    
    // Initialise population
    if (initialize) {
        // Loop and create individuals
        for (int i = 0; i < populationSize; i++) {
            Individual newIndividual;
            newIndividual.generateIndividual();
            saveIndividual(i, newIndividual);
        }
    }
}

void Population::saveIndividual(int index, Individual indiv) {
    
    individuals.at(index) = indiv;
}

Individual Population::getIndividual(int index) {
    
    return individuals.at(index);
}

int Population::getTotalFitness() {
    
    int total = 0;
    
    // Loop through individuals to sum fitness
    for (int i = 0; i < individuals.size(); i++) {
        total += individuals.at(i).getFitness();
    }
    return total;
}

int Population::getSize() {
    
    return individuals.size();
}
