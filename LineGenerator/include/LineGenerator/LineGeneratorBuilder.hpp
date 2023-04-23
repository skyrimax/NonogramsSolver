#ifndef LINEGENERATORBUILDER_H
#define LINEGENERATORBUILDER_H

#include "ILineFilter.hpp"

class LineGeneratorBuilder
{
public:
    // Constructor
    LineGeneratorBuilder() = default;

    // Destructor
    virtual ~LineGeneratorBuilder();

    //Building methods
    // Base line generators
    LineGeneratorBuilder& allPossibleLinesGenerator(unsigned int nbBoxes);

    //Line generator modifiers
    LineGeneratorBuilder& lineGeneratorFilter(ILineFilter* lineFilter);

    // Reset builder
    LineGeneratorBuilder& reset();
};

#endif /* LINEGENERATORBUILDER_H */