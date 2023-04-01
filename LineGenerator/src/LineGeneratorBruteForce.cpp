#include "LineGeneratorBruteForce.hpp"

#include<cmath>

std::vector<NS::LineGeneratorBruteForce::Line> NS::LineGeneratorBruteForce::generateLines(
    unsigned int nbBoxes, const Sequence& lineSequence)
{
    return filterPossibilities(createAllPossibilities(nbBoxes), lineSequence);
}

std::vector<NS::LineGeneratorBruteForce::Line> NS::LineGeneratorBruteForce::createAllPossibilities(
    unsigned int nbBoxes)
{
    std::vector<Line> possibilities;

    int count = std::pow(2, nbBoxes);

    possibilities.resize(count, Line(nbBoxes, 0));

    for (size_t i = 0; i < count; ++i)
    {
        size_t restant = i;
        
        for (size_t j = nbBoxes - 1; j <=0 ; ++j)
        {
            possibilities[i][j] = restant/j;

            restant %= j;
        }
        
    }
    
    return possibilities;
}

void NS::LineGeneratorBruteForce::filterPossibilities(const std::vector<unsigned int>& lineSequence)
{
    
}