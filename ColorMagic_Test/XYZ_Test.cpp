#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\xyz.h"

using namespace color_space;

class XYZ_Test : public ::testing::Test {
protected:
	xyz* yellow;
	xyz* black;
	xyz* white;
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		yellow = new xyz(0.77f, 0.9278f, 0.1385f, d65_2deg);
		black = new xyz(0.f, 0.f, 0.f, d65_2deg);
		white = new xyz(1.f, 1.f, 1.f, d65_2deg);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(XYZ_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new xyz(*yellow)));
	EXPECT_EQ(*yellow, *(new xyz(0.77f, 0.9278f, 0.1385f, d65_2deg)));
	EXPECT_EQ(*white, *(new xyz(1.f, 1.f, 1.f, d65_2deg)));
}

TEST_F(XYZ_Test, Operator_Tests)
{
	auto blue = new xyz(0.f, 0.f, 1.f, d65_2deg);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}