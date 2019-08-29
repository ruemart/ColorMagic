#include "stdafx.h"
#include "porter_duff.h"

color_space::color_base * color_manipulation::porter_duff::src(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::SOURCE, region::NEITHER, region::SOURCE), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::NEITHER, region::DESTINATION, region::DESTINATION), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::atop(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::NEITHER, region::DESTINATION, region::SOURCE), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_atop(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::SOURCE, region::NEITHER, region::DESTINATION), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::over(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::SOURCE, region::DESTINATION, region::SOURCE), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_over(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::SOURCE, region::DESTINATION, region::DESTINATION), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::in(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::NEITHER, region::NEITHER, region::SOURCE), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_in(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::NEITHER, region::NEITHER, region::DESTINATION), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::out(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::SOURCE, region::NEITHER, region::NEITHER), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::dest_out(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::NEITHER, region::DESTINATION, region::NEITHER), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::x_or(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::SOURCE, region::DESTINATION, region::NEITHER), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::clear(color_space::color_base * source, color_space::color_base * destination)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

	return color_converter::convertTo(do_porter_duff(color_converter::to_rgb_deep(source), color_converter::to_rgb_deep(destination), region::NEITHER, region::NEITHER, region::NEITHER), source->get_color_type());
}

color_space::color_base * color_manipulation::porter_duff::do_porter_duff(color_space::rgb_deepcolor * source, color_space::rgb_deepcolor * destination, region s, region d, region b)
{
	// Check input params
	if (source == nullptr) throw new std::invalid_argument("source color is null.");
	if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
	if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");
	if (s == region::DESTINATION) throw new std::invalid_argument("s param must not be region::DESTINATION.");
	if (d == region::SOURCE) throw new std::invalid_argument("s param must not be region::SOURCE.");

	// Calculate area factors
	float src_area = source->alpha() * (1.f - destination->alpha());
	float dest_area = destination->alpha() * (1.f - source->alpha());
	float both_area = source->alpha() * destination->alpha();

	// Calculate resulting alpha value
	float resulting_alpha =	src_area * ((s == region::NEITHER) ? 0.f : 1.f) + dest_area * ((d == region::NEITHER) ? 0.f : 1.f) + both_area * ((b == region::NEITHER) ? 0.f : 1.f);

	// Create a new rgb object for the resulting color
	color_space::rgb_deepcolor* resulting_color = new color_space::rgb_deepcolor(0.f, resulting_alpha, source->get_rgb_color_space());

	// Calculate the resulting color component wise
	for (size_t i = 0; i < resulting_color->get_component_vector().size(); ++i)
	{
		// Source and destination products
		float s_product = src_area * ((s == region::SOURCE) ? source->get_component_vector()[i] : 0.f);
		float d_product = dest_area * ((d == region::DESTINATION) ? destination->get_component_vector()[i] : 0.f);

		// Both product
		float b_factor;
		switch (b)
		{
		case color_manipulation::porter_duff::SOURCE:
			b_factor = source->get_component_vector()[i];
			break;
		case color_manipulation::porter_duff::DESTINATION:
			b_factor = destination->get_component_vector()[i];
			break;
		case color_manipulation::porter_duff::NEITHER:
		default:
			b_factor = 0.f;
			break;
		}
		float b_product = both_area * b_factor;

		// Sum up products and assign them to the resulting color object.
		resulting_color->set_component(s_product + d_product + b_product, i);
	}

	resulting_color->alpha_divide();
	return resulting_color;
}
