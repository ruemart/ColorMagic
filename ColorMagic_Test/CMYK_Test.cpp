#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\icolor.h"
#include "..\ColorMagic\spaces\cmyk.h"

using namespace color_space;

class CMYK_Test : public ::testing::Test {
protected:
	cmyk* red;
	cmyk* yellow;
	cmyk* white;

	virtual void SetUp()
	{
		red = new cmyk(0.15f, 1.f, 0.9f, 0.1f);
		yellow = new cmyk(0.05f, 0.f, 0.9f, 0.f);
		white = new cmyk(0.f, 0.f, 0.f, 0.f);
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
	EXPECT_EQ(*white, *(new cmyk()));
	EXPECT_EQ(*white, *(new cmyk(0.f)));
	EXPECT_EQ(*yellow, *(new cmyk(0.05f, 0.f, 0.9f, 0.f)));
}

TEST_F(CMYK_Test, Operator_Tests)
{
	auto blue = new cmyk(1.f, 0.33f, 0.f, 0.f);
	EXPECT_TRUE(*blue != *red);
	blue = red;
	EXPECT_TRUE(*blue == *red);
}