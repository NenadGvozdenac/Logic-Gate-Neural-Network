#ifndef NEURON_CPP_INCLUDED
#define NEURON_CPP_INCLUDED

#include "../HeaderFiles/Neuron.hpp"

Neuron::Neuron(unsigned numOutputs, int index) {
    for(unsigned i = 0; i < numOutputs; i++) {
        this->outputWeights.push_back(Connection());
    }

    this->index = index;
}

void Neuron::setOutputValue(double outputValue) {
    this->outputValue = outputValue;
}

double Neuron::getOutputValue() {
    return this->outputValue;
}

std::vector<Connection> Neuron::getOutputWeights() {
    return this->outputWeights;
}

void Neuron::setOutputWeights(std::vector<Connection> outputWeights) {
    this->outputWeights = outputWeights;
}

double Connection::getWeight() {
    return this->weight;
}

double Connection::getDeltaWeight() {
    return this->deltaWeight;
}

void Connection::setWeight(double weight) {
    this->weight = weight;
}

void Connection::setDeltaWeight(double deltaWeight) {
    this->deltaWeight = deltaWeight;
}

Connection::Connection() {
    this->weight = rand() / double(RAND_MAX); 
}

double Neuron::transferFunction(double x) {
    return tanh(x);
}

double Neuron::transferFunctionDerivative(double x) {
    return 1 - pow(tanh(x), 2);
}

#endif