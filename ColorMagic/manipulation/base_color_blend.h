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
		enum both_region
		{
			SOURCE_COLOR = 0, /*!< SOURCE - the source color will be used for the both region */
			DESTINATION_COLOR, /*!< DESTINATION - the destination color will be used for the both region */
			NORMAL_BLEND, /*!< NORMAL_BLEND - Normal blending will be used for the both region */
			MULTIPLY_BLEND, /*!< MULTIPLY_BLEND - Multiply blending will be used for the both region */
			SCREEN_BLEND, /*!< SCREEN_BLEND - Screen blending will be used for the both region */
			OVERLAY_BLEND, /*!< OVERLAY_BLEND - Overlay blending will be used for the both region */
			DARKEN_BLEND, /*!< DARKEN_BLEND - Darken blending will be used for the both region */
			LIGHTEN_BLEND, /*!< LIGHTEN_BLEND - Lighten blending will be used for the both region */
			COLOR_DODGE_BLEND, /*!< COLOR_DODGE_BLEND - Color dodge blending will be used for the both region */
			COLOR_BURN_BLEND, /*!< COLOR_BURN_BLEND - Color burn blending will be used for the both region */
			HARD_LIGHT_BLEND, /*!< HARD_LIGHT_BLEND - Hard light blending will be used for the both region */
			SOFT_LIGHT_BLEND, /*!< SOFT_LIGHT_BLEND - Soft light blending will be used for the both region */
			DIFFERENCE_BLEND, /*!< DIFFERENCE_BLEND - Difference blending will be used for the both region */
			EXCLUSION_BLEND, /*!< EXCLUSION_BLEND - Exclusion blending will be used for the both region */
			BLANK /*!< BLANK - Neither source or destination color will be used for the both region */
		};

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
		* \param b The both area of the resulting pixel. Use SOURCE to include the source color in the
		* operation, DESTINATION to include the destination color, NEITHER to exclude both colors or a
		* blend mode to use special functions for the both area.
		* \return the combination of source and destination calculated based on the given s, d, b parameters.
		*/
		virtual color_space::color_base* general_porter_duff(color_space::rgb_deepcolor* source, color_space::rgb_deepcolor* destination, bool use_s, bool use_d, both_region b)
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
			float resulting_alpha = src_area * (use_s ? 1.f : 0.f) + dest_area * (use_d ? 1.f : 0.f) + both_area * ((b == both_region::BLANK) ? 0.f : 1.f);

			// Create a new rgb object for the resulting color
			color_space::rgb_deepcolor* resulting_color = new color_space::rgb_deepcolor(0.f, resulting_alpha, source->get_rgb_color_space());

			// Calculate the resulting color component wise
			for (size_t i = 0; i < resulting_color->get_component_vector().size(); ++i)
			{
				// Source and destination products
				float s_product = src_area * (use_s ? source->get_component_vector()[i] : 0.f);
				float d_product = dest_area * (use_d ? destination->get_component_vector()[i] : 0.f);

				// Both product
				float b_factor;
				switch (b)
				{
				case both_region::SOURCE_COLOR:
					b_factor = source->get_component_vector()[i];
					break;
				case both_region::DESTINATION_COLOR:
					b_factor = destination->get_component_vector()[i];
					break;
				case both_region::NORMAL_BLEND:
					break;
				case both_region::MULTIPLY_BLEND:
					break;
				case both_region::SCREEN_BLEND:
					break;
				case both_region::OVERLAY_BLEND:
					break;
				case both_region::DARKEN_BLEND:
					break;
				case both_region::LIGHTEN_BLEND:
					break;
				case both_region::COLOR_DODGE_BLEND:
					break;
				case both_region::COLOR_BURN_BLEND:
					break;
				case both_region::HARD_LIGHT_BLEND:
					break;
				case both_region::SOFT_LIGHT_BLEND:
					break;
				case both_region::DIFFERENCE_BLEND:
					break;
				case both_region::EXCLUSION_BLEND:
					break;
				case both_region::BLANK:
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
	};
}
