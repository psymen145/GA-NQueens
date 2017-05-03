#pragma once
#ifndef fitnessCalc_h
#define fitnessCalc_h
#include "individual.h"

using namespace std;

class fitnessCalc {
public:
	static int getFitness(Individual* individual);
	static void setSolution(string newSolution);
	static int getMaxFitness();
private:
	static string solution;
	fitnessCalc() {}
};

#endif
