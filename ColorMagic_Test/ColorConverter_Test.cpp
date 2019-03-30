#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\icolor.h"
#include "..\ColorMagic\spaces\cmyk.h"
#include "..\ColorMagic\spaces\grey_deepcolor.h"
#include "..\ColorMagic\spaces\grey_truecolor.h"
#include "..\ColorMagic\spaces\hsl.h"
#include "..\ColorMagic\spaces\hsv.h"
#include "..\ColorMagic\spaces\lab.h"
#include "..\ColorMagic\spaces\rgb_deepcolor.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\spaces\xyz.h"
#include "..\ColorMagic\manipulation\color_converter.h"

using namespace color_space;

class ColorConverter_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	cmyk* cmyk_yellow;
	hsv* hsv_yellow;
	hsl* hsl_yellow;
	xyz* xyz_yellow;
	lab* lab_yellow;
	grey_deepcolor* grey_d;
	grey_truecolor* grey_t;
	rgb_deepcolor* rgb_d_yellow;
	rgb_truecolor* rgb_t_yellow;

	virtual void SetUp()
	{
		cmyk_yellow = new cmyk(0.f, 0.f, 1.f, 0.f);
		hsv_yellow = new hsv(60.f, 1.f, 1.f);
		hsl_yellow = new hsl(60.f, 1.f, 0.5f);
		xyz_yellow = new xyz(77.f, 92.78f, 13.85f);
		lab_yellow = new lab(97.14f, -21.56f, 94.48f);
		grey_d = new grey_deepcolor(0.6666f);
		grey_t = new grey_truecolor((unsigned char)170);
		rgb_d_yellow = new rgb_deepcolor(1.f, 1.f, 0.f);
		rgb_t_yellow = new rgb_truecolor((unsigned char)255, (unsigned char)255, (unsigned char)0);
	}

	virtual void TearDown()
	{
		delete cmyk_yellow;
		delete hsv_yellow;
		delete hsl_yellow;
		delete xyz_yellow;
		delete lab_yellow;
		delete grey_d;
		delete grey_t;
		delete rgb_d_yellow;
		delete rgb_t_yellow;
	}
};

