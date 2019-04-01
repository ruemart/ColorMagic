#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_deepcolor.h"

using namespace color_space;

class RGB_Deep_Test : public ::testing::Test {
protected:
	rgb_deepcolor* red;
	rgb_deepcolor* yellow;
	rgb_deepcolor* black;
	rgb_deepcolor* white;
	rgb_deepcolor* transparent;

	virtual void SetUp()
	{
		red = new rgb_deepcolor(1.f, 0.f, 0.f, 1.f);
		yellow = new rgb_deepcolor(1.f, 1.f, 0.f, 1.f);
		black = new rgb_deepcolor(0.f, 0.f, 0.f, 1.f);
		white = new rgb_deepcolor(1.f, 1.f, 1.f, 1.f);
		transparent = new rgb_deepcolor(1.f, 1.f, 1.f, 0.f);
	}

	virtual void TearDown()
	{
		delete red;
		delete yellow;
		delete black;
		delete white;
		delete transparent;
	}
};

TEST_F(RGB_Deep_Test, Constructor_Tests)
{
	EXPECT_EQ(*black, *(new rgb_deepcolor()));
	EXPECT_EQ(*white, *(new rgb_deepcolor(1.f)));
	EXPECT_EQ(*transparent, *(new rgb_deepcolor(1.f, 0.f)));
	EXPECT_EQ(*yellow, *(new rgb_deepcolor(1.f, 1.f, 0.f)));
	EXPECT_EQ(*yellow, *(new rgb_deepcolor(1.f, 1.f, 0.f, 1.f)));
	EXPECT_EQ(*yellow, *(new rgb_deepcolor(*yellow)));
}

TEST_F(RGB_Deep_Test, Operator_Tests)
{
	auto blue = new rgb_deepcolor(0.f, 0.f, 1.f, 1.f);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}