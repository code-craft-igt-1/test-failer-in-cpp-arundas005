#include "misaligned.h"
#include "tshirts.h"
#include <gtest\gtest.h>
#include <string>
#include <iostream>
#include <sstream>

std::string removeLineEndings(const std::string& input) {
    std::string result = input;
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        bool isMatch = false;
        if(!std::isalnum(static_cast<unsigned char>(c)))
        {
            if( c != '|' && c != ' ')
            {
                isMatch = true;
            }
        }
        return isMatch;
    }), result.end());
    return result;
}


TEST(PrintColorMap, testPrintColorMap)
{
    //redirect console output to a stringstream
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    int actualResult = printColorMap();
    std::cout.rdbuf(oldCoutStreamBuf); // Restore the original cout buffer
    std::string capturedOutput = output.str();
    std::string actual = removeLineEndings(capturedOutput);
    std::string expected = "1 | White | Blue2 | White | Blue3 | White | Blue4 | \
White | Blue5 | White | Blue6 | Red | Orange7 | Red | Orange8 | Red | \
Orange9 | Red | Orange10 | Red | Orange11 | Black | Green12 | Black | \
Green13 | Black | Green14 | Black | Green15 | Black | Green16 | Yellow | \
Brown17 | Yellow | Brown18 | Yellow | Brown19 | Yellow | Brown20 | Yellow | \
Brown21 | Violet | Slate22 | Violet | Slate23 | Violet | Slate24 | \
Violet | Slate25 | Violet | Slate";
    EXPECT_EQ(actual, expected);
}