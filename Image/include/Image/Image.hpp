#ifndef IMAGE_H
#define IMAGE_H

#include <grid.hpp>
#include <Square.hpp>

namespace NS
{
    class Image: public Grid<Square>
    {
    public:
        Image();

        Image(size_type nbRows, size_type nbCols);

        Image(const Image &image);

        Image(Image &&image);

        bool completed() const;
    };
}

#endif /* IMAGE_H */