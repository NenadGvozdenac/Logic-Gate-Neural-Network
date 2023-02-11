#ifndef NETWORK_CPP_INCLUDED
#define NETWORK_CPP_INCLUDED

#include "../HeaderFiles/Network.hpp"

Network::Network(std::vector<unsigned>& topology) {
    this->topology = topology;
    this->numLayers = topology.size();

    for(unsigned layer = 0; layer < this->numLayers; ++layer) {
        std::cout << "Added a new layer!" << std::endl;
        layers.push_back(Layer());  // Create a new layer

        unsigned numOutputs = (numLayers == topology.size() - 1) ? 0 : topology[layer + 1];

        for(unsigned neuron = 0; neuron <= topology[layer]; ++neuron) {
            layers.back().addNewNeuron(numOutputs, neuron);

            std::cout << "Made a " << neuron << ". neuron and added it to " << layers.size() - 1 << ". layer." << std::endl;
        }
    }
}

void Network::feedForward(std::vector<double>& inputValues) {
    if(!(inputValues.size() == this->layers[0].neurons.size() - 1)) {
        std::cout << "Error has come by! Number of input neurons is not the same as the size of neurons in the layer!" << std::endl;
        exit(0);
    }

    // Set the original neuron's values

    for (unsigned i = 0; i < inputValues.size(); ++i) {
        layers[0].neurons[i].setOutputValue(inputValues[i]);
    }

    // Forward propagate

    for(int layerNum = 1; layerNum < layers.size(); ++layerNum) {
        for(int neuron = 0; neuron < layers[layerNum].neurons.size() - 1; ++neuron) {
            layers[layerNum].neurons[neuron].feedForwardNeuron(layers[layerNum - 1]);
        }
    }
}

Network::~Network() {
    delete this;
}

void Network::backPropagation(std::vector<double>& targetValues) {
    Layer& outputLayer = layers.back();
    error = 0.0;

    for(int i = 0; i < outputLayer.neurons.size() - 1; ++i) {
        double delta = targetValues[i] - outputLayer.neurons[i].getOutputValue();
        error += delta * delta;
    }

    error /= outputLayer.neurons.size() - 1;
    error = sqrt(error);

    std::cout << "Error: " << error << std::endl;

    for(int n = 0; n < outputLayer.neurons.size() - 1; ++n) {
        outputLayer.neurons[n].calculateOutputGradients(targetValues[n]);
    }

    for(int layerNum = layers.size() - 2; layerNum > 0; --layerNum) {
        for(int n = 0; n < layers[layerNum].neurons.size(); ++n) {
            layers[layerNum].neurons[n].calculateHiddenGradient(layers[layerNum + 1]);
        }
    }

    for(int layerNum = layers.size() - 1; layerNum > 0; --layerNum) {
        for(int n = 0; n < layers[layerNum].neurons.size() - 1; ++n) {
            layers[layerNum].neurons[n].updateInputWeights(layers[layerNum - 1]);
        }
    }
}

void Network::getNeuralResults(std::vector<double>& resultVals) {
    resultVals.clear();

    for(int n = 0; n < layers.back().neurons.size() - 1; ++n) {
        resultVals.push_back(layers.back().neurons[n].getOutputValue());
    }
}

#endif