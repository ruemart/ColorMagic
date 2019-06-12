#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\lab.h"

using namespace color_space;

class LAB_Test : public ::testing::Test {
protected:
	lab* yellow;
	lab* black;
	lab* white;
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		yellow = new lab(0.77f, 0.9278f, 0.1385f, 1.f, d65_2deg);
		black = new lab(0.f, 0.f, 0.f, 1.f, d65_2deg);
		white = new lab(1.f, 0.f, 0.f, 1.f, d65_2deg);
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
	EXPECT_EQ(*yellow, *(new lab(*yellow)));
	EXPECT_EQ(*yellow, *(new lab(0.77f, 0.9278f, 0.1385f, 1.f, d65_2deg)));
	EXPECT_EQ(*white, *(new lab(1.f, 0.f, 0.f, 1.f, d65_2deg)));
}

TEST_F(LAB_Test, Operator_Tests)
{
	auto blue = new lab(32.3f, 79.2f, -107.86f, 1.f, d65_2deg);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}