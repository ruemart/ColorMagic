#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\utils\colors.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"

using namespace color_space;

class RGB_True_Test : public ::testing::Test {
protected:
	rgb_truecolor* red;
	rgb_truecolor* yellow;
	rgb_truecolor* grey;
	rgb_truecolor* white;
	reference_white* d65_2deg;

	virtual void SetUp() 
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		red = new rgb_truecolor(255.f, 0.f, 0.f, 255.f, d65_2deg);
		yellow = new rgb_truecolor(255.f, 255.f, 0.f, 255.f, d65_2deg);
		grey = new rgb_truecolor(128.f, 128.f, 128.f, 255.f, d65_2deg);
		white = new rgb_truecolor(255.f, 255.f, 255.f, 255.f, d65_2deg);
	}

	virtual void TearDown()
	{
		delete red;
		delete yellow;
		delete grey;
		delete white;
	}
};

TEST_F(RGB_True_Test, From_HexCode_Tests)
{
	EXPECT_EQ(*red, *(predefined_color(HexcodeColors::Red, d65_2deg).get_rgb_true()));
	EXPECT_EQ(*yellow, *(predefined_color(HexcodeColors::Yellow, d65_2deg).get_rgb_true()));
	EXPECT_EQ(*grey, *(predefined_color(HexcodeColors::Gray, d65_2deg).get_rgb_true()));
	EXPECT_EQ(*white, *(predefined_color(HexcodeColors::White, d65_2deg).get_rgb_true()));
}

TEST_F(RGB_True_Test, From_HexString_Tests)
{
	EXPECT_EQ(*red, *(new rgb_truecolor("#FFFF0000", d65_2deg)));
	EXPECT_EQ(*red, *(new rgb_truecolor("#FF0000", d65_2deg)));
	EXPECT_EQ(*red, *(new rgb_truecolor("FF0000", d65_2deg)));
	EXPECT_THROW(new rgb_truecolor("#GGFF0000", d65_2deg), std::invalid_argument);
	EXPECT_THROW(new rgb_truecolor("FF", d65_2deg), std::invalid_argument);

	EXPECT_EQ(*red, *(new rgb_truecolor("FFFF0000", d65_2deg)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor("FFFFFF00", d65_2deg)));
	EXPECT_EQ(*grey, *(new rgb_truecolor("FF808080", d65_2deg)));
	EXPECT_EQ(*white, *(new rgb_truecolor("FFFFFFFF", d65_2deg)));
}

TEST_F(RGB_True_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new rgb_truecolor(255.f, 255.f, 0.f, 255.f, d65_2deg)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor(*yellow)));
}

TEST_F(RGB_True_Test, Operator_Tests)
{
	auto blue = new rgb_truecolor(0.f, 0.f, 255.f, 255.f, d65_2deg);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}