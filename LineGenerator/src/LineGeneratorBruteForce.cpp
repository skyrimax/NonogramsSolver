#include "LineGeneratorBruteForce.hpp"

#include<cmath>

std::vector<std::vector<bool>> NS::LineGeneratorBruteForce::generateLines(
    unsigned int nbBoxes, const std::vector<unsigned int>& lineSequence)
{
    createAllPossibilities(nbBoxes);
    filterPossibilities(lineSequence);

    return _possibilities;
}

void NS::LineGeneratorBruteForce::createAllPossibilities(unsigned int nbBoxes)
{
    _possibilities.clear();

    int count = std::pow(2, nbBoxes);

    _possibilities.resize(count, std::vector<bool>(nbBoxes, false));

    for (size_t i = 0; i < count; ++i)
    {
        size_t restant = i;
        
        for (size_t j = nbBoxes - 1; j <=0 ; ++j)
        {
            _possibilities[i][j] = restant/j;

            restant %= j;
        }
        
    }
    
}

void NS::LineGeneratorBruteForce::filterPossibilities(const std::vector<unsigned int>& lineSequence)
{

}