#include "stdafx.h"
#include "color_combinations.h"

color_space::color_base * color_manipulation::color_combinations::get_complimentary_color(color_space::color_base * color)
{
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	color_hsl->hue(color_hsl->hue() + 180.f);

	return color_manipulation::color_converter::convertTo(color_hsl, color->get_color_type());
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_triplet(color_space::color_base * color)
{
	std::vector<color_space::color_base*> color_triplet;
	color_triplet.push_back(color);

	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	for (auto i = 1; i <= 2; ++i)
	{
		auto new_color = new color_space::hsl(color_hsl->hue() + (i * 120.f), color_hsl->saturation(), color_hsl->lightness());
		color_triplet.push_back(color_manipulation::color_converter::convertTo(new_color, color->get_color_type()));
	}

	return color_triplet;
}
