#ifndef LINEGENERATORFILTER_H
#define LINEGENERATORFILTER_H

#include "ILineGeneratorModifier.hpp"

#include "ILineFilter.hpp"

#include <memory>

namespace NS
{
    class LineGeneratorFilter: public ILineGeneratorModifier
    {
    public:
        // Constructor
        LineGeneratorFilter(std::shared_ptr<ILineFilter> lineFilter, std::unique_ptr<ILineGenerator> lineGenerator);

        // Destructor
        ~LineGeneratorFilter();

        virtual std::vector<Line> generateLines() override;

    protected:
        std::shared_ptr<ILineFilter> lineFilter_;
    };
}

#endif /* LINEGENERATORFILTER_H */