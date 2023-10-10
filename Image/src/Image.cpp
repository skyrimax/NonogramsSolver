#include "Image.hpp"

#include <algorithm>

NS::Image::Image()
    : Grid<Square>()
{
}

NS::Image::Image(size_type nbRows, size_type nbCols)
    : Grid<Square>(nbRows, nbCols)
{
}

NS::Image::Image(const Image &image)
    : Grid<Square>(image)
{
}

NS::Image::Image(Image &&image)
    : Grid<Square>(std::move(image))
{
}

bool NS::Image::completed() const
{
    return !std::count(data().begin(), data().end(), -1);
}