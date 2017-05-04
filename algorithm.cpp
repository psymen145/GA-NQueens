#include "stdafx.h"
#include <stdio.h>
#include "algorithm.h"

//const double Algorithm::uniformRate = 0.5;
const double Algorithm::mutationRate = 0.01;

// Evolve a population
Population Algorithm::evolvePopulation(Population pop) {
	Population newPopulation(pop.getSize(), false);

	//sort the population
	sortPopulation(pop);

	// Loop over the population size and create new individuals with
	// crossover
	for (int i = 0; i < pop.getSize(); i++) {
		Individual indiv1 = selection(pop);
		Individual indiv2 = selection(pop);
		cout << indiv1.getFitness() << endl;
		cout << indiv2.getFitness() << endl;
		//Individual newIndiv = crossover(indiv1, indiv2);
		//newPopulation.saveIndividual(i, newIndiv);
	}
	
	// Mutate population
	for (int i = 0; i < newPopulation.getSize(); i++) {
		mutate(newPopulation.getIndividual(i));
	}

	return pop;
}

// Crossover individuals
Individual Algorithm::crossover(Individual indiv1, Individual indiv2) {
	int crossOverPoint = rand() % indiv1.getSize();

	Individual newSol = Individual();
	// Loop through genes
	for (int i = 0; i < indiv1.getSize(); i++) {
		// Crossover
		if (i < crossOverPoint) {
			newSol.setGene(i, indiv1.getGene(i));
		}
		else {
			newSol.setGene(i, indiv2.getGene(i));
		}
	}
	return newSol;
}

// Mutate an individual
void Algorithm::mutate(Individual indiv) {
	// Loop through genes
	for (int i = 0; i < indiv.getSize(); i++) {
		if (rand() <= mutationRate) {
			// Create random gene
			if (rand() % 2 == 0) {
				indiv.setGene(i, '0');
			}
			else {
				indiv.setGene(i, '1');
			}
		}
	}
}

// Select individuals for crossover
Individual Algorithm::selection(Population pop) {
	// get total fitness of population
	int totalFit = pop.getTotalFitness();
	double previousProbability = 0;
	int previousFitness = -99;
	Individual chosenIndividual;
	vector<double> alteredWeights;

	// For each place in the tournament get a random individual
	/*for (int i = 0; i < pop.getSize(); i++) {
		//check if fitness is the same as previous fitness
		if (pop.getIndividual(i).getFitness() != previousFitness) {
			alteredWeights.at(i) = (pop.getIndividual(i).getFitness() / pop.getTotalFitness()) + previousProbability;
		}
		else {
			alteredWeights.at(i) = alteredWeights.at(i - 1);
		}

		previousFitness = pop.getIndividual(i).getFitness();
	}

	//randomly choose the sector of the wheel
	double randomNum = (double)rand() / (double)RAND_MAX;
	int sector;

	for (int i = 0; i < alteredWeights.size(); i++) {
		if (alteredWeights.at(i) >= randomNum) {
			sector = i;
			break;
		}
	}

	//randomly choose within that sector
	//get all individuals with that same fitness
	vector<Individual> sameFitnessIndividuals;

	for (int i = sector; pop.getSize(); i++) {
		if (pop.getIndividual(sector).getFitness() == pop.getIndividual(i).getFitness()) {
			sameFitnessIndividuals.push_back(pop.getIndividual(i));
		}
		else {
			break;
		}
	}

	int randomSpot = rand() % sameFitnessIndividuals.size();*/

	return pop.getIndividual(0);
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