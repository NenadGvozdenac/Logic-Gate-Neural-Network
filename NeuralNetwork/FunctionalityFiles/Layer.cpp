#ifndef LAYER_CPP_INCLUDED
#define LAYER_CPP_INCLUDED

#include "../HeaderFiles/Layer.hpp"

void Layer::setNeurons(std::vector<Neuron> neurons) {
    this->neurons = neurons;
}

std::vector<Neuron>& Layer::getNeurons() {
    return this->neurons;
}

void Layer::addNewNeuron(unsigned outputWeight, int neuronNum) {
    std::cout << "C" << std::endl;
    Neuron neuron(outputWeight, neuronNum);
    this->neurons.push_back(neuron);
}

void Neuron::calculateHiddenGradient(Layer& nextLayer) {
    double dow = sumDOW(nextLayer);
    this->gradient = dow * Neuron::transferFunctionDerivative(this->outputValue);
}

void Neuron::feedForwardNeuron(Layer& previousLayer) {
    double sumOfAllInputs = 0.0;

    for(int numberOfNeuron = 0; numberOfNeuron < previousLayer.getNeurons().size(); ++numberOfNeuron) {
        sumOfAllInputs += previousLayer.getNeurons()[numberOfNeuron].getOutputValue() * previousLayer.getNeurons()[numberOfNeuron].getOutputWeights()[index].getWeight();
    }

    this->outputValue = Neuron::transferFunction(sumOfAllInputs);
}

double Neuron::sumDOW(Layer& nextLayer) {
    double sum = 0.0;

    for(int n = 0; n < nextLayer.getNeurons().size() - 1; ++n) {
        sum += outputWeights[n].getWeight() * nextLayer.getNeurons()[n].gradient;
    }

    return sum;
}


void Neuron::updateInputWeights(Layer& previousLayer) {

    for(int n = 0; n < previousLayer.getNeurons().size(); ++n) {
        double oldDeltaWeight = previousLayer.getNeurons()[n].getOutputWeights()[index].getDeltaWeight();
        double newDeltaWeight = eta * previousLayer.getNeurons()[n].getOutputValue() * gradient + alpha * oldDeltaWeight;

        previousLayer.getNeurons()[n].getOutputWeights()[index].setDeltaWeight(newDeltaWeight);
        previousLayer.getNeurons()[n].getOutputWeights()[index].setWeight(previousLayer.getNeurons()[n].getOutputWeights()[index].getWeight() + newDeltaWeight);
    }
}

#endif