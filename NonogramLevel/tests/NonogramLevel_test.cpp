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
    std::vector<NS::Sequence> rowSequences;
    std::vector<NS::Sequence> colSequences;

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_TRUE(nonogramLevel.rowSequences().empty());
    EXPECT_TRUE(nonogramLevel.colSequences().empty());
}

TEST(NonogramLevelFullConstructor, HandleNoRow)
{
    std::vector<NS::Sequence> rowSequences;

    std::vector<NS::Sequence> colSequences({
        NS::Sequence({2}),
        NS::Sequence({4}),
        NS::Sequence({4}),
        NS::Sequence({4}),
        NS::Sequence({2}),
    });

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_TRUE(nonogramLevel.rowSequences().empty());
    EXPECT_EQ(nonogramLevel.colSequences().size(), 5);
}

TEST(NonogramLevelFullConstructor, HandleNoColumn)
{
    std::vector<NS::Sequence> rowSequences({
        NS::Sequence({1, 1}),
        NS::Sequence({5}),
        NS::Sequence({5}),
        NS::Sequence({3}),
        NS::Sequence({1}),
    });
    
    std::vector<NS::Sequence> colSequences;

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_EQ(nonogramLevel.rowSequences().size(), 5);
    EXPECT_TRUE(nonogramLevel.colSequences().empty());
}

TEST(NonogramLevelFullConstructor, CorrectValues)
{
    std::vector<NS::Sequence> rowSequences({
        NS::Sequence({1, 1}),
        NS::Sequence({5}),
        NS::Sequence({5}),
        NS::Sequence({3}),
        NS::Sequence({1}),
    });
    
    std::vector<NS::Sequence> colSequences({
        NS::Sequence({2}),
        NS::Sequence({4}),
        NS::Sequence({4}),
        NS::Sequence({4}),
        NS::Sequence({2}),
    });

    NS::NonogramLevel nonogramLevel(rowSequences, colSequences);

    EXPECT_EQ(nonogramLevel.rowSequences(), rowSequences);
    EXPECT_EQ(nonogramLevel.colSequences(), colSequences);
}