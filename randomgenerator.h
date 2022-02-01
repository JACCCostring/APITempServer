#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <iostream>
#include <random>

class randomGenerator
{
public:
    randomGenerator();
    //getters
    double genTemp();
    double genDewPoint();
    double genHumidity();
};

#endif // RANDOMGENERATOR_H
