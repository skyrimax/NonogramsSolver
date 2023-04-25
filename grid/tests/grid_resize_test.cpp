#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>

TEST(GridResizeTest, resizeSmaller)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(2, 2);

    EXPECT_EQ(grid.nbRows(), 2);
    EXPECT_EQ(grid.nbCols(), 2);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
}

TEST(GridResizeTest, resizeMoreColsLessRows)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(2, 4);

    EXPECT_EQ(grid.nbRows(), 2);
    EXPECT_EQ(grid.nbCols(), 4);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(0, 2), 3);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(1, 2), 6);
}

TEST(GridResizeTest, resizeLessColsMoreRows)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(4, 2);

    EXPECT_EQ(grid.nbRows(), 4);
    EXPECT_EQ(grid.nbCols(), 2);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(2, 0), 7);
    EXPECT_EQ(grid(2, 1), 8);
}

TEST(GridResizeTest, resizeBigger)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(4, 4);
    
    EXPECT_EQ(grid.nbRows(), 4);
    EXPECT_EQ(grid.nbCols(), 4);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(0, 2), 3);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(1, 2), 6);
    EXPECT_EQ(grid(2, 0), 7);
    EXPECT_EQ(grid(2, 1), 8);
    EXPECT_EQ(grid(2, 2), 9);
}

TEST(GridResizeWithValueTest, resizeSmaller)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(2, 2, -1);

    EXPECT_EQ(grid.nbRows(), 2);
    EXPECT_EQ(grid.nbCols(), 2);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
}

TEST(GridResizeWithValueTest, resizeMoreColsLessRows)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(2, 4, -1);

    EXPECT_EQ(grid.nbRows(), 2);
    EXPECT_EQ(grid.nbCols(), 4);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(0, 2), 3);
    EXPECT_EQ(grid(0, 3), -1);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(1, 2), 6);
    EXPECT_EQ(grid(1, 3), -1);
}

TEST(GridResizeWithValueTest, resizeLessColsMoreRows)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(4, 2, -1);

    EXPECT_EQ(grid.nbRows(), 4);
    EXPECT_EQ(grid.nbCols(), 2);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(2, 0), 7);
    EXPECT_EQ(grid(2, 1), 8);
    EXPECT_EQ(grid(3, 0), -1);
    EXPECT_EQ(grid(3, 1), -1);
}

TEST(GridResizeWithValueTest, resizeBigger)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    grid.resize(4, 4, -1);
    
    EXPECT_EQ(grid.nbRows(), 4);
    EXPECT_EQ(grid.nbCols(), 4);

    EXPECT_EQ(grid(0, 0), 1);
    EXPECT_EQ(grid(0, 1), 2);
    EXPECT_EQ(grid(0, 2), 3);
    EXPECT_EQ(grid(0, 3), -1);
    EXPECT_EQ(grid(1, 0), 4);
    EXPECT_EQ(grid(1, 1), 5);
    EXPECT_EQ(grid(1, 2), 6);
    EXPECT_EQ(grid(1, 3), -1);
    EXPECT_EQ(grid(2, 0), 7);
    EXPECT_EQ(grid(2, 1), 8);
    EXPECT_EQ(grid(2, 2), 9);
    EXPECT_EQ(grid(2, 3), -1);
    EXPECT_EQ(grid(3, 0), -1);
    EXPECT_EQ(grid(3, 1), -1);
    EXPECT_EQ(grid(3, 2), -1);
    EXPECT_EQ(grid(3, 3), -1);
}