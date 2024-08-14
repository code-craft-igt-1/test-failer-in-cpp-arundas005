#include <iostream>
#include "misaligned.h"
#include "TestPrintColorMap.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int colorPairNumber( int majorColorIndex, int minorColorIndex) {
    return majorColorIndex * 5 + minorColorIndex;
}

std::string formatOneLine(int colorPairIndex, std::string majorColor, std::string minorColor) {
    return std::to_string(colorPairIndex) + " | " + majorColor + " | " + minorColor;
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
