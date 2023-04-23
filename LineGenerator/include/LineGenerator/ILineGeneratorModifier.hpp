#ifndef ILINEGENERATORMODIFIER_H
#define ILINEGENERATORMODIFIER_H

#include "ILineGenerator.hpp"

namespace NS
{
    class ILineGeneratorModifier: public ILineGenerator
    {
    public:
        // Constructors
        ILineGeneratorModifier(ILineGenerator* lineGenerator);

        // Destructor
        ~ILineGeneratorModifier();

    protected:
        ILineGenerator* lineGenerator_;
    };
}

#endif /* ILINEGENERATORMODIFIER_H */