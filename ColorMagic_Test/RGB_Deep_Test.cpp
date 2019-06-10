#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_deepcolor.h"

using namespace color_space;

class RGB_Deep_Test : public ::testing::Test {
protected:
	rgb_deepcolor* red;
	rgb_deepcolor* yellow;
	rgb_deepcolor* white;
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		red = new rgb_deepcolor(1.f, 0.f, 0.f, 1.f, d65_2deg);
		yellow = new rgb_deepcolor(1.f, 1.f, 0.f, 1.f, d65_2deg);
		white = new rgb_deepcolor(1.f, 1.f, 1.f, 1.f, d65_2deg);
	}

	virtual void TearDown()
	{
		delete red;
		delete yellow;
		delete white;
	}
};

TEST_F(RGB_Deep_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new rgb_deepcolor(1.f, 1.f, 0.f, 1.f, d65_2deg)));
	EXPECT_EQ(*yellow, *(new rgb_deepcolor(*yellow)));
}

TEST_F(RGB_Deep_Test, Operator_Tests)
{
	auto blue = new rgb_deepcolor(0.f, 0.f, 1.f, 1.f, d65_2deg);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}