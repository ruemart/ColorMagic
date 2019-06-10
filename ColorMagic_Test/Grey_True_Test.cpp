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
	reference_white* d65_2deg;
	
	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		grey = new grey_truecolor(128, 255, d65_2deg);
		black = new grey_truecolor(0, 255, d65_2deg);
		white = new grey_truecolor(255, 255, d65_2deg);
		transparent = new grey_truecolor(255, 0, d65_2deg);
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
	EXPECT_EQ(*transparent, *(new grey_truecolor(255, 0, d65_2deg)));
	EXPECT_EQ(*white, *(new grey_truecolor(*white)));
}

TEST_F(Grey_True_Test, Operator_Tests)
{
	auto dark_grey = new grey_truecolor(25, 255, d65_2deg);
	EXPECT_TRUE(*dark_grey != *white);
	dark_grey = white;
	EXPECT_TRUE(*dark_grey == *white);
}