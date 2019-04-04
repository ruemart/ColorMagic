#include "stdafx.h"
#include "color_combinations.h"

color_space::color_base * color_manipulation::color_combinations::get_complimentary_color(color_space::color_base * color)
{
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	color_hsl->hue(color_hsl->hue() + 180.f);

	return color_manipulation::color_converter::convertTo(color_hsl, color->get_color_type());
}
