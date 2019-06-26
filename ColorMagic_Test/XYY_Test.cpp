#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\xyy.h"

using namespace color_space;

class XYY_Test : public ::testing::Test {
protected:
	xyy* yellow;
	xyy* black;
	xyy* white;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		yellow = new xyy(0.41f, 0.505f, 0.9278f, 1.f, srgb);
		black = new xyy(0.f, 0.f, 0.f, 1.f, srgb);
		white = new xyy(0.33f, 0.33f, 1.f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(XYY_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new xyy(*yellow)));
	EXPECT_EQ(*yellow, *(new xyy(0.41f, 0.505f, 0.9278f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new xyy(0.33f, 0.33f, 1.f, 1.f, srgb)));
}

TEST_F(XYY_Test, Operator_Tests)
{
	auto blue = new xyy(0.15f, 0.06f, 0.072f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}