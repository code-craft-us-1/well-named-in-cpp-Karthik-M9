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
    const int expectedPairNumber){
    const int pairNumber = GetNumberFromColorPair(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void unitTests(){
    testNumberToPair(4, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::BROWN);
    testNumberToPair(5, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::SLATE);

    testPairToNumber(TelCoColorCoder::MajorColor::BLACK, TelCoColorCoder::MinorColor::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::MajorColor::VIOLET, TelCoColorCoder::MinorColor::SLATE, 25);
}

void printManual(){
    auto pairNo = 1;
    std::cout << "**************** Manual ***************" << '\n';
    for (auto i = 0; i < TelCoColorCoder::MajorColor::maxSizeMajorColor; i++)
    {
        for (auto j = 0; j < TelCoColorCoder::MinorColor::maxSizeMinorColor; j++)
        {
            TelCoColorCoder::ColorPair colorPairTemp = { static_cast<TelCoColorCoder::MajorColor>(i),static_cast<TelCoColorCoder::MinorColor>(j) };
            std::cout << pairNo++ << " " << colorPairTemp.getColorPairInString() << '\n';
        }
    }
}

int main() {
    unitTests();
    printManual();
    return 0;
}
