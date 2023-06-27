#include <gtest/gtest.h>

#include <NonogramLevel.hpp>

#include <utility>

TEST(NonogramLevelDefaultConstructor, isEmpty)
{
    NS::NonogramLevel nonogramLevel;

    EXPECT_TRUE(nonogramLevel.rowSequences().empty());
    EXPECT_TRUE(nonogramLevel.colSequences().empty());
}

TEST(NonogramLevelFullConstructor, HandleEmpty)
{
    std::vector<NS::NonogramLevel::Sequence> rowSequences;
    std::vector<NS::NonogramLevel::Sequence> colSequences;

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_TRUE(nonogramLevel.rowSequences().empty());
    EXPECT_TRUE(nonogramLevel.colSequences().empty());
}

TEST(NonogramLevelFullConstructor, HandleNoRow)
{
    std::vector<NS::NonogramLevel::Sequence> rowSequences;

    std::vector<NS::NonogramLevel::Sequence> colSequences({
        NS::NonogramLevel::Sequence({2}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({2}),
    });

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_TRUE(nonogramLevel.rowSequences().empty());
    EXPECT_EQ(nonogramLevel.colSequences().size(), 5);
}

TEST(NonogramLevelFullConstructor, HandleNoColumn)
{
    std::vector<NS::NonogramLevel::Sequence> rowSequences({
        NS::NonogramLevel::Sequence({1, 1}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({3}),
        NS::NonogramLevel::Sequence({1}),
    });
    
    std::vector<NS::NonogramLevel::Sequence> colSequences;

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_EQ(nonogramLevel.rowSequences().size(), 5);
    EXPECT_TRUE(nonogramLevel.colSequences().empty());
}

TEST(NonogramLevelFullConstructor, CorrectValues)
{
    std::vector<NS::NonogramLevel::Sequence> rowSequences({
        NS::NonogramLevel::Sequence({1, 1}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({5}),
        NS::NonogramLevel::Sequence({3}),
        NS::NonogramLevel::Sequence({1}),
    });
    
    std::vector<NS::NonogramLevel::Sequence> colSequences({
        NS::NonogramLevel::Sequence({2}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({4}),
        NS::NonogramLevel::Sequence({2}),
    });

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_EQ(nonogramLevel.rowSequences(), rowSequences);
    EXPECT_EQ(nonogramLevel.colSequences(), colSequences);
}