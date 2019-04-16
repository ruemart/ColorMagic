#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\grey_deepcolor.h"

using namespace color_space;

class Grey_Deep_Test : public ::testing::Test {
protected:
	grey_deepcolor* grey;
	grey_deepcolor* black;
	grey_deepcolor* white;
	grey_deepcolor* transparent;

	virtual void SetUp()
	{
		grey = new grey_deepcolor(0.5f, 1.f);
		black = new grey_deepcolor(0.f, 1.f);
		white = new grey_deepcolor(1.f, 1.f);
		transparent = new grey_deepcolor(1.f, 0.f);
	}

	virtual void TearDown()
	{
		delete grey;
		delete black;
		delete white;
		delete transparent;
	}
};

TEST_F(Grey_Deep_Test, Constructor_Tests)
{
	EXPECT_EQ(*black, *(new grey_deepcolor()));
	EXPECT_EQ(*grey, *(new grey_deepcolor(0.5f)));
	EXPECT_EQ(*transparent, *(new grey_deepcolor(1.f, 0.f)));
	EXPECT_EQ(*white, *(new grey_deepcolor(*white)));
}

TEST_F(Grey_Deep_Test, Operator_Tests)
{
	auto dark_grey = new grey_deepcolor(0.2f);
	EXPECT_TRUE(*dark_grey != *white);
	dark_grey = white;
	EXPECT_TRUE(*dark_grey == *white);
}