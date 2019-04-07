#include "stdafx.h"
#include "color_combinations.h"

color_space::color_base * color_manipulation::color_combinations::create_complimentary(color_space::color_base * color)
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

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_quintet(color_space::color_base * color)
{
	return create_combination(color, 5);
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_combination(color_space::color_base * color, int number_of_colors)
{
	if (number_of_colors == 0) throw new std::invalid_argument("A color combination with 0 colors in it is invalid. Chose a color count >= 2");
	if (number_of_colors == 1) throw new std::invalid_argument("A color combination with 1 colors in it is invalid since it would just return the input color. Chose a color count >= 2");
	if (number_of_colors > 360) throw new std::invalid_argument("A color combination with more than 360 colors is invalid.");

	std::vector<color_space::color_base*> combination;
	combination.push_back(color);

	//number_of_colors = max(min(360, number_of_colors), 2); // Using exceptions instead of clamp. Maybe change back to clamp? I am unsure
	auto degrees = 360.f / number_of_colors;
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(color, color_type::HSL));

	for (auto i = 1; i <= number_of_colors - 1; ++i)
	{
		auto new_color = new color_space::hsl(color_hsl->hue() + (i * degrees), color_hsl->saturation(), color_hsl->lightness());
		combination.push_back(color_manipulation::color_converter::convertTo(new_color, color->get_color_type()));
	}

	return combination;
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_analogous(color_space::color_base * base_color, float distance_between)
{
	if (distance_between == 0.f) throw new std::invalid_argument("The distance between the analogous color can not be 0.");
	if (distance_between > 360.f / 3.f) throw new std::invalid_argument("The distance can not be greater than 120 degrees.");

	std::vector<color_space::color_base*> triplet;
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(base_color, color_type::HSL));

	triplet.push_back(color_manipulation::color_converter::convertTo(new color_space::hsl(color_hsl->hue() - distance_between, color_hsl->saturation(), color_hsl->lightness()), base_color->get_color_type()));
	triplet.push_back(base_color);
	triplet.push_back(color_manipulation::color_converter::convertTo(new color_space::hsl(color_hsl->hue() + distance_between, color_hsl->saturation(), color_hsl->lightness()), base_color->get_color_type()));

	return triplet;
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_monochromatic(color_space::color_base * base_color, int mode, float amount, int color_count)
{
	if (amount < 0.f) throw new std::invalid_argument("The amount of saturation/lightness in percent between two resulting colors can not be less than 0.");
	if (amount > 1.f) throw new std::invalid_argument("The amount of saturation/lightness in percent between two resulting colors can not be greater than 1.");
	if (color_count <= 0) throw new std::invalid_argument("The number of resulting colors must be greater than 0.");

	std::vector<color_space::color_base*> combination;
	combination.push_back(base_color);

	amount *= -1.f; // negative amounts decrease saturation/lightness of colors by using saturate/luminate functions.
	for (unsigned int i = 0; i < color_count - 1; ++i) // -1 because the first color is the input color
	{
		switch (mode)
		{
		case 0:
			combination.push_back(color_adjustments::saturate_in_hsl_space(combination[combination.size() - 1], amount));
			break;
		case 1:
			combination.push_back(color_adjustments::luminate_in_hsl_space(combination[combination.size() - 1], amount));
			break;
		case 2:
			combination.push_back(color_adjustments::luminate_in_hsl_space(color_adjustments::saturate_in_hsl_space(combination[combination.size() - 1], amount), amount));
			break;
		default:
			throw new std::invalid_argument("Invalid mode.");;
		}
	}

	return combination;
}

std::vector<color_space::color_base*> color_manipulation::color_combinations::create_complimentary_split(color_space::color_base * base_color, float amount)
{
	std::vector<color_space::color_base*> complimentary;
	auto color_hsl = dynamic_cast<color_space::hsl*>(color_manipulation::color_converter::convertTo(base_color, color_type::HSL));

	auto complimentary_color = color_manipulation::color_combinations::create_complimentary(base_color);
	auto analogous_colors = color_manipulation::color_combinations::create_analogous(complimentary_color, amount);
	complimentary.push_back(analogous_colors[0]);
	complimentary.push_back(base_color);
	complimentary.push_back(analogous_colors[2]);

	return complimentary;
}
