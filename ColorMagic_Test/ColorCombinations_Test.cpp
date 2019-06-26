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
	rgb_truecolor *rgb_t_orange;
	rgb_truecolor *rgb_t_yellow;
	rgb_truecolor *rgb_t_green;
	rgb_truecolor *rgb_t_light_green;
	rgb_truecolor *rgb_t_mint;
	rgb_truecolor *rgb_t_lime;
	rgb_truecolor *rgb_t_blue;
	rgb_truecolor *rgb_t_light_blue;
	rgb_truecolor *rgb_t_light_blue2;
	rgb_truecolor *rgb_t_cyan;
	rgb_truecolor *rgb_t_violet;
	rgb_truecolor *rgb_t_pink;
	rgb_truecolor *rgb_t_pink2;
	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		rgb_t_red = new rgb_truecolor(255, 0, 0, 255, srgb);
		rgb_t_orange = new rgb_truecolor(255, 128, 0, 255, srgb);
		rgb_t_yellow = new rgb_truecolor(204, 255, 0, 255, srgb);
		rgb_t_green = new rgb_truecolor(0, 255, 0, 255, srgb);
		rgb_t_light_green = new rgb_truecolor(0, 255, 127, 255, srgb);
		rgb_t_mint = new rgb_truecolor(0, 255, 102, 255, srgb);
		rgb_t_lime = new rgb_truecolor(127, 255, 0, 255, srgb);
		rgb_t_blue = new rgb_truecolor(0, 0, 255, 255, srgb);
		rgb_t_light_blue = new rgb_truecolor(0, 102, 255, 255, srgb);
		rgb_t_light_blue2 = new rgb_truecolor(0, 128, 255, 255, srgb);
		rgb_t_cyan = new rgb_truecolor(0, 255, 255, 255, srgb);
		rgb_t_violet = new rgb_truecolor(128, 0, 255, 255, srgb);
		rgb_t_pink = new rgb_truecolor(204, 0, 255, 255, srgb);
		rgb_t_pink2 = new rgb_truecolor(255, 0, 127, 255, srgb);
	}

	virtual void TearDown()
	{
		delete rgb_t_red;
		delete rgb_t_orange;
		delete rgb_t_yellow;
		delete rgb_t_green;
		delete rgb_t_light_green;
		delete rgb_t_mint;
		delete rgb_t_lime;
		delete rgb_t_blue;
		delete rgb_t_light_blue;
		delete rgb_t_light_blue2;
		delete rgb_t_cyan;
		delete rgb_t_violet;
		delete rgb_t_pink;
		delete rgb_t_pink2;
	}
};

TEST_F(ColorCombinations_Test, Complimentary)
{
	auto red_complimentary = dynamic_cast<color_space::rgb_truecolor*>(color_manipulation::color_combinations::create_complimentary(rgb_t_red));
	EXPECT_NEAR(rgb_t_cyan->red(), red_complimentary->red(), avg_error);
	EXPECT_NEAR(rgb_t_cyan->green(), red_complimentary->green(), avg_error);
	EXPECT_NEAR(rgb_t_cyan->blue(), red_complimentary->blue(), avg_error);
}

TEST_F(ColorCombinations_Test, Triplet)
{
	auto red_triplet = color_manipulation::color_combinations::create_triplet(rgb_t_red);

	EXPECT_EQ(3, red_triplet.size());
	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[0])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_green->red(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[1])->red(), avg_error);
	EXPECT_NEAR(rgb_t_green->green(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[1])->green(), avg_error);
	EXPECT_NEAR(rgb_t_green->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[1])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_blue->red(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[2])->red(), avg_error);
	EXPECT_NEAR(rgb_t_blue->green(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[2])->green(), avg_error);
	EXPECT_NEAR(rgb_t_blue->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_triplet[2])->blue(), avg_error);
}

TEST_F(ColorCombinations_Test, Quartet)
{
	auto red_quartet = color_manipulation::color_combinations::create_quartet(rgb_t_red);

	EXPECT_EQ(4, red_quartet.size());
	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[0])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_lime->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[1])->red(), avg_error);
	EXPECT_NEAR(rgb_t_lime->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[1])->green(), avg_error);
	EXPECT_NEAR(rgb_t_lime->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[1])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_cyan->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[2])->red(), avg_error);
	EXPECT_NEAR(rgb_t_cyan->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[2])->green(), avg_error);
	EXPECT_NEAR(rgb_t_cyan->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[2])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_violet->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[3])->red(), avg_error);
	EXPECT_NEAR(rgb_t_violet->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[3])->green(), avg_error);
	EXPECT_NEAR(rgb_t_violet->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quartet[3])->blue(), avg_error);
}

