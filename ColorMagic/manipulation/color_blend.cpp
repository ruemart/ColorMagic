#include "stdafx.h"
#include "color_blend.h"

color_space::color_base * color_manipulation::color_blend::normal(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return s_component; }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::dissolve(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	float source_dest_alpha_diff = source->alpha() - destination->alpha();
	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[source_dest_alpha_diff](float s_component, float d_component) { return dissolve_func(s_component, d_component, source_dest_alpha_diff); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::multiply(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return multiply_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::screen(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component)
	{
		return screen_func(s_component, d_component);
	}),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::overlay(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component)
	{
		return overlay_func(s_component, d_component);
	}),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::darken(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return darken_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::lighten(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) {return lighten_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::color_dodge(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return color_dodge_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::linear_dodge(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return linear_dodge_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::color_burn(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return color_burn_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::linear_burn(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return linear_burn_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::hard_light(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) {return hard_light_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::soft_light(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) {return soft_light_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::vivid_light(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return vivid_light_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::linear_light(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return linear_light_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::difference(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) {return difference_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::subtract(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return subtract_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::divide(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return divide_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::plus_lighter(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return plus_lighter_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::plus_darker(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) { return plus_darker_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::exclusion(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			[](float s_component, float d_component) {return exclusion_func(s_component, d_component); }),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::custom_componentwise_blend(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region, std::function<float(float, float)> blend_function)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(
		(new color_blend())->general_porter_duff(
			color_converter::to_rgb_deep(source),
			color_converter::to_rgb_deep(destination),
			use_source_region,
			use_destination_region,
			true,
			blend_function),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::hue(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	color_space::hcy* s_hcy = color_manipulation::color_converter::to_hcy(source);
	color_space::hcy* d_hcy = color_manipulation::color_converter::to_hcy(destination);
	color_space::hcy* result = new color_space::hcy(s_hcy->hue(), d_hcy->chroma(), d_hcy->luma(), s_hcy->alpha(), s_hcy->get_rgb_color_space());
	return color_manipulation::color_converter::convertTo(result, source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::saturation(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	color_space::hcy* s_hcy = color_manipulation::color_converter::to_hcy(source);
	color_space::hcy* d_hcy = color_manipulation::color_converter::to_hcy(destination);
	color_space::hcy* result = new color_space::hcy(d_hcy->hue(), s_hcy->chroma(), d_hcy->luma(), s_hcy->alpha(), s_hcy->get_rgb_color_space());
	return color_manipulation::color_converter::convertTo(result, source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::color(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	color_space::hcy* s_hcy = color_manipulation::color_converter::to_hcy(source);
	color_space::hcy* d_hcy = color_manipulation::color_converter::to_hcy(destination);
	color_space::hcy* result = new color_space::hcy(s_hcy->hue(), s_hcy->chroma(), d_hcy->luma(), s_hcy->alpha(), s_hcy->get_rgb_color_space());
	return color_manipulation::color_converter::convertTo(result, source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::luminosity(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	color_space::hcy* s_hcy = color_manipulation::color_converter::to_hcy(source);
	color_space::hcy* d_hcy = color_manipulation::color_converter::to_hcy(destination);
	color_space::hcy* result = new color_space::hcy(d_hcy->hue(), d_hcy->chroma(), s_hcy->luma(), s_hcy->alpha(), s_hcy->get_rgb_color_space());
	return color_manipulation::color_converter::convertTo(result, source->get_color_type());
}