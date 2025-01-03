#ifndef LINEGENERATORBUILDER_H
#define LINEGENERATORBUILDER_H

#include "ILineGenerator.hpp"
#include "ILineFilter.hpp"

#include <memory>

namespace NS
{
    class LineGeneratorBuilder
    {
    public:
        // Constructor
        LineGeneratorBuilder() = default;

        // Destructor
        virtual ~LineGeneratorBuilder() = default;

        //Building methods
        // Base line generators
        LineGeneratorBuilder& allPossibleLinesGenerator(unsigned int nbBoxes);

        //Line generator modifiers
        LineGeneratorBuilder& lineGeneratorFilter(std::shared_ptr<ILineFilter> lineFilter);

        // Make line filter
        std::unique_ptr<ILineGenerator> makeLineGenerator();

        // Reset builder
        LineGeneratorBuilder& reset();

    protected:
        std::unique_ptr<NS::ILineGenerator> lineGenerator_ = std::unique_ptr<NS::ILineGenerator>();
    };
}
#endif /* LINEGENERATORBUILDER_H */