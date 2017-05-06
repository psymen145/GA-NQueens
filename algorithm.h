
#ifndef algorithm_h
#define algorithm_h
#include "population.h"
#include "individual.h"

class Algorithm {
public:
    static Population evolvePopulation(Population pop);
private:
    //static const double uniformRate;
    static const double mutationRate;
    //static const int tournamentSize = 5;
    static const bool elitism = true;
    
    static Individual mutate(Individual indiv);
    static Individual crossover(Individual indiv1, Individual indiv2);
    static Individual selection(Population pop);
    static void sortPopulation(Population& pop);
};

#endif
