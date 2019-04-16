#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\grey_truecolor.h"

using namespace color_space;

class Grey_True_Test : public ::testing::Test {
protected:
	grey_truecolor* grey;
	grey_truecolor* black;
	grey_truecolor* white;
	grey_truecolor* transparent;

	virtual void SetUp()
	{
		grey = new grey_truecolor((unsigned char)128, (unsigned char)255);
		black = new grey_truecolor((unsigned char)0, (unsigned char)255);
		white = new grey_truecolor((unsigned char)255, (unsigned char)255);
		transparent = new grey_truecolor((unsigned char)255, (unsigned char)0);
	}

	virtual void TearDown()
	{
		delete grey;
		delete black;
		delete white;
		delete transparent;
	}
};

TEST_F(Grey_True_Test, Constructor_Tests)
{
	EXPECT_EQ(*black, *(new grey_truecolor()));
	EXPECT_EQ(*grey, *(new grey_truecolor((unsigned char)128)));
	EXPECT_EQ(*transparent, *(new grey_truecolor((unsigned char)255, (unsigned char)0)));
	EXPECT_EQ(*white, *(new grey_truecolor(*white)));
}

TEST_F(Grey_True_Test, Operator_Tests)
{
	auto dark_grey = new grey_truecolor((unsigned char)25);
	EXPECT_TRUE(*dark_grey != *white);
	dark_grey = white;
	EXPECT_TRUE(*dark_grey == *white);
}