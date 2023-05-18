#include <gtest/gtest.h>

#include <grid.hpp>

#include <vector>
#include <utility>

TEST(GridExtractRowTest, ContainsCorrectValues)
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

TEST(GridExtractConstRowTest, ContainsCorrectValues)
{
    std::vector<int> sourceVals({1, 2, 3, 4, 5, 6, 7, 8, 9});

    const Grid<int> grid(3, 3, sourceVals);

    auto row0 = grid.row(0);

    std::is_const<const int &>::value;
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(row0[0].get())>::type>::value);
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(row0[1].get())>::type>::value);
    ASSERT_TRUE(std::is_const<std::remove_reference<decltype(row0[2].get())>::type>::value);
}