#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\ColorSpaces\icolor.h"
#include "..\ColorMagic\ColorSpaces\hsv.h"

using namespace ColorSpaces;

class HSV_Test : public ::testing::Test {
protected:
	hsv* yellow;
	hsv* black;
	hsv* white;

	virtual void SetUp()
	{
		yellow = new hsv(60.f, 1.f, 1.f);
		black = new hsv(0.f, 0.f, 0.f);
		white = new hsv(0.f, 0.f, 1.f);
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
	EXPECT_EQ(*black, *(new hsv()));
	EXPECT_EQ(*yellow, *(new hsv(60.f, 1.f, 1.f)));
	EXPECT_EQ(*white, *(new hsv(0.f, 0.f, 1.f)));
}

TEST_F(HSV_Test, Operator_Tests)
{
	auto blue = new hsv(240.f, 1.f, 1.f);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}