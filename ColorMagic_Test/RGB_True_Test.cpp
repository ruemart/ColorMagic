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
	rgb_truecolor* black;
	rgb_truecolor* grey;
	rgb_truecolor* white;
	rgb_truecolor* transparent;

	virtual void SetUp() 
	{
		red = new rgb_truecolor(255, 0, 0, 255);
		yellow = new rgb_truecolor(255, 255, 0, 255);
		black = new rgb_truecolor(0, 0, 0, 255);
		grey = new rgb_truecolor(128, 128, 128, 255);
		white = new rgb_truecolor(255, 255, 255, 255);
		transparent = new rgb_truecolor(255, 255, 255, 0);
	}

	virtual void TearDown()
	{
		delete red;
		delete yellow;
		delete black;
		delete grey;
		delete white;
		delete transparent;
	}
};

TEST_F(RGB_True_Test, From_HexCode_Tests)
{
	EXPECT_EQ(*red, *(predefined_color(HexcodeColors::Red).get_rgb_true()));
	EXPECT_EQ(*yellow, *(predefined_color(HexcodeColors::Yellow).get_rgb_true()));
	EXPECT_EQ(*black, *(predefined_color(HexcodeColors::Black).get_rgb_true()));
	EXPECT_EQ(*grey, *(predefined_color(HexcodeColors::Gray).get_rgb_true()));
	EXPECT_EQ(*white, *(predefined_color(HexcodeColors::White).get_rgb_true()));
	EXPECT_EQ(*transparent, *(predefined_color(HexcodeColors::Transparent).get_rgb_true()));
}

TEST_F(RGB_True_Test, From_HexString_Tests)
{
	EXPECT_EQ(*red, *(new rgb_truecolor("#FFFF0000")));
	EXPECT_EQ(*red, *(new rgb_truecolor("#FF0000")));
	EXPECT_EQ(*red, *(new rgb_truecolor("FF0000")));
	EXPECT_THROW(*(new rgb_truecolor("#GGFF0000")), std::invalid_argument);
	EXPECT_THROW(*(new rgb_truecolor("FF")), std::invalid_argument);

	EXPECT_EQ(*red, *(new rgb_truecolor("FFFF0000")));
	EXPECT_EQ(*yellow, *(new rgb_truecolor("FFFFFF00")));
	EXPECT_EQ(*black, *(new rgb_truecolor("FF000000")));
	EXPECT_EQ(*grey, *(new rgb_truecolor("FF808080")));
	EXPECT_EQ(*white, *(new rgb_truecolor("FFFFFFFF")));
	EXPECT_EQ(*transparent, *(new rgb_truecolor("00FFFFFF")));
}

TEST_F(RGB_True_Test, Constructor_Tests)
{
	EXPECT_EQ(*black, *(new rgb_truecolor()));
	EXPECT_EQ(*white, *(new rgb_truecolor((unsigned char)255)));
	EXPECT_EQ(*transparent, *(new rgb_truecolor((unsigned char)255, (unsigned char)0)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor((unsigned char)255, (unsigned char)255, (unsigned char)0)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor((unsigned char)255, (unsigned char)255, (unsigned char)0, (unsigned char)255)));
	EXPECT_EQ(*yellow, *(new rgb_truecolor(*yellow)));
}

TEST_F(RGB_True_Test, Operator_Tests)
{
	auto blue = new rgb_truecolor((unsigned char)0, (unsigned char)0, (unsigned char)255, (unsigned char)255);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}