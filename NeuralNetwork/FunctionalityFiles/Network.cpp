#ifndef NETWORK_CPP_INCLUDED
#define NETWORK_CPP_INCLUDED

#include "../HeaderFiles/Network.hpp"

Network::Network() {
    this->topology.push_back(3);    // Default constructor, constructs a default NeuralNetwork with 3 -> 2 -> 1 topology.
    this->topology.push_back(2);
    this->topology.push_back(1);
}

Network::Network(std::vector<unsigned>& topology) {
    this->topology = topology;
    this->numLayers = topology.size();

    for(unsigned layer = 0; layer < this->numLayers; layer++) {
        layers.push_back(Layer());  // Create a new layer

        unsigned numOutputs;

        if(layer == this->numLayers - 1) {
            numOutputs = 0;
        } else {
            numOutputs = topology[layer + 1];
        }

        for(unsigned neuron = 0; neuron <= topology[layer]; neuron++) {
            layers[layers.size() - 1].addNewNeuron(numOutputs, neuron);

            std::cout << "Made a " << neuron << ". neuron and added it to " << layers.size() - 1 << ". layer." << std::endl;
        }
    }
}

void Network::feedForward(std::vector<double>& inputValues) {
    if(!(inputValues.size() == this->layers[0].getNeurons().size() - 1)) {
        std::cout << "Error has come by! Number of input neurons is not the same as the size of neurons in the layer!" << std::endl;
        exit(0);
    }

    // Set the original neuron's values
    for(int i = 0; i < inputValues.size(); i++) {
        this->layers[0].getNeurons()[i].setOutputValue(inputValues[i]);
    }

    // Forward propagate

    for(int layerNum = 1; layerNum < this->layers.size(); layerNum++) {
        
        Layer& previousLayer = this->layers[layerNum - 1];

        for(int neuron = 0; neuron < this->layers[layerNum].getNeurons().size() - 1; neuron++) {
            Neuron neuronRef = this->layers[layerNum].getNeurons()[neuron];
            neuronRef.feedForwardNeuron(previousLayer);
        }
    }
}

Network::~Network() {
    delete this;
}

#endif