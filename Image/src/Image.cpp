#include "Image.hpp"

#include <algorithm>

NS::Image::Image()
    : Grid<int>()
{
}

NS::Image::Image(size_type nbRows, size_type nbCols)
    : Grid<int>(nbRows, nbCols)
{
}

NS::Image::Image(const Image &image)
    : Grid<int>(image)
{
}

NS::Image::Image(Image &&image)
    : Grid<int>(std::move(image))
{
}

bool NS::Image::completed() const
{
    return !std::count(data().begin(), data().end(), -1);
}