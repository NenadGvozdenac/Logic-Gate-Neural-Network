#ifndef LAYER_CPP_INCLUDED
#define LAYER_CPP_INCLUDED

#include "../HeaderFiles/Layer.hpp"

void Layer::setNeurons(std::vector<Neuron> neurons) {
    this->neurons = neurons;
}

void Layer::addNewNeuron(unsigned outputWeight, int neuronNum) {
    Neuron neuron(outputWeight, neuronNum);
    this->neurons.push_back(neuron);
}

void Neuron::calculateHiddenGradient(Layer& nextLayer) {
    double dow = sumDOW(nextLayer);
    this->gradient = dow * Neuron::transferFunctionDerivative(this->outputValue);
}

void Neuron::feedForwardNeuron(Layer& previousLayer) {
    double sumOfAllInputs = 0.0;

    for(int numberOfNeuron = 0; numberOfNeuron < previousLayer.neurons.size(); ++numberOfNeuron) {
        sumOfAllInputs += previousLayer.neurons[numberOfNeuron].getOutputValue() * previousLayer.neurons[numberOfNeuron].outputWeights[index].getWeight();
    }

    this->outputValue = Neuron::transferFunction(sumOfAllInputs);
}

double Neuron::sumDOW(Layer& nextLayer) {
    double sum = 0.0;

    for(int n = 0; n < nextLayer.neurons.size() - 1; ++n) {
        sum += outputWeights[n].getWeight() * nextLayer.neurons[n].gradient;
    }

    return sum;
}


void Neuron::updateInputWeights(Layer& previousLayer) {

    for(int n = 0; n < previousLayer.neurons.size(); ++n) {
        double oldDeltaWeight = previousLayer.neurons[n].outputWeights[index].getDeltaWeight();
        double newDeltaWeight = eta * previousLayer.neurons[n].getOutputValue() * gradient + alpha * oldDeltaWeight;

        previousLayer.neurons[n].outputWeights[index].setDeltaWeight(newDeltaWeight);
        previousLayer.neurons[n].outputWeights[index].setWeight(previousLayer.neurons[n].outputWeights[index].getWeight() + newDeltaWeight);
    }
}

#endif