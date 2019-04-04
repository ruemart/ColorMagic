#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\cmyk.h"
#include "..\ColorMagic\spaces\grey_deepcolor.h"
#include "..\ColorMagic\spaces\grey_truecolor.h"
#include "..\ColorMagic\spaces\hsl.h"
#include "..\ColorMagic\spaces\hsv.h"
#include "..\ColorMagic\spaces\lab.h"
#include "..\ColorMagic\spaces\rgb_deepcolor.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\spaces\xyz.h"
#include "..\ColorMagic\manipulation\color_adjustments.h"

using namespace color_space;

class ColorAdjustments_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	rgb_truecolor *rgb_t_red;

	virtual void SetUp()
	{
		rgb_t_red = new rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);
	}

	virtual void TearDown()
	{
		delete rgb_t_red;
	}
};

TEST_F(ColorAdjustments_Test, SaturateRGB)
{
	auto minus100 = rgb_truecolor((unsigned char)76, (unsigned char)76, (unsigned char)76);
	auto plus50 = rgb_truecolor((unsigned char)211, (unsigned char)19, (unsigned char)19);
	auto minus50 = rgb_truecolor((unsigned char)166, (unsigned char)38, (unsigned char)38);
	auto zero = rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_rgb_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_rgb_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_rgb_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_rgb_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}

TEST_F(ColorAdjustments_Test, SaturateHSL)
{
	auto minus100 = rgb_truecolor((unsigned char)128, (unsigned char)128, (unsigned char)128);
	auto plus50 = rgb_truecolor((unsigned char)223, (unsigned char)32, (unsigned char)32);
	auto minus50 = rgb_truecolor((unsigned char)191, (unsigned char)64, (unsigned char)64);
	auto zero = rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_hsl_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_hsl_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_hsl_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate_in_hsl_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}

TEST_F(ColorAdjustments_Test, LuminateRGB)
{
	auto minus100 = rgb_truecolor((unsigned char)0, (unsigned char)0, (unsigned char)0);
	auto plus50 = rgb_truecolor((unsigned char)192, (unsigned char)0, (unsigned char)0);
	auto minus50 = rgb_truecolor((unsigned char)128, (unsigned char)0, (unsigned char)0);
	auto zero = rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_rgb_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_rgb_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_rgb_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_rgb_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}

TEST_F(ColorAdjustments_Test, LuminateHSL)
{
	auto minus100 = rgb_truecolor((unsigned char)0, (unsigned char)0, (unsigned char)0);
	auto plus50 = rgb_truecolor((unsigned char)192, (unsigned char)0, (unsigned char)0);
	auto minus50 = rgb_truecolor((unsigned char)128, (unsigned char)0, (unsigned char)0);
	auto zero = rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_hsl_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_hsl_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_hsl_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::luminate_in_hsl_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}