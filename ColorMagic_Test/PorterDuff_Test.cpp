#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\rgb_deepcolor.h"
#include "..\ColorMagic\manipulation\porter_duff.h"

using namespace color_space;

class PorterDuff_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	rgb_deepcolor* red_100;
	rgb_deepcolor* red_50;
	rgb_deepcolor* red_0;

	rgb_deepcolor* blue_100;
	rgb_deepcolor* blue_50;
	rgb_deepcolor* blue_0;

	rgb_color_space_definition* srgb;

	virtual void SetUp()
	{
		srgb = color_space::rgb_color_space_definition_presets().sRGB();
		red_100 = new rgb_deepcolor(1.f, 0.f, 0.f, 1.f, srgb);
		red_50 = new rgb_deepcolor(1.f, 0.f, 0.f, 0.5f, srgb);
		red_0 = new rgb_deepcolor(1.f, 0.f, 0.f, 0.f, srgb);

		blue_100 = new rgb_deepcolor(0.f, 0.f, 1.f, 1.f, srgb);
		blue_50 = new rgb_deepcolor(0.f, 0.f, 1.f, 0.5f, srgb);
		blue_0 = new rgb_deepcolor(0.f, 0.f, 1.f, 0.f, srgb);
	}

	virtual void TearDown()
	{
		delete red_100;
		delete red_50;
		delete red_0;
		delete blue_100;
		delete blue_50;
		delete blue_0;
	}
};

TEST_F(PorterDuff_Test, src)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_50, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_50, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_50, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_0, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::src(red_0, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, dest)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_100, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_50, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_50, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_0, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest(red_0, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, atop)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::atop(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::atop(red_50, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::atop(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, dest_atop)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_atop(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_atop(red_50, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_atop(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, over)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::over(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::over(red_50, blue_50));
	ASSERT_NEAR(0.66f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.33f, result->blue(), avg_error);
	ASSERT_NEAR(0.75f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::over(red_50, blue_100));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::over(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::over(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, dest_over)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_over(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_over(red_50, blue_50));
	ASSERT_NEAR(0.33f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.66f, result->blue(), avg_error);
	ASSERT_NEAR(0.75f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_over(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_over(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_over(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, in)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::in(red_100, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::in(red_50, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.25f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::in(red_50, blue_100));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::in(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::in(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::in(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, dest_in)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_in(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_in(red_50, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.25f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_in(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_in(red_100, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_in(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_in(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, out)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::out(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::out(red_50, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.25f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::out(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::out(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::out(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::out(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, dest_out)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_out(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_out(red_50, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.25f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_out(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_out(red_100, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_out(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::dest_out(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, x_or)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::x_or(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error); // Still premultiplied because alpha is 0 -> Avoid divide by zero
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::x_or(red_50, blue_50));
	ASSERT_NEAR(0.5f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.5f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::x_or(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::x_or(red_100, blue_50));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.5f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::x_or(red_100, blue_0));
	ASSERT_NEAR(1.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::x_or(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(1.f, result->blue(), avg_error);
	ASSERT_NEAR(1.f, result->alpha(), avg_error);
	delete result;
}

TEST_F(PorterDuff_Test, clear)
{
	auto result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::clear(red_100, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::clear(red_50, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::clear(red_50, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::clear(red_100, blue_50));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::clear(red_100, blue_0));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;

	result = color_manipulation::color_converter::to_rgb_deep(color_manipulation::porter_duff::clear(red_0, blue_100));
	ASSERT_NEAR(0.f, result->red(), avg_error);
	ASSERT_NEAR(0.f, result->green(), avg_error);
	ASSERT_NEAR(0.f, result->blue(), avg_error);
	ASSERT_NEAR(0.f, result->alpha(), avg_error);
	delete result;
}