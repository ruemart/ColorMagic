#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\cmyk.h"

using namespace color_space;

class CMYK_Test : public ::testing::Test {
protected:
	cmyk* red;
	cmyk* yellow;
	cmyk* white;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		red = new cmyk(0.15f, 1.f, 0.9f, 0.1f, 1.f, srgb);
		yellow = new cmyk(0.05f, 0.f, 0.9f, 0.f, 1.f, srgb);
		white = new cmyk(0.f, 0.f, 0.f, 0.f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete red;
		delete yellow;
		delete white;
	}
};

TEST_F(CMYK_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new cmyk(*yellow)));
	EXPECT_EQ(*yellow, *(new cmyk(0.05f, 0.f, 0.9f, 0.f, 1.f, srgb)));
}

TEST_F(CMYK_Test, Operator_Tests)
{
	auto blue = new cmyk(1.f, 0.33f, 0.f, 0.f, 1.f, srgb);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}