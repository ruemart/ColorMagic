/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "..\spaces\color_base.h"
#include "color_converter.h"

namespace color_manipulation
{
	//! Base class for porter duff and color blend operations.
	/*
	* Abstract base class for porter duff and color blend operations. It offers an implementation of the general
	* porter duff equation as well as a enum specifying the 4 regions of a resultant pixel. Both contents are 
	* used by porter_duff and color_blend classes.
	*/
	class base_color_blend
	{
	protected:
		//! Virtual function that actually does the combination of both colors by using a porter duff operator.
		/*!
		* Virtual function that actually does the combination of both colors by using a porter duff operator.
		* The definition of the operator to use is done with the s, d and b parameters. These parameters
		* define wether the source, destination or both areas of the resulting pixel should be included in
		* the operation.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_s Whether the source area of the resulting pixel is blank or source color.
		* \param use_d Whether the destination area of the resulting pixel is blank or destination color.
		* \param use_b Whether the both area of the resulting pixel is blank or not.
		* \param both_function The function used to calculate the factor of the both region. It take a source (1st param)
		* and a destination (2nd param) value to calculate the result.
		* \return the combination of source and destination calculated based on the given s, d, b parameters.
		*/
		virtual color_space::color_base* general_porter_duff(color_space::rgb_deepcolor* source, color_space::rgb_deepcolor* destination, bool use_s, bool use_d, bool use_b, std::function<float(float, float)> both_function)
		{
			// Check input params
			if (source == nullptr) throw new std::invalid_argument("source color is null.");
			if (destination == nullptr) throw new std::invalid_argument("destination color is null.");
			if (source->get_rgb_color_space() != destination->get_rgb_color_space()) throw new std::invalid_argument("The rgb color space definitions of both colors do not match.");

			// Calculate area factors
			float src_area = source->alpha() * (1.f - destination->alpha());
			float dest_area = destination->alpha() * (1.f - source->alpha());
			float both_area = source->alpha() * destination->alpha();

			// Calculate resulting alpha value
			float resulting_alpha = src_area * (use_s ? 1.f : 0.f) + dest_area * (use_d ? 1.f : 0.f) + both_area * (use_b ? 1.f : 0.f);

			// Create a new rgb object for the resulting color
			color_space::rgb_deepcolor* resulting_color = new color_space::rgb_deepcolor(0.f, resulting_alpha, source->get_rgb_color_space());

			// Calculate the resulting color component wise
			for (size_t i = 0; i < resulting_color->get_component_vector().size(); ++i)
			{
				// Source and destination products
				float s_product = src_area * (use_s ? source->get_component_vector()[i] : 0.f);
				float d_product = dest_area * (use_d ? destination->get_component_vector()[i] : 0.f);

				// Both product
				float b_product = both_area * (both_function(source->get_component_vector()[i], destination->get_component_vector()[i]));

				// Sum up products and assign them to the resulting color object.
				resulting_color->set_component(s_product + d_product + b_product, i);
			}

			resulting_color->alpha_divide();
			return resulting_color;
		}
	};
}
