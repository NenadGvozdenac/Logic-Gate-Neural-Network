#ifndef LAYER_HPP_INCLUDED
#define LAYER_HPP_INCLUDED

#include "../FunctionalityFiles/Neuron.cpp"

class Layer {
public:
    std::vector<Neuron> neurons;
    void setNeurons(std::vector<Neuron> neurons);
    void addNewNeuron(unsigned outputNum, int neuronNum);
};

#endif