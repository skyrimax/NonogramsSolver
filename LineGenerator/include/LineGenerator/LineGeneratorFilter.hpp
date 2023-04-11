#ifndef LINEGENERATORFILTER_H
#define LINEGENERATORFILTER_H

#include "ILineGeneratorModifier.hpp"

#include "ILineFilter.hpp"

namespace NS
{
    class LineGeneratorFilter: public ILineGeneratorModifier
    {
    public:
        // Constructor
        LineGeneratorFilter(ILineFilter* lineFilter, ILineGenerator* lineGenerator);

        // Destructor
        ~LineGeneratorFilter();

        virtual std::vector<Line> generateLines() override;

    protected:
        ILineFilter* lineFilter_;
    };
}

#endif /* LINEGENERATORFILTER_H */