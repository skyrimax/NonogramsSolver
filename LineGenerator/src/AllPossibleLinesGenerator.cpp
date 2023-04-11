#include "AllPossibleLinesGenerator.hpp"

#include <cmath>
#include <algorithm>

NS::AllPossibleLinesGenerator::AllPossibleLinesGenerator(unsigned int nbBoxes)
    : nbBoxes_{nbBoxes}
{

}

std::vector<NS::AllPossibleLinesGenerator::Line> NS::AllPossibleLinesGenerator::generateLines(
    unsigned int nbBoxes, const Sequence& lineSequence)
{
    return filterPossibilities(createAllPossibilities(nbBoxes), lineSequence);
}

std::vector<NS::AllPossibleLinesGenerator::Line> NS::AllPossibleLinesGenerator::createAllPossibilities(
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

std::vector<NS::AllPossibleLinesGenerator::Line> NS::AllPossibleLinesGenerator::filterPossibilities(
    std::vector<Line> possibilities, const Sequence& lineSequence)
{
    auto predicate = [this](Line line) {
        return filter_(line);
    };

    possibilities.erase(std::remove_if(
        possibilities.begin(), possibilities.end(),
        predicate
    ), possibilities.end());

    return possibilities;
}