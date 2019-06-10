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
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		yellow = new hsl(60.f, 1.f, 0.5f, d65_2deg);
		black = new hsl(0.f, 0.f, 0.f, d65_2deg);
		white = new hsl(0.f, 0.f, 1.f, d65_2deg);

		test1 = new hsl(-30.f, 1.f, 0.5f, d65_2deg);
		test2 = new hsl(460.f, 1.f, 0.5f, d65_2deg);
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
	EXPECT_EQ(*yellow, *(new hsl(60.f, 1.f, 0.5f, d65_2deg)));
	EXPECT_EQ(*white, *(new hsl(0.f, 0.f, 1.f, d65_2deg)));
}

TEST_F(HSL_Test, Operator_Tests)
{
	auto blue = new hsl(240.f, 1.f, 0.5f, d65_2deg);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}