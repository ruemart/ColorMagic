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
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		yellow = new hsv(60.f, 1.f, 1.f, 1.f, srgb);
		black = new hsv(0.f, 0.f, 0.f, 1.f, srgb);
		white = new hsv(0.f, 0.f, 1.f, 1.f, srgb);
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
	EXPECT_EQ(*yellow, *(new hsv(60.f, 1.f, 1.f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new hsv(0.f, 0.f, 1.f, 1.f, srgb)));
}

TEST_F(HSV_Test, Operator_Tests)
{
	auto blue = new hsv(240.f, 1.f, 1.f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}