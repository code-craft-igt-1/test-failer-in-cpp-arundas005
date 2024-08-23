#include "misaligned.h"
#include "TestPrintColorMap.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <assert.h>

std::vector<std::vector<std::string> > expectedContent = {
        {"1", "White", "Blue"},
        {"2", "White", "Orange"},
        {"3", "White", "Green"},
        {"4", "White", "Brown"},
        {"5", "White", "Slate"},
        {"6", "Red", "Blue"},
        {"7", "Red", "Orange"},
        {"8", "Red", "Green"},
        {"9", "Red", "Brown"},
        {"10", "Red", "Slate"},
        {"11", "Black", "Blue"},
        {"12", "Black", "Orange"},
        {"13", "Black", "Green"},
        {"14", "Black", "Brown"},
        {"15", "Black", "Slate"},
        {"16", "Yellow", "Blue"},
        {"17", "Yellow", "Orange"},
        {"18", "Yellow", "Green"},
        {"19", "Yellow", "Brown"},
        {"20", "Yellow", "Slate"},
        {"21", "Violet", "Blue"},
        {"22", "Violet", "Orange"},
        {"23", "Violet", "Green"},
        {"24", "Violet", "Brown"},
        {"25", "Violet", "Slate"}
    };

std::vector<std::string> tokenizeString(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string line;
    while (std::getline(iss, line)) {
        tokens.push_back(line);
    }
    return tokens;
}

bool isDelimiterPresent(const std::string& input, char delimiter, int position1, int position2) {
    if (position1 < 0 || position1 >= input.length() || position2 < 0 || position2 >= input.length()) {
        return false;
    }
    
    if (input[position1] == delimiter && input[position2] == delimiter) {
        return true;
    }
    
    return false;
}

bool IsFormatCorrect(const std::vector<std::string>& tokens)
{
    bool isFormatCorrect = true;
    for (const std::string& token : tokens)
    {
        if (token.length() < 2)
        {
            isFormatCorrect = false;
            break;
        }
        if (!isDelimiterPresent(token, '|', 6, 19))
        {
            isFormatCorrect = false;
            break;
        }
    } 
    return isFormatCorrect;
}

std::string removeWhiteSpaces(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

std::vector<std::string> tokenizeString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool checkColorMapContentOfEachLine(const std::vector<std::string>& tokens, const std::vector<std::string>& expectedTokens)
{
    bool isContentCorrect = true;
    std::cout<<"Actual: " <<tokens[0] << " " << tokens[1] << " " << tokens[2] << std::endl;
    std::cout << "Expected: " << expectedTokens[0] << " " << expectedTokens[1] << " " << expectedTokens[2] << std::endl;
    for (int i = 0; i < expectedTokens.size(); i++)
    {
        if (tokens[i] != expectedTokens[i])
        {
            isContentCorrect = false;
            break;
        }
    }
    return isContentCorrect;
}

bool checkColorMapContent(const std::vector<std::string>& actualColorMapPrinted, const std::vector<std::vector<std::string> >& expectedTokens)
{
    bool isContentCorrect = true;
    for (int i = 0; i < expectedTokens.size(); i++)
    {
        std::string line = removeWhiteSpaces(actualColorMapPrinted[i]);
        std::vector<std::string> tokenizedCodeAndColors = tokenizeString(line, '|');
        if (!checkColorMapContentOfEachLine(tokenizedCodeAndColors, expectedTokens[i]))
        {
            isContentCorrect = false;
            break;
        }
    }   
    return isContentCorrect;
}

void testPrintColorMap()
{
    //redirect console output to a stringstream
    std::ostringstream output;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    printColorMap();
    std::cout.rdbuf(oldCoutStreamBuf); // Restore the original cout buffer
    std::string capturedOutput = output.str();

    //get each line of the output
    std::vector<std::string>& actualContent = tokenizeString(capturedOutput);
    
    //check printed color map format
    bool isFormatCorrect = IsFormatCorrect(actualContent);
    assert(isFormatCorrect);

    //check printed color map content
    bool IsContentCorrect = checkColorMapContent(actualContent, expectedContent);
    assert(IsContentCorrect);
}
