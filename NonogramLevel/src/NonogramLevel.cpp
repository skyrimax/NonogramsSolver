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

NS::Sequence& NS::NonogramLevel::rowSequence(size_type row)
{
    return rowSequences_.at(row);
}

const NS::Sequence& NS::NonogramLevel::rowSequence(size_type row) const
{
    return rowSequences_.at(row);
}

std::vector<NS::Sequence>& NS::NonogramLevel::rowSequences()
{
    return rowSequences_;
}

const std::vector<NS::Sequence>& NS::NonogramLevel::rowSequences() const
{
    return rowSequences_;
}

NS::Sequence& NS::NonogramLevel::colSequence(size_type col)
{
    return colSequences_.at(col);
}

const NS::Sequence& NS::NonogramLevel::colSequence(size_type col) const
{
    return colSequences_.at(col);
}

std::vector<NS::Sequence>& NS::NonogramLevel::colSequences()
{
    return colSequences_;
}

const std::vector<NS::Sequence>& NS::NonogramLevel::colSequences() const
{
    return colSequences_;
}

void NS::NonogramLevel::addRowSequence(const NS::Sequence& rowSequence)
{
    rowSequences_.push_back(rowSequence);
}

void NS::NonogramLevel::addRowSequence(Sequence&& rosSequence)
{
    rowSequences_.push_back(std::move(rosSequence));
}

void NS::NonogramLevel::addRowSequences(const std::vector<NS::Sequence>& rowSequences)
{
    rowSequences_.insert(rowSequences_.end(), rowSequences.begin(), rowSequences.end());
}

void NS::NonogramLevel::addRowSequences(std::vector<NS::Sequence>&& rowSequences)
{
    rowSequences_.insert(rowSequences_.end(),
        std::make_move_iterator(rowSequences.begin()), std::make_move_iterator(rowSequences.end()));
}

void NS::NonogramLevel::addColSequence(const NS::Sequence& colSequence)
{
    colSequences_.push_back(colSequence);
}

void NS::NonogramLevel::addColSequence(Sequence&& rosSequence)
{
    rowSequences_.push_back(std::move(rosSequence));
}

void NS::NonogramLevel::addColSequences(const std::vector<NS::Sequence>& colSequences)
{
    colSequences_.insert(colSequences_.end(), colSequences.begin(), colSequences.end());
}

void NS::NonogramLevel::addColSequences(std::vector<NS::Sequence>&& colSequences)
{
    colSequences_.insert(colSequences_.end(),
        std::make_move_iterator(colSequences.begin()), std::make_move_iterator(colSequences.end()));
}
