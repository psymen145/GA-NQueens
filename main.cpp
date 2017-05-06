
#include <iostream>
#include <time.h>
#include "individual.h"
#include "population.h"
#include "algorithm.h"
#include "fitnessCalc.h"
#include <string>

using namespace std;

int main() {
    
    srand(time(NULL));
    string solution;
    
    cout << "Enter a binary string: " << endl;
    cin >> solution;
    
    fitnessCalc::setSolution(solution);
    Individual::setDefaultGeneLength(solution.size());
    
    Population myPop(50, true);
    
    // Evolve our population until we reach an optimum solution
    int generationCount = 0;
    while (myPop.getFittest().getFitness() < fitnessCalc::getMaxFitness()) {
        generationCount++;
        cout << "Generation: " << generationCount << " Fittest: " << myPop.getFittest().getEntireGene() << endl;
        myPop = Algorithm::evolvePopulation(myPop);
    }
    
    cout << "\nSolution found!" << endl;
    cout << "Generation: " << generationCount + 1 << endl;
    cout << "Solution: " << myPop.getFittest().getEntireGene() << endl;
    return 0;
}
