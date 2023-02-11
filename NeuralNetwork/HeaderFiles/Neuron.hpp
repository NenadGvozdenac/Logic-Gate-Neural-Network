#ifndef NEURON_HPP_INCLUDED
#define NEURON_HPP_INCLUDED

#include <vector>

class Layer;

class Connection {

private:
    double weight;
    double deltaWeight;

public:
    Connection();
    double getWeight();
    double getDeltaWeight();
    void setWeight(double weight);
    void setDeltaWeight(double deltaWeight);

};

class Neuron {

private:
    double outputValue;
    std::vector<Connection> outputWeights;
    int index;

public:
    Neuron(unsigned numOutputs, int index);
    void setOutputValue(double outputValue);
    double getOutputValue();
    void setOutputWeights(std::vector<Connection> outputWeights);
    std::vector<Connection> getOutputWeights();
    void feedForwardNeuron(Layer& previousLayer);
    double transferFunction(double x);
    double transferFunctionDerivative(double x);

};

#endif