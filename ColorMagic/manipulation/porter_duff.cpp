#include "stdafx.h"
#include "porter_duff.h"

color_space::color_base * color_manipulation::porter_duff::src(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), true, false, both_region::SOURCE_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), false, true, both_region::DESTINATION_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::atop(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), false, true, both_region::SOURCE_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_atop(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), true, false, both_region::DESTINATION_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::over(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), true, true, both_region::SOURCE_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_over(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), true, true, both_region::DESTINATION_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::in(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), false, false, both_region::SOURCE_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_in(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), false, false, both_region::DESTINATION_COLOR), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::out(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), true, false, both_region::BLANK), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_out(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), false, true, both_region::BLANK), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::x_or(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), true, true, both_region::BLANK), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::clear(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo((new porter_duff())->do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), false, false, both_region::BLANK), source->get_color_type());
}
