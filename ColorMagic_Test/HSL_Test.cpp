#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\hsl.h"

using namespace color_space;

class HSL_Test : public ::testing::Test {
protected:
	hsl* yellow;
	hsl* black;
	hsl* white;
	hsl* test1;
	hsl* test2;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = &color_space::rgb_color_space_definition_presets::sRGB;
		yellow = new hsl(60.f, 1.f, 0.5f, 1.f, srgb);
		black = new hsl(0.f, 0.f, 0.f, 1.f, srgb);
		white = new hsl(0.f, 0.f, 1.f, 1.f, srgb);

		test1 = new hsl(-30.f, 1.f, 0.5f, 1.f, srgb);
		test2 = new hsl(460.f, 1.f, 0.5f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(HSL_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new hsl(*yellow)));
	EXPECT_EQ(*yellow, *(new hsl(60.f, 1.f, 0.5f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new hsl(0.f, 0.f, 1.f, 1.f, srgb)));
}

TEST_F(HSL_Test, Operator_Tests)
{
	auto blue = new hsl(240.f, 1.f, 0.5f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}