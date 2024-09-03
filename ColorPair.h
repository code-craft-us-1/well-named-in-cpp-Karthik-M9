#pragma once
#include <string>

namespace TelCoColorCoder
{
    enum MajorColor { WHITE=1, RED=2, BLACK=3, YELLOW=4, VIOLET=5 };
    enum MinorColor { BLUE=1, ORANGE=2, GREEN=3, BROWN=4, SLATE=5 };

    class ColorPair {
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);

        MajorColor getMajorColor() const; 

        MinorColor getMinorColor() const;

        std::string getColorPairInString() const;
    };

    ColorPair GetColorPairFromNumber(int pairNumber);
    int GetNumberFromColorPair(MajorColor major, MinorColor minor);
}
