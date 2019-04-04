#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\manipulation\color_combinations.h"

using namespace color_space;

class ColorCombinations_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	rgb_truecolor *rgb_t_red;
	rgb_truecolor *rgb_t_cyan;

	virtual void SetUp()
	{
		rgb_t_red = new rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);
		rgb_t_cyan = new rgb_truecolor((unsigned char)0, (unsigned char)255, (unsigned char)255);
	}

	virtual void TearDown()
	{
		delete rgb_t_red;
	}
};

TEST_F(ColorCombinations_Test, Complimentary)
{
	auto red_complimentary = dynamic_cast<color_space::rgb_truecolor*>(color_manipulation::color_combinations::get_complimentary_color(rgb_t_red));
	EXPECT_NEAR(rgb_t_cyan->red(), red_complimentary->red(), avg_error);
	EXPECT_NEAR(rgb_t_cyan->green(), red_complimentary->green(), avg_error);
	EXPECT_NEAR(rgb_t_cyan->blue(), red_complimentary->blue(), avg_error);
}