#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>
#include <utility>

TEST(GridDefaultConstructorTest, IsEmpty)
{
    Grid<int> grid;

    EXPECT_EQ(grid.nbRows(), 0);
    EXPECT_EQ(grid.nbCols(), 0);
    EXPECT_EQ(grid.data().size(), 0);
    EXPECT_TRUE(grid.empty());
}

TEST(GridSizeConstructorTest, CorrectSize)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        for (size_t j = 1; j <= 5; ++j)
        {
            Grid<int> grid(i, j);

            EXPECT_EQ(grid.nbRows(), i);
            EXPECT_EQ(grid.nbCols(), j);
            EXPECT_EQ(grid.data().size(), i * j);
        }
    }
}

TEST(GridSizeConstructorTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid(0, j);

        EXPECT_EQ(grid.nbRows(), 0);
        EXPECT_EQ(grid.nbCols(), j);
        EXPECT_EQ(grid.data().size(), 0);
        EXPECT_TRUE(grid.empty());
    }
}

TEST(GridSizeConstructorTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid(i, 0);

        EXPECT_EQ(grid.nbRows(), i);
        EXPECT_EQ(grid.nbCols(), 0);
        EXPECT_EQ(grid.data().size(), 0);
        EXPECT_TRUE(grid.empty());
    }
}

TEST(GridSizeValueConstructorTest, ContainsCorrectValue)
{
    for (int val = -5; val <= 5; ++val)
    {
        Grid<int> grid(3, 3, val);

        for (size_t i = 0; i < 3; ++i)
        {
            for (size_t j = 0; j < 3; ++j)
            {
                EXPECT_EQ(grid(i, j), val);
            }
        }
    }
}

TEST(GridSizeSourceVectorCopyConstructorTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(0, 2), 3);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(1, 2), 6);
    EXPECT_EQ(grid(2, 0), 7);
    EXPECT_EQ(grid(2, 1), 8);
    EXPECT_EQ(grid(2, 2), 9);

    EXPECT_EQ(sourceVals.size(), 9);
}

TEST(GridSizeSourceVectorCopyConstructorTest, SourceTooSmall)
{
    std::vector<int> sourceVals({1, 2, 3, 4});

    EXPECT_THROW(Grid<int> grid(3, 3, sourceVals), std::invalid_argument);
}

TEST(GridSizeSourceVectorCopyConstructorTest, SourceTooBig)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    EXPECT_THROW(Grid<int> grid(2, 2, sourceVals), std::invalid_argument);
}

TEST(GridSizeSourceVectorMoveConstructorTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, std::move(sourceVals));

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(0, 2), 3);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(1, 2), 6);
    EXPECT_EQ(grid(2, 0), 7);
    EXPECT_EQ(grid(2, 1), 8);
    EXPECT_EQ(grid(2, 2), 9);

    EXPECT_EQ(sourceVals.size(), 0);
}

TEST(GridSizeSourceVectorMoveConstructorTest, SourceTooSmall)
{
    std::vector<int> sourceVals({1, 2, 3, 4});

    EXPECT_THROW(Grid<int> grid(3, 3, std::move(sourceVals)), std::invalid_argument);
}

TEST(GridSizeSourceVectorMoveConstructorTest, SourceTooBig)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    EXPECT_THROW(Grid<int> grid(2, 2, std::move(sourceVals)), std::invalid_argument);
}

TEST(GridCopyConstructorTest, HandleEmpty)
{
    Grid<int> grid1;

    Grid<int> grid2(grid1);

    EXPECT_EQ(grid2.nbRows(), 0);
    EXPECT_EQ(grid2.nbCols(), 0);
    EXPECT_EQ(grid2.data().size(), 0);
    EXPECT_TRUE(grid2.empty());
}

TEST(GridCopyConstructorTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid1(0, j);
        Grid<int> grid2(grid1);

        EXPECT_EQ(grid2.nbRows(), 0);
        EXPECT_EQ(grid2.nbCols(), j);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());
    }
}

TEST(GridCopyConstructorTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid1(i, 0);
        Grid<int> grid2(grid1);

        EXPECT_EQ(grid2.nbRows(), i);
        EXPECT_EQ(grid2.nbCols(), 0);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());
    }
}

TEST(GridCopyConstructorTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid1(3, 3, sourceVals);
    Grid<int> grid2(grid1);

    EXPECT_EQ(grid2(0, 0), 1);
    EXPECT_EQ(grid2(0, 1), 2);
    EXPECT_EQ(grid2(0, 2), 3);
    EXPECT_EQ(grid2(1, 0), 4);
    EXPECT_EQ(grid2(1, 1), 5);
    EXPECT_EQ(grid2(1, 2), 6);
    EXPECT_EQ(grid2(2, 0), 7);
    EXPECT_EQ(grid2(2, 1), 8);
    EXPECT_EQ(grid2(2, 2), 9);
}

TEST(GridMoveConstructorTest, HandleEmpty)
{
    Grid<int> grid1;

    Grid<int> grid2(std::move(grid1));

    EXPECT_EQ(grid2.nbRows(), 0);
    EXPECT_EQ(grid2.nbCols(), 0);
    EXPECT_EQ(grid2.data().size(), 0);
    EXPECT_TRUE(grid2.empty());

    EXPECT_EQ(grid1.nbRows(), 0);
    EXPECT_EQ(grid1.nbCols(), 0);
    EXPECT_EQ(grid1.data().size(), 0);
    EXPECT_TRUE(grid1.empty());
}

TEST(GridMoveConstructorTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid1(0, j);
        Grid<int> grid2(std::move(grid1));

        EXPECT_EQ(grid2.nbRows(), 0);
        EXPECT_EQ(grid2.nbCols(), j);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());

        EXPECT_EQ(grid1.nbRows(), 0);
        EXPECT_EQ(grid1.nbCols(), 0);
        EXPECT_EQ(grid1.data().size(), 0);
        EXPECT_TRUE(grid1.empty());
    }
}

TEST(GridMoveConstructorTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid1(i, 0);
        Grid<int> grid2(std::move(grid1));

        EXPECT_EQ(grid2.nbRows(), i);
        EXPECT_EQ(grid2.nbCols(), 0);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());

        EXPECT_EQ(grid1.nbRows(), 0);
        EXPECT_EQ(grid1.nbCols(), 0);
        EXPECT_EQ(grid1.data().size(), 0);
        EXPECT_TRUE(grid1.empty());
    }
}

TEST(GridMoveConstructorTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid1(3, 3, sourceVals);
    Grid<int> grid2(std::move(grid1));

    EXPECT_EQ(grid2(0, 0), 1);
    EXPECT_EQ(grid2(0, 1), 2);
    EXPECT_EQ(grid2(0, 2), 3);
    EXPECT_EQ(grid2(1, 0), 4);
    EXPECT_EQ(grid2(1, 1), 5);
    EXPECT_EQ(grid2(1, 2), 6);
    EXPECT_EQ(grid2(2, 0), 7);
    EXPECT_EQ(grid2(2, 1), 8);
    EXPECT_EQ(grid2(2, 2), 9);

    EXPECT_EQ(grid1.nbRows(), 0);
    EXPECT_EQ(grid1.nbCols(), 0);
    EXPECT_EQ(grid1.data().size(), 0);
    EXPECT_TRUE(grid1.empty());
}