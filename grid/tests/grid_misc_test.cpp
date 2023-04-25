#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>

TEST(GridAssignTest, assignEmpty)
{
    Grid<int> grid1;

    grid1.assign(0, 0, -1);

    EXPECT_EQ(grid1.nbRows(), 0);
    EXPECT_EQ(grid1.nbCols(), 0);
    EXPECT_EQ(grid1.data().size(), 0);
    EXPECT_TRUE(grid1.empty());

    Grid<int> grid2(3, 3);

    grid2.assign(0, 0, -1);

    EXPECT_EQ(grid2.nbRows(), 0);
    EXPECT_EQ(grid2.nbCols(), 0);
    EXPECT_EQ(grid2.data().size(), 0);
    EXPECT_TRUE(grid2.empty());
}

TEST(GridAssignTest, assignNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid1;

        grid1.assign(0, j, -1);

        EXPECT_EQ(grid1.nbRows(), 0);
        EXPECT_EQ(grid1.nbCols(), j);
        EXPECT_EQ(grid1.data().size(), 0);
        EXPECT_TRUE(grid1.empty());

        Grid<int> grid2(3, 3, 1);

        grid2.assign(0, j, -1);

        EXPECT_EQ(grid2.nbRows(), 0);
        EXPECT_EQ(grid2.nbCols(), j);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());
    }
}

TEST(GridAssignTest, assignNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid1;

        grid1.assign(i, 0, -1);

        EXPECT_EQ(grid1.nbRows(), i);
        EXPECT_EQ(grid1.nbCols(), 0);
        EXPECT_EQ(grid1.data().size(), 0);
        EXPECT_TRUE(grid1.empty());

        Grid<int> grid2(3, 3, 1);

        grid2.assign(i, 0, -1);

        EXPECT_EQ(grid2.nbRows(), i);
        EXPECT_EQ(grid2.nbCols(), 0);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());
    }
}

TEST(GridAssignTest, assignSmaller)
{
    Grid<int> grid(3, 3, 1);

    grid.assign(2, 2, -1);

    EXPECT_EQ(grid.nbRows(), 2);
    EXPECT_EQ(grid.nbCols(), 2);

    EXPECT_EQ(grid(0, 0), -1);
    EXPECT_EQ(grid(0, 1), -1);
    EXPECT_EQ(grid(1, 0), -1);
    EXPECT_EQ(grid(1, 1), -1);
}

TEST(GridAssignTest, assignMoreColsLessRows)
{
    Grid<int> grid(3, 3, 1);

    grid.assign(2, 4, -1);

    EXPECT_EQ(grid.nbRows(), 2);
    EXPECT_EQ(grid.nbCols(), 4);

    EXPECT_EQ(grid(0, 0), -1);
    EXPECT_EQ(grid(0, 1), -1);
    EXPECT_EQ(grid(0, 2), -1);
    EXPECT_EQ(grid(1, 0), -1);
    EXPECT_EQ(grid(1, 1), -1);
    EXPECT_EQ(grid(1, 2), -1);
}

TEST(GridAssignTest, assignLessColsMoreRows)
{
    Grid<int> grid(3, 3, 1);

    grid.assign(4, 2, -1);

    EXPECT_EQ(grid.nbRows(), 4);
    EXPECT_EQ(grid.nbCols(), 2);

    EXPECT_EQ(grid(0, 0), -1);
    EXPECT_EQ(grid(0, 1), -1);
    EXPECT_EQ(grid(1, 0), -1);
    EXPECT_EQ(grid(1, 1), -1);
    EXPECT_EQ(grid(2, 0), -1);
    EXPECT_EQ(grid(2, 1), -1);
}

TEST(GridAssignTest, assignBigger)
{
    Grid<int> grid(3, 3, 1);

    grid.assign(4, 4, -1);
    
    EXPECT_EQ(grid.nbRows(), 4);
    EXPECT_EQ(grid.nbCols(), 4);

    EXPECT_EQ(grid(0, 0), -1);
    EXPECT_EQ(grid(0, 1), -1);
    EXPECT_EQ(grid(0, 2), -1);
    EXPECT_EQ(grid(1, 0), -1);
    EXPECT_EQ(grid(1, 1), -1);
    EXPECT_EQ(grid(1, 2), -1);
    EXPECT_EQ(grid(2, 0), -1);
    EXPECT_EQ(grid(2, 1), -1);
    EXPECT_EQ(grid(2, 2), -1);
}

