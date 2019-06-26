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
	rgb_color_space_definition* srgb;

	virtual void SetUp() 
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		red = new rgb_truecolor(255.f, 0.f, 0.f, 255.f, srgb);
		yellow = new rgb_truecolor(255.f, 255.f, 0.f, 255.f, srgb);
		grey = new rgb_truecolor(128.f, 128.f, 128.f, 255.f, srgb);
		white = new rgb_truecolor(255.f, 255.f, 255.f, 255.f, srgb);
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
	EXPECT_EQ(*red, *(predefined_color(HexcodeColors::Red, srgb).get_rgb_true()));
	EXPECT_EQ(*yellow, *(predefined_color(HexcodeColors::Yellow, srgb).get_rgb_true()));
	EXPECT_EQ(*grey, *(predefined_color(HexcodeColors::Gray, srgb).get_rgb_true()));
	EXPECT_EQ(*white, *(predefined_color(HexcodeColors::White, srgb).get_rgb_true()));
}

TEST_F(RGB_True_Test, From_HexString_Tests)
{
	EXPECT_EQ(*red, *(new rgb_truecolor("#FFFF0000", srgb)));
	EXPECT_EQ(*red, *(new rgb_truecolor("#FF0000", srgb)));
	EXPECT_EQ(*red, *(new rgb_truecolor("FF0000", srgb)));
	EXPECT_THROW(new rgb_truecolor("#GGFF0000", srgb), std::invalid_argument);
	EXPECT_THROW(new rgb_truecolor("FF", srgb), std::invalid_argument);

	EXPECT_EQ(*red, *(new rgb_truecolor("FFFF0000", srgb)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor("FFFFFF00", srgb)));
	EXPECT_EQ(*grey, *(new rgb_truecolor("FF808080", srgb)));
	EXPECT_EQ(*white, *(new rgb_truecolor("FFFFFFFF", srgb)));
}

TEST_F(RGB_True_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new rgb_truecolor(255.f, 255.f, 0.f, 255.f, srgb)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor(*yellow)));
}

TEST_F(RGB_True_Test, Operator_Tests)
{
	auto blue = new rgb_truecolor(0.f, 0.f, 255.f, 255.f, srgb);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}