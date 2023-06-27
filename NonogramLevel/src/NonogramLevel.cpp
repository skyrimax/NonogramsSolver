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

std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::rows()
{
    return rows_;
}

const std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::rows() const
{
    return rows_;
}

std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::cols()
{
    return cols_;
}

const std::vector<NS::NonogramLevel::Sequence>& NS::NonogramLevel::cols() const
{
    return cols_;
}