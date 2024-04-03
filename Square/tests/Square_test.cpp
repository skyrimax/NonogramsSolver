#include <gtest/gtest.h>

#include <Square.hpp>

TEST(SquareTest, Comparisson)
{
    EXPECT_EQ(NS::Square::Empty, NS::DefinedSquare::Empty);
    EXPECT_NE(NS::Square::Empty, NS::DefinedSquare::Filled);

    EXPECT_NE(NS::Square::Filled, NS::DefinedSquare::Empty);
    EXPECT_EQ(NS::Square::Filled, NS::DefinedSquare::Filled);

    EXPECT_NE(NS::Square::Undefined, NS::DefinedSquare::Empty);
    EXPECT_NE(NS::Square::Undefined, NS::DefinedSquare::Filled);
}

TEST(DefinedSquareTest, Comparisson)
{
    EXPECT_EQ(NS::DefinedSquare::Empty, NS::Square::Empty);
    EXPECT_NE(NS::DefinedSquare::Empty, NS::Square::Filled);
    EXPECT_NE(NS::DefinedSquare::Empty, NS::Square::Undefined);

    EXPECT_NE(NS::DefinedSquare::Filled, NS::Square::Empty);
    EXPECT_EQ(NS::DefinedSquare::Filled, NS::Square::Filled);
    EXPECT_NE(NS::DefinedSquare::Filled, NS::Square::Undefined);
}