#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\hsv.h"

using namespace color_space;

class HSV_Test : public ::testing::Test {
protected:
	hsv* yellow;
	hsv* black;
	hsv* white;
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		yellow = new hsv(60.f, 1.f, 1.f, d65_2deg);
		black = new hsv(0.f, 0.f, 0.f, d65_2deg);
		white = new hsv(0.f, 0.f, 1.f, d65_2deg);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(HSV_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new hsv(*yellow)));
	EXPECT_EQ(*yellow, *(new hsv(60.f, 1.f, 1.f, d65_2deg)));
	EXPECT_EQ(*white, *(new hsv(0.f, 0.f, 1.f, d65_2deg)));
}

TEST_F(HSV_Test, Operator_Tests)
{
	auto blue = new hsv(240.f, 1.f, 1.f, d65_2deg);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}