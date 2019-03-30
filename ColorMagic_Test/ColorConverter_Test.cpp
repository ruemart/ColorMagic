#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\ColorSpaces\icolor.h"
#include "..\ColorMagic\ColorSpaces\cmyk.h"
#include "..\ColorMagic\ColorSpaces\grey_deepcolor.h"
#include "..\ColorMagic\ColorSpaces\grey_truecolor.h"
#include "..\ColorMagic\ColorSpaces\hsl.h"
#include "..\ColorMagic\ColorSpaces\hsv.h"
#include "..\ColorMagic\ColorSpaces\lab.h"
#include "..\ColorMagic\ColorSpaces\rgb_deepcolor.h"
#include "..\ColorMagic\ColorSpaces\rgb_truecolor.h"
#include "..\ColorMagic\ColorSpaces\xyz.h"
#include "..\ColorMagic\color_converter.h"

using namespace ColorSpaces;

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
	EXPECT_EQ(*cmyk_yellow, *dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::CMYK)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::RGB_DEEP)));

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->m_hue, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(hsv_yellow->m_saturation, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsv_yellow->m_value, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->m_hue, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(hsl_yellow->m_saturation, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsl_yellow->m_lightness, hsl_converted->m_lightness, avg_error);
	
	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->m_x, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(xyz_yellow->m_y, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(xyz_yellow->m_z, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->m_luminance, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(lab_yellow->m_a, lab_converted->m_a, avg_error);
	EXPECT_NEAR(lab_yellow->m_b, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_rgb_true(rgb_t_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_RGB_Deep)
{
	EXPECT_EQ(*cmyk_yellow, *dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::CMYK)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::RGB_TRUE)));

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->m_hue, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(hsv_yellow->m_saturation, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsv_yellow->m_value, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->m_hue, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(hsl_yellow->m_saturation, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsl_yellow->m_lightness, hsl_converted->m_lightness, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->m_x, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(xyz_yellow->m_y, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(xyz_yellow->m_z, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->m_luminance, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(lab_yellow->m_a, lab_converted->m_a, avg_error);
	EXPECT_NEAR(lab_yellow->m_b, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_rgb_deep(rgb_d_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_Grey_True)
{
	EXPECT_EQ(*(new rgb_truecolor((unsigned char)170)), *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::CMYK));
	EXPECT_NEAR(0.f, cmyk_converted->m_cyan, avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->m_magenta, avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->m_yellow, avg_error);
	EXPECT_NEAR(0.33f, cmyk_converted->m_black, avg_error);

	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::RGB_DEEP));
	EXPECT_NEAR(0.66f, rgb_d_converted->m_red, avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->m_green, avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->m_blue, avg_error);
	EXPECT_NEAR(1.f, rgb_d_converted->m_alpha, avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::HSV));
	EXPECT_NEAR(0.f, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(0.f, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(0.66f, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::HSL));
	EXPECT_NEAR(0.f, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(0.f, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(0.66f, hsl_converted->m_lightness, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::XYZ));
	EXPECT_NEAR(38.21f, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(40.20f, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(43.78f, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::LAB));
	EXPECT_NEAR(69.61f, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(0.f, lab_converted->m_a, avg_error);
	EXPECT_NEAR(0.f, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_grey_true(grey_t, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_Grey_Deep)
{
	auto rgb_t_converted = dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::RGB_TRUE));
	EXPECT_NEAR(170, rgb_t_converted->m_red, avg_error);
	EXPECT_NEAR(170, rgb_t_converted->m_green, avg_error);
	EXPECT_NEAR(170, rgb_t_converted->m_blue, avg_error);
	EXPECT_NEAR(255, rgb_t_converted->m_alpha, avg_error);

	auto cmyk_converted = dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::CMYK));
	EXPECT_NEAR(0.f, cmyk_converted->m_cyan, avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->m_magenta, avg_error);
	EXPECT_NEAR(0.f, cmyk_converted->m_yellow, avg_error);
	EXPECT_NEAR(0.33f, cmyk_converted->m_black, avg_error);

	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::RGB_DEEP));
	EXPECT_NEAR(0.66f, rgb_d_converted->m_red, avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->m_green, avg_error);
	EXPECT_NEAR(0.66f, rgb_d_converted->m_blue, avg_error);
	EXPECT_NEAR(1.f, rgb_d_converted->m_alpha, avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::HSV));
	EXPECT_NEAR(0.f, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(0.f, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(0.66f, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::HSL));
	EXPECT_NEAR(0.f, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(0.f, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(0.66f, hsl_converted->m_lightness, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::XYZ));
	EXPECT_NEAR(38.21f, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(40.20f, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(43.78f, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::LAB));
	EXPECT_NEAR(69.61f, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(0.f, lab_converted->m_a, avg_error);
	EXPECT_NEAR(0.f, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_grey_deep(grey_d, color_type::GREY_TRUE));
	EXPECT_NEAR(grey_t->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_t->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_CMYK)
{
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::RGB_DEEP)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::RGB_TRUE)));

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->m_hue, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(hsv_yellow->m_saturation, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsv_yellow->m_value, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->m_hue, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(hsl_yellow->m_saturation, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsl_yellow->m_lightness, hsl_converted->m_lightness, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->m_x, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(xyz_yellow->m_y, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(xyz_yellow->m_z, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->m_luminance, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(lab_yellow->m_a, lab_converted->m_a, avg_error);
	EXPECT_NEAR(lab_yellow->m_b, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_cmyk(cmyk_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_HSV)
{
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::RGB_DEEP)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->m_cyan, cmyk_converted->m_cyan, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_magenta, cmyk_converted->m_magenta, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_yellow, cmyk_converted->m_yellow, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_black, cmyk_converted->m_black, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->m_hue, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(hsl_yellow->m_saturation, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsl_yellow->m_lightness, hsl_converted->m_lightness, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->m_x, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(xyz_yellow->m_y, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(xyz_yellow->m_z, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->m_luminance, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(lab_yellow->m_a, lab_converted->m_a, avg_error);
	EXPECT_NEAR(lab_yellow->m_b, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_hsv(hsv_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_HSL)
{
	EXPECT_EQ(*rgb_d_yellow, *dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::RGB_DEEP)));
	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->m_cyan, cmyk_converted->m_cyan, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_magenta, cmyk_converted->m_magenta, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_yellow, cmyk_converted->m_yellow, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_black, cmyk_converted->m_black, avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->m_hue, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(hsv_yellow->m_saturation, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsv_yellow->m_value, hsv_converted->m_value, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->m_x, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(xyz_yellow->m_y, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(xyz_yellow->m_z, xyz_converted->m_z, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->m_luminance, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(lab_yellow->m_a, lab_converted->m_a, avg_error);
	EXPECT_NEAR(lab_yellow->m_b, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_hsl(hsl_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_XYZ)
{
	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::RGB_DEEP));
	EXPECT_NEAR(rgb_d_yellow->m_red, rgb_d_converted->m_red, avg_error);
	EXPECT_NEAR(rgb_d_yellow->m_green, rgb_d_converted->m_green, avg_error);
	EXPECT_NEAR(rgb_d_yellow->m_blue, rgb_d_converted->m_blue, avg_error);
	EXPECT_NEAR(rgb_d_yellow->m_alpha, rgb_d_converted->m_alpha, avg_error);

	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->m_cyan, cmyk_converted->m_cyan, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_magenta, cmyk_converted->m_magenta, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_yellow, cmyk_converted->m_yellow, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_black, cmyk_converted->m_black, avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->m_hue, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(hsv_yellow->m_saturation, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsv_yellow->m_value, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->m_hue, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(hsl_yellow->m_saturation, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsl_yellow->m_lightness, hsl_converted->m_lightness, avg_error);

	auto lab_converted = dynamic_cast<lab*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::LAB));
	EXPECT_NEAR(lab_yellow->m_luminance, lab_converted->m_luminance, avg_error);
	EXPECT_NEAR(lab_yellow->m_a, lab_converted->m_a, avg_error);
	EXPECT_NEAR(lab_yellow->m_b, lab_converted->m_b, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_xyz(xyz_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}

TEST_F(ColorConverter_Test, From_LAB)
{
	auto rgb_d_converted = dynamic_cast<rgb_deepcolor*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::RGB_DEEP));
	EXPECT_NEAR(rgb_d_yellow->m_red, rgb_d_converted->m_red, avg_error);
	EXPECT_NEAR(rgb_d_yellow->m_green, rgb_d_converted->m_green, avg_error);
	EXPECT_NEAR(rgb_d_yellow->m_blue, rgb_d_converted->m_blue, avg_error);
	EXPECT_NEAR(rgb_d_yellow->m_alpha, rgb_d_converted->m_alpha, avg_error);

	EXPECT_EQ(*grey_t, *dynamic_cast<grey_truecolor*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::GREY_TRUE)));
	EXPECT_EQ(*rgb_t_yellow, *dynamic_cast<rgb_truecolor*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::RGB_TRUE)));

	auto cmyk_converted = dynamic_cast<cmyk*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::CMYK));
	EXPECT_NEAR(cmyk_yellow->m_cyan, cmyk_converted->m_cyan, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_magenta, cmyk_converted->m_magenta, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_yellow, cmyk_converted->m_yellow, avg_error);
	EXPECT_NEAR(cmyk_yellow->m_black, cmyk_converted->m_black, avg_error);

	auto hsv_converted = dynamic_cast<hsv*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::HSV));
	EXPECT_NEAR(hsv_yellow->m_hue, hsv_converted->m_hue, avg_error);
	EXPECT_NEAR(hsv_yellow->m_saturation, hsv_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsv_yellow->m_value, hsv_converted->m_value, avg_error);

	auto hsl_converted = dynamic_cast<hsl*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::HSL));
	EXPECT_NEAR(hsl_yellow->m_hue, hsl_converted->m_hue, avg_error);
	EXPECT_NEAR(hsl_yellow->m_saturation, hsl_converted->m_saturation, avg_error);
	EXPECT_NEAR(hsl_yellow->m_lightness, hsl_converted->m_lightness, avg_error);

	auto xyz_converted = dynamic_cast<xyz*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::XYZ));
	EXPECT_NEAR(xyz_yellow->m_x, xyz_converted->m_x, avg_error);
	EXPECT_NEAR(xyz_yellow->m_y, xyz_converted->m_y, avg_error);
	EXPECT_NEAR(xyz_yellow->m_z, xyz_converted->m_z, avg_error);

	auto grey_converted = dynamic_cast<grey_deepcolor*>(ColorManipulation::color_converter::from_lab(lab_yellow, color_type::GREY_DEEP));
	EXPECT_NEAR(grey_d->m_grey, grey_converted->m_grey, avg_error);
	EXPECT_NEAR(grey_d->m_alpha, grey_converted->m_alpha, avg_error);
}