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

	cmyk *cmyk_red;
	hsv *hsv_red;
	hsl *hsl_red;
	xyz *xyz_red;
	lab *lab_red;
	grey_deepcolor *grey2_d;
	grey_truecolor *grey2_t;
	rgb_deepcolor *rgb_d_red;
	rgb_truecolor *rgb_t_red;

	virtual void SetUp()
	{
		cmyk_red = new cmyk(0.f, 1.f, 1.f, 0.f);
		hsv_red = new hsv(0.f, 1.f, 1.f);
		hsl_red = new hsl(0.f, 1.f, 0.5f);
		xyz_red = new xyz(41.24f, 21.26f, 1.93f);
		lab_red = new lab(53.23f, 80.11f, 67.22f);
		grey2_d = new grey_deepcolor(0.3333f);
		grey2_t = new grey_truecolor((unsigned char)85);
		rgb_d_red = new rgb_deepcolor(1.f, 0.f, 0.f);
		rgb_t_red = new rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);
	}

	virtual void TearDown()
	{
		delete cmyk_red;
		delete hsv_red;
		delete hsl_red;
		delete xyz_red;
		delete lab_red;
		delete grey2_d;
		delete grey2_t;
		delete rgb_d_red;
		delete rgb_t_red;
	}
};

TEST_F(ColorAdjustments_Test, SaturateRGB)
{
	auto minus100 = rgb_truecolor((unsigned char)76, (unsigned char)76, (unsigned char)76);
	auto plus50 = rgb_truecolor((unsigned char)211, (unsigned char)19, (unsigned char)19);
	auto minus50 = rgb_truecolor((unsigned char)166, (unsigned char)38, (unsigned char)38);
	auto zero = rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);

	auto minus100_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate(rgb_t_red, -1.f)));
	EXPECT_NEAR(minus100.red(), minus100_calc.red(), avg_error);
	EXPECT_NEAR(minus100.green(), minus100_calc.green(), avg_error);
	EXPECT_NEAR(minus100.blue(), minus100_calc.blue(), avg_error);

	auto minus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate(rgb_t_red, -0.5f)));
	EXPECT_NEAR(minus50.red(), minus50_calc.red(), avg_error);
	EXPECT_NEAR(minus50.green(), minus50_calc.green(), avg_error);
	EXPECT_NEAR(minus50.blue(), minus50_calc.blue(), avg_error);

	auto zero_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate(rgb_t_red, 0.f)));
	EXPECT_NEAR(zero.red(), zero_calc.red(), avg_error);
	EXPECT_NEAR(zero.green(), zero_calc.green(), avg_error);
	EXPECT_NEAR(zero.blue(), zero_calc.blue(), avg_error);

	auto plus50_calc = *(dynamic_cast<rgb_truecolor*>(color_adjustments::saturate(&minus50_calc, 0.5f)));
	EXPECT_NEAR(plus50.red(), plus50_calc.red(), avg_error);
	EXPECT_NEAR(plus50.green(), plus50_calc.green(), avg_error);
	EXPECT_NEAR(plus50.blue(), plus50_calc.blue(), avg_error);
}