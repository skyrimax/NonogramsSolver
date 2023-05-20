#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>
#include <utility>

TEST(GridExtractRowTest, HandleEmpty)
{
    Grid<int> grid;

    auto row0 = grid.row(0);

    EXPECT_EQ(row0.size(), 0);
    EXPECT_TRUE(row0.empty());
}

TEST(GridExtractRowTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid(0, j);

        EXPECT_THROW(grid.row(0), std::out_of_range);
    }
}

TEST(GridExtractRowTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid(i, 0);

        auto row0 = grid.row(0);

        EXPECT_EQ(row0.size(), 0);
        EXPECT_TRUE(row0.empty());
    }
}

TEST(GridExtractRowTest, accessOutsideRangeRows)
{
    Grid<int> grid(3, 3, 1);

    EXPECT_THROW(grid.row(3), std::out_of_range);
}

TEST(GridExtractRowTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    auto row0 = grid.row(0);

    EXPECT_EQ(row0[0], 1);
    EXPECT_EQ(row0[1], 2);
    EXPECT_EQ(row0[2], 3);
}

TEST(GridExtractRowTest, ValuesModifiable)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    auto row0 = grid.row(0);

    row0[0].get() = 10;
    row0[1].get() = 20;
    row0[2].get() = 30;

    ASSERT_EQ(grid(0, 0), 10);
    ASSERT_EQ(grid(0, 1), 20);
    ASSERT_EQ(grid(0, 2), 30);
}

TEST(GridExtractConstRowTest, HandleEmpty)
{
    const Grid<int> grid;

    auto row0 = grid.row(0);

    EXPECT_EQ(row0.size(), 0);
    EXPECT_TRUE(row0.empty());
}

TEST(GridExtractConstRowTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        const Grid<int> grid(0, j);

        EXPECT_THROW(grid.row(0), std::out_of_range);
    }
}

TEST(GridExtractConstRowTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        const Grid<int> grid(i, 0);

        auto row0 = grid.row(0);

        EXPECT_EQ(row0.size(), 0);
        EXPECT_TRUE(row0.empty());
    }
}

TEST(GridExtractConstRowTest, accessOutsideRangeRows)
{
    const Grid<int> grid(3, 3, 1);

    EXPECT_THROW(grid.row(3), std::out_of_range);
}

TEST(GridExtractConstRowTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    const Grid<int> grid(3, 3, sourceVals);

    auto row0 = grid.row(0);

    EXPECT_EQ(row0[0], 1);
    EXPECT_EQ(row0[1], 2);
    EXPECT_EQ(row0[2], 3);
}

TEST(GridExtractConstRowTest, ValuesNonModifiable)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    const Grid<int> grid(3, 3, sourceVals);

    auto row0 = grid.row(0);

    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(row0[0].get())>::type>::value);
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(row0[1].get())>::type>::value);
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(row0[2].get())>::type>::value);
}

TEST(GridExtractColTest, HandleEmpty)
{
    Grid<int> grid;

    auto col0 = grid.col(0);

    EXPECT_EQ(col0.size(), 0);
    EXPECT_TRUE(col0.empty());
}

TEST(GridExtractColTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        Grid<int> grid(i, 0);

        EXPECT_THROW(grid.col(0), std::out_of_range);
    }
}

TEST(GridExtractColTest, HandleNoColRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        Grid<int> grid(0, j);

        auto col0 = grid.col(0);

        EXPECT_EQ(col0.size(), 0);
        EXPECT_TRUE(col0.empty());
    }
}

TEST(GridExtractColTest, accessOutsideRangeColumns)
{
    Grid<int> grid(3, 3, 1);

    EXPECT_THROW(grid.col(3), std::out_of_range);
}

TEST(GridExtractColTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    auto col0 = grid.col(0);

    EXPECT_EQ(col0[0], 1);
    EXPECT_EQ(col0[1], 4);
    EXPECT_EQ(col0[2], 7);
}

TEST(GridExtractColTest, ValuesModifiable)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    Grid<int> grid(3, 3, sourceVals);

    auto col0 = grid.col(0);

    col0[0].get() = 10;
    col0[1].get() = 40;
    col0[2].get() = 70;

    ASSERT_EQ(grid(0, 0), 10);
    ASSERT_EQ(grid(1, 0), 40);
    ASSERT_EQ(grid(2, 0), 70);
}

TEST(GridExtractConstColTest, HandleEmpty)
{
    const Grid<int> grid;

    auto col0 = grid.col(0);

    EXPECT_EQ(col0.size(), 0);
    EXPECT_TRUE(col0.empty());
}

TEST(GridExtractConstColTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        const Grid<int> grid(i, 0);

        EXPECT_THROW(grid.col(0), std::out_of_range);
    }
}

TEST(GridExtractConstColTest, HandleNoColRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        const Grid<int> grid(0, j);

        auto col0 = grid.col(0);

        EXPECT_EQ(col0.size(), 0);
        EXPECT_TRUE(col0.empty());
    }
}

TEST(GridExtractConstColTest, accessOutsideRangeColumns)
{
    const Grid<int> grid(3, 3, 1);

    EXPECT_THROW(grid.col(3), std::out_of_range);
}

TEST(GridExtractConstColTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    const Grid<int> grid(3, 3, sourceVals);

    auto col0 = grid.col(0);

    EXPECT_EQ(col0[0], 1);
    EXPECT_EQ(col0[1], 4);
    EXPECT_EQ(col0[2], 7);
}

TEST(GridExtractConstColTest, ValuesNonModifiable)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    const Grid<int> grid(3, 3, sourceVals);

    auto col0 = grid.col(0);

    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(col0[0].get())>::type>::value);
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(col0[1].get())>::type>::value);
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(col0[2].get())>::type>::value);
}