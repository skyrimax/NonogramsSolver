#include "NonogramLevel.hpp"

#include <utility>

NS::NonogramLevel::NonogramLevel(const std::vector<Sequence>& rows, const std::vector<Sequence>& cols)
    : rows_(rows), cols_(cols)
{
}

NS::NonogramLevel::NonogramLevel(const NS::NonogramLevel &nonogramLevel)
    : rows_(nonogramLevel.rows_), cols_(nonogramLevel.cols_)
{
}

NS::NonogramLevel::NonogramLevel(NS::NonogramLevel &&nonogramLevel)
    : rows_(std::move(nonogramLevel.rows_)), cols_(std::move(nonogramLevel.cols_))
{
}