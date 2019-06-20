#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\grey_truecolor.h"

using namespace color_space;

class Grey_True_Test : public ::testing::Test {
protected:
	grey_truecolor* grey;
	grey_truecolor* black;
	grey_truecolor* white;
	grey_truecolor* transparent;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = &color_space::rgb_color_space_definition_presets::sRGB;
		grey = new grey_truecolor(128, 255, srgb);
		black = new grey_truecolor(0, 255, srgb);
		white = new grey_truecolor(255, 255, srgb);
		transparent = new grey_truecolor(255, 0, srgb);
	}

	virtual void TearDown()
	{
		delete grey;
		delete black;
		delete white;
		delete transparent;
	}
};

TEST_F(Grey_True_Test, Constructor_Tests)
{
	EXPECT_EQ(*transparent, *(new grey_truecolor(255, 0, srgb)));
	EXPECT_EQ(*white, *(new grey_truecolor(*white)));
}

TEST_F(Grey_True_Test, Operator_Tests)
{
	auto dark_grey = new grey_truecolor(25, 255, srgb);
	EXPECT_TRUE(*dark_grey != *white);
	dark_grey = white;
	EXPECT_TRUE(*dark_grey == *white);
}