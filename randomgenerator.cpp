#include "randomgenerator.h"

randomGenerator::randomGenerator()
{

}

double randomGenerator::genTemp()
{
    return arc4random_uniform(27.3) + -7.8;
}


double randomGenerator::genDewPoint()
{
    return arc4random_uniform(27.3) + 8.7;
}

double randomGenerator::genHumidity()
{
    return arc4random_uniform(100) + 8;
}
