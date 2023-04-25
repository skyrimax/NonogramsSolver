#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>
#include <utility>

TEST(GridAssignmentOperatorCopyTest, HandleEmpty)
{
    Grid<int> grid1;

    Grid<int> grid2;

    grid2 = grid1;

    EXPECT_EQ(grid2.nbRows(), 0);
    EXPECT_EQ(grid2.nbCols(), 0);
    EXPECT_EQ(grid2.data().size(), 0);
    EXPECT_TRUE(grid2.empty());

    Grid<int> grid3(3, 3, 1);

    grid3 = grid1;

    EXPECT_EQ(grid3.nbRows(), 0);
    EXPECT_EQ(grid3.nbCols(), 0);
    EXPECT_EQ(grid3.data().size(), 0);
    EXPECT_TRUE(grid3.empty());
}

TEST(GridAssignmentOperatorCopyTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid1(0, j);
        Grid<int> grid2;

        grid2 = grid1;

        EXPECT_EQ(grid2.nbRows(), 0);
        EXPECT_EQ(grid2.nbCols(), j);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());

        Grid<int> grid3(3, 3, 1);

        grid3 = grid1;

        EXPECT_EQ(grid3.nbRows(), 0);
        EXPECT_EQ(grid3.nbCols(), j);
        EXPECT_EQ(grid3.data().size(), 0);
        EXPECT_TRUE(grid3.empty());
    }
}

TEST(GridAssignmentOperatorCopyTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid1(i, 0);
        Grid<int> grid2;

        grid2 = grid1;

        EXPECT_EQ(grid2.nbRows(), i);
        EXPECT_EQ(grid2.nbCols(), 0);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());

        Grid<int> grid3(3, 3, 1);

        grid3 = grid1;

        EXPECT_EQ(grid3.nbRows(), i);
        EXPECT_EQ(grid3.nbCols(), 0);
        EXPECT_EQ(grid3.data().size(), 0);
        EXPECT_TRUE(grid3.empty());
    }
}

TEST(GridAssignmentOperatorCopyTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals1({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::vector<int> sourceVals3({10, 20, 30, 40});

    Grid<int> grid1(3, 3, sourceVals1);
    Grid<int> grid2;

    grid2 = grid1;

    EXPECT_EQ(grid2(0, 0), 1);
    EXPECT_EQ(grid2(0, 1), 2);
    EXPECT_EQ(grid2(0, 2), 3);
    EXPECT_EQ(grid2(1, 0), 4);
    EXPECT_EQ(grid2(1, 1), 5);
    EXPECT_EQ(grid2(1, 2), 6);
    EXPECT_EQ(grid2(2, 0), 7);
    EXPECT_EQ(grid2(2, 1), 8);
    EXPECT_EQ(grid2(2, 2), 9);

    Grid<int> grid3(2, 2, sourceVals3);

    grid3 = grid1;

    EXPECT_EQ(grid3(0, 0), 1);
    EXPECT_EQ(grid3(0, 1), 2);
    EXPECT_EQ(grid3(0, 2), 3);
    EXPECT_EQ(grid3(1, 0), 4);
    EXPECT_EQ(grid3(1, 1), 5);
    EXPECT_EQ(grid3(1, 2), 6);
    EXPECT_EQ(grid3(2, 0), 7);
    EXPECT_EQ(grid3(2, 1), 8);
    EXPECT_EQ(grid3(2, 2), 9);
}

TEST(GridAssignmentOperatorMoveTest, HandleEmpty)
{
    Grid<int> grid1;

    Grid<int> grid2;

    grid2 = grid1;

    EXPECT_EQ(grid1.nbRows(), 0);
    EXPECT_EQ(grid1.nbCols(), 0);
    EXPECT_EQ(grid1.data().size(), 0);
    EXPECT_TRUE(grid1.empty());

    EXPECT_EQ(grid2.nbRows(), 0);
    EXPECT_EQ(grid2.nbCols(), 0);
    EXPECT_EQ(grid2.data().size(), 0);
    EXPECT_TRUE(grid2.empty());

    Grid<int> grid3;

    Grid<int> grid4(3, 3, 1);

    grid4 = std::move(grid3);

    EXPECT_EQ(grid3.nbRows(), 0);
    EXPECT_EQ(grid3.nbCols(), 0);
    EXPECT_EQ(grid3.data().size(), 0);
    EXPECT_TRUE(grid3.empty());

    EXPECT_EQ(grid4.nbRows(), 0);
    EXPECT_EQ(grid4.nbCols(), 0);
    EXPECT_EQ(grid4.data().size(), 0);
    EXPECT_TRUE(grid4.empty());
}

TEST(GridAssignmentOperatorMoveTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid1(0, j);
        Grid<int> grid2;

        grid2 = std::move(grid1);

        EXPECT_EQ(grid1.nbRows(), 0);
        EXPECT_EQ(grid1.nbCols(), 0);
        EXPECT_EQ(grid1.data().size(), 0);
        EXPECT_TRUE(grid1.empty());

        EXPECT_EQ(grid2.nbRows(), 0);
        EXPECT_EQ(grid2.nbCols(), j);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());

        Grid<int> grid3(0, j);
        Grid<int> grid4 (3, 3, 1);

        grid4 = std::move(grid3);

        EXPECT_EQ(grid3.nbRows(), 0);
        EXPECT_EQ(grid3.nbCols(), 0);
        EXPECT_EQ(grid3.data().size(), 0);
        EXPECT_TRUE(grid3.empty());

        EXPECT_EQ(grid4.nbRows(), 0);
        EXPECT_EQ(grid4.nbCols(), j);
        EXPECT_EQ(grid4.data().size(), 0);
        EXPECT_TRUE(grid4.empty());
    }
}

TEST(GridAssignmentOperatorMoveTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid1(i, 0);
        Grid<int> grid2;

        grid2 = std::move(grid1);

        EXPECT_EQ(grid1.nbRows(), 0);
        EXPECT_EQ(grid1.nbCols(), 0);
        EXPECT_EQ(grid1.data().size(), 0);
        EXPECT_TRUE(grid1.empty());

        EXPECT_EQ(grid2.nbRows(), i);
        EXPECT_EQ(grid2.nbCols(), 0);
        EXPECT_EQ(grid2.data().size(), 0);
        EXPECT_TRUE(grid2.empty());

        Grid<int> grid3(i, 0);
        Grid<int> grid4 (3, 3, 1);

        grid4 = std::move(grid3);

        EXPECT_EQ(grid3.nbRows(), 0);
        EXPECT_EQ(grid3.nbCols(), 0);
        EXPECT_EQ(grid3.data().size(), 0);
        EXPECT_TRUE(grid3.empty());

        EXPECT_EQ(grid4.nbRows(), i);
        EXPECT_EQ(grid4.nbCols(), 0);
        EXPECT_EQ(grid4.data().size(), 0);
        EXPECT_TRUE(grid4.empty());
    }
}

TEST(GridAssignmentOperatorMoveTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals1({1, 2, 3, 4, 5, 6, 7, 8, 9});
    std::vector<int> sourceVals4({10, 20, 30, 40});

    Grid<int> grid1(3, 3, sourceVals1);
    Grid<int> grid2;

    grid2 = std::move(grid1);

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

    Grid<int> grid3(3, 3, sourceVals1);
    Grid<int> grid4(2, 2, sourceVals4);

    grid4 = std::move(grid3);

    EXPECT_EQ(grid3.nbRows(), 0);
    EXPECT_EQ(grid3.nbCols(), 0);
    EXPECT_EQ(grid3.data().size(), 0);
    EXPECT_TRUE(grid3.empty());

    EXPECT_EQ(grid3(0, 0), 1);
    EXPECT_EQ(grid3(0, 1), 2);
    EXPECT_EQ(grid3(0, 2), 3);
    EXPECT_EQ(grid3(1, 0), 4);
    EXPECT_EQ(grid3(1, 1), 5);
    EXPECT_EQ(grid3(1, 2), 6);
    EXPECT_EQ(grid3(2, 0), 7);
    EXPECT_EQ(grid3(2, 1), 8);
    EXPECT_EQ(grid3(2, 2), 9);
}