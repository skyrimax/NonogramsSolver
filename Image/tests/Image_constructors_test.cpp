#include <gtest/gtest.h>

#include <Image.hpp>

#include <utility>

TEST(ImageDefaultConstructorTest, IsEmpty)
{
    NS::Image image;

    EXPECT_EQ(image.nbRows(), 0);
    EXPECT_EQ(image.nbCols(), 0);
    EXPECT_EQ(image.data().size(), 0);
    EXPECT_TRUE(image.empty());
}

TEST(ImageSizeConstructorTest, CorrectSize)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        for (size_t j = 1; j <= 5; ++j)
        {
            NS::Image image(i, j);

            EXPECT_EQ(image.nbRows(), i);
            EXPECT_EQ(image.nbCols(), j);
            EXPECT_EQ(image.data().size(), i * j);
        }
    }
}

TEST(ImageSizeConstructorTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        NS::Image image(0, j);

        EXPECT_EQ(image.nbRows(), 0);
        EXPECT_EQ(image.nbCols(), j);
        EXPECT_EQ(image.data().size(), 0);
        EXPECT_TRUE(image.empty());
    }
}

TEST(ImageSizeConstructorTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        NS::Image image(i, 0);

        EXPECT_EQ(image.nbRows(), i);
        EXPECT_EQ(image.nbCols(), 0);
        EXPECT_EQ(image.data().size(), 0);
        EXPECT_TRUE(image.empty());
    }
}

TEST(ImageCopyConstructorTest, HandleEmpty)
{
    NS::Image image1;

    NS::Image image2(image1);

    EXPECT_EQ(image2.nbRows(), 0);
    EXPECT_EQ(image2.nbCols(), 0);
    EXPECT_EQ(image2.data().size(), 0);
    EXPECT_TRUE(image2.empty());
}

TEST(ImageCopyConstructorTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        NS::Image image1(0, j);
        NS::Image image2(image1);

        EXPECT_EQ(image2.nbRows(), 0);
        EXPECT_EQ(image2.nbCols(), j);
        EXPECT_EQ(image2.data().size(), 0);
        EXPECT_TRUE(image2.empty());
    }
}

TEST(ImageCopyConstructorTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        NS::Image image1(i, 0);
        NS::Image image2(image1);

        EXPECT_EQ(image2.nbRows(), i);
        EXPECT_EQ(image2.nbCols(), 0);
        EXPECT_EQ(image2.data().size(), 0);
        EXPECT_TRUE(image2.empty());
    }
}

TEST(ImageCopyConstructorTest, ContainsCorrectValues)
{
    NS::Image image1(3, 3);

    image1(0, 0) = NS::Square::Empty;
    image1(0, 1) = NS::Square::Filled;
    image1(0, 2) = NS::Square::Undefined;
    image1(1, 0) = NS::Square::Filled;
    image1(1, 1) = NS::Square::Undefined;
    image1(1, 2) = NS::Square::Empty;
    image1(2, 0) = NS::Square::Undefined;
    image1(2, 1) = NS::Square::Empty;
    image1(2, 2) = NS::Square::Filled;

    NS::Image image2(image1);

    EXPECT_EQ(image2(0, 0), NS::Square::Empty);
    EXPECT_EQ(image2(0, 1), NS::Square::Filled);
    EXPECT_EQ(image2(0, 2), NS::Square::Undefined);
    EXPECT_EQ(image2(1, 0), NS::Square::Filled);
    EXPECT_EQ(image2(1, 1), NS::Square::Undefined);
    EXPECT_EQ(image2(1, 2), NS::Square::Empty);
    EXPECT_EQ(image2(2, 0), NS::Square::Undefined);
    EXPECT_EQ(image2(2, 1), NS::Square::Empty);
    EXPECT_EQ(image2(2, 2), NS::Square::Filled);
}

TEST(ImageMoveConstructorTest, HandleEmpty)
{
    NS::Image image1;

    NS::Image image2(std::move(image1));

    EXPECT_EQ(image2.nbRows(), 0);
    EXPECT_EQ(image2.nbCols(), 0);
    EXPECT_EQ(image2.data().size(), 0);
    EXPECT_TRUE(image2.empty());

    EXPECT_EQ(image1.nbRows(), 0);
    EXPECT_EQ(image1.nbCols(), 0);
    EXPECT_EQ(image1.data().size(), 0);
    EXPECT_TRUE(image1.empty());
}

TEST(ImageMoveConstructorTest, HandleNoRow)
{
    for (size_t j = 1; j <= 5; ++j)
    {
        NS::Image image1(0, j);
        NS::Image image2(std::move(image1));

        EXPECT_EQ(image2.nbRows(), 0);
        EXPECT_EQ(image2.nbCols(), j);
        EXPECT_EQ(image2.data().size(), 0);
        EXPECT_TRUE(image2.empty());

        EXPECT_EQ(image1.nbRows(), 0);
        EXPECT_EQ(image1.nbCols(), 0);
        EXPECT_EQ(image1.data().size(), 0);
        EXPECT_TRUE(image1.empty());
    }
}

TEST(ImageMoveConstructorTest, HandleNoColumn)
{
    for (size_t i = 1; i <= 5; ++i)
    {
        NS::Image image1(i, 0);
        NS::Image image2(std::move(image1));

        EXPECT_EQ(image2.nbRows(), i);
        EXPECT_EQ(image2.nbCols(), 0);
        EXPECT_EQ(image2.data().size(), 0);
        EXPECT_TRUE(image2.empty());

        EXPECT_EQ(image1.nbRows(), 0);
        EXPECT_EQ(image1.nbCols(), 0);
        EXPECT_EQ(image1.data().size(), 0);
        EXPECT_TRUE(image1.empty());
    }
}

TEST(ImageMoveConstructorTest, ContainsCorrectValues)
{
    NS::Image image1(3, 3);

    image1(0, 0) = NS::Square::Empty;
    image1(0, 1) = NS::Square::Filled;
    image1(0, 2) = NS::Square::Undefined;
    image1(1, 0) = NS::Square::Filled;
    image1(1, 1) = NS::Square::Undefined;
    image1(1, 2) = NS::Square::Empty;
    image1(2, 0) = NS::Square::Undefined;
    image1(2, 1) = NS::Square::Empty;
    image1(2, 2) = NS::Square::Filled;

    NS::Image image2(std::move(image1));

    EXPECT_EQ(image2(0, 0), NS::Square::Empty);
    EXPECT_EQ(image2(0, 1), NS::Square::Filled);
    EXPECT_EQ(image2(0, 2), NS::Square::Undefined);
    EXPECT_EQ(image2(1, 0), NS::Square::Filled);
    EXPECT_EQ(image2(1, 1), NS::Square::Undefined);
    EXPECT_EQ(image2(1, 2), NS::Square::Empty);
    EXPECT_EQ(image2(2, 0), NS::Square::Undefined);
    EXPECT_EQ(image2(2, 1), NS::Square::Empty);
    EXPECT_EQ(image2(2, 2), NS::Square::Filled);

    EXPECT_EQ(image1.nbRows(), 0);
    EXPECT_EQ(image1.nbCols(), 0);
    EXPECT_EQ(image1.data().size(), 0);
    EXPECT_TRUE(image1.empty());
}