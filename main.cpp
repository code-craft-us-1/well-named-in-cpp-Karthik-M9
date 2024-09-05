#include <iostream>
#include <cassert>
#include "ColorPair.h"

void testNumberToPair(const int pairNumber,
                      const TelCoColorCoder::MajorColor expectedMajor,
                      const TelCoColorCoder::MinorColor expectedMinor)
{
    const TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorPairFromNumber(pairNumber);
    std::cout << "Got pair " << colorPair.getColorPairInString() << std::endl;
    assert(colorPair.getMajorColor() == expectedMajor);
    assert(colorPair.getMinorColor() == expectedMinor);
}

void testPairToNumber(
    const TelCoColorCoder::MajorColor major,
    const TelCoColorCoder::MinorColor minor,
    const int expectedPairNumber)
{
    const int pairNumber = GetNumberFromColorPair(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::BROWN);
    testNumberToPair(5, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::SLATE);

    testPairToNumber(TelCoColorCoder::MajorColor::BLACK, TelCoColorCoder::MinorColor::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::MajorColor::VIOLET, TelCoColorCoder::MinorColor::SLATE, 25);

    int pairNo = 1;
    std::cout << "*************** Manual ***************" << std::endl;
    for (auto i = 1; i < TelCoColorCoder::MajorColor::maxSizeMajorColor; i++)
    {
        const auto majorColor = static_cast<TelCoColorCoder::MajorColor>(i - 1 / TelCoColorCoder::MajorColor::maxSizeMajorColor);
        for (auto j = 1; j < TelCoColorCoder::MinorColor::maxSizeMinorColor; j++)
        {
            const auto minorColor = static_cast<TelCoColorCoder::MinorColor>(j-1 % TelCoColorCoder::MinorColor::maxSizeMinorColor);
            TelCoColorCoder::ColorPair colorPairTemp = { majorColor,minorColor };
            std::cout << pairNo++ << " " << colorPairTemp.getColorPairInString()<< std::endl;
        }        
    }
    return 0;
}
