#ifndef NEURON_CPP_INCLUDED
#define NEURON_CPP_INCLUDED

#include "../HeaderFiles/Neuron.hpp"

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;

Neuron::Neuron(unsigned numOutputs, int index) {
    std::cout << numOutputs << std::endl;
    for(unsigned i = 0; i < numOutputs; ++i) {
        std::cout << "Created conn.";
        this->outputWeights.push_back(Connection());
    }

    this->index = index;
    this->setOutputValue(0.005);
}

void Neuron::calculateOutputGradients(double targetValue) {
    double delta = targetValue - this->outputValue;
    this->gradient = delta * Neuron::transferFunctionDerivative(this->outputValue);
}

void Neuron::setOutputValue(double outputValue) {
    this->outputValue = outputValue;
}

double Neuron::getOutputValue() {
    return outputValue;
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
    return 1.0 - pow(tanh(x), 2);
}

#endif