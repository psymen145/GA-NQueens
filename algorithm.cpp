#include "stdafx.h"
#include <stdio.h>
#include "algorithm.h"

const double Algorithm::uniformRate = 0.5;
const double Algorithm::mutationRate = 0.015;

// Evolve a population
Population Algorithm::evolvePopulation(Population pop) {
	Population newPopulation(pop.getSize(), false);

	// Keep our best individual
	if (elitism) {
		newPopulation.saveIndividual(0, pop.getFittest());
	}

	// Crossover population
	int elitismOffset;
	if (elitism) {
		elitismOffset = 1;
	}
	else {
		elitismOffset = 0;
	}

	// Loop over the population size and create new individuals with
	// crossover
	for (int i = elitismOffset; i < pop.getSize(); i++) {
		Individual indiv1 = tournamentSelection(pop);
		Individual indiv2 = tournamentSelection(pop);
		Individual newIndiv = crossover(indiv1, indiv2);
		newPopulation.saveIndividual(i, newIndiv);
	}

	// Mutate population
	for (int i = elitismOffset; i < newPopulation.getSize(); i++) {
		mutate(newPopulation.getIndividual(i));
	}

	return newPopulation;
}

// Crossover individuals
Individual Algorithm::crossover(Individual indiv1, Individual indiv2) {
	Individual newSol = Individual();
	// Loop through genes
	for (int i = 0; i < indiv1.getSize(); i++) {
		// Crossover
		if (rand() <= uniformRate) {
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
Individual Algorithm::tournamentSelection(Population pop) {
	// Create a tournament population
	Population tournament(tournamentSize, false);
	// For each place in the tournament get a random individual
	for (int i = 0; i < tournamentSize; i++) {
		int randomId = (int)(rand() * pop.getSize());
		tournament.saveIndividual(i, pop.getIndividual(randomId));
	}
	// Get the fittest
	Individual fittest = tournament.getFittest();
	return fittest;
}
