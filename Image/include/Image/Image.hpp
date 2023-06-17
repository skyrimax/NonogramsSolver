#ifndef IMAGE_H
#define IMAGE_H

#include <grid.hpp>

namespace NS
{
    class Image: public Grid<int>
    {
    public:
        Image();

        Image(size_type nbRows, size_type nbCols);

        Image(const Image &image);

        Image(Image &&image);
    };
}


#endif /* IMAGE_H */