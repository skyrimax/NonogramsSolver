#include "FSTLineSequencer.hpp"

#include <stdexcept>
#include <sstream>

NS::Sequence FSTLineSequencer::operator()(Line line) const
{
    // Current state, represent the last value read from the line
    unsigned int state = 0;

    // index of group, used to increment number of tiles in said group
    unsigned int groupIndex = 0;

    NS::Sequence seq;
    
    for(const auto& tile : line) {
        switch (state)
        {
        case 0:
            if(tile == 1) {
                seq.resize(seq.size()+1);
                ++(seq.back());
            }
            break;

        case 1:
            if(tile == 1) {
                ++(seq.back());
            }
            break;
        default:
            std::stringstream what;
            what << "State is not valid : " << tile;
            throw std::logic_error(what.str());
            break;
        }

        state = tile;
    }

    return seq;
}
