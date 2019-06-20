#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\grey_deepcolor.h"

using namespace color_space;

class Grey_Deep_Test : public ::testing::Test {
protected:
	grey_deepcolor* grey;
	grey_deepcolor* black;
	grey_deepcolor* white;
	grey_deepcolor* transparent;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = &color_space::rgb_color_space_definition_presets::sRGB;
		grey = new grey_deepcolor(0.5f, 1.f, srgb);
		black = new grey_deepcolor(0.f, 1.f, srgb);
		white = new grey_deepcolor(1.f, 1.f, srgb);
		transparent = new grey_deepcolor(1.f, 0.f, srgb);
	}

	virtual void TearDown()
	{
		delete grey;
		delete black;
		delete white;
		delete transparent;
	}
};

TEST_F(Grey_Deep_Test, Constructor_Tests)
{
	EXPECT_EQ(*transparent, *(new grey_deepcolor(1.f, 0.f, srgb)));
	EXPECT_EQ(*white, *(new grey_deepcolor(*white)));
}

TEST_F(Grey_Deep_Test, Operator_Tests)
{
	auto dark_grey = new grey_deepcolor(0.2f, 1.f, srgb);
	EXPECT_TRUE(*dark_grey != *white);
	dark_grey = white;
	EXPECT_TRUE(*dark_grey == *white);
}