TEST(GridSwapTest, swapInEmpty)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid1;

    Grid<int> grid2(3, 3, sourceVals);

    grid1.swap(grid2);

    EXPECT_EQ(grid2.nbRows(), 0);
    EXPECT_EQ(grid2.nbCols(), 0);
    EXPECT_EQ(grid2.data().size(), 0);
    EXPECT_TRUE(grid2.empty());

    EXPECT_EQ(grid1(0, 0), 1);
    EXPECT_EQ(grid1(0, 1), 2);
    EXPECT_EQ(grid1(0, 2), 3);
    EXPECT_EQ(grid1(1, 0), 4);
    EXPECT_EQ(grid1(1, 1), 5);
    EXPECT_EQ(grid1(1, 2), 6);
    EXPECT_EQ(grid1(2, 0), 7);
    EXPECT_EQ(grid1(2, 1), 8);
    EXPECT_EQ(grid1(2, 2), 9);
}

TEST(GridSwapTest, swapWithEmpty)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid1(3, 3, sourceVals);

    Grid<int> grid2;

    grid1.swap(grid2);

    EXPECT_EQ(grid1.nbRows(), 0);
    EXPECT_EQ(grid1.nbCols(), 0);
    EXPECT_EQ(grid1.data().size(), 0);
    EXPECT_TRUE(grid1.empty());

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

TEST(GridSwapTest, swapSmallAndLarge)
{
    std::vector<int> sourceVals1({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::vector<int> sourceVals2({11, 22, 33, 44});

    Grid<int> grid1(3, 3, sourceVals1);
    Grid<int> grid2(2, 2, sourceVals2);

    grid1.swap(grid2);

    EXPECT_EQ(grid2(0, 0), 1);
    EXPECT_EQ(grid2(0, 1), 2);
    EXPECT_EQ(grid2(0, 2), 3);
    EXPECT_EQ(grid2(1, 0), 4);
    EXPECT_EQ(grid2(1, 1), 5);
    EXPECT_EQ(grid2(1, 2), 6);
    EXPECT_EQ(grid2(2, 0), 7);
    EXPECT_EQ(grid2(2, 1), 8);
    EXPECT_EQ(grid2(2, 2), 9);

    EXPECT_EQ(grid1(0, 0), 11);
    EXPECT_EQ(grid1(0, 1), 22);
    EXPECT_EQ(grid1(0, 2), 33);
    EXPECT_EQ(grid1(1, 0), 44);
}

TEST(GridClearTest, clearEmpty)
{
    Grid<int> grid;

    grid.clear();

    EXPECT_EQ(grid.nbRows(), 0);
    EXPECT_EQ(grid.nbCols(), 0);
    EXPECT_EQ(grid.data().size(), 0);
    EXPECT_TRUE(grid.empty());
}

TEST(GridClearTest, clearNoRow)
{
    Grid<int> grid(0, 3, 1);

    grid.clear();

    EXPECT_EQ(grid.nbRows(), 0);
    EXPECT_EQ(grid.nbCols(), 0);
    EXPECT_EQ(grid.data().size(), 0);
    EXPECT_TRUE(grid.empty());
}

TEST(GridClearTest, clearNoColumn)
{
    Grid<int> grid(3, 0, 1);

    grid.clear();

    EXPECT_EQ(grid.nbRows(), 0);
    EXPECT_EQ(grid.nbCols(), 0);
    EXPECT_EQ(grid.data().size(), 0);
    EXPECT_TRUE(grid.empty());
}

TEST(GridClearTest, clearGrid)
{
    Grid<int> grid(3, 3, 1);

    grid.clear();

    EXPECT_EQ(grid.nbRows(), 0);
    EXPECT_EQ(grid.nbCols(), 0);
    EXPECT_EQ(grid.data().size(), 0);
    EXPECT_TRUE(grid.empty());
}