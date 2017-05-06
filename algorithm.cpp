
#include <stdio.h>
#include "algorithm.h"
#include <string>
#include <map>

//const double Algorithm::uniformRate = 0.5;
const double Algorithm::mutationRate = 0.01;

// Evolve a population
Population Algorithm::evolvePopulation(Population pop) {
    Population newPopulation(pop.getSize(), false);
    
    //sort the population
    sortPopulation(pop);
    
    // Loop over the population size and create new individuals with crossover
    for (int i = 0; i < pop.getSize(); i++) {
        Individual indiv1 = selection(pop);
        //cout << indiv1.getEntireGene() << "   ";
        Individual indiv2 = selection(pop);
        //cout << indiv2.getEntireGene() << "  ";
        Individual newIndiv = crossover(indiv1, indiv2);
        //cout << newIndiv.getEntireGene() << endl;
        newPopulation.saveIndividual(i, newIndiv);
    }
    
    // Mutate population
    for (int i = 0; i < newPopulation.getSize(); i++) {
        Individual mutatedIndiv;
        mutatedIndiv = mutate(newPopulation.getIndividual(i));
        newPopulation.saveIndividual(i,mutatedIndiv);
    }
    
    return newPopulation;
}

// Crossover individuals
Individual Algorithm::crossover(Individual indiv1, Individual indiv2) {
    int crossOverPoint = rand() % indiv1.getSize();
    
    Individual newSol = indiv1;
    // Loop through genes
    for (int i = 0; i < indiv1.getSize(); i++) {
        // Crossover
        if (i <= crossOverPoint) {
            newSol.setGene(i, indiv1.getGene(i));
        }
        else {
            newSol.setGene(i, indiv2.getGene(i));
        }
    }
    return newSol;
}

// Mutate an individual
Individual Algorithm::mutate(Individual indiv) {
    
    // Loop through genes
    for (int i = 0; i < indiv.getSize(); i++) {
        if ( ((double)rand() / (double)RAND_MAX) <= mutationRate) {
            // Create random gene
            if (indiv.getGene(i) == '0') {
                indiv.setGene(i, '1');
            }
            else {
                indiv.setGene(i, '0');
            }
        }
    }
    
    return indiv;
}

// Select individuals for crossover
Individual Algorithm::selection(Population pop) {
    // get total fitness of population
    double previousProbability = 0.0;
    double previousFitness = -99;
    vector<double> alteredWeights(pop.getSize());
    
    // calculate probability for each individual in the population
    for (int i = 0; i < pop.getSize(); i++) {
        //check if fitness is the same as previous fitness, if it is then you do not add previous weight
        if (pop.getIndividual(i).getFitness() != previousFitness) {
            alteredWeights.at(i) = (double)pop.getIndividual(i).getFitness() / (double)pop.getTotalFitness() + previousProbability;
            previousProbability = (double)pop.getIndividual(i).getFitness() / (double)pop.getTotalFitness() + previousProbability;
        }
        else {
            alteredWeights.at(i) = previousProbability;
        }
        
        previousFitness = (double)pop.getIndividual(i).getFitness();
    }
    
    
    //randomly choose the sector of the wheel
    double randomNum = (double)rand() / (double)RAND_MAX;
    int index = 0;  //store the location of roulette wheel
    
    for (int i = 0; i < pop.getSize(); i++) {
        if (alteredWeights.at(i) >= randomNum) {
            index = i;
        }
    }
    
    return pop.getIndividual(index);
}

void Algorithm::sortPopulation(Population& pop) {
    
    int j;
    Individual temp;
    
    for (int i = 1; i < pop.getSize(); i++) {
        j = i;
        while ( j > 0 && pop.getIndividual(j - 1).getFitness() < pop.getIndividual(j).getFitness() ) {
            temp = pop.getIndividual(j);
            pop.saveIndividual(j, pop.getIndividual(j - 1));
            pop.saveIndividual(j - 1, temp);
            j--;
        }
    }
}
