#ifndef IMAGE_H
#define IMAGE_H

namespace NS
{
    class NonogramLevel
    {
    public:
        NonogramLevel();

        NonogramLevel(Sequence rows, Sequence cols);

        NonogramLevel(const NonogramLevel &nonogramLevel);

        NonogramLevel(NonogramLevel &&nonogramLevel);
    };
}

#endif /* IMAGE_H */