
#include "population.h"

Population::Population(int populationSize, bool initialize){
    
    // Initialise population
    if (initialize) {
        // Loop and create individuals
        for (int i = 0; i < populationSize; i++) {
            Individual newIndividual;
            newIndividual.generateIndividual();
            saveIndividual(newIndividual);
        }
    }
    else {
        individuals.clear();
        for (int i = 0; i < populationSize; i++) {
            Individual newIndividual;
            newIndividual.generateIndividual();
            saveIndividual(newIndividual);
        }
    }
}

void Population::saveIndividual(Individual indiv) {
    
    individuals.push_back(indiv);
}

//for a specific location, used for sorting
void Population::saveIndividual(int i, Individual indiv) {
    
    individuals.at(i) = indiv;
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

Individual Population::getFittest() {
    Individual fittest = individuals.at(0);
    // Loop through individuals to find fittest
    for (int i = 0; i < individuals.size(); i++) {
        if (fittest.getFitness() <= getIndividual(i).getFitness()) {
            fittest = getIndividual(i);
        }
    }
    return fittest;
}
