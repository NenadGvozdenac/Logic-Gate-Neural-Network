#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <string>

#include "../FunctionalityFiles/Generator.cpp"

void testCase(int value1, int value2, int value3, int expectedValue, Generator generator) {
    std::vector<double> inputValues, targetValues, resultValues;
    
    inputValues.clear();
    resultValues.clear();
    inputValues.push_back(value1);
    inputValues.push_back(value2);
    inputValues.push_back(value3);

    generator.network->feedForward(inputValues);
    generator.network->getNeuralResults(resultValues);
    generator.outputResults(resultValues);
}

int getExpectedValue(int i, int j, int k) {
    switch(k) {
        case 0:
            return i ^ j;
        break;
        case 1:
            return i | j;
        break;
        case 2:
            return i & j;
        break;
    }

    return 0;
}

char getOperation(int k) {
    switch(k) {
        case 0:
            return '^';
        break;
        case 1:
            return '|';
        break;
        case 2:
            return '&';
        break;
    }
    return ' ';
}

int main(int argn, const char* argv[]) {

    Generator generator(argn, argv);
    Network* network = generator.network;

    std::cout << "--- Testing cases ---" << std::endl;

    int testCaseValue = 1;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                std::cout << "Test " << testCaseValue << " :: Value expected: " << getExpectedValue(i, j, k) << " = " << i << " " << getOperation(k) << " " << j << std::endl;
                testCaseValue++;
                testCase(i, j, k, getExpectedValue(i, j, k), generator);
            }
        }
    }

    return 0;
}