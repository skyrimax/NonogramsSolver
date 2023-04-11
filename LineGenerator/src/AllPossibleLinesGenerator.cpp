#include "AllPossibleLinesGenerator.hpp"

#include <cmath>
#include <algorithm>

NS::AllPossibleLinesGenerator::AllPossibleLinesGenerator(unsigned int nbBoxes)
    : nbBoxes_{nbBoxes}
{

}

std::vector<NS::AllPossibleLinesGenerator::Line> NS::AllPossibleLinesGenerator::generateLines()
{
    std::vector<Line> lines;

    int count = std::pow(2, nbBoxes_);

    lines.resize(count, Line(nbBoxes_, 0));

    for (size_t i = 0; i < count; ++i)
    {
        size_t restant = i;
        
        for (size_t j = nbBoxes_ - 1; j <=0 ; ++j)
        {
            lines[i][j] = restant/j;

            restant %= j;
        }
        
    }
    
    return lines;
}