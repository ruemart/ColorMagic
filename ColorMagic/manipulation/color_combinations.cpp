#include "stdafx.h"
#include "color_combinations.h"

color_space::color_base * color_manipulation::color_combinations::get_complimentary_color(color_space::color_base * color)
{
	return create_combination(color, 2)[1];
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_triplet(color_space::color_base * color)
{
	return create_combination(color, 3);
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_quartet(color_space::color_base * color)
{
	return create_combination(color, 4);
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_combination(color_space::color_base * color, int number_of_elements)
{
	std::vector<color_space::color_base*> combination;
	combination.push_back(color);

	number_of_elements = max(min(360, number_of_elements), 0);
	auto degrees = 360.f / number_of_elements;
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	for (auto i = 1; i <= number_of_elements - 1; ++i)
	{
		auto new_color = new color_space::hsl(color_hsl->hue() + (i * degrees), color_hsl->saturation(), color_hsl->lightness());
		combination.push_back(color_manipulation::color_converter::convertTo(new_color, color->get_color_type()));
	}

	return combination;
}
