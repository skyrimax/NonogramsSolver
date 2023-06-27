#include <gtest/gtest.h>

#include <Image.hpp>

#include <utility>

TEST(ImageCompleted, HandleEmpty)
{
    NS::Image image;

    EXPECT_TRUE(image.completed());
}

TEST(ImageCompleted, HandleNoRow)
{
    NS::Image image(0, 3);

    EXPECT_TRUE(image.completed());
}

TEST(ImageCompleted, HandleNoColumn)
{
    NS::Image image(3, 0);

    EXPECT_TRUE(image.completed());
}

TEST(ImageCompleted, IncompleteImage)
{
    NS::Image image(3, 3);

    image(0, 0) = -1;

    EXPECT_FALSE(image.completed());
}

TEST(ImageCompleted, CompleteImage)
{
    NS::Image image(3, 3);

    EXPECT_TRUE(image.completed());
}