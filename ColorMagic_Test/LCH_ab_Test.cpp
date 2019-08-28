#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\lch_ab.h"

using namespace color_space;

class LCH_ab_Test : public ::testing::Test {
protected:
	lch_ab* yellow;
	lch_ab* black;
	lch_ab* white;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		yellow = new lch_ab(100.f, 100.f, 80.f, 1.f, srgb);
		black = new lch_ab(0.f, 0.f, 80.f, 1.f, srgb);
		white = new lch_ab(100.f, 0.f, 80.f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(LCH_ab_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new lch_ab(*yellow)));
	EXPECT_EQ(*yellow, *(new lch_ab(100.f, 100.f, 80.f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new lch_ab(100.f, 0.f, 80.f, 1.f, srgb)));
}

TEST_F(LCH_ab_Test, Operator_Tests)
{
	auto blue = new lch_ab(50.f, 100.f, 260.f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}