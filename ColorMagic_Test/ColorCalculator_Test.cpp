#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\manipulation\color_calculation.h"

using namespace color_space;

class ColorCalculator_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;
	reference_white* d65_2deg;

	virtual void SetUp()
	{
		d65_2deg = &color_space::reference_white_presets::D65_2Degree;
	}

	virtual void TearDown()
	{
	}
};

TEST_F(ColorCalculator_Test, RGB_True_Add)
{
	auto rgb_t_red = new rgb_truecolor(255.f, 0.f, 0.f, 1.f, d65_2deg);
	auto rgb_t_blue = new rgb_truecolor(0.f, 0.f, 255.f, 1.f, d65_2deg);
	auto rgb_t_pink = new rgb_truecolor(255.f, 0.f, 255.f, 1.f, d65_2deg);
	auto rgb_t_purple = new rgb_truecolor(180.3f, 0.f, 180.3f, 1.f, d65_2deg);
	auto rgb_t_dark_purple = new rgb_truecolor(127.5f, 0.f, 255.f, 1.f, d65_2deg);

	auto red_red_sum1 = color_manipulation::color_calculation::add(rgb_t_red, rgb_t_red);
	EXPECT_NEAR(rgb_t_red->red(), red_red_sum1->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), red_red_sum1->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), red_red_sum1->blue(), avg_error);
	EXPECT_NEAR(rgb_t_red->alpha(), red_red_sum1->alpha(), avg_error);

	auto red_blue_sum1 = color_manipulation::color_calculation::add(rgb_t_red, rgb_t_blue);
	EXPECT_NEAR(rgb_t_pink->red(), red_blue_sum1->red(), avg_error);
	EXPECT_NEAR(rgb_t_pink->green(), red_blue_sum1->green(), avg_error);
	EXPECT_NEAR(rgb_t_pink->blue(), red_blue_sum1->blue(), avg_error);
	EXPECT_NEAR(rgb_t_pink->alpha(), red_blue_sum1->alpha(), avg_error);

	auto red_blue_sum2 = color_manipulation::color_calculation::add(rgb_t_red, rgb_t_blue, 0.5f, 0.5f);
	EXPECT_NEAR(rgb_t_purple->red(), red_blue_sum2->red(), avg_error);
	EXPECT_NEAR(rgb_t_purple->green(), red_blue_sum2->green(), avg_error);
	EXPECT_NEAR(rgb_t_purple->blue(), red_blue_sum2->blue(), avg_error);
	EXPECT_NEAR(rgb_t_purple->alpha(), red_blue_sum2->alpha(), avg_error);

	auto red_blue_sum3 = color_manipulation::color_calculation::add(rgb_t_red, rgb_t_blue, 0.25f);
	EXPECT_NEAR(rgb_t_dark_purple->red(), red_blue_sum3->red(), avg_error);
	EXPECT_NEAR(rgb_t_dark_purple->green(), red_blue_sum3->green(), avg_error);
	EXPECT_NEAR(rgb_t_dark_purple->blue(), red_blue_sum3->blue(), avg_error);
	EXPECT_NEAR(rgb_t_dark_purple->alpha(), red_blue_sum3->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, RGB_Deep_Add)
{
	auto rgb_d_red = new rgb_deepcolor(1.f, 0.f, 0.f, 1.f, d65_2deg);
	auto rgb_d_blue = new rgb_deepcolor(0.f, 0.f, 1.f, 1.f, d65_2deg);
	auto rgb_d_pink = new rgb_deepcolor(1.f, 0.f, 1.f, 1.f, d65_2deg);
	auto rgb_d_purple = new rgb_deepcolor(0.7f, 0.f, 0.7f, 1.f, d65_2deg);
	auto rgb_d_dark_purple = new rgb_deepcolor(0.5f, 0.f, 1.f, 1.f, d65_2deg);

	auto red_red_sum = color_manipulation::color_calculation::add(rgb_d_red, rgb_d_red);
	EXPECT_NEAR(rgb_d_red->red(), red_red_sum->red(), avg_error);
	EXPECT_NEAR(rgb_d_red->green(), red_red_sum->green(), avg_error);
	EXPECT_NEAR(rgb_d_red->blue(), red_red_sum->blue(), avg_error);
	EXPECT_NEAR(rgb_d_red->alpha(), red_red_sum->alpha(), avg_error);

	auto red_blue_sum1 = color_manipulation::color_calculation::add(rgb_d_red, rgb_d_blue);
	EXPECT_NEAR(rgb_d_pink->red(), red_blue_sum1->red(), avg_error);
	EXPECT_NEAR(rgb_d_pink->green(), red_blue_sum1->green(), avg_error);
	EXPECT_NEAR(rgb_d_pink->blue(), red_blue_sum1->blue(), avg_error);
	EXPECT_NEAR(rgb_d_pink->alpha(), red_blue_sum1->alpha(), avg_error);

	auto red_blue_sum2 = color_manipulation::color_calculation::add(rgb_d_red, rgb_d_blue, 0.5f, 0.5f);
	EXPECT_NEAR(rgb_d_purple->red(), red_blue_sum2->red(), avg_error);
	EXPECT_NEAR(rgb_d_purple->green(), red_blue_sum2->green(), avg_error);
	EXPECT_NEAR(rgb_d_purple->blue(), red_blue_sum2->blue(), avg_error);
	EXPECT_NEAR(rgb_d_purple->alpha(), red_blue_sum2->alpha(), avg_error);

	auto red_blue_sum3 = color_manipulation::color_calculation::add(rgb_d_red, rgb_d_blue, 0.25f);
	EXPECT_NEAR(rgb_d_dark_purple->red(), red_blue_sum3->red(), avg_error);
	EXPECT_NEAR(rgb_d_dark_purple->green(), red_blue_sum3->green(), avg_error);
	EXPECT_NEAR(rgb_d_dark_purple->blue(), red_blue_sum3->blue(), avg_error);
	EXPECT_NEAR(rgb_d_dark_purple->alpha(), red_blue_sum3->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, Grey_True_Add)
{
	auto grey1 = new grey_truecolor(64, 255, d65_2deg);
	auto grey2 = new grey_truecolor(128, 255, d65_2deg);
	auto grey_mix_1 = new grey_truecolor(192, 255, d65_2deg);
	auto grey_mix_2 = new grey_truecolor(96, 255, d65_2deg);
	auto grey_mix_3 = new grey_truecolor(144, 255, d65_2deg);

	auto sum1 = color_manipulation::color_calculation::add(grey1, grey2);
	EXPECT_NEAR(grey_mix_1->grey(), sum1->grey(), avg_error);
	EXPECT_NEAR(grey_mix_1->alpha(), sum1->alpha(), avg_error);

	auto sum2 = color_manipulation::color_calculation::add(grey1, grey2, 0.5f, 0.5f);
	EXPECT_NEAR(grey_mix_2->grey(), sum2->grey(), avg_error);
	EXPECT_NEAR(grey_mix_2->alpha(), sum2->alpha(), avg_error);

	auto sum3 = color_manipulation::color_calculation::add(grey1, grey2, 0.25f);
	EXPECT_NEAR(grey_mix_3->grey(), sum3->grey(), avg_error);
	EXPECT_NEAR(grey_mix_3->alpha(), sum3->alpha(), avg_error);

	auto sum4 = color_manipulation::color_calculation::add(grey1, grey1);
	EXPECT_NEAR(2.f * grey1->grey(), sum4->grey(), avg_error);
	EXPECT_NEAR(grey1->alpha(), sum4->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, Grey_Deep_Add)
{
	auto grey1 = new grey_deepcolor(0.25f, 1.f, d65_2deg);
	auto grey2 = new grey_deepcolor(0.5f, 1.f, d65_2deg);
	auto grey_mix_1 = new grey_deepcolor(0.75f, 1.f, d65_2deg);
	auto grey_mix_2 = new grey_deepcolor(0.375f, 1.f, d65_2deg);
	auto grey_mix_3 = new grey_deepcolor(0.56f, 1.f, d65_2deg);

	auto sum1 = color_manipulation::color_calculation::add(grey1, grey2);
	EXPECT_NEAR(grey_mix_1->grey(), sum1->grey(), avg_error);
	EXPECT_NEAR(grey_mix_1->alpha(), sum1->alpha(), avg_error);

	auto sum2 = color_manipulation::color_calculation::add(grey1, grey2, 0.5f, 0.5f);
	EXPECT_NEAR(grey_mix_2->grey(), sum2->grey(), avg_error);
	EXPECT_NEAR(grey_mix_2->alpha(), sum2->alpha(), avg_error);

	auto sum3 = color_manipulation::color_calculation::add(grey1, grey2, 0.25f);
	EXPECT_NEAR(grey_mix_3->grey(), sum3->grey(), avg_error);
	EXPECT_NEAR(grey_mix_3->alpha(), sum3->alpha(), avg_error);

	auto sum4 = color_manipulation::color_calculation::add(grey1, grey1);
	EXPECT_NEAR(2.f * grey1->grey(), sum4->grey(), avg_error);
	EXPECT_NEAR(grey1->alpha(), sum4->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, CMYK_Add)
{
	auto cmyk_cyan = new cmyk(1.f, 0.f, 0.f, 0.f, d65_2deg);
	auto cmyk_yellow = new cmyk(0.f, 0.f, 1.f, 0.f, d65_2deg);
	auto cmyk_green = new cmyk(1.f, 0.f, 1.f, 0.f, d65_2deg);
	auto cmyk_lime = new cmyk(0.5f, 0.f, 0.5f, 0.f, d65_2deg);
	auto cmyk_lemon = new cmyk(0.25f, 0.f, 1.f, 0.f, d65_2deg);

	auto cyan_cyan_sum = color_manipulation::color_calculation::add(cmyk_cyan, cmyk_cyan);
	EXPECT_NEAR(cmyk_cyan->cyan(), cyan_cyan_sum->cyan(), avg_error);
	EXPECT_NEAR(cmyk_cyan->magenta(), cyan_cyan_sum->magenta(), avg_error);
	EXPECT_NEAR(cmyk_cyan->yellow(), cyan_cyan_sum->yellow(), avg_error);
	EXPECT_NEAR(cmyk_cyan->black(), cyan_cyan_sum->black(), avg_error);

	auto cyan_yellow_sum1 = color_manipulation::color_calculation::add(cmyk_cyan, cmyk_yellow);
	EXPECT_NEAR(cmyk_green->cyan(), cyan_yellow_sum1->cyan(), avg_error);
	EXPECT_NEAR(cmyk_green->magenta(), cyan_yellow_sum1->magenta(), avg_error);
	EXPECT_NEAR(cmyk_green->yellow(), cyan_yellow_sum1->yellow(), avg_error);
	EXPECT_NEAR(cmyk_green->black(), cyan_yellow_sum1->black(), avg_error);

	auto cyan_yellow_sum2 = color_manipulation::color_calculation::add(cmyk_cyan, cmyk_yellow, 0.5f, 0.5f);
	EXPECT_NEAR(cmyk_lime->cyan(), cyan_yellow_sum2->cyan(), avg_error);
	EXPECT_NEAR(cmyk_lime->magenta(), cyan_yellow_sum2->magenta(), avg_error);
	EXPECT_NEAR(cmyk_lime->yellow(), cyan_yellow_sum2->yellow(), avg_error);
	EXPECT_NEAR(cmyk_lime->black(), cyan_yellow_sum2->black(), avg_error);

	auto cyan_yellow_sum3 = color_manipulation::color_calculation::add(cmyk_cyan, cmyk_yellow, 0.25f);
	EXPECT_NEAR(cmyk_lemon->cyan(), cyan_yellow_sum3->cyan(), avg_error);
	EXPECT_NEAR(cmyk_lemon->magenta(), cyan_yellow_sum3->magenta(), avg_error);
	EXPECT_NEAR(cmyk_lemon->yellow(), cyan_yellow_sum3->yellow(), avg_error);
	EXPECT_NEAR(cmyk_lemon->black(), cyan_yellow_sum3->black(), avg_error);
}

TEST_F(ColorCalculator_Test, HSV_Add)
{
	auto hsv_red = new hsv(0.f, 1.f, 1.f, d65_2deg);
	auto hsv_blue = new hsv(240.f, 1.f, 1.f, d65_2deg);
	auto hsv_pink = new hsv(300.f, 1.f, 1.f, d65_2deg);
	auto hsv_rose = new hsv(300.f, 0.5f, 1.f, d65_2deg);
	auto hsv_purple = new hsv(253.f, 0.9f, 1.f, d65_2deg);

	auto red_red_sum = color_manipulation::color_calculation::add(hsv_red, hsv_red);
	EXPECT_NEAR(hsv_red->hue(), red_red_sum->hue(), avg_error);
	EXPECT_NEAR(hsv_red->saturation(), red_red_sum->saturation(), avg_error);
	EXPECT_NEAR(hsv_red->value(), red_red_sum->value(), avg_error);

	auto red_blue_sum1 = color_manipulation::color_calculation::add(hsv_red, hsv_blue);
	EXPECT_NEAR(hsv_pink->hue(), red_blue_sum1->hue(), avg_error);
	EXPECT_NEAR(hsv_pink->saturation(), red_blue_sum1->saturation(), avg_error);
	EXPECT_NEAR(hsv_pink->value(), red_blue_sum1->value(), avg_error);

	auto red_blue_sum2 = color_manipulation::color_calculation::add(hsv_red, hsv_blue, 0.5f, 0.5f);
	EXPECT_NEAR(hsv_rose->hue(), red_blue_sum2->hue(), avg_error);
	EXPECT_NEAR(hsv_rose->saturation(), red_blue_sum2->saturation(), avg_error);
	EXPECT_NEAR(hsv_rose->value(), red_blue_sum2->value(), avg_error);

	auto red_blue_sum3 = color_manipulation::color_calculation::add(hsv_red, hsv_blue, 0.25f);
	EXPECT_NEAR(hsv_purple->hue(), red_blue_sum3->hue(), avg_error);
	EXPECT_NEAR(hsv_purple->saturation(), red_blue_sum3->saturation(), avg_error);
	EXPECT_NEAR(hsv_purple->value(), red_blue_sum3->value(), avg_error);
}

TEST_F(ColorCalculator_Test, HSL_Add)
{
	auto hsv_red = new hsl(0.f, 1.f, 0.5f, d65_2deg);
	auto hsv_blue = new hsl(240.f, 1.f, 0.5f, d65_2deg);
	auto hsv_pink = new hsl(300.f, 1.f, 0.5f, d65_2deg);
	auto hsv_rose = new hsl(300.f, 1.f, 0.75f, d65_2deg);
	auto hsv_purple = new hsl(253.f, 1.f, 0.55f, d65_2deg);

	auto red_red_sum = color_manipulation::color_calculation::add(hsv_red, hsv_red);
	EXPECT_NEAR(hsv_red->hue(), red_red_sum->hue(), avg_error);
	EXPECT_NEAR(hsv_red->saturation(), red_red_sum->saturation(), avg_error);
	EXPECT_NEAR(hsv_red->lightness(), red_red_sum->lightness(), avg_error);

	auto red_blue_sum1 = color_manipulation::color_calculation::add(hsv_red, hsv_blue);
	EXPECT_NEAR(hsv_pink->hue(), red_blue_sum1->hue(), avg_error);
	EXPECT_NEAR(hsv_pink->saturation(), red_blue_sum1->saturation(), avg_error);
	EXPECT_NEAR(hsv_pink->lightness(), red_blue_sum1->lightness(), avg_error);

	auto red_blue_sum2 = color_manipulation::color_calculation::add(hsv_red, hsv_blue, 0.5f, 0.5f);
	EXPECT_NEAR(hsv_rose->hue(), red_blue_sum2->hue(), avg_error);
	EXPECT_NEAR(hsv_rose->saturation(), red_blue_sum2->saturation(), avg_error);
	EXPECT_NEAR(hsv_rose->lightness(), red_blue_sum2->lightness(), avg_error);

	auto red_blue_sum3 = color_manipulation::color_calculation::add(hsv_red, hsv_blue, 0.25f);
	EXPECT_NEAR(hsv_purple->hue(), red_blue_sum3->hue(), avg_error);
	EXPECT_NEAR(hsv_purple->saturation(), red_blue_sum3->saturation(), avg_error);
	EXPECT_NEAR(hsv_purple->lightness(), red_blue_sum3->lightness(), avg_error);
}

TEST_F(ColorCalculator_Test, XYZ_Add)
{
	auto xyz_red = new xyz(41.2f, 21.3f, 2.f, d65_2deg);
	auto xyz_blue = new xyz(18.f, 7.2f, 100.f, d65_2deg);
	auto xyz_pink = new xyz(59.2f, 28.5f, 100.f, d65_2deg);
	auto xyz_purple1 = new xyz(29.6f, 14.25f, 51.f, d65_2deg);
	auto xyz_purple2 = new xyz(28.3f, 12.5f, 100.f, d65_2deg);

	auto red_red_sum = color_manipulation::color_calculation::add(xyz_red, xyz_red);
	EXPECT_NEAR(2.f * xyz_red->x(), red_red_sum->x(), avg_error);
	EXPECT_NEAR(2.f * xyz_red->y(), red_red_sum->y(), avg_error);
	EXPECT_NEAR(2.f * xyz_red->z(), red_red_sum->z(), avg_error);

	auto red_blue_sum1 = color_manipulation::color_calculation::add(xyz_red, xyz_blue);
	EXPECT_NEAR(xyz_pink->x(), red_blue_sum1->x(), avg_error);
	EXPECT_NEAR(xyz_pink->y(), red_blue_sum1->y(), avg_error);
	EXPECT_NEAR(xyz_pink->z(), red_blue_sum1->z(), avg_error);

	auto red_blue_sum2 = color_manipulation::color_calculation::add(xyz_red, xyz_blue, 0.5f, 0.5f);
	EXPECT_NEAR(xyz_purple1->x(), red_blue_sum2->x(), avg_error);
	EXPECT_NEAR(xyz_purple1->y(), red_blue_sum2->y(), avg_error);
	EXPECT_NEAR(xyz_purple1->z(), red_blue_sum2->z(), avg_error);

	auto red_blue_sum3 = color_manipulation::color_calculation::add(xyz_red, xyz_blue, 0.25f);
	EXPECT_NEAR(xyz_purple2->x(), red_blue_sum3->x(), avg_error);
	EXPECT_NEAR(xyz_purple2->y(), red_blue_sum3->y(), avg_error);
	EXPECT_NEAR(xyz_purple2->z(), red_blue_sum3->z(), avg_error);
}

TEST_F(ColorCalculator_Test, RGB_True_Subtract)
{
	auto rgb_t_red = new rgb_truecolor(255.f, 0.f, 0.f, 255.f, d65_2deg);
	auto rgb_t_blue = new rgb_truecolor(0.f, 0.f, 255.f, 255.f, d65_2deg);
	auto rgb_t_pink = new rgb_truecolor(255.f, 0.f, 255.f, 255.f, d65_2deg);
	auto rgb_t_purple = new rgb_truecolor(180.f, 0.f, 180.f, 255.f, d65_2deg);
	auto rgb_t_dark_purple = new rgb_truecolor(127.f, 0.f, 255.f, 255.f, d65_2deg);

	auto red_red_sub = color_manipulation::color_calculation::subtract(rgb_t_red, rgb_t_red);
	EXPECT_NEAR(0.f, red_red_sub->red(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->green(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->blue(), avg_error);
	EXPECT_NEAR(255.f, red_red_sub->alpha(), avg_error);

	auto pink_blue_sub = color_manipulation::color_calculation::subtract(rgb_t_pink, rgb_t_blue);
	EXPECT_NEAR(rgb_t_red->red(), pink_blue_sub->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), pink_blue_sub->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), pink_blue_sub->blue(), avg_error);
	EXPECT_NEAR(rgb_t_red->alpha(), pink_blue_sub->alpha(), avg_error);

	auto purple_blue_sub = color_manipulation::color_calculation::subtract(rgb_t_purple, rgb_t_blue, 0.5f, true);
	EXPECT_NEAR(180.f, purple_blue_sub->red(), avg_error);
	EXPECT_NEAR(0.f, purple_blue_sub->green(), avg_error);
	EXPECT_NEAR(52.5f, purple_blue_sub->blue(), avg_error);
	EXPECT_NEAR(127.5f, purple_blue_sub->alpha(), avg_error);

	auto dark_purple_blue_sub = color_manipulation::color_calculation::subtract(rgb_t_dark_purple, rgb_t_blue, 0.25f);
	EXPECT_NEAR(127.f, dark_purple_blue_sub->red(), avg_error);
	EXPECT_NEAR(0.f, dark_purple_blue_sub->green(), avg_error);
	EXPECT_NEAR(191.25f, dark_purple_blue_sub->blue(), avg_error);
	EXPECT_NEAR(255.f, dark_purple_blue_sub->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, RGB_Deep_Subtract)
{
	auto rgb_d_red = new rgb_deepcolor(1.f, 0.f, 0.f, 1.f, d65_2deg);
	auto rgb_d_blue = new rgb_deepcolor(0.f, 0.f, 1.f, 1.f, d65_2deg);
	auto rgb_d_pink = new rgb_deepcolor(1.f, 0.f, 1.f, 1.f, d65_2deg);
	auto rgb_d_purple = new rgb_deepcolor(0.7f, 0.f, 0.7f, 1.f, d65_2deg);
	auto rgb_d_dark_purple = new rgb_deepcolor(0.5f, 0.f, 1.f, 1.f, d65_2deg);

	auto red_red_sub = color_manipulation::color_calculation::subtract(rgb_d_red, rgb_d_red);
	EXPECT_NEAR(0.f, red_red_sub->red(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->green(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->blue(), avg_error);
	EXPECT_NEAR(1.f, red_red_sub->alpha(), avg_error);

	auto pink_blue_sub = color_manipulation::color_calculation::subtract(rgb_d_pink, rgb_d_blue);
	EXPECT_NEAR(rgb_d_red->red(), pink_blue_sub->red(), avg_error);
	EXPECT_NEAR(rgb_d_red->green(), pink_blue_sub->green(), avg_error);
	EXPECT_NEAR(rgb_d_red->blue(), pink_blue_sub->blue(), avg_error);
	EXPECT_NEAR(rgb_d_red->alpha(), pink_blue_sub->alpha(), avg_error);

	auto purple_blue_sub = color_manipulation::color_calculation::subtract(rgb_d_purple, rgb_d_blue, 0.5f, true);
	EXPECT_NEAR(0.7f, purple_blue_sub->red(), avg_error);
	EXPECT_NEAR(0.f, purple_blue_sub->green(), avg_error);
	EXPECT_NEAR(0.2f, purple_blue_sub->blue(), avg_error);
	EXPECT_NEAR(0.5f, purple_blue_sub->alpha(), avg_error);

	auto dark_purple_blue_sub = color_manipulation::color_calculation::subtract(rgb_d_dark_purple, rgb_d_blue, 0.25f);
	EXPECT_NEAR(0.5f, dark_purple_blue_sub->red(), avg_error);
	EXPECT_NEAR(0.f, dark_purple_blue_sub->green(), avg_error);
	EXPECT_NEAR(0.75f, dark_purple_blue_sub->blue(), avg_error);
	EXPECT_NEAR(1.f, dark_purple_blue_sub->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, Grey_True_Subtract)
{
	auto grey1 = new grey_truecolor(64.f, 255.f, d65_2deg);
	auto grey2 = new grey_truecolor(128.f, 255.f, d65_2deg);

	auto sub1 = color_manipulation::color_calculation::subtract(grey2, grey1);
	EXPECT_NEAR(64.f, sub1->grey(), avg_error);
	EXPECT_NEAR(255.f, sub1->alpha(), avg_error);

	auto sub2 = color_manipulation::color_calculation::subtract(grey2, grey1, 0.5f, true);
	EXPECT_NEAR(96.f, sub2->grey(), avg_error);
	EXPECT_NEAR(127.5f, sub2->alpha(), avg_error);

	auto sub3 = color_manipulation::color_calculation::subtract(grey2, grey1, 0.25f);
	EXPECT_NEAR(112.f, sub3->grey(), avg_error);
	EXPECT_NEAR(255.f, sub3->alpha(), avg_error);

	auto sub4 = color_manipulation::color_calculation::subtract(grey2, grey2);
	EXPECT_NEAR(0.f, sub4->grey(), avg_error);
	EXPECT_NEAR(255.f, sub4->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, Grey_Deep_Subtract)
{
	auto grey1 = new grey_deepcolor(0.25f, 1.f, d65_2deg);
	auto grey2 = new grey_deepcolor(0.5f, 1.f, d65_2deg);

	auto sub1 = color_manipulation::color_calculation::subtract(grey2, grey1);
	EXPECT_NEAR(0.25f, sub1->grey(), avg_error);
	EXPECT_NEAR(1.f, sub1->alpha(), avg_error);

	auto sub2 = color_manipulation::color_calculation::subtract(grey2, grey1, 0.5f, true);
	EXPECT_NEAR(0.375f, sub2->grey(), avg_error);
	EXPECT_NEAR(0.5f, sub2->alpha(), avg_error);

	auto sub3 = color_manipulation::color_calculation::subtract(grey2, grey1, 0.25f);
	EXPECT_NEAR(0.4375f, sub3->grey(), avg_error);
	EXPECT_NEAR(1.f, sub3->alpha(), avg_error);

	auto sub4 = color_manipulation::color_calculation::subtract(grey1, grey1);
	EXPECT_NEAR(0.f, sub4->grey(), avg_error);
	EXPECT_NEAR(1.f, sub4->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, CMYK_Subtract)
{
	auto cmyk_cyan = new cmyk(1.f, 0.f, 0.f, 0.f, d65_2deg);
	auto cmyk_yellow = new cmyk(0.f, 0.f, 1.f, 0.f, d65_2deg);
	auto cmyk_green = new cmyk(1.f, 0.f, 1.f, 0.f, d65_2deg);

	auto cyan_cyan_sub = color_manipulation::color_calculation::subtract(cmyk_cyan, cmyk_cyan);
	EXPECT_NEAR(0.f, cyan_cyan_sub->cyan(), avg_error);
	EXPECT_NEAR(0.f, cyan_cyan_sub->magenta(), avg_error);
	EXPECT_NEAR(0.f, cyan_cyan_sub->yellow(), avg_error);
	EXPECT_NEAR(0.f, cyan_cyan_sub->black(), avg_error);

	auto green_yellow_sub1 = color_manipulation::color_calculation::subtract(cmyk_green, cmyk_yellow);
	EXPECT_NEAR(1.f, green_yellow_sub1->cyan(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub1->magenta(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub1->yellow(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub1->black(), avg_error);

	auto green_yellow_sub2 = color_manipulation::color_calculation::subtract(cmyk_green, cmyk_yellow, 0.5f);
	EXPECT_NEAR(1.f, green_yellow_sub2->cyan(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub2->magenta(), avg_error);
	EXPECT_NEAR(0.5f, green_yellow_sub2->yellow(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub2->black(), avg_error);

	auto green_yellow_sub3 = color_manipulation::color_calculation::subtract(cmyk_green, cmyk_yellow, 0.25f);
	EXPECT_NEAR(1.f, green_yellow_sub3->cyan(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub3->magenta(), avg_error);
	EXPECT_NEAR(0.75f, green_yellow_sub3->yellow(), avg_error);
	EXPECT_NEAR(0.f, green_yellow_sub3->black(), avg_error);
}

TEST_F(ColorCalculator_Test, HSV_Subtract)
{
	auto hsv_red = new hsv(0.f, 1.f, 1.f, d65_2deg);
	auto hsv_blue = new hsv(240.f, 1.f, 1.f, d65_2deg);
	auto hsv_pink = new hsv(300.f, 1.f, 1.f, d65_2deg);

	auto red_red_sub = color_manipulation::color_calculation::subtract(hsv_red, hsv_red);
	EXPECT_NEAR(0.f, red_red_sub->hue(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->saturation(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->value(), avg_error);

	auto pink_blue_sub1 = color_manipulation::color_calculation::subtract(hsv_pink, hsv_blue);
	EXPECT_NEAR(0.f, pink_blue_sub1->hue(), avg_error);
	EXPECT_NEAR(1.f, pink_blue_sub1->saturation(), avg_error);
	EXPECT_NEAR(0.f, pink_blue_sub1->value(), avg_error);

	auto pink_blue_sub2 = color_manipulation::color_calculation::subtract(hsv_pink, hsv_blue, 0.5f);
	EXPECT_NEAR(330.f, pink_blue_sub2->hue(), avg_error);
	EXPECT_NEAR(0.86f, pink_blue_sub2->saturation(), avg_error);
	EXPECT_NEAR(0.5f, pink_blue_sub2->value(), avg_error);

	auto pink_blue_sub3 = color_manipulation::color_calculation::subtract(hsv_pink, hsv_blue, 0.25f);
	EXPECT_NEAR(313.f, pink_blue_sub3->hue(), avg_error);
	EXPECT_NEAR(0.9f, pink_blue_sub3->saturation(), avg_error);
	EXPECT_NEAR(0.75f, pink_blue_sub3->value(), avg_error);
}

TEST_F(ColorCalculator_Test, HSL_Subtract)
{
	auto hsl_red = new hsl(0.f, 1.f, 0.5f, d65_2deg);
	auto hsl_blue = new hsl(240.f, 1.f, 0.5f, d65_2deg);
	auto hsl_pink = new hsl(300.f, 1.f, 0.5f, d65_2deg);

	auto red_red_sub = color_manipulation::color_calculation::subtract(hsl_red, hsl_red);
	EXPECT_NEAR(0.f, red_red_sub->hue(), avg_error);
	EXPECT_NEAR(1.f, red_red_sub->saturation(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->lightness(), avg_error);

	auto pink_blue_sub1 = color_manipulation::color_calculation::subtract(hsl_pink, hsl_blue);
	EXPECT_NEAR(0.f, pink_blue_sub1->hue(), avg_error);
	EXPECT_NEAR(1.f, pink_blue_sub1->saturation(), avg_error);
	EXPECT_NEAR(0.f, pink_blue_sub1->lightness(), avg_error);

	auto pink_blue_sub2 = color_manipulation::color_calculation::subtract(hsl_pink, hsl_blue, 0.5f);
	EXPECT_NEAR(330.f, pink_blue_sub2->hue(), avg_error);
	EXPECT_NEAR(0.76f, pink_blue_sub2->saturation(), avg_error);
	EXPECT_NEAR(0.28f, pink_blue_sub2->lightness(), avg_error);

	auto pink_blue_sub3 = color_manipulation::color_calculation::subtract(hsl_pink, hsl_blue, 0.25f);
	EXPECT_NEAR(313.f, pink_blue_sub3->hue(), avg_error);
	EXPECT_NEAR(0.82f, pink_blue_sub3->saturation(), avg_error);
	EXPECT_NEAR(0.41f, pink_blue_sub3->lightness(), avg_error);
}

TEST_F(ColorCalculator_Test, XYZ_Subtract)
{
	auto xyz_red = new xyz(41.2f, 21.3f, 2.f, d65_2deg);
	auto xyz_blue = new xyz(18.f, 7.2f, 100.f, d65_2deg);
	auto xyz_pink = new xyz(59.2f, 28.5f, 100.f, d65_2deg);

	auto red_red_sub = color_manipulation::color_calculation::subtract(xyz_red, xyz_red);
	EXPECT_NEAR(0.f, red_red_sub->x(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->y(), avg_error);
	EXPECT_NEAR(0.f, red_red_sub->z(), avg_error);

	auto pink_blue_sub1 = color_manipulation::color_calculation::subtract(xyz_pink, xyz_blue);
	EXPECT_NEAR(41.2f, pink_blue_sub1->x(), avg_error);
	EXPECT_NEAR(21.3f, pink_blue_sub1->y(), avg_error);
	EXPECT_NEAR(0.f, pink_blue_sub1->z(), avg_error);

	auto pink_blue_sub2 = color_manipulation::color_calculation::subtract(xyz_pink, xyz_blue, 0.5f);
	EXPECT_NEAR(50.2f, pink_blue_sub2->x(), avg_error);
	EXPECT_NEAR(24.9f, pink_blue_sub2->y(), avg_error);
	EXPECT_NEAR(50.f, pink_blue_sub2->z(), avg_error);

	auto pink_blue_sub3 = color_manipulation::color_calculation::subtract(xyz_pink, xyz_blue, 0.25f);
	EXPECT_NEAR(54.7f, pink_blue_sub3->x(), avg_error);
	EXPECT_NEAR(26.7f, pink_blue_sub3->y(), avg_error);
	EXPECT_NEAR(75.f, pink_blue_sub3->z(), avg_error);
}

TEST_F(ColorCalculator_Test, RGB_True_Average)
{
	auto colors = std::vector<rgb_truecolor*>();
	colors.push_back(new rgb_truecolor(255.f, 0.f, 0.f, 255.f, d65_2deg));
	colors.push_back(new rgb_truecolor(0.f, 0.f, 255.f, 255.f, d65_2deg));
	colors.push_back(new rgb_truecolor(255.f, 0.f, 255.f, 255.f, d65_2deg));
	colors.push_back(new rgb_truecolor(180.f, 0.f, 180.f, 255.f, d65_2deg));
	colors.push_back(new rgb_truecolor(127.f, 0.f, 255.f, 255.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_rgb_true(colors);
	ASSERT_NEAR(163.4f, avg->red(), avg_error);
	ASSERT_NEAR(0.f, avg->green(), avg_error);
	ASSERT_NEAR(189.f, avg->blue(), avg_error);
	ASSERT_NEAR(255.f, avg->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, RGB_Deep_Average)
{
	auto colors = std::vector<rgb_deepcolor*>();
	colors.push_back(new rgb_deepcolor(1.f, 0.f, 0.f, 1.f, d65_2deg));
	colors.push_back(new rgb_deepcolor(0.f, 0.f, 1.f, 1.f, d65_2deg));
	colors.push_back(new rgb_deepcolor(1.f, 0.f, 1.f, 1.f, d65_2deg));
	colors.push_back(new rgb_deepcolor(0.7f, 0.f, 0.7f, 1.f, d65_2deg));
	colors.push_back(new rgb_deepcolor(0.5f, 0.f, 1.f, 1.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_rgb_deep(colors);
	ASSERT_NEAR(0.64f, avg->red(), avg_error);
	ASSERT_NEAR(0.f, avg->green(), avg_error);
	ASSERT_NEAR(0.74f, avg->blue(), avg_error);
	ASSERT_NEAR(1.f, avg->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, Grey_True_Average)
{
	auto colors = std::vector<grey_truecolor*>();
	colors.push_back(new grey_truecolor(64.f, 255.f, d65_2deg));
	colors.push_back(new grey_truecolor(128.f, 255.f, d65_2deg));
	colors.push_back(new grey_truecolor(192.f, 255.f, d65_2deg));
	colors.push_back(new grey_truecolor(96.f, 255.f, d65_2deg));
	colors.push_back(new grey_truecolor(144.f, 255.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_grey_true(colors);
	ASSERT_NEAR(124.8f, avg->grey(), avg_error);
	ASSERT_NEAR(255.f, avg->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, Grey_Deep_Average)
{
	auto colors = std::vector<grey_deepcolor*>();
	colors.push_back(new grey_deepcolor(0.25f, 1.f, d65_2deg));
	colors.push_back(new grey_deepcolor(0.5f, 1.f, d65_2deg));
	colors.push_back(new grey_deepcolor(0.75f, 1.f, d65_2deg));
	colors.push_back(new grey_deepcolor(0.375f, 1.f, d65_2deg));
	colors.push_back(new grey_deepcolor(0.56f, 1.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_grey_deep(colors);
	ASSERT_NEAR(0.48f, avg->grey(), avg_error);
	ASSERT_NEAR(1.f, avg->alpha(), avg_error);
}

TEST_F(ColorCalculator_Test, CMYK_Average)
{
	auto colors = std::vector<cmyk*>();
	colors.push_back(new cmyk(1.f, 0.f, 0.f, 0.f, d65_2deg));
	colors.push_back(new cmyk(0.f, 0.f, 1.f, 0.f, d65_2deg));
	colors.push_back(new cmyk(1.f, 0.f, 1.f, 0.f, d65_2deg));
	colors.push_back(new cmyk(0.5f, 0.f, 0.5f, 0.f, d65_2deg));
	colors.push_back(new cmyk(0.25f, 0.f, 1.f, 0.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_cmyk(colors);
	ASSERT_NEAR(0.55f, avg->cyan(), avg_error);
	ASSERT_NEAR(0.f, avg->magenta(), avg_error);
	ASSERT_NEAR(0.7f, avg->yellow(), avg_error);
	ASSERT_NEAR(0.f, avg->black(), avg_error);
}

TEST_F(ColorCalculator_Test, HSV_Average)
{
	auto colors = std::vector<hsv*>();
	colors.push_back(new hsv(0.f, 1.f, 1.f, d65_2deg));
	colors.push_back(new hsv(240.f, 1.f, 1.f, d65_2deg));
	colors.push_back(new hsv(300.f, 1.f, 1.f, d65_2deg));
	colors.push_back(new hsv(300.f, 0.5f, 1.f, d65_2deg));
	colors.push_back(new hsv(253.f, 0.9f, 1.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_hsv(colors);
	ASSERT_NEAR(218.f, avg->hue(), avg_error);
	ASSERT_NEAR(0.88f, avg->saturation(), avg_error);
	ASSERT_NEAR(1.f, avg->value(), avg_error);
}

TEST_F(ColorCalculator_Test, HSL_Average)
{
	auto colors = std::vector<hsl*>();
	colors.push_back(new hsl(0.f, 1.f, 0.5f, d65_2deg));
	colors.push_back(new hsl(240.f, 1.f, 0.5f, d65_2deg));
	colors.push_back(new hsl(300.f, 1.f, 0.5f, d65_2deg));
	colors.push_back(new hsl(300.f, 0.5f, 0.5f, d65_2deg));
	colors.push_back(new hsl(253.f, 0.9f, 0.5f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_hsl(colors);
	ASSERT_NEAR(218.f, avg->hue(), avg_error);
	ASSERT_NEAR(0.88f, avg->saturation(), avg_error);
	ASSERT_NEAR(0.5f, avg->lightness(), avg_error);
}

TEST_F(ColorCalculator_Test, XYZ_Average)
{
	auto colors = std::vector<xyz*>();
	colors.push_back(new xyz(41.2f, 21.3f, 2.f, d65_2deg));
	colors.push_back(new xyz(18.f, 7.2f, 100.f, d65_2deg));
	colors.push_back(new xyz(59.2f, 28.5f, 100.f, d65_2deg));
	colors.push_back(new xyz(29.6f, 14.25f, 51.f, d65_2deg));
	colors.push_back(new xyz(28.3f, 12.5f, 100.f, d65_2deg));

	auto avg = color_manipulation::color_calculation::average_xyz(colors);
	ASSERT_NEAR(35.26f, avg->x(), avg_error);
	ASSERT_NEAR(16.75f, avg->y(), avg_error);
	ASSERT_NEAR(70.6f, avg->z(), avg_error);
}