TEST_F(ColorConverter_Test, From_RGB_True)
{
	EXPECT_EQ(*cmyk_yellow, *dynamic_cast<cmyk*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::CMYK)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::RGB_DEEP)));

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->hue(), hsv_converted->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->hue(), hsl_converted->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), hsl_converted->lightness(), avg_error);
	
	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->x(), xyz_converted->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), xyz_converted->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->luminance(), lab_converted->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), lab_converted->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_RGB_Deep)
{
	EXPECT_EQ(*cmyk_yellow, *dynamic_cast<cmyk*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::CMYK)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::RGB_TRUE)));

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->hue(), hsv_converted->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->hue(), hsl_converted->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), hsl_converted->lightness(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->x(), xyz_converted->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), xyz_converted->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->luminance(), lab_converted->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), lab_converted->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_Grey_True)
{
	EXPECT_EQ(*(new rgb_truecolor((unsigned char)170)), *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::CMYK));
	EXPECT_NEAR(0.f, cmyk_converted->cyan(), avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->magenta(), avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->yellow(), avg_error);
	EXPECT_NEAR(0.33f, cmyk_converted->black(), avg_error);

	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::RGB_DEEP));
	EXPECT_NEAR(0.66f, rgb_d_converted->red(), avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->green(), avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->blue(), avg_error);
	EXPECT_NEAR(1.f, rgb_d_converted->alpha(), avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::HSV));
	EXPECT_NEAR(0.f, hsv_converted->hue(), avg_error);
	EXPECT_NEAR(0.f, hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(0.66f, hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::HSL));
	EXPECT_NEAR(0.f, hsl_converted->hue(), avg_error);
	EXPECT_NEAR(0.f, hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(0.66f, hsl_converted->lightness(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::XYZ));
	EXPECT_NEAR(38.21f, xyz_converted->x(), avg_error);
	EXPECT_NEAR(40.20f, xyz_converted->y(), avg_error);
	EXPECT_NEAR(43.78f, xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::LAB));
	EXPECT_NEAR(69.61f, lab_converted->luminance(), avg_error);
	EXPECT_NEAR(0.f, lab_converted->a(), avg_error);
	EXPECT_NEAR(0.f, lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_grey_true(grey_t, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_Grey_Deep)
{
	auto rgb_t_converted = dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::RGB_TRUE));
	EXPECT_NEAR(170, rgb_t_converted->red(), avg_error);
	EXPECT_NEAR(170, rgb_t_converted->green(), avg_error);
	EXPECT_NEAR(170, rgb_t_converted->blue(), avg_error);
	EXPECT_NEAR(255, rgb_t_converted->alpha(), avg_error);

	auto cmyk_converted = dynamic_cast<cmyk*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::CMYK));
	EXPECT_NEAR(0.f, cmyk_converted->cyan(), avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->magenta(), avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->yellow(), avg_error);
	EXPECT_NEAR(0.33f, cmyk_converted->black(), avg_error);

	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::RGB_DEEP));
	EXPECT_NEAR(0.66f, rgb_d_converted->red(), avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->green(), avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->blue(), avg_error);
	EXPECT_NEAR(1.f, rgb_d_converted->alpha(), avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::HSV));
	EXPECT_NEAR(0.f, hsv_converted->hue(), avg_error);
	EXPECT_NEAR(0.f, hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(0.66f, hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::HSL));
	EXPECT_NEAR(0.f, hsl_converted->hue(), avg_error);
	EXPECT_NEAR(0.f, hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(0.66f, hsl_converted->lightness(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::XYZ));
	EXPECT_NEAR(38.21f, xyz_converted->x(), avg_error);
	EXPECT_NEAR(40.20f, xyz_converted->y(), avg_error);
	EXPECT_NEAR(43.78f, xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::LAB));
	EXPECT_NEAR(69.61f, lab_converted->luminance(), avg_error);
	EXPECT_NEAR(0.f, lab_converted->a(), avg_error);
	EXPECT_NEAR(0.f, lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_grey_deep(grey_d, color_type::GREY_TRUE));
	EXPECT_NEAR(grey_t->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_CMYK)
{
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::RGB_DEEP)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::RGB_TRUE)));

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->hue(), hsv_converted->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->hue(), hsl_converted->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), hsl_converted->lightness(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->x(), xyz_converted->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), xyz_converted->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->luminance(), lab_converted->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), lab_converted->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_cmyk(cmyk_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_HSV)
{
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::RGB_DEEP)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->cyan(), cmyk_converted->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), cmyk_converted->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), cmyk_converted->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), cmyk_converted->black(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->hue(), hsl_converted->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), hsl_converted->lightness(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->x(), xyz_converted->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), xyz_converted->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->luminance(), lab_converted->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), lab_converted->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_hsv(hsv_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_HSL)
{
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::RGB_DEEP)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->cyan(), cmyk_converted->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), cmyk_converted->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), cmyk_converted->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), cmyk_converted->black(), avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->hue(), hsv_converted->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), hsv_converted->value(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->x(), xyz_converted->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), xyz_converted->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), xyz_converted->z(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->luminance(), lab_converted->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), lab_converted->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_hsl(hsl_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_XYZ)
{
	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::RGB_DEEP));
	EXPECT_NEAR(rgb_d_yellow->red(), rgb_d_converted->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), rgb_d_converted->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), rgb_d_converted->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), rgb_d_converted->alpha(), avg_error);

	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->cyan(), cmyk_converted->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), cmyk_converted->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), cmyk_converted->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), cmyk_converted->black(), avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->hue(), hsv_converted->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->hue(), hsl_converted->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), hsl_converted->lightness(), avg_error);

	auto lab_converted = dynamic_cast<lab*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->luminance(), lab_converted->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), lab_converted->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), lab_converted->b(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_xyz(xyz_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, From_LAB)
{
	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::RGB_DEEP));
	EXPECT_NEAR(rgb_d_yellow->red(), rgb_d_converted->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), rgb_d_converted->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), rgb_d_converted->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), rgb_d_converted->alpha(), avg_error);

	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->cyan(), cmyk_converted->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), cmyk_converted->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), cmyk_converted->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), cmyk_converted->black(), avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->hue(), hsv_converted->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), hsv_converted->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), hsv_converted->value(), avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->hue(), hsl_converted->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), hsl_converted->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), hsl_converted->lightness(), avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->x(), xyz_converted->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), xyz_converted->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), xyz_converted->z(), avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(color_manipulation::color_converter::from_lab(lab_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->grey(), grey_converted->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), grey_converted->alpha(), avg_error);
}