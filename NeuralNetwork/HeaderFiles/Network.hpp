#ifndef NETWORK_HPP_INCLUDED
#define NETWORK_HPP_INCLUDED

#include <vector>
#include <iostream>

#include "../FunctionalityFiles/Layer.cpp"

class Network {

private:
    std::vector<unsigned> topology;
    std::vector<Layer> layers;
    unsigned numLayers;

public:
    Network();
    ~Network();
    Network(std::vector<unsigned>&);                       // Topology (3, 2, 1) -> 3 neurons in input layer, 2 neurons in hidden layer, 1 neuron in outter layer

    void feedForward(std::vector<double>& inputValues);             // Feed Forward method of sending data to the next Layer of neurons
    void backPropagation(std::vector<double>& targetValues);        // Back propagation - used for learning (or rather, teaching) the neural network
    void getNeuralResults(std::vector<double>& resultValues) const; // Getting results from the final layer

};

#endif