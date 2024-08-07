#include "tshirts.h"
#include <gtest\gtest.h>

TEST(TShirtSize, testSmallsize)
{
    char actualSize = size(37);
    char expectedSize = 'S';
    EXPECT_EQ(actualSize, expectedSize);
}

TEST(TShirtSize, testSmallsizeUpperLimit)
{
    char actualSize = size(38);
    char expectedSize = 'S';
    EXPECT_EQ(actualSize, expectedSize);
}

TEST(TShirtSize, testMediumsize)
{
    char actualSize = size(40);
    char expectedSize = 'M';
    EXPECT_EQ(actualSize, expectedSize);
}

TEST(TShirtSize, testMediumLowerLimit)
{
    char actualSize = size(39);
    char expectedSize = 'M';
    EXPECT_EQ(actualSize, expectedSize);
}

TEST(TShirtSize, testMediumUpperLimit)
{
    char actualSize = size(42);
    char expectedSize = 'M';
    EXPECT_EQ(actualSize, expectedSize);
}

TEST(TShirtSize, testLargesize)
{
    char actualSize = size(45);
    char expectedSize = 'L';
    EXPECT_EQ(actualSize, expectedSize);
}

TEST(TShirtSize, testLargesizeLowerLimit)
{
    char actualSize = size(43);
    char expectedSize = 'L';
    EXPECT_EQ(actualSize, expectedSize);
}
