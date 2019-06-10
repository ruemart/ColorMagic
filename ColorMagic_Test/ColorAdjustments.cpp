#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\manipulation\color_adjustments.h"

using namespace color_space;

class ColorAdjustments_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	rgb_truecolor *rgb_t_red;
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
		rgb_t_red = new rgb_truecolor(255, 0, 0, 255, d65_2deg);
	}

	virtual void TearDown()
	{
		delete rgb_t_red;
	}
};

TEST_F(ColorAdjustments_Test, SaturateRGB)
{
	auto minus100 = rgb_truecolor(76, 76, 76, 255, d65_2deg);
	auto plus50 = rgb_truecolor(211, 19, 19, 255, d65_2deg);
	auto minus50 = rgb_truecolor(166, 38, 38, 255, d65_2deg);
	auto zero = rgb_truecolor(255, 0, 0, 255, d65_2deg);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_rgb_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_rgb_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_rgb_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_rgb_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}

TEST_F(ColorAdjustments_Test, SaturateHSL)
{
	auto minus100 = rgb_truecolor(128, 128, 128, 255, d65_2deg);
	auto plus50 = rgb_truecolor(223, 32, 32, 255, d65_2deg);
	auto minus50 = rgb_truecolor(191, 64, 64, 255, d65_2deg);
	auto zero = rgb_truecolor(255, 0, 0, 255, d65_2deg);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_hsl_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_hsl_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_hsl_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::saturate_in_hsl_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}

TEST_F(ColorAdjustments_Test, LuminateRGB)
{
	auto minus100 = rgb_truecolor(0, 0, 0, 255, d65_2deg);
	auto plus50 = rgb_truecolor(192, 0, 0, 255, d65_2deg);
	auto minus50 = rgb_truecolor(128, 0, 0, 255, d65_2deg);
	auto zero = rgb_truecolor(255, 0, 0, 255, d65_2deg);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_rgb_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_rgb_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_rgb_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_rgb_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}

TEST_F(ColorAdjustments_Test, LuminateHSL)
{
	auto minus100 = rgb_truecolor(0, 0, 0, 255, d65_2deg);
	auto plus50 = rgb_truecolor(192, 0, 0, 255, d65_2deg);
	auto minus50 = rgb_truecolor(128, 0, 0, 255, d65_2deg);
	auto zero = rgb_truecolor(255, 0, 0, 255, d65_2deg);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_hsl_space(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_hsl_space(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_hsl_space(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_manipulation::color_adjustments::luminate_in_hsl_space(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}