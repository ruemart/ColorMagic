#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\hsl.h"

using namespace color_space;

class HSL_Test : public ::testing::Test {
protected:
	hsl* yellow;
	hsl* black;
	hsl* white;
	hsl* test1;
	hsl* test2;

	virtual void SetUp()
	{
		yellow = new hsl(60.f, 1.f, 0.5f);
		black = new hsl(0.f, 0.f, 0.f);
		white = new hsl(0.f, 0.f, 1.f);

		test1 = new hsl(-30.f, 1.f, 0.5f);
		test2 = new hsl(460.f, 1.f, 0.5f);
	}

	virtual void TearDown()
	{
		delete yellow;
		delete black;
		delete white;
	}
};

TEST_F(HSL_Test, Constructor_Tests)
{
	EXPECT_EQ(*black, *(new hsl()));
	EXPECT_EQ(*yellow, *(new hsl(60.f, 1.f, 0.5f)));
	EXPECT_EQ(*white, *(new hsl(0.f, 0.f, 1.f)));
}

TEST_F(HSL_Test, Operator_Tests)
{
	auto blue = new hsl(240.f, 1.f, 0.5f);
	EXPECT_TRUE(*blue != *yellow);
	blue = yellow;
	EXPECT_TRUE(*blue == *yellow);
}