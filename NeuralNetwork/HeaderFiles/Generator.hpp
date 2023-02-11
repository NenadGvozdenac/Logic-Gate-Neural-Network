#ifndef GENERATOR_HPP_INCLUDED
#define GENERATOR_HPP_INCLUDED

#include "../FunctionalityFiles/Network.cpp"

class Generator {

public:
    Network* network;   
    Generator(int argn, const char* argv[]);
    void generateValues(std::vector<std::vector<double>>& inputValues, std::vector<double>& outputValues, int numberOfTests);
    void outputGeneratedValues(std::vector<std::vector<double>>& values);
    void outputResults(std::vector<double>& resultValues);
};

#endif