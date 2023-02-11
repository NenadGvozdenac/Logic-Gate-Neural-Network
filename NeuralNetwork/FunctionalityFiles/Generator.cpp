#ifndef GENERATOR_CPP_INCLUDED
#define GENERATOR_CPP_INCLUDED

#include "../HeaderFiles/Generator.hpp"
#include <string>

Generator::Generator(int argn, const char* argv[]) {

    int numberOfTestsSent = (argn == 2) ? std::stoi(argv[1]) : 2000;

    srand(time(NULL));

    std::vector<unsigned> topology;

    topology.push_back(3);
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);

    network = new Network(topology);

    std::vector<std::vector<double>> generatedInputValues;
    std::vector<double> listOfTargetValues;
    
    Generator::generateValues(generatedInputValues, listOfTargetValues, numberOfTestsSent);

    std::vector<double> inputValues, targetValues, resultValues;

    for(int i = 0; i < numberOfTestsSent; i++) {
        std::cout << "Phase " << i+1 << std::endl;
        inputValues = generatedInputValues.at(i);
        targetValues.clear();
        targetValues.push_back(listOfTargetValues.at(i));

        switch((int)inputValues[2]) {
            case 0:
                std::cout << "Input: " << inputValues[0] << " ^ " << inputValues[1] << " = " << targetValues[0] << std::endl;
            break;

            case 1:
                std::cout << "Input: " << inputValues[0] << " | " << inputValues[1] << " = " << targetValues[0] << std::endl;
            break;

            case 2:
                std::cout << "Input: " << inputValues[0] << " & " << inputValues[1] << " = " << targetValues[0] << std::endl;
            break;
        }

        network->feedForward(inputValues);
        network->backPropagation(targetValues);
        network->getNeuralResults(resultValues);  

        outputResults(resultValues);
    }
}

void Generator::generateValues(std::vector<std::vector<double>>& inputValues, std::vector<double>& outputValues, int numberOfTests) {
    for(int i = 0; i < numberOfTests; i++) {

        double value1 = rand() % 2; // 0, 1
        double value2 = rand() % 2; // 0, 1
        double value3 = rand() % 3; // 0, 1, 2   -> 0 xor, 1 or, 2 and

        std::vector<double> iValues;
        iValues.push_back(value1);
        iValues.push_back(value2);
        iValues.push_back(value3);

        inputValues.push_back(iValues);

        int val1 = (int) value1;
        int val2 = (int) value2;
        int val3 = (int) value3;

        double outputValue;

        switch(val3) {
            case 0:
                outputValue = val1 ^ val2;
            break;

            case 1:
                outputValue = val1 | val2;
            break;

            case 2:
                outputValue = val1 & val2;
            break;

            default:
                outputValue = 0;
        }

        outputValues.push_back(outputValue);
    }
}
    
void Generator::outputGeneratedValues(std::vector<std::vector<double>>& values) {
    for(int i = 0; i < values.size(); i++) {
        std::cout << "Input: ";
        for(int j = 0; j < 3; j++) {
            std::cout << values[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Generator::outputResults(std::vector<double>& resultValues) {

    std::cout << "Output is: ";

    for(double& d : resultValues) {
        std::cout << d << " ";
    }

    std::cout << "\n\n";
}

#endif