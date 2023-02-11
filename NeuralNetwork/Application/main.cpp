#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "../FunctionalityFiles/Network.cpp"

int main(int argn, char* argv[]) {

    std::vector<unsigned> topology;

    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);

    Network* neuralNetwork = new Network(topology);

    return 0;
}