#include <iostream>
#include <iomanip>
#include <sstream>
#include "misaligned.h"
#include "TestPrintColorMap.h"


const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int colorPairNumber( int majorColorIndex, int minorColorIndex) {
    return majorColorIndex * 5 + minorColorIndex + 1;
}

std::string formatOneLine(int colorPairIndex, std::string majorColor, std::string minorColor) {
    //Align color map output
    std::stringstream singleLineOutput;
    singleLineOutput << std::left << std::setw(5) << colorPairIndex << " | ";
    singleLineOutput << std::left << std::setw(10) << majorColor << " | ";
    singleLineOutput << std::left << std::setw(10) << minorColor;
    return singleLineOutput.str();
}

void printColorMap() {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << formatOneLine(colorPairNumber(i, j) , majorColor[i], minorColor[j]) << std::endl;
        }
    }
}

int main() {
    printColorMap();
    testPrintColorMap();
    return 0;
}
