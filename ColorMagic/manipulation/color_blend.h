/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "base_color_blend.h"
#include "..\spaces\color_base.h"
#include "color_converter.h"

namespace color_manipulation
{
	//! Static class for color blending operations
	/*!
	* This static class implements 16 different color blending operations.
	*/
	class color_blend : protected base_color_blend
	{
	public:
		//! Static function that does not do any special blending.
		/*!
		* Static function that does not do any special blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator. Only source and only destination equals porter duffs' source
		* respectively destination operators. Neither source and destination will produce
		* something simular to porter duffs in operator.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with normal blending.
		*/
		static color_space::color_base* normal(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does multiply blending.
		/*!
		* Static function that does multiply blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being multiplied componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus multiply). Neither source and destination will produce something simular
		* to porter duffs in operator with multiply.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with multiply blending.
		*/
		static color_space::color_base* multiply(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does screen blending.
		/*!
		* Static function that does screen blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being screen blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus screen blending). Neither source and destination will produce something
		* simular to porter duffs in operator with screen blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with screen blending.
		*/
		static color_space::color_base* screen(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does overlay blending.
		/*!
		* Static function that does overlay blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being overlay blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus overlay blending). Neither source and destination will produce something
		* simular to porter duffs in operator with overlay blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with overlay blending.
		*/
		static color_space::color_base* overlay(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does darken blending.
		/*!
		* Static function that does darken blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being darken blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus darken blending). Neither source and destination will produce something
		* simular to porter duffs in operator with darken blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with darken blending.
		*/
		static color_space::color_base* darken(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does lighten blending.
		/*!
		* Static function that does lighten blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being lighten blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus lighten blending). Neither source and destination will produce something
		* simular to porter duffs in operator with lighten blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with lighten blending.
		*/
		static color_space::color_base* lighten(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does color-dodge blending.
		/*!
		* Static function that does color-dodge blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being color-dodge blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus color-dodge blending). Neither source and destination will produce something
		* simular to porter duffs in operator with color-dodge blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with color-dodge blending.
		*/
		static color_space::color_base* color_dodge(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does color-burn blending.
		/*!
		* Static function that does color-burn blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being color-dodge blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus color-burn blending). Neither source and destination will produce something
		* simular to porter duffs in operator with color-burn blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with color-burn blending.
		*/
		static color_space::color_base* color_burn(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does hard-light blending.
		/*!
		* Static function that does hard-light blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being hard-light blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus hard-light blending). Neither source and destination will produce something
		* simular to porter duffs in operator with hard-light blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with hard-light blending.
		*/
		static color_space::color_base* hard_light(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does soft-light blending.
		/*!
		* Static function that does soft-light blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being soft-light blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus soft-light blending). Neither source and destination will produce something
		* simular to porter duffs in operator with soft-light blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with soft-light blending.
		*/
		static color_space::color_base* soft_light(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does difference blending.
		/*!
		* Static function that does difference blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being difference blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus difference blending). Neither source and destination will produce something
		* simular to porter duffs in operator with difference blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with difference blending.
		*/
		static color_space::color_base* difference(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does exclusion blending.
		/*!
		* Static function that does exclusion blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being exclusion blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus exclusion blending). Neither source and destination will produce something
		* simular to porter duffs in operator with exclusion blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with exclusion blending.
		*/
		static color_space::color_base* exclusion(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does custom componentwise blending.
		/*!
		* Static function that does custom componentwise blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being custom blended componentwise.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus custom blending). Neither source and destination will produce something
		* simular to porter duffs in operator with custom blending.
		* Since the operation is done in rgb deep color space a conversion will be done first.
		* Therefore source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \param blend_function The function that does the blending. It awaits source and destination
		* components as input (in this order) and returns a blended float component.
		* \return the combination of source and destination calculated with custom blending.
		*/
		static color_space::color_base* custom_componentwise_blend(color_space::color_base* source, color_space::color_base* destination, bool use_source_region, bool use_destination_region, std::function<float(float, float)> blend_function);

		//! Static function that does hue blending.
		/*!
		* Static function that does hue blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being hue blended.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus hue blending). Neither source and destination will produce something
		* simular to porter duffs in operator with hue blending.
		* Note that this blend operator does not work componentwise but consider all components
		* in a combination.
		* Since the operation is done in hsl space a conversion will be done first. Therefore
		* source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with hue blending.
		*/
		static color_space::color_base* hue(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does saturation blending.
		/*!
		* Static function that does saturation blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being saturation blended.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus saturation blending). Neither source and destination will produce something
		* simular to porter duffs in operator with saturation blending.
		* Note that this blend operator does not work componentwise but consider all components
		* in a combination.
		* Since the operation is done in hsl space a conversion will be done first. Therefore
		* source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with saturation blending.
		*/
		static color_space::color_base* saturation(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does color blending.
		/*!
		* Static function that does color blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being color blended.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus color blending). Neither source and destination will produce something
		* simular to porter duffs in operator with color blending.
		* Note that this blend operator does not work componentwise but consider all components
		* in a combination.
		* Since the operation is done in hsl space a conversion will be done first. Therefore
		* source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with color blending.
		*/
		static color_space::color_base* color(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does luminosity blending.
		/*!
		* Static function that does luminosity blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being luminosity blended.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus luminosity blending). Neither source and destination will produce something
		* simular to porter duffs in operator with luminosity blending.
		* Note that this blend operator does not work componentwise but consider all components
		* in a combination.
		* Since the operation is done in hsl space a conversion will be done first. Therefore
		* source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \return the combination of source and destination calculated with luminosity blending.
		*/
		static color_space::color_base* luminosity(color_space::color_base* source, color_space::color_base* destination, bool use_source_region = true, bool use_destination_region = true);

		//! Static function that does custom non-componentwise  blending.
		/*!
		* Static function that does custom non-componentwise blending. In its default configuration
		* (use source and destination region) it will produce the same result like the porter
		* duff over operator with the overlapping area being custom blended.
		* Only source and only destination equals porter duffs' source respectively destination
		* operators (plus custom blending). Neither source and destination will produce something
		* simular to porter duffs in operator with custom blending.
		* Note that this blend operator does not work componentwise but consider all components
		* in a combination.
		* Since the operation is done in hsl space a conversion will be done first. Therefore
		* source and destination do not need to have the same color type. However the
		* rgb color space definitions of both colors must match. The resulting color will be in
		* the same space like source color.
		* \param source The source color of the operation.
		* \param destination The destination color of the operation.
		* \param use_source_region Whether the source region of the resulting pixel will be blank
		* or not.
		* \param use_destination_region Whether the destination region of the resulting pixel will
		* be blank or not.
		* \param blend_function The function that does the blending. It awaits source and destination
		* values as input (in this order) and returns a blended values.
		* \return the combination of source and destination calculated with custom blending.
		*/
		static color_space::color_base* custom_combination_blend(color_space::color_base* source, color_space::color_base* destination, bool use_source_region, bool use_destination_region, std::function<float(float, float)> blend_function);


	protected:
		static float multiply_func(float s, float d)
		{
			return s * d;
		}

		static float screen_func(float s, float d)
		{
			return s + d - (s * d);
		}

		static float overlay_func(float s, float d)
		{
			return hard_light_func(d, s);
		}

		static float darken_func(float s, float d)
		{
			return (s <= d) ? s : d;
		}

		static float lighten_func(float s, float d)
		{
			return (s <= d) ? d : s;
		}

		static float color_dodge_func(float s, float d)
		{
			if (d == 0.f) return 0.f;
			else if (s == 1.f) return 1.f;
			float tmp = d / (1.f - s);
			return (tmp <= 1.f) ? tmp : 1.f;
		}

		static float color_burn_func(float s, float d)
		{
			if (d == 1.f) return 1.f;
			else if (s == 0.f) return 0.f;
			float tmp = (1.f - d) / s;
			return (tmp <= 1.f) ? tmp : 1.f;
		}

		static float hard_light_func(float s, float d)
		{
			if (s <= 0.5f) return multiply_func(2.f * s, d);
			return screen_func(2.f * s - 1.f, d);
		}

		static float soft_light_func(float s, float d)
		{
			if (s <= 0.5f) return d - (1.f - 2.f * s) * d * (1.f - d);

			float tmp;
			if (d <= 0.25f) tmp = ((16.f * d - 12.f) * d + 4.f) * d;
			else tmp = sqrtf(d);

			return d + (2.f * s - 1.f) * (tmp - d);
		}

		static float difference_func(float s, float d)
		{
			return fabsf(d - s);
		}

		static float exclusion_func(float s, float d)
		{
			return d + s - 2.f * d * s;
		}
	};
}