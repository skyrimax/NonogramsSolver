#ifndef ILINEGENERATORMODIFIER_H
#define ILINEGENERATORMODIFIER_H

#include "ILineGenerator.hpp"

#include <memory>

namespace NS
{
    class ILineGeneratorModifier: public ILineGenerator
    {
    public:
        // Constructors
        ILineGeneratorModifier(std::unique_ptr<ILineGenerator> lineGenerator);

        // Destructor
        ~ILineGeneratorModifier();

    protected:
        std::unique_ptr<ILineGenerator> lineGenerator_;
    };
}

#endif /* ILINEGENERATORMODIFIER_H */