#include "population.h"

Population::Population(int populationSize, bool initialize){
    
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

void Population::saveIndividual(int index, Individual indiv){
                                
    individuals.at(index) = indiv;
}

Individual Population::getIndividual(int index){
    
    return individuals.at(index);
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
