#include "ILineGeneratorModifier.hpp"

NS::ILineGeneratorModifier::ILineGeneratorModifier(std::unique_ptr<ILineGenerator> lineGenerator)
    : lineGenerator_(std::move(lineGenerator))
{

}

NS::ILineGeneratorModifier::~ILineGeneratorModifier()
{
    
}