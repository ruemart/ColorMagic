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
#include "..\ColorMagic\manipulation\color_distance.h"

using namespace color_space;

class ColorDistance_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	cmyk *cmyk_yellow, *cmyk_red;
	hsv *hsv_yellow, *hsv_red;
	hsl *hsl_yellow, *hsl_red;
	xyz *xyz_yellow, *xyz_red;
	lab *lab_yellow, *lab_red;
	grey_deepcolor *grey1_d, *grey2_d;
	grey_truecolor *grey1_t, *grey2_t;
	rgb_deepcolor *rgb_d_yellow, *rgb_d_red;
	rgb_truecolor *rgb_t_yellow, *rgb_t_red;

	virtual void SetUp()
	{
		cmyk_yellow = new cmyk(0.f, 0.f, 1.f, 0.f);
		cmyk_red = new cmyk(0.f, 1.f, 1.f, 0.f);

		hsv_yellow = new hsv(60.f, 1.f, 1.f);
		hsv_red = new hsv(0.f, 1.f, 1.f);

		hsl_yellow = new hsl(60.f, 1.f, 0.5f);
		hsl_red = new hsl(0.f, 1.f, 0.5f);

		xyz_yellow = new xyz(77.f, 92.78f, 13.85f);
		xyz_red = new xyz(41.24f, 21.26f, 1.93f);

		lab_yellow = new lab(97.14f, -21.56f, 94.48f);
		lab_red = new lab(53.23f, 80.11f, 67.22f);

		grey1_d = new grey_deepcolor(0.6666f);
		grey2_d = new grey_deepcolor(0.3333f);

		grey1_t = new grey_truecolor((unsigned char)170);
		grey2_t = new grey_truecolor((unsigned char)85);

		rgb_d_yellow = new rgb_deepcolor(1.f, 1.f, 0.f);
		rgb_d_red = new rgb_deepcolor(1.f, 0.f, 0.f);

		rgb_t_yellow = new rgb_truecolor((unsigned char)255, (unsigned char)255, (unsigned char)0);
		rgb_t_red = new rgb_truecolor((unsigned char)255, (unsigned char)0, (unsigned char)0);
	}

	virtual void TearDown()
	{
		delete cmyk_yellow;
		delete cmyk_red;
		delete hsv_yellow;
		delete hsv_red;
		delete hsl_yellow;
		delete hsl_red;
		delete xyz_yellow;
		delete xyz_red;
		delete lab_yellow;
		delete lab_red;
		delete grey1_d;
		delete grey2_d;
		delete grey1_t;
		delete grey2_t;
		delete rgb_d_yellow;
		delete rgb_d_red;
		delete rgb_t_yellow;
		delete rgb_t_red;
	}
};

TEST_F(ColorDistance_Test, EuclideanSquared)
{
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(0.33f, color_manipulation::color_distance::euclidean_distance_squared(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(0.33f, color_manipulation::color_distance::euclidean_distance_squared(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_squared(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::euclidean_distance_squared(cmyk_yellow, cmyk_yellow), avg_error);
}

TEST_F(ColorDistance_Test, Euclidean)
{
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(0.57f, color_manipulation::color_distance::euclidean_distance(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(0.57f, color_manipulation::color_distance::euclidean_distance(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::euclidean_distance(cmyk_yellow, cmyk_yellow), avg_error);
}

TEST_F(ColorDistance_Test, EuclideanWeighted)
{
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_weighted(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(1.f, color_manipulation::color_distance::euclidean_distance_weighted(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(2.f, color_manipulation::color_distance::euclidean_distance_weighted(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::euclidean_distance_weighted(cmyk_yellow, cmyk_yellow), avg_error);
}

TEST_F(ColorDistance_Test, CIELAB_DeltaE_CIE76)
{
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(33.45f, color_manipulation::color_distance::cielab_delta_e_cie76(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(33.45f, color_manipulation::color_distance::cielab_delta_e_cie76(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(114.025f, color_manipulation::color_distance::cielab_delta_e_cie76(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cielab_delta_e_cie76(cmyk_yellow, cmyk_yellow), avg_error);
}

TEST_F(ColorDistance_Test, CIELAB_DeltaE_CIE94)
{
	// Graphic Art kL = 1, K1 = 0.045, K2 = 0.015 (default)
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(33.45f, color_manipulation::color_distance::cielab_delta_e_cie94(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(33.45f, color_manipulation::color_distance::cielab_delta_e_cie94(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(61.3f, color_manipulation::color_distance::cielab_delta_e_cie94(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cielab_delta_e_cie94(cmyk_yellow, cmyk_yellow), avg_error);

	// Textiles kL = 2, K1 = 0.048, K2 = 0.014
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(cmyk_yellow, cmyk_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(hsv_yellow, hsv_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(hsl_yellow, hsl_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(xyz_yellow, xyz_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(lab_yellow, lab_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(16.75f, color_manipulation::color_distance::cielab_delta_e_cie94(grey1_d, grey2_d, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(16.75f, color_manipulation::color_distance::cielab_delta_e_cie94(grey1_t, grey2_t, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(rgb_d_yellow, rgb_d_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(rgb_t_yellow, rgb_t_red, 2.f, 0.048f, 0.014f), avg_error);

	EXPECT_NEAR(49.65f, color_manipulation::color_distance::cielab_delta_e_cie94(cmyk_yellow, rgb_t_red, 2.f, 0.048f, 0.014f), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cielab_delta_e_cie94(cmyk_yellow, cmyk_yellow, 2.f, 0.048f, 0.014f), avg_error);
}

TEST_F(ColorDistance_Test, CIELAB_DeltaE_CIE00)
{
	// Graphic Art kL = 1, K1 = 0.045, K2 = 0.015 (default)
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(32.7f, color_manipulation::color_distance::cielab_delta_e_cie00(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(32.7f, color_manipulation::color_distance::cielab_delta_e_cie00(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(63.6f, color_manipulation::color_distance::cielab_delta_e_cie00(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cielab_delta_e_cie00(cmyk_yellow, cmyk_yellow), avg_error);

	// Textiles kL = 2, K1 = 0.048, K2 = 0.014
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(cmyk_yellow, cmyk_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(hsv_yellow, hsv_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(hsl_yellow, hsl_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(xyz_yellow, xyz_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(lab_yellow, lab_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(16.4f, color_manipulation::color_distance::cielab_delta_e_cie00(grey1_d, grey2_d, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(16.4f, color_manipulation::color_distance::cielab_delta_e_cie00(grey1_t, grey2_t, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(rgb_d_yellow, rgb_d_red, 2.f, 0.048f, 0.014f), avg_error);
	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(rgb_t_yellow, rgb_t_red, 2.f, 0.048f, 0.014f), avg_error);

	EXPECT_NEAR(59.1f, color_manipulation::color_distance::cielab_delta_e_cie00(cmyk_yellow, rgb_t_red, 2.f, 0.048f, 0.014f), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cielab_delta_e_cie00(cmyk_yellow, cmyk_yellow, 2.f, 0.048f, 0.014f), avg_error);
}

TEST_F(ColorDistance_Test, CMC_DeltaE_LC84)
{
	// Lightness = 2 (default)
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(cmyk_yellow, cmyk_red), avg_error);
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(hsv_yellow, hsv_red), avg_error);
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(hsl_yellow, hsl_red), avg_error);
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(xyz_yellow, xyz_red), avg_error);
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(lab_yellow, lab_red), avg_error);
	EXPECT_NEAR(13.1f, color_manipulation::color_distance::cmc_delta_e_lc84(grey1_d, grey2_d), avg_error);
	EXPECT_NEAR(13.1f, color_manipulation::color_distance::cmc_delta_e_lc84(grey1_t, grey2_t), avg_error);
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(rgb_d_yellow, rgb_d_red), avg_error);
	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(rgb_t_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(49.9f, color_manipulation::color_distance::cmc_delta_e_lc84(cmyk_yellow, rgb_t_red), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cmc_delta_e_lc84(cmyk_yellow, cmyk_yellow), avg_error);

	// Lightness = 1
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(cmyk_yellow, cmyk_red, 1.f), avg_error);
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(hsv_yellow, hsv_red, 1.f), avg_error);
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(hsl_yellow, hsl_red, 1.f), avg_error);
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(xyz_yellow, xyz_red, 1.f), avg_error);
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(lab_yellow, lab_red, 1.f), avg_error);
	EXPECT_NEAR(26.15, color_manipulation::color_distance::cmc_delta_e_lc84(grey1_d, grey2_d, 1.f), avg_error);
	EXPECT_NEAR(26.15f, color_manipulation::color_distance::cmc_delta_e_lc84(grey1_t, grey2_t, 1.f), avg_error);
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(rgb_d_yellow, rgb_d_red, 1.f), avg_error);
	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(rgb_t_yellow, rgb_t_red, 1.f), avg_error);

	EXPECT_NEAR(56.25f, color_manipulation::color_distance::cmc_delta_e_lc84(cmyk_yellow, rgb_t_red, 1.f), avg_error);

	EXPECT_NEAR(0.f, color_manipulation::color_distance::cmc_delta_e_lc84(cmyk_yellow, cmyk_yellow, 1.f), avg_error);
}