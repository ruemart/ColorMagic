#include "stdafx.h"
#include "color_adjustments.h"

void color_adjustments::saturate_in_rgb_space(color_space::color_base &color, float percentage)
{
	color = *saturate_in_rgb_space(&color, percentage);
}

color_space::color_base * color_adjustments::saturate_in_rgb_space(color_space::color_base* color, float percentage)
{
	auto color_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color, color_type::RGB_DEEP));

	auto L = 0.299f * color_rgb_d->red() + 0.587f * color_rgb_d->green() + 0.114f * color_rgb_d->blue();
	auto new_r = color_rgb_d->red() - percentage * (L - color_rgb_d->red());
	auto new_g = color_rgb_d->green() - percentage * (L - color_rgb_d->green());
	auto new_b = color_rgb_d->blue() - percentage * (L - color_rgb_d->blue());

	return color_manipulation::color_converter::convertTo(new color_space::rgb_deepcolor(new_r, new_g, new_b, color_rgb_d->alpha()), color->get_color_type());
}

void color_adjustments::saturate_in_hsl_space(color_space::color_base & color, float percentage)
{
	color = *saturate_in_hsl_space(&color, percentage);
}

color_space::color_base * color_adjustments::saturate_in_hsl_space(color_space::color_base * color, float percentage)
{
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	auto factor = 1.f + percentage;
	color_hsl->saturation(color_hsl->saturation() * factor);

	return color_manipulation::color_converter::convertTo(color_hsl, color->get_color_type());
}

void color_adjustments::luminate_in_rgb_space(color_space::color_base & color, float percentage)
{
	color = *luminate_in_rgb_space(&color, percentage);
}

color_space::color_base * color_adjustments::luminate_in_rgb_space(color_space::color_base * color, float percentage)
{
	auto color_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color, color_type::RGB_DEEP));

	auto factor = 1.f + percentage;
	auto new_r = color_rgb_d->red() * factor;
	auto new_g = color_rgb_d->green() * factor;
	auto new_b = color_rgb_d->blue() * factor;

	return color_manipulation::color_converter::convertTo(new color_space::rgb_deepcolor(new_r, new_g, new_b, color_rgb_d->alpha()), color->get_color_type());
}

void color_adjustments::luminate_in_hsl_space(color_space::color_base & color, float percentage)
{
	color = *luminate_in_hsl_space(&color, percentage);
}

color_space::color_base * color_adjustments::luminate_in_hsl_space(color_space::color_base * color, float percentage)
{
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	auto factor = 1.f + percentage;
	color_hsl->lightness(color_hsl->lightness() * factor);

	return color_manipulation::color_converter::convertTo(color_hsl, color->get_color_type());
}
