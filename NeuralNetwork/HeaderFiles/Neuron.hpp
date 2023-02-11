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
    double gradient;

public:
    Neuron(unsigned numOutputs, int index);
    void setOutputValue(double outputValue);
    double getOutputValue();
    void setOutputWeights(std::vector<Connection> outputWeights);
    std::vector<Connection> getOutputWeights();
    void feedForwardNeuron(Layer& previousLayer);
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    void calculateOutputGradients(double targetValue);
    void calculateHiddenGradient(Layer& nextLayer);
    double sumDOW(Layer& nextLayer);
    void updateInputWeights(Layer& previousLayer);
    static double eta;
    static double alpha;
};

#endif