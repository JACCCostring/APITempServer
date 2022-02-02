#include "randomgenerator.h"

randomGenerator::randomGenerator()
{

}

double randomGenerator::genTemp()
{
    qsrand(time(NULL));

    return qrand()  % 27;
}


double randomGenerator::genDewPoint()
{
    qsrand(time(NULL));

    return qrand()  % 17;
}

double randomGenerator::genHumidity()
{
    qsrand(time(NULL));

    return qrand()  % 98;
}
