#include <stdio.h>
#include "fitnessCalc.h"
#include "individual.h"
#include <string>

void fitnessCalc::setSolution(vector<int8_t> newSolution){
    
    solution = newSolution;
}

int fitnessCalc::getFitness(Individual individual){
    
    int fitness = 0;
    
    for (int i = 0; i < individual.getSize() && i < solution.size(); i++){
        if(individual.getGene(i) == solution.at(i)){
            fitness++;
        }
    }
    return fitness;
}


int fitnessCalc::getMaxFitness(){
    
    int maxFitness = solution.size();
    return maxFitness;
}

void fitnessCalc::setSolution(string newSolution) {
    
    vector<int8_t> solution(newSolution.length());

    // Loop through each character of our string and save it in our byte vector
    for (int i = 0; i < newSolution.length(); i++) {
        string character = newSolution.substr(i, i + 1);
        if (character == "0" || character == "1") {
            solution[i] = (int8_t)character;
        } else {
            solution[i] = 0;
        }
    }
}

