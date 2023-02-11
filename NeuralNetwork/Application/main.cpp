#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>

#include "../FunctionalityFiles/Network.cpp"

std::vector<std::vector<double>> generateXORValues() {
    std::vector<std::vector<double>> values;

    for(int i = 0; i < 800; i++) {

        double value1 = rand() % 2;
        double value2 = rand() % 2;

        std::vector<double> iValues;
        iValues.push_back(value1);
        iValues.push_back(value2);

        values.push_back(iValues);
    }

    return values;
}

void outputGeneratedXORValues(std::vector<std::vector<double>>& values) {
    for(int i = 0; i < values.size(); i++) {
        std::cout << "Input: ";
        for(int j = 0; j < 2; j++) {
            std::cout << values[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void getInputValues(std::vector<std::vector<double>>& generatedXORValues, std::vector<double>& inputValues, std::vector<double>& outputValues, int index) {
    inputValues.clear();
    outputValues.clear();

    inputValues = generatedXORValues[index];
    double outputValue = (int)inputValues.at(0) ^ (int)inputValues.at(1);
    outputValues.push_back(outputValue);
}

void outputResults(std::vector<double>& resultValues) {

    std::cout << "Output is: ";

    for(double& d : resultValues) {
        std::cout << d << " ";
    }

    std::cout << "\n\n";
}

int main(int argn, char* argv[]) {

    srand(time(NULL));

    std::vector<unsigned> topology;

    topology.push_back(2);
    topology.push_back(3);
    topology.push_back(4);
    topology.push_back(4);
    topology.push_back(1);

    Network* neuralNetwork = new Network(topology);

    std::vector<std::vector<double>> generatedInputValues = generateXORValues();

    std::vector<double> inputValues, targetValues;
    std::vector<double> resultValues;

    for(int i = 0; i < 800; i++) {
        std::cout << "Phase " << i+1 << std::endl;
        getInputValues(generatedInputValues, inputValues, targetValues, i);

        std::cout << "Input: " << inputValues[0] << + " ^ " << inputValues[1] << " = " << targetValues[0] << std::endl;
            
        neuralNetwork->feedForward(inputValues);
        neuralNetwork->backPropagation(targetValues);
        neuralNetwork->getNeuralResults(resultValues);  

        outputResults(resultValues);
    }
    
    return 0;
}