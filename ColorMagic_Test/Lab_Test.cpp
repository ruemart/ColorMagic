#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\ColorSpaces\icolor.h"
#include "..\ColorMagic\ColorSpaces\lab.h"

using namespace ColorSpaces;

class LAB_Test : public ::testing::Test {
protected:
	lab* yellow;
	lab* black;
	lab* white;

	virtual void SetUp()
	{
		yellow = new lab(0.77f, 0.9278f, 0.1385f);
		black = new lab(0.f, 0.f, 0.f);
		white = new lab(1.f, 0.f, 0.f);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(LAB_Test, Constructor_Tests)
{
	EXPECT_EQ(*black, *(new lab()));
	EXPECT_EQ(*yellow, *(new lab(0.77f, 0.9278f, 0.1385f)));
	EXPECT_EQ(*white, *(new lab(1.f, 0.f, 0.f)));
}

TEST_F(LAB_Test, Operator_Tests)
{
	auto blue = new lab(32.3f, 79.2f, -107.86f);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}