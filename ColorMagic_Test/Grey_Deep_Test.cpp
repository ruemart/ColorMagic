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
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		grey = new grey_deepcolor(0.5f, 1.f, d65_2deg);
		black = new grey_deepcolor(0.f, 1.f, d65_2deg);
		white = new grey_deepcolor(1.f, 1.f, d65_2deg);
		transparent = new grey_deepcolor(1.f, 0.f, d65_2deg);
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
	EXPECT_EQ(*transparent, *(new grey_deepcolor(1.f, 0.f, d65_2deg)));
	EXPECT_EQ(*white, *(new grey_deepcolor(*white)));
}

TEST_F(Grey_Deep_Test, Operator_Tests)
{
	auto dark_grey = new grey_deepcolor(0.2f, 1.f, d65_2deg);
	EXPECT_TRUE(*dark_grey != *white);
	dark_grey = white;
	EXPECT_TRUE(*dark_grey == *white);
}