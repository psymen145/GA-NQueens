#include "stdafx.h"
#include "individual.h"
#include "fitnessCalc.h"
#include <string>

using namespace std;

Individual::Individual() {}

int Individual::defaultGeneLength = 64;

void Individual::generateIndividual() {

	for (int i = 0; i < defaultGeneLength; i++) {
		if (rand() % 2 == 0) {
			genes += '0';
		}
		else {
			genes += '1';
		}
	}

	if (fitness == 0) {
		fitness = fitnessCalc::getFitness((*this));
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

	return genes.size();
}

int Individual::getFitness() {

	if (fitness == 0) {
		fitness = fitnessCalc::getFitness((*this));
	}

	return fitness;
}

void Individual::setDefaultGeneLength(int length) {
	defaultGeneLength = length;
}

string Individual::getEntireGene() {
	return genes;
}