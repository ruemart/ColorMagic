#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\rgb_deepcolor.h"
#include "..\ColorMagic\manipulation\color_blend.h"

using namespace color_space;

class ColorBlend_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	rgb_deepcolor* red_100;

	rgb_deepcolor* blue_100;
	rgb_deepcolor* blue_50;
	rgb_deepcolor* blue_0;

	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		red_100 = new rgb_deepcolor(1.f, 0.f, 0.f, 1.f, srgb);

		blue_100 = new rgb_deepcolor(0.f, 0.f, 1.f, 1.f, srgb);
		blue_50 = new rgb_deepcolor(0.f, 0.f, 1.f, 0.5f, srgb);
		blue_0 = new rgb_deepcolor(0.f, 0.f, 1.f, 0.f, srgb);
	}

	virtual void TearDown()
	{
		delete red_100;
		delete blue_100;
		delete blue_50;
		delete blue_0;
	}
};

TEST_F(ColorBlend_Test, DefaultTests)
{
	EXPECT_ANY_THROW(color_manipulation::color_blend::normal(blue_100, nullptr));
	EXPECT_ANY_THROW(color_manipulation::color_blend::normal(nullptr, blue_100));
	EXPECT_ANY_THROW(color_manipulation::color_blend::normal(nullptr, nullptr));
}

TEST_F(ColorBlend_Test, NormalTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::normal(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::normal(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::normal(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, MultiplyTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::multiply(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::multiply(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::multiply(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, ScreenTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::screen(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::screen(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::screen(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, OverlayTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::overlay(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::overlay(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::overlay(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, DarkenTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::darken(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::darken(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::darken(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, LightenTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::lighten(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::lighten(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::lighten(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, ColorDodgeTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color_dodge(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color_dodge(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color_dodge(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, LinearDodgeTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_dodge(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_dodge(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_dodge(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, ColorBurnTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color_burn(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color_burn(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color_burn(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, LinearBurnTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_burn(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_burn(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_burn(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, HardLightTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::hard_light(red_100, blue_100));
	ASSERT_NEAR(0.99f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::hard_light(red_100, blue_50));
	ASSERT_NEAR(0.99f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::hard_light(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, SoftLightTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::soft_light(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::soft_light(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::soft_light(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, VividLightTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::vivid_light(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::vivid_light(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::vivid_light(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, LinearLightTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_light(red_100, blue_100));
	ASSERT_NEAR(0.99f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_light(red_100, blue_50));
	ASSERT_NEAR(0.99f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::linear_light(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, DifferenceTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::difference(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::difference(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::difference(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, SubtractTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::subtract(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::subtract(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::subtract(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, DivideTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::divide(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::divide(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::divide(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, PlusLighterTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::plus_lighter(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::plus_lighter(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::plus_lighter(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, PlusDarkerTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::plus_darker(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::plus_darker(red_100, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::plus_darker(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, ExclusionTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::exclusion(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::exclusion(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::exclusion(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, HueTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::hue(red_100, blue_100));
	ASSERT_NEAR(0.85f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::hue(red_100, blue_50));
	ASSERT_NEAR(0.85f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::hue(red_100, blue_0));
	ASSERT_NEAR(0.85f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, SaturationTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::saturation(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::saturation(red_100, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::saturation(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, ColorTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color(red_100, blue_100));
	ASSERT_NEAR(0.85f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color(red_100, blue_50));
	ASSERT_NEAR(0.85f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::color(red_100, blue_0));
	ASSERT_NEAR(0.85f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(ColorBlend_Test, LuminosityTests)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::luminosity(red_100, blue_100));
	ASSERT_NEAR(0.14f, result->red(), avg_error);
	ASSERT_NEAR(0.14f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::luminosity(red_100, blue_50));
	ASSERT_NEAR(0.14f, result->red(), avg_error);
	ASSERT_NEAR(0.14f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::color_blend::luminosity(red_100, blue_0));
	ASSERT_NEAR(0.14f, result->red(), avg_error);
	ASSERT_NEAR(0.14f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}