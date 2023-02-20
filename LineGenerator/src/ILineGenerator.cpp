#include "ILineGenerator.hpp"

#include <sstream>
#include <exception>

std::vector<std::vector<bool>> NS::ILineGenerator::generateLines(unsigned int nbBoxes, const std::string& lineSequence, const std::string& separator)
{
    std::vector<unsigned int> lineSequenceUInt;
    std::string token;
    int start = 0;

    int end = lineSequence.find(separator);
    while (end != -1) {
        token = lineSequence.substr(start, end - start);
        
        try{
            lineSequenceUInt.push_back(std::stoul(token));
        }
        catch (std::invalid_argument const& ex){
            throw std::invalid_argument(token + " is not a valid number : " + ex.what());
        }
        catch (std::out_of_range const& ex){
            throw std::out_of_range(token + " is out of range of uint : " + ex.what());
        }

        start = end + separator.size();
        end = lineSequence.find(separator, start);
    }

    return this->generateLines(nbBoxes, lineSequenceUInt);
}