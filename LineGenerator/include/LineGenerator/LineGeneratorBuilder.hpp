#ifndef LINEGENERATORBUILDER_H
#define LINEGENERATORBUILDER_H

#include "ILineGenerator.hpp"
#include "ILineFilter.hpp"

namespace NS
{
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
    
    protected:
        NS::ILineGenerator* lineGenerator_;
    };
}
#endif /* LINEGENERATORBUILDER_H */