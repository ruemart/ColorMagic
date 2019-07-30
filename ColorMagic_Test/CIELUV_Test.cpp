#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\cieluv.h"

using namespace color_space;

class CIELUV_Test : public ::testing::Test {
protected:
	cieluv* orange;
	cieluv* black;
	cieluv* cyan;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		orange = new cieluv(100.f, 100.f, 100.f, 1.f, srgb);
		black = new cieluv(0.f, 50.f, 50.f, 1.f, srgb);
		cyan = new cieluv(100.f, -100.f, -100.f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete orange;
		delete black;
		delete cyan;
	}
};

TEST_F(CIELUV_Test, Constructor_Tests)
{
	EXPECT_EQ(*orange, *(new cieluv(*orange)));
	EXPECT_EQ(*black, *(new cieluv(0.f, 50.f, 50.f, 1.f, srgb)));
	EXPECT_EQ(*cyan, *(new cieluv(100.f, -100.f, -100.f, 1.f, srgb)));
}

TEST_F(CIELUV_Test, Operator_Tests)
{
	auto green = new cieluv(50.f, -100.f, 0.f, 1.f, srgb);
	EXPECT_TRUE(*green != *orange);
	green = orange;
	EXPECT_TRUE(*green == *orange);
}