#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\hcy.h"

using namespace color_space;

class HCY_Test : public ::testing::Test {
protected:
	hcy* yellow;
	hcy* black;
	hcy* white;
	hcy* test1;
	hcy* test2;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		yellow = new hcy(60.f, 1.f, 0.5f, 1.f, srgb);
		black = new hcy(0.f, 0.f, 0.f, 1.f, srgb);
		white = new hcy(0.f, 0.f, 1.f, 1.f, srgb);

		test1 = new hcy(-30.f, 1.f, 0.5f, 1.f, srgb);
		test2 = new hcy(460.f, 1.f, 0.5f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(HCY_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new hcy(*yellow)));
	EXPECT_EQ(*yellow, *(new hcy(60.f, 1.f, 0.5f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new hcy(0.f, 0.f, 1.f, 1.f, srgb)));
}

TEST_F(HCY_Test, Operator_Tests)
{
	auto blue = new hcy(240.f, 1.f, 0.5f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}