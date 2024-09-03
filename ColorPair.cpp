#include "ColorPair.h"

namespace TelCoColorCoder {

    const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
    int numberOfMajorColors = std::size(MajorColorNames);

    const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int numberOfMinorColors = std::size(MinorColorNames);


    ColorPair GetColorPairFromNumber(const int pairNumber) {
        auto zeroBasedNumber = pairNumber - 1;
        auto majorColor = static_cast<MajorColor>(zeroBasedNumber / numberOfMinorColors);
        auto minorColor = static_cast<MinorColor>(zeroBasedNumber % numberOfMinorColors);
        return { majorColor, minorColor };
    }

    int GetNumberFromColorPair(const MajorColor major, const MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    ColorPair::ColorPair(const MajorColor major, const MinorColor minor) : majorColor(major), minorColor(minor)
    {}

    MajorColor ColorPair::getMajorColor() const
    {
        return majorColor;
    }

    MinorColor ColorPair::getMinorColor() const
    {
        return minorColor;
    }

    std::string ColorPair::getColorPairInString() const
    {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }
}