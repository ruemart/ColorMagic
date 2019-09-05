#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\hsi.h"

using namespace color_space;

class HSI_Test : public ::testing::Test {
protected:
	hsi* yellow;
	hsi* black;
	hsi* white;
	hsi* test1;
	hsi* test2;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		yellow = new hsi(60.f, 1.f, 0.5f, 1.f, srgb);
		black = new hsi(0.f, 0.f, 0.f, 1.f, srgb);
		white = new hsi(0.f, 0.f, 1.f, 1.f, srgb);

		test1 = new hsi(-30.f, 1.f, 0.5f, 1.f, srgb);
		test2 = new hsi(460.f, 1.f, 0.5f, 1.f, srgb);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(HSI_Test, Constructor_Tests)
{
	EXPECT_EQ(*yellow, *(new hsi(*yellow)));
	EXPECT_EQ(*yellow, *(new hsi(60.f, 1.f, 0.5f, 1.f, srgb)));
	EXPECT_EQ(*white, *(new hsi(0.f, 0.f, 1.f, 1.f, srgb)));
}

TEST_F(HSI_Test, Operator_Tests)
{
	auto blue = new hsi(240.f, 1.f, 0.5f, 1.f, srgb);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}