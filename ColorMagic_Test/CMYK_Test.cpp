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
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		red = new cmyk(0.15f, 1.f, 0.9f, 0.1f, d65_2deg);
		yellow = new cmyk(0.05f, 0.f, 0.9f, 0.f, d65_2deg);
		white = new cmyk(0.f, 0.f, 0.f, 0.f, d65_2deg);
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
	EXPECT_EQ(*yellow, *(new cmyk(0.05f, 0.f, 0.9f, 0.f, d65_2deg)));
}

TEST_F(CMYK_Test, Operator_Tests)
{
	auto blue = new cmyk(1.f, 0.33f, 0.f, 0.f, d65_2deg);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}