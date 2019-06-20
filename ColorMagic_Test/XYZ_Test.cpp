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
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = &color_space::rgb_color_space_definition_presets::sRGB;
		yellow = new xyz(0.77f, 0.9278f, 0.1385f, 1.f, srgb);
		black = new xyz(0.f, 0.f, 0.f, 1.f, srgb);
		white = new xyz(1.f, 1.f, 1.f, 1.f, srgb);
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
	EXPECT_EQ(*yellow, *(new xyz(0.77f, 0.9278f, 0.1385f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new xyz(1.f, 1.f, 1.f, 1.f, srgb)));
}

TEST_F(XYZ_Test, Operator_Tests)
{
	auto blue = new xyz(0.f, 0.f, 1.f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}