TEST_F(ColorCombinations_Test, Quintet)
{
	auto red_quintet = color_manipulation::color_combinations::create_quintet(rgb_t_red);

	EXPECT_EQ(5, red_quintet.size());
	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[0])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_yellow->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[1])->red(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[1])->green(), avg_error);
	EXPECT_NEAR(rgb_t_yellow->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[1])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_mint->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[2])->red(), avg_error);
	EXPECT_NEAR(rgb_t_mint->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[2])->green(), avg_error);
	EXPECT_NEAR(rgb_t_mint->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[2])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_light_blue->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[3])->red(), avg_error);
	EXPECT_NEAR(rgb_t_light_blue->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[3])->green(), avg_error);
	EXPECT_NEAR(rgb_t_light_blue->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[3])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_pink->red(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[4])->red(), avg_error);
	EXPECT_NEAR(rgb_t_pink->green(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[4])->green(), avg_error);
	EXPECT_NEAR(rgb_t_pink->blue(), dynamic_cast<color_space::rgb_truecolor*>(red_quintet[4])->blue(), avg_error);
}

TEST_F(ColorCombinations_Test, N_Combination)
{
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_combination(rgb_t_red, 0));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_combination(rgb_t_red, 1));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_combination(rgb_t_red, 720));
	EXPECT_EQ(359, color_manipulation::color_combinations::create_combination(rgb_t_red, 359).size());
}

TEST_F(ColorCombinations_Test, Analogous)
{
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_analogous(rgb_t_red, 0));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_analogous(rgb_t_red, 720));

	auto triplet = color_manipulation::color_combinations::create_analogous(rgb_t_red, 30);
	EXPECT_EQ(3, triplet.size());
	EXPECT_NEAR(rgb_t_pink2->red(), dynamic_cast<color_space::rgb_truecolor*>(triplet[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_pink2->green(), dynamic_cast<color_space::rgb_truecolor*>(triplet[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_pink2->blue(), dynamic_cast<color_space::rgb_truecolor*>(triplet[0])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(triplet[1])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(triplet[1])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(triplet[1])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_orange->red(), dynamic_cast<color_space::rgb_truecolor*>(triplet[2])->red(), avg_error);
	EXPECT_NEAR(rgb_t_orange->green(), dynamic_cast<color_space::rgb_truecolor*>(triplet[2])->green(), avg_error);
	EXPECT_NEAR(rgb_t_orange->blue(), dynamic_cast<color_space::rgb_truecolor*>(triplet[2])->blue(), avg_error);
}

TEST_F(ColorCombinations_Test, Monochromatic)
{
	auto desaturated_red_1 = new rgb_truecolor(191, 64, 64, 255, srgb);
	auto desaturated_red_2 = new rgb_truecolor(159, 96, 96, 255, srgb);

	auto deluminated_red_1 = new rgb_truecolor(128, 0, 0, 255, srgb);
	auto deluminated_red_2 = new rgb_truecolor(64, 0, 0, 255, srgb);

	auto mono_red_1 = new rgb_truecolor(96, 32, 32, 255, srgb);
	auto mono_red_2 = new rgb_truecolor(40, 24, 24, 255, srgb);

	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 0, -0.5, 3));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 0, 1.5, 3));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 0, 0.5, -2));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 0, 0.5, 0));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 5, 0.5, 3));

	auto desaturated = color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 0, 0.5, 3);
	EXPECT_EQ(3, desaturated.size());
	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[0])->blue(), avg_error);

	EXPECT_NEAR(desaturated_red_1->red(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[1])->red(), avg_error);
	EXPECT_NEAR(desaturated_red_1->green(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[1])->green(), avg_error);
	EXPECT_NEAR(desaturated_red_1->blue(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[1])->blue(), avg_error);

	EXPECT_NEAR(desaturated_red_2->red(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[2])->red(), avg_error);
	EXPECT_NEAR(desaturated_red_2->green(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[2])->green(), avg_error);
	EXPECT_NEAR(desaturated_red_2->blue(), dynamic_cast<color_space::rgb_truecolor*>(desaturated[2])->blue(), avg_error);

	auto deluminated = color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 1, 0.5, 3);
	EXPECT_EQ(3, deluminated.size());
	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[0])->blue(), avg_error);

	EXPECT_NEAR(deluminated_red_1->red(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[1])->red(), avg_error);
	EXPECT_NEAR(deluminated_red_1->green(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[1])->green(), avg_error);
	EXPECT_NEAR(deluminated_red_1->blue(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[1])->blue(), avg_error);

	EXPECT_NEAR(deluminated_red_2->red(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[2])->red(), avg_error);
	EXPECT_NEAR(deluminated_red_2->green(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[2])->green(), avg_error);
	EXPECT_NEAR(deluminated_red_2->blue(), dynamic_cast<color_space::rgb_truecolor*>(deluminated[2])->blue(), avg_error);

	auto mono = color_manipulation::color_combinations::create_monochromatic(rgb_t_red, 2, 0.5, 3);
	EXPECT_EQ(3, mono.size());
	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(mono[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(mono[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(mono[0])->blue(), avg_error);

	EXPECT_NEAR(mono_red_1->red(), dynamic_cast<color_space::rgb_truecolor*>(mono[1])->red(), avg_error);
	EXPECT_NEAR(mono_red_1->green(), dynamic_cast<color_space::rgb_truecolor*>(mono[1])->green(), avg_error);
	EXPECT_NEAR(mono_red_1->blue(), dynamic_cast<color_space::rgb_truecolor*>(mono[1])->blue(), avg_error);

	EXPECT_NEAR(mono_red_2->red(), dynamic_cast<color_space::rgb_truecolor*>(mono[2])->red(), avg_error);
	EXPECT_NEAR(mono_red_2->green(), dynamic_cast<color_space::rgb_truecolor*>(mono[2])->green(), avg_error);
	EXPECT_NEAR(mono_red_2->blue(), dynamic_cast<color_space::rgb_truecolor*>(mono[2])->blue(), avg_error);

	auto desaturated_blue_1 = new hsl(240, 1.f, 0.5f, 1.f, srgb);
	auto desaturated_blue_2 = new hsl(240, 0.8f, 0.5f, 1.f, srgb);
	auto desaturated_blue_3 = new hsl(240, 0.6f, 0.5f, 1.f, srgb);
	auto desaturated_blues = color_manipulation::color_combinations::create_monochromatic(desaturated_blue_1, 0, 0.2, 3);
	EXPECT_EQ(3, desaturated_blues.size());
	EXPECT_NEAR(desaturated_blue_1->hue(), dynamic_cast<color_space::hsl*>(desaturated_blues[0])->hue(), avg_error);
	EXPECT_NEAR(desaturated_blue_1->saturation(), dynamic_cast<color_space::hsl*>(desaturated_blues[0])->saturation(), avg_error);
	EXPECT_NEAR(desaturated_blue_1->lightness(), dynamic_cast<color_space::hsl*>(desaturated_blues[0])->lightness(), avg_error);

	EXPECT_NEAR(desaturated_blue_2->hue(), dynamic_cast<color_space::hsl*>(desaturated_blues[1])->hue(), avg_error);
	EXPECT_NEAR(desaturated_blue_2->saturation(), dynamic_cast<color_space::hsl*>(desaturated_blues[1])->saturation(), avg_error);
	EXPECT_NEAR(desaturated_blue_2->lightness(), dynamic_cast<color_space::hsl*>(desaturated_blues[1])->lightness(), avg_error);

	EXPECT_NEAR(desaturated_blue_3->hue(), dynamic_cast<color_space::hsl*>(desaturated_blues[2])->hue(), avg_error);
	EXPECT_NEAR(desaturated_blue_3->saturation(), dynamic_cast<color_space::hsl*>(desaturated_blues[2])->saturation(), avg_error);
	EXPECT_NEAR(desaturated_blue_3->lightness(), dynamic_cast<color_space::hsl*>(desaturated_blues[2])->lightness(), avg_error);
}

TEST_F(ColorCombinations_Test, ComplimentarySplit)
{
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_complimentary_split(rgb_t_red, 0));
	EXPECT_ANY_THROW(color_manipulation::color_combinations::create_complimentary_split(rgb_t_red, 720));

	auto triplet = color_manipulation::color_combinations::create_complimentary_split(rgb_t_red, 30);
	EXPECT_EQ(3, triplet.size());
	EXPECT_NEAR(rgb_t_light_green->red(), dynamic_cast<color_space::rgb_truecolor*>(triplet[0])->red(), avg_error);
	EXPECT_NEAR(rgb_t_light_green->green(), dynamic_cast<color_space::rgb_truecolor*>(triplet[0])->green(), avg_error);
	EXPECT_NEAR(rgb_t_light_green->blue(), dynamic_cast<color_space::rgb_truecolor*>(triplet[0])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_red->red(), dynamic_cast<color_space::rgb_truecolor*>(triplet[1])->red(), avg_error);
	EXPECT_NEAR(rgb_t_red->green(), dynamic_cast<color_space::rgb_truecolor*>(triplet[1])->green(), avg_error);
	EXPECT_NEAR(rgb_t_red->blue(), dynamic_cast<color_space::rgb_truecolor*>(triplet[1])->blue(), avg_error);

	EXPECT_NEAR(rgb_t_light_blue2->red(), dynamic_cast<color_space::rgb_truecolor*>(triplet[2])->red(), avg_error);
	EXPECT_NEAR(rgb_t_light_blue2->green(), dynamic_cast<color_space::rgb_truecolor*>(triplet[2])->green(), avg_error);
	EXPECT_NEAR(rgb_t_light_blue2->blue(), dynamic_cast<color_space::rgb_truecolor*>(triplet[2])->blue(), avg_error);
}