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
			both_region::NORMAL_BLEND),
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
			both_region::MULTIPLY_BLEND),
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
			both_region::SCREEN_BLEND),
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
			both_region::OVERLAY_BLEND),
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
			both_region::DARKEN_BLEND),
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
			both_region::LIGHTEN_BLEND),
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
			both_region::COLOR_DODGE_BLEND),
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
			both_region::COLOR_BURN_BLEND),
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
			both_region::HARD_LIGHT_BLEND),
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
			both_region::SOFT_LIGHT_BLEND),
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
			both_region::DIFFERENCE_BLEND),
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
			both_region::EXCLUSION_BLEND),
		source->get_color_type());
}

color_space::color_base * color_manipulation::color_blend::hue(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	return nullptr;
}

color_space::color_base * color_manipulation::color_blend::saturation(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	return nullptr;
}

color_space::color_base * color_manipulation::color_blend::color(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	return nullptr;
}

color_space::color_base * color_manipulation::color_blend::luminosity(color_space::color_base * source, color_space::color_base * destination, bool use_source_region, bool use_destination_region)
{
	return nullptr;
}
