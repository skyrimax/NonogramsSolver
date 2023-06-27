#include "NonogramLevel.hpp"

#include <utility>
#include <iterator>

NS::NonogramLevel::NonogramLevel(const std::vector<Sequence>& rowSequences, const std::vector<Sequence>& colSequences)
    : rowSequences_(rowSequences), colSequences_(colSequences)
{
}

NS::NonogramLevel::NonogramLevel(const NS::NonogramLevel &nonogramLevel)
    : rowSequences_(nonogramLevel.rowSequences_), colSequences_(nonogramLevel.colSequences_)
{
}

NS::NonogramLevel::NonogramLevel(NS::NonogramLevel &&nonogramLevel)
    : rowSequences_(std::move(nonogramLevel.rowSequences_)), colSequences_(std::move(nonogramLevel.colSequences_))
{
}

std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::rowSequences()
{
    return rowSequences_;
}

const std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::rowSequences() const
{
    return rowSequences_;
}

std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::colSequences()
{
    return colSequences_;
}

const std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::colSequences() const
{
    return colSequences_;
}

void NS::NonogramLevel::addRowSequence(const NS::NonogramLevel::Sequence& rowSequence)
{
    rowSequences_.push_back(rowSequence);
}

void NS::NonogramLevel::addRowSequence(Sequence &&rosSequence)
{
    rowSequences_.push_back(std::move(rosSequence));
}

void NS::NonogramLevel::addRowSequences(const std::vector<NS::NonogramLevel::Sequence>& rowSequences)
{
    rowSequences_.insert(rowSequences_.end(), rowSequences.begin(), rowSequences.end());
}

void NS::NonogramLevel::addRowSequences(std::vector<NS::NonogramLevel::Sequence>&& rowSequences)
{
    rowSequences_.insert(rowSequences_.end(),
        std::make_move_iterator(rowSequences.begin()), std::make_move_iterator(rowSequences.end()));
}
