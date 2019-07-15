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
#include "..\ColorMagic\manipulation\color_converter.h"

using namespace color_space;

class ColorConverter_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	cmyk* cmyk_yellow;
	hsv* hsv_yellow;
	hsl* hsl_yellow;
	xyz* xyz_yellow;
	xyz* xyz_blue;
	xyy* xyy_yellow;
	xyy* xyy_blue;
	lab* lab_yellow;
	grey_deepcolor* grey_d;
	grey_truecolor* grey_t;
	rgb_deepcolor* rgb_d_yellow;
	rgb_truecolor* rgb_t_yellow;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		cmyk_yellow = new cmyk(0.f, 0.f, 1.f, 0.f, 1.f, srgb);
		hsv_yellow = new hsv(60.f, 1.f, 1.f, 1.f, srgb);
		hsl_yellow = new hsl(60.f, 1.f, 0.5f, 1.f, srgb);
		xyz_yellow = new xyz(0.77f, 0.9278f, 0.1385f, 1.f, srgb);
		xyz_blue = new xyz(0.18f, 0.072f, 0.95f, 1.f, srgb);
		xyy_yellow = new xyy(0.42f, 0.505f, 0.928f, 1.f, srgb);
		xyy_blue = new xyy(0.15f, 0.06f, 0.072f, 1.f, srgb);
		lab_yellow = new lab(97.14f, -21.56f, 94.48f, 1.f, srgb);
		grey_d = new grey_deepcolor(0.6666f, 1.f, srgb);
		grey_t = new grey_truecolor(170.f, 255.f, srgb);
		rgb_d_yellow = new rgb_deepcolor(1.f, 1.f, 0.f, 1.f, srgb);
		rgb_t_yellow = new rgb_truecolor(255.f, 255.f, 0.f, 255.f, srgb);
	}

	virtual void TearDown()
	{
		delete cmyk_yellow;
		delete hsv_yellow;
		delete hsl_yellow;
		delete xyz_yellow;
		delete xyz_blue;
		delete xyy_yellow;
		delete xyy_blue;
		delete lab_yellow;
		delete grey_d;
		delete grey_t;
		delete rgb_d_yellow;
		delete rgb_t_yellow;
	}
};

TEST_F(ColorConverter_Test, To_RGB_True)
{
	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(rgb_t_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(rgb_t_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(rgb_t_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(rgb_t_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(rgb_d_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(rgb_d_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(rgb_d_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(rgb_d_yellow)->alpha(), avg_error);

	EXPECT_NEAR(170.f, color_manipulation::color_converter::to_rgb_true(grey_t)->red(), avg_error);
	EXPECT_NEAR(170.f, color_manipulation::color_converter::to_rgb_true(grey_t)->green(), avg_error);
	EXPECT_NEAR(170.f, color_manipulation::color_converter::to_rgb_true(grey_t)->blue(), avg_error);
	EXPECT_NEAR(255.f, color_manipulation::color_converter::to_rgb_true(grey_t)->alpha(), avg_error);

	EXPECT_NEAR(170.f, color_manipulation::color_converter::to_rgb_true(grey_d)->red(), avg_error);
	EXPECT_NEAR(170.f, color_manipulation::color_converter::to_rgb_true(grey_d)->green(), avg_error);
	EXPECT_NEAR(170.f, color_manipulation::color_converter::to_rgb_true(grey_d)->blue(), avg_error);
	EXPECT_NEAR(255.f, color_manipulation::color_converter::to_rgb_true(grey_d)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(cmyk_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(cmyk_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(cmyk_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(cmyk_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(hsv_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(hsv_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(hsv_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(hsv_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(hsl_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(hsl_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(hsl_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(hsl_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(xyz_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(xyz_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(xyz_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(xyz_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(xyy_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(xyy_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(xyy_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(xyy_yellow)->alpha(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_rgb_true(xyy_blue)->red(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_rgb_true(xyy_blue)->green(), avg_error);
	EXPECT_NEAR(255.f, color_manipulation::color_converter::to_rgb_true(xyy_blue)->blue(), avg_error);
	EXPECT_NEAR(255.f, color_manipulation::color_converter::to_rgb_true(xyy_blue)->alpha(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), color_manipulation::color_converter::to_rgb_true(lab_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), color_manipulation::color_converter::to_rgb_true(lab_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), color_manipulation::color_converter::to_rgb_true(lab_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->alpha(), color_manipulation::color_converter::to_rgb_true(lab_yellow)->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, To_RGB_Deep)
{
	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(rgb_t_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(rgb_t_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(rgb_t_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(rgb_t_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(rgb_d_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(rgb_d_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(rgb_d_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(rgb_d_yellow)->alpha(), avg_error);

	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_rgb_deep(grey_t)->red(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_rgb_deep(grey_t)->green(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_rgb_deep(grey_t)->blue(), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_converter::to_rgb_deep(grey_t)->alpha(), avg_error);

	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_rgb_deep(grey_d)->red(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_rgb_deep(grey_d)->green(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_rgb_deep(grey_d)->blue(), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_converter::to_rgb_deep(grey_d)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(cmyk_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(cmyk_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(cmyk_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(cmyk_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(hsv_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(hsv_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(hsv_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(hsv_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(hsl_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(hsl_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(hsl_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(hsl_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(xyz_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(xyz_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(xyz_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(xyz_yellow)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(xyy_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(xyy_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(xyy_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(xyy_yellow)->alpha(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_rgb_deep(xyy_blue)->red(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_rgb_deep(xyy_blue)->green(), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_converter::to_rgb_deep(xyy_blue)->blue(), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_converter::to_rgb_deep(xyy_blue)->alpha(), avg_error);

	EXPECT_NEAR(rgb_d_yellow->red(), color_manipulation::color_converter::to_rgb_deep(lab_yellow)->red(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->green(), color_manipulation::color_converter::to_rgb_deep(lab_yellow)->green(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->blue(), color_manipulation::color_converter::to_rgb_deep(lab_yellow)->blue(), avg_error);
	EXPECT_NEAR(rgb_d_yellow->alpha(), color_manipulation::color_converter::to_rgb_deep(lab_yellow)->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, To_Grey_True)
{
	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(rgb_t_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(rgb_t_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(rgb_d_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(rgb_d_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(grey_t)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(grey_t)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(grey_d)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(grey_d)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(cmyk_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(cmyk_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(hsv_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(hsv_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(hsl_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(hsl_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(xyz_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(xyz_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(xyy_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(xyy_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_t->grey(), color_manipulation::color_converter::to_grey_true(lab_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_t->alpha(), color_manipulation::color_converter::to_grey_true(lab_yellow)->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, To_Grey_Deep)
{
	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(rgb_t_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(rgb_t_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(rgb_d_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(rgb_d_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(grey_t)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(grey_t)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(grey_d)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(grey_d)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(cmyk_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(cmyk_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(hsv_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(hsv_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(hsl_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(hsl_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(xyz_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(xyz_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(xyy_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(xyy_yellow)->alpha(), avg_error);

	EXPECT_NEAR(grey_d->grey(), color_manipulation::color_converter::to_grey_deep(lab_yellow)->grey(), avg_error);
	EXPECT_NEAR(grey_d->alpha(), color_manipulation::color_converter::to_grey_deep(lab_yellow)->alpha(), avg_error);
}

TEST_F(ColorConverter_Test, To_CMYK)
{
	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(rgb_t_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(rgb_t_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(rgb_t_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(rgb_t_yellow)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(rgb_d_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(rgb_d_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(rgb_d_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(rgb_d_yellow)->black(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_cmyk(grey_t)->cyan(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_cmyk(grey_t)->magenta(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_cmyk(grey_t)->yellow(), avg_error);
	EXPECT_NEAR(0.33f, color_manipulation::color_converter::to_cmyk(grey_t)->black(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_cmyk(grey_d)->cyan(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_cmyk(grey_d)->magenta(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_cmyk(grey_d)->yellow(), avg_error);
	EXPECT_NEAR(0.33f, color_manipulation::color_converter::to_cmyk(grey_d)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(cmyk_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(cmyk_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(cmyk_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(cmyk_yellow)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(hsv_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(hsv_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(hsv_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(hsv_yellow)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(hsl_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(hsl_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(hsl_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(hsl_yellow)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(xyz_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(xyz_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(xyz_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(xyz_yellow)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(xyy_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(xyy_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(xyy_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(xyy_yellow)->black(), avg_error);

	EXPECT_NEAR(cmyk_yellow->cyan(), color_manipulation::color_converter::to_cmyk(lab_yellow)->cyan(), avg_error);
	EXPECT_NEAR(cmyk_yellow->magenta(), color_manipulation::color_converter::to_cmyk(lab_yellow)->magenta(), avg_error);
	EXPECT_NEAR(cmyk_yellow->yellow(), color_manipulation::color_converter::to_cmyk(lab_yellow)->yellow(), avg_error);
	EXPECT_NEAR(cmyk_yellow->black(), color_manipulation::color_converter::to_cmyk(lab_yellow)->black(), avg_error);
}

TEST_F(ColorConverter_Test, To_HSV)
{
	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(rgb_t_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(rgb_t_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(rgb_t_yellow)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(rgb_d_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(rgb_d_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(rgb_d_yellow)->value(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsv(grey_t)->hue(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsv(grey_t)->saturation(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_hsv(grey_t)->value(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsv(grey_d)->hue(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsv(grey_d)->saturation(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_hsv(grey_d)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(cmyk_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(cmyk_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(cmyk_yellow)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(hsv_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(hsv_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(hsv_yellow)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(hsl_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(hsl_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(hsl_yellow)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(xyz_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(xyz_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(xyz_yellow)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(xyy_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(xyy_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(xyy_yellow)->value(), avg_error);

	EXPECT_NEAR(hsv_yellow->hue(), color_manipulation::color_converter::to_hsv(lab_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsv_yellow->saturation(), color_manipulation::color_converter::to_hsv(lab_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsv_yellow->value(), color_manipulation::color_converter::to_hsv(lab_yellow)->value(), avg_error);
}

TEST_F(ColorConverter_Test, To_HSL)
{
	color_space::rgb_deepcolor* cyan = new color_space::rgb_deepcolor(0.f, 0.5747f, 0.5747f, 1.f, srgb);
	EXPECT_NEAR(180.f, color_manipulation::color_converter::to_hsl(cyan)->hue(), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_converter::to_hsl(cyan)->saturation(), avg_error);
	EXPECT_NEAR(0.2873f, color_manipulation::color_converter::to_hsl(cyan)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(rgb_t_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(rgb_t_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(rgb_t_yellow)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(rgb_d_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(rgb_d_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(rgb_d_yellow)->lightness(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsl(grey_t)->hue(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsl(grey_t)->saturation(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_hsl(grey_t)->lightness(), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsl(grey_d)->hue(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_hsl(grey_d)->saturation(), avg_error);
	EXPECT_NEAR(0.66f, color_manipulation::color_converter::to_hsl(grey_d)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(cmyk_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(cmyk_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(cmyk_yellow)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(hsv_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(hsv_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(hsv_yellow)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(hsl_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(hsl_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(hsl_yellow)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(xyz_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(xyz_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(xyz_yellow)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(xyy_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(xyy_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(xyy_yellow)->lightness(), avg_error);

	EXPECT_NEAR(hsl_yellow->hue(), color_manipulation::color_converter::to_hsl(lab_yellow)->hue(), avg_error);
	EXPECT_NEAR(hsl_yellow->saturation(), color_manipulation::color_converter::to_hsl(lab_yellow)->saturation(), avg_error);
	EXPECT_NEAR(hsl_yellow->lightness(), color_manipulation::color_converter::to_hsl(lab_yellow)->lightness(), avg_error);
}

TEST_F(ColorConverter_Test, To_XYZ)
{
	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(rgb_t_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(rgb_t_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(rgb_t_yellow)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(rgb_d_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(rgb_d_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(rgb_d_yellow)->z(), avg_error);

	EXPECT_NEAR(0.382f, color_manipulation::color_converter::to_xyz(grey_t)->x(), avg_error);
	EXPECT_NEAR(0.402f, color_manipulation::color_converter::to_xyz(grey_t)->y(), avg_error);
	EXPECT_NEAR(0.438f, color_manipulation::color_converter::to_xyz(grey_t)->z(), avg_error);

	EXPECT_NEAR(0.382f, color_manipulation::color_converter::to_xyz(grey_d)->x(), avg_error);
	EXPECT_NEAR(0.402f, color_manipulation::color_converter::to_xyz(grey_d)->y(), avg_error);
	EXPECT_NEAR(0.438f, color_manipulation::color_converter::to_xyz(grey_d)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(cmyk_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(cmyk_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(cmyk_yellow)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(hsv_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(hsv_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(hsv_yellow)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(hsl_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(hsl_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(hsl_yellow)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(xyz_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(xyz_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(xyz_yellow)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(xyy_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(xyy_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(xyy_yellow)->z(), avg_error);

	EXPECT_NEAR(xyz_blue->x(), color_manipulation::color_converter::to_xyz(xyy_blue)->x(), avg_error);
	EXPECT_NEAR(xyz_blue->y(), color_manipulation::color_converter::to_xyz(xyy_blue)->y(), avg_error);
	EXPECT_NEAR(xyz_blue->z(), color_manipulation::color_converter::to_xyz(xyy_blue)->z(), avg_error);

	EXPECT_NEAR(xyz_yellow->x(), color_manipulation::color_converter::to_xyz(lab_yellow)->x(), avg_error);
	EXPECT_NEAR(xyz_yellow->y(), color_manipulation::color_converter::to_xyz(lab_yellow)->y(), avg_error);
	EXPECT_NEAR(xyz_yellow->z(), color_manipulation::color_converter::to_xyz(lab_yellow)->z(), avg_error);
}

TEST_F(ColorConverter_Test, To_XYY)
{
	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(rgb_t_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(rgb_t_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(rgb_t_yellow)->Y(), avg_error);

	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(rgb_d_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(rgb_d_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(rgb_d_yellow)->Y(), avg_error);

	EXPECT_NEAR(0.3127f, color_manipulation::color_converter::to_xyy(grey_t)->x(), avg_error);
	EXPECT_NEAR(0.3290f, color_manipulation::color_converter::to_xyy(grey_t)->y(), avg_error);
	EXPECT_NEAR(0.4019f, color_manipulation::color_converter::to_xyy(grey_t)->Y(), avg_error);

	EXPECT_NEAR(0.3127f, color_manipulation::color_converter::to_xyy(grey_d)->x(), avg_error);
	EXPECT_NEAR(0.3290f, color_manipulation::color_converter::to_xyy(grey_d)->y(), avg_error);
	EXPECT_NEAR(0.4019f, color_manipulation::color_converter::to_xyy(grey_d)->Y(), avg_error);

	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(cmyk_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(cmyk_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(cmyk_yellow)->Y(), avg_error);

	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(hsv_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(hsv_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(hsv_yellow)->Y(), avg_error);
	
	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(hsl_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(hsl_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(hsl_yellow)->Y(), avg_error);
	
	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(xyz_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(xyz_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(xyz_yellow)->Y(), avg_error);

	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(xyy_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(xyy_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(xyy_yellow)->Y(), avg_error);

	EXPECT_NEAR(xyy_blue->x(), color_manipulation::color_converter::to_xyy(xyy_blue)->x(), avg_error);
	EXPECT_NEAR(xyy_blue->y(), color_manipulation::color_converter::to_xyy(xyy_blue)->y(), avg_error);
	EXPECT_NEAR(xyy_blue->Y(), color_manipulation::color_converter::to_xyy(xyy_blue)->Y(), avg_error);

	EXPECT_NEAR(xyy_yellow->x(), color_manipulation::color_converter::to_xyy(lab_yellow)->x(), avg_error);
	EXPECT_NEAR(xyy_yellow->y(), color_manipulation::color_converter::to_xyy(lab_yellow)->y(), avg_error);
	EXPECT_NEAR(xyy_yellow->Y(), color_manipulation::color_converter::to_xyy(lab_yellow)->Y(), avg_error);
}

TEST_F(ColorConverter_Test, To_LAB)
{
	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(rgb_t_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(rgb_t_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(rgb_t_yellow)->b(), avg_error);

	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(rgb_d_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(rgb_d_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(rgb_d_yellow)->b(), avg_error);

	EXPECT_NEAR(69.6f, color_manipulation::color_converter::to_lab(grey_t)->luminance(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_lab(grey_t)->a(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_lab(grey_t)->b(), avg_error);

	EXPECT_NEAR(69.6f, color_manipulation::color_converter::to_lab(grey_d)->luminance(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_lab(grey_d)->a(), avg_error);
	EXPECT_NEAR(0.f, color_manipulation::color_converter::to_lab(grey_d)->b(), avg_error);

	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(cmyk_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(cmyk_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(cmyk_yellow)->b(), avg_error);

	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(hsv_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(hsv_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(hsv_yellow)->b(), avg_error);

	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(hsl_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(hsl_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(hsl_yellow)->b(), avg_error);

	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(xyz_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(xyz_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(xyz_yellow)->b(), avg_error);

	EXPECT_NEAR(97.14f, color_manipulation::color_converter::to_lab(xyy_yellow)->luminance(), avg_error); // because of calculation inaccuracies
	EXPECT_NEAR(-21.22f, color_manipulation::color_converter::to_lab(xyy_yellow)->a(), avg_error);
	EXPECT_NEAR(94.66f, color_manipulation::color_converter::to_lab(xyy_yellow)->b(), avg_error);

	EXPECT_NEAR(lab_yellow->luminance(), color_manipulation::color_converter::to_lab(lab_yellow)->luminance(), avg_error);
	EXPECT_NEAR(lab_yellow->a(), color_manipulation::color_converter::to_lab(lab_yellow)->a(), avg_error);
	EXPECT_NEAR(lab_yellow->b(), color_manipulation::color_converter::to_lab(lab_yellow)->b(), avg_error);
}