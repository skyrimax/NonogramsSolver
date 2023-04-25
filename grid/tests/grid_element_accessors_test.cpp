#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>

TEST(GridElementAccessorTest, readRowOriented)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    EXPECT_EQ(grid(0, 0), sourceVals[0]);
    EXPECT_EQ(grid(0, 1), sourceVals[1]);
    EXPECT_EQ(grid(0, 2), sourceVals[2]);
    EXPECT_EQ(grid(1, 0), sourceVals[3]);
    EXPECT_EQ(grid(1, 1), sourceVals[4]);
    EXPECT_EQ(grid(1, 2), sourceVals[5]);
    EXPECT_EQ(grid(2, 0), sourceVals[6]);
    EXPECT_EQ(grid(2, 1), sourceVals[7]);
    EXPECT_EQ(grid(2, 2), sourceVals[8]);
}

TEST(GridElementAccessorTest, writeRowOriented)
{
    Grid<int> grid(3, 3);

    grid(0, 0) = 1;
    grid(0, 1) = 2;
    grid(0, 2) = 3;
    grid(1, 0) = 4;
    grid(1, 1) = 5;
    grid(1, 2) = 6;
    grid(2, 0) = 7;
    grid(2, 1) = 8;
    grid(2, 2) = 9;

    const std::vector<int>& vec = grid.data();

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
    EXPECT_EQ(vec[4], 5);
    EXPECT_EQ(vec[5], 6);
    EXPECT_EQ(vec[6], 7);
    EXPECT_EQ(vec[7], 8);
    EXPECT_EQ(vec[8], 9);
}

TEST(GridAtElementAccessorTest, readRowOriented)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    EXPECT_EQ(grid.at(0, 0), sourceVals[0]);
    EXPECT_EQ(grid.at(0, 1), sourceVals[1]);
    EXPECT_EQ(grid.at(0, 2), sourceVals[2]);
    EXPECT_EQ(grid.at(1, 0), sourceVals[3]);
    EXPECT_EQ(grid.at(1, 1), sourceVals[4]);
    EXPECT_EQ(grid.at(1, 2), sourceVals[5]);
    EXPECT_EQ(grid.at(2, 0), sourceVals[6]);
    EXPECT_EQ(grid.at(2, 1), sourceVals[7]);
    EXPECT_EQ(grid.at(2, 2), sourceVals[8]);
}

TEST(GridAtElementAccessorTest, writeRowOriented)
{
    Grid<int> grid(3, 3);

    grid.at(0, 0) = 1;
    grid.at(0, 1) = 2;
    grid.at(0, 2) = 3;
    grid.at(1, 0) = 4;
    grid.at(1, 1) = 5;
    grid.at(1, 2) = 6;
    grid.at(2, 0) = 7;
    grid.at(2, 1) = 8;
    grid.at(2, 2) = 9;

    const std::vector<int>& vec = grid.data();

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
    EXPECT_EQ(vec[4], 5);
    EXPECT_EQ(vec[5], 6);
    EXPECT_EQ(vec[6], 7);
    EXPECT_EQ(vec[7], 8);
    EXPECT_EQ(vec[8], 9);
}

TEST(GridAtElementAccessorTest, accessOutsideRangeRows)
{
    Grid<int> grid(2, 2);

    EXPECT_THROW(grid.at(2, 0), std::out_of_range);
}

TEST(GridAtElementAccessorTest, accessOutsideRangeColumns)
{
    Grid<int> grid(2, 2);

    EXPECT_THROW(grid.at(0, 2), std::out_of_range);
}