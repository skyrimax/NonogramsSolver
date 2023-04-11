#include "ILineGeneratorModifier.hpp"

NS::ILineGeneratorModifier::ILineGeneratorModifier(ILineGenerator* lineGenerator)
    : lineGenerator_{lineGenerator}
{

}

NS::ILineGeneratorModifier::~ILineGeneratorModifier()
{
    delete lineGenerator_;
}