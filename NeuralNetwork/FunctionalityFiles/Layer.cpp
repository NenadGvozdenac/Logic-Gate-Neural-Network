#ifndef LAYER_CPP_INCLUDED
#define LAYER_CPP_INCLUDED

#include "../HeaderFiles/Layer.hpp"

void Layer::setNeurons(std::vector<Neuron> neurons) {
    this->neurons = neurons;
}

std::vector<Neuron> Layer::getNeurons() {
    return this->neurons;
}

void Layer::addNewNeuron(unsigned outputWeight, int neuronNum) {
    Neuron neuron(outputWeight, neuronNum);
    this->neurons.push_back(neuron);
}

void Neuron::feedForwardNeuron(Layer& previousLayer) {
    double sumOfAllInputs = 0.f;

    for(int numberOfNeuron = 0; numberOfNeuron < previousLayer.getNeurons().size(); numberOfNeuron++) {
        sumOfAllInputs += previousLayer.getNeurons()[numberOfNeuron].getOutputValue() * previousLayer.getNeurons()[numberOfNeuron].getOutputWeights()[this->index].getWeight();
    }

    this->outputValue = transferFunction(sumOfAllInputs);
}

#endif