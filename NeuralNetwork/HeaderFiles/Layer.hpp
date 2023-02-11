#ifndef LAYER_HPP_INCLUDED
#define LAYER_HPP_INCLUDED

#include "../FunctionalityFiles/Neuron.cpp"

class Layer {

private:
    std::vector<Neuron> neurons;

public:
    void setNeurons(std::vector<Neuron> neurons);
    std::vector<Neuron>& getNeurons();
    void addNewNeuron(unsigned outputNum, int neuronNum);
};

#endif