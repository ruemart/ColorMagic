#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\manipulation\color_calculation.h"

using namespace color_space;

class ColorCalculator_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
};

TEST_F(ColorCalculator_Test, RGB_True_Add)
{
	auto rgb_t_red = new rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);
	auto rgb_t_blue = new rgb_truecolor((unsigned char)0, (unsigned char)0, (unsigned char)255);
	auto rgb_t_pink = new rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)255);
	auto rgb_t_purple = new rgb_truecolor((unsigned char)180, (unsigned char)0, (unsigned char)180);
	auto rgb_t_dark_purple = new rgb_truecolor((unsigned char)127, (unsigned char)0, (unsigned char)255);

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
	auto rgb_d_red = new rgb_deepcolor(1.f, 0.f, 0.f);
	auto rgb_d_blue = new rgb_deepcolor(0.f, 0.f, 1.f);
	auto rgb_d_pink = new rgb_deepcolor(1.f, 0.f, 1.f);
	auto rgb_d_purple = new rgb_deepcolor(0.7f, 0.f, 0.7f);
	auto rgb_d_dark_purple = new rgb_deepcolor(0.5f, 0.f, 1.f);

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
	auto grey1 = new grey_truecolor((unsigned char)64);
	auto grey2 = new grey_truecolor((unsigned char)128);
	auto grey_mix_1 = new grey_truecolor((unsigned char)192);
	auto grey_mix_2 = new grey_truecolor((unsigned char)96);
	auto grey_mix_3 = new grey_truecolor((unsigned char)144);

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
	auto grey1 = new grey_deepcolor(0.25f);
	auto grey2 = new grey_deepcolor(0.5f);
	auto grey_mix_1 = new grey_deepcolor(0.75f);
	auto grey_mix_2 = new grey_deepcolor(0.375f);
	auto grey_mix_3 = new grey_deepcolor(0.56f);

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
	auto cmyk_cyan = new cmyk(1.f, 0.f, 0.f, 0.f);
	auto cmyk_yellow = new cmyk(0.f, 0.f, 1.f, 0.f);
	auto cmyk_green = new cmyk(1.f, 0.f, 1.f, 0.f);
	auto cmyk_lime = new cmyk(0.5f, 0.f, 0.5f, 0.f);
	auto cmyk_lemon = new cmyk(0.25f, 0.f, 1.f, 0.f);

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

TEST_F(ColorCalculator_Test, HSV)
{
	auto hsv_red = new hsv(0.f, 1.f, 1.f);
	auto hsv_blue = new hsv(240.f, 1.f, 1.f);
	auto hsv_pink = new hsv(300.f, 1.f, 1.f);
	auto hsv_rose = new hsv(300.f, 0.5f, 1.f);
	auto hsv_purple = new hsv(253.f, 0.9f, 1.f);

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

TEST_F(ColorCalculator_Test, HSL)
{
	auto hsv_red = new hsl(0.f, 1.f, 0.5f);
	auto hsv_blue = new hsl(240.f, 1.f, 0.5f);
	auto hsv_pink = new hsl(300.f, 1.f, 0.5f);
	auto hsv_rose = new hsl(300.f, 1.f, 0.75f);
	auto hsv_purple = new hsl(253.f, 1.f, 0.55f);

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

TEST_F(ColorCalculator_Test, XYZ)
{
	auto xyz_red = new xyz(41.2f, 21.3f, 2.f);
	auto xyz_blue = new xyz(18.f, 7.2f, 100.f);
	auto xyz_pink = new xyz(59.2f, 28.5f, 100.f);
	auto xyz_purple1 = new xyz(29.6f, 14.25f, 51.f);
	auto xyz_purple2 = new xyz(28.3f, 12.5f, 100.f);

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