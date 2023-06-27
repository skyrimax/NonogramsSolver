#include <gtest/gtest.h>

#include <NonogramLevel.hpp>

#include <utility>

TEST(NonogramLevelDefaultConstructor, isEmpty)
{
    NS::NonogramLevel nonogramLevel;

    EXPECT_TRUE(nonogramLevel.rows().empty());
    EXPECT_TRUE(nonogramLevel.cols().empty());
}

TEST(NonogramLevelFullConstructor, HandleEmpty)
{
    std::vector<NS::NonogramLevel::Sequence> rows;
    std::vector<NS::NonogramLevel::Sequence> cols;

    NS::NonogramLevel nonogramLevel(rows, cols);

    EXPECT_TRUE(nonogramLevel.rows().empty());
    EXPECT_TRUE(nonogramLevel.cols().empty());
}

TEST(NonogramLevelFullConstructor, HandleNoRow)
{
    std::vector<NS::NonogramLevel::Sequence> rows;

    std::vector<NS::NonogramLevel::Sequence> cols({
        NS::NonogramLevel::Sequence({2}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({2}),
    });

    NS::NonogramLevel nonogramLevel(rows, cols);

    EXPECT_TRUE(nonogramLevel.rows().empty());
    EXPECT_EQ(nonogramLevel.cols().size(), 5);
}

TEST(NonogramLevelFullConstructor, HandleNoColumn)
{
    std::vector<NS::NonogramLevel::Sequence> rows({
        NS::NonogramLevel::Sequence({1, 1}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({3}),
        NS::NonogramLevel::Sequence({1}),
    });
    
    std::vector<NS::NonogramLevel::Sequence> cols;

    NS::NonogramLevel nonogramLevel(rows, cols);

    EXPECT_EQ(nonogramLevel.rows().size(), 5);
    EXPECT_TRUE(nonogramLevel.cols().empty());
}

TEST(NonogramLevelFullConstructor, CorrectValues)
{
    std::vector<NS::NonogramLevel::Sequence> rows({
        NS::NonogramLevel::Sequence({1, 1}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({3}),
        NS::NonogramLevel::Sequence({1}),
    });
    
    std::vector<NS::NonogramLevel::Sequence> cols({
        NS::NonogramLevel::Sequence({2}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({2}),
    });

    NS::NonogramLevel nonogramLevel(rows, cols);

    EXPECT_EQ(nonogramLevel.rows(), rows);
    EXPECT_EQ(nonogramLevel.cols(), cols);
}