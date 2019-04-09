/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "..\utils\color_type.h"
#include "..\spaces\color_base.h"
#include "..\spaces\cmyk.h"
#include "..\spaces\grey_deepcolor.h"
#include "..\spaces\grey_truecolor.h"
#include "..\spaces\hsl.h"
#include "..\spaces\hsv.h"
#include "..\spaces\lab.h"
#include "..\spaces\rgb_deepcolor.h"
#include "..\spaces\rgb_truecolor.h"
#include "..\spaces\xyz.h"

#include <string>
#include <algorithm>

namespace color_manipulation
{
	struct reference_white
	{
		reference_white(float x, float y, float z) : x(x), y(y), z(z) { }
		float x;
		float y;
		float z;
	};

	class reference_white_presets
	{
	public:
		static reference_white CIE_D50;
		static reference_white CIE_D55;
		static reference_white CIE_D65;
		static reference_white CIE_Standard_Illuminant_A;
		static reference_white CIE_Standard_Illuminant_C;
		static reference_white Equal_Energy_Radiator;
		static reference_white ICC;
	};

	class color_converter
	{
	public:
		//! Static function that converts an arbitrary color to another arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* convertTo(color_space::color_base* in_color, color_type out_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an rgb true color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_rgb_true(color_space::rgb_truecolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an rgb deep color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_rgb_deep(color_space::rgb_deepcolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an grey true color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_grey_true(color_space::grey_truecolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an grey deep color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_grey_deep(color_space::grey_deepcolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an cmyk color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_cmyk(color_space::cmyk* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an hsv color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_hsv(color_space::hsv* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an hsl color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_hsl(color_space::hsl* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an xyz color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_xyz(color_space::xyz* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an lab color to an arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the output color type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The converted input color.
		*/
		static color_space::color_base* from_lab(color_space::lab* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to rgb true color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* to_rgb_true(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to rgb deep color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* to_rgb_deep(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to grey true color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* to_grey_true(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to grey deep color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* to_grey_deep(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to cmyk color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* to_cmyk(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to hsv color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* to_hsv(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to hsl color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* to_hsl(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to xyz color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* to_xyz(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts an arbitrary color to lab color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param reference The reference white that will be needed if in_color is of type lab. Otherwise this
		* parameter will be ignored.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* to_lab(color_space::color_base* in_color, reference_white reference = reference_white_presets::CIE_D65);

	protected:
		//! Static function that converts a rgb true color to rgb deep color space.
		/*!
		* Divides each component by 255.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* rgb_true_to_rgb_deep(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to grey true color space.
		/*!
		* Calculates the average of red, green and blue and sets it as grey value.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* rgb_true_to_grey_true(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to grey deep color space.
		/*!
		* First converts the input color to grey true color space and afterwards divides value 
		* and alpha by 255.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* rgb_true_to_grey_deep(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* rgb_true_to_cmyk(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* rgb_true_to_hsv(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* rgb_true_to_hsl(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* rgb_true_to_xyz(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* rgb_true_to_lab(color_space::rgb_truecolor* color, reference_white reference = reference_white_presets::CIE_D65);


		//! Static function that converts a rgb deep color to rgb true color space.
		/*!
		* Multiplies each component by 255.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* rgb_deep_to_rgb_true(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to rgb true and afterwards
		* the rgb true color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::grey_truecolor* rgb_deep_to_grey_true(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to rgb true color space.
		/*!
		* Calculates the average of red, green and blue and sets it as grey value.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* rgb_deep_to_grey_deep(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to cmyk color space.
		/*!
		* First this function calculates black by finding the maximum value of red, green
		* and blue. Afterwards cyan, magenta and yellow are calculated with the formula
		* (1 - rgb_comp - black) / (1 - black)
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* rgb_deep_to_cmyk(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to hsv color space.
		/*!
		* First this function finds the minimum and maximum components of the input color.
		* If max and min are equal the input color is grey and the resulting hsv color will 
		* be hsv(0, 0, min).
		* Otherwise hue is calculated depending on the max value and the difference of max 
		* and min.
		* Finally saturation is defined by delta / max and value is equal to max.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* rgb_deep_to_hsv(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to hsv and afterwards
		* the hsv color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* rgb_deep_to_hsl(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to xyz color space.
		/*!
		* The resulting components are calculated by the following formulas:
		* x = red * 0.4124564 + green * 0.3575761 + blue * 0.1804375
		* y = red * 0.2126729 + green * 0.7151522 + blue * 0.0721750
		* z = red * 0.0193339 + green * 0.1191920 + blue * 0.9503041
		* Finally all components are multiplied by 100.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* rgb_deep_to_xyz(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to lab color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to lab.
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* rgb_deep_to_lab(color_space::rgb_deepcolor* color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts a rgb deep color to srgb.
		/*!
		* Depending on the value of each component it is divided by 12.92 (if smaller than 0.04045)
		* or it will be converted by the formula:
		* ((comp + 0.055) / 1.055)^2.4
		* \param in_color The color to convert.
		* \return The input color converted to srgb.
		*/
		static color_space::rgb_deepcolor* rgb_deep_to_linear_srgb_deep(color_space::rgb_deepcolor* color);
		
		//! Static function that converts a srgb color to rgb deep.
		/*!
		* Depending on the value of each component it is multiplied by 12.92 (if smaller than 0.003108)
		* or it will be converted by the formula:
		* sqrt((comp * 1.055)^2.4) - 0.055
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep.
		*/
		static color_space::rgb_deepcolor* linear_srgb_deep_to_rgb_deep(color_space::rgb_deepcolor* color);


		//! Static function that converts a grey true color to rgb true color space.
		/*!
		* Sets the grey colors value as the red, green and blue components.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* grey_true_to_rgb_true(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to rgb deep color space.
		/*!
		* Divides the grey colors value by 255 and afterwards sets it as red, green and blue 
		* components.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* grey_true_to_rgb_deep(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to grey deep color space.
		/*!
		* Divides the grey colors value by 255.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::grey_deepcolor* grey_true_to_grey_deep(color_space::grey_truecolor* color);
		
		//! Static function that converts a grey true color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* grey_true_to_cmyk(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* grey_true_to_hsv(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsl* grey_true_to_hsl(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* grey_true_to_xyz(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* grey_true_to_lab(color_space::grey_truecolor* color, reference_white reference = reference_white_presets::CIE_D65);


		//! Static function that converts a grey deep color to rgb true color space.
		/*!
		* Multiplies value and alpha by 255 and sets value as red, green and blue components.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* grey_deep_to_rgb_true(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to rgb deep color space.
		/*!
		* Sets greys value as red, green and blue components.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* grey_deep_to_rgb_deep(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to grey true color space.
		/*!
		* Multiplies value and alpha by 255.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* grey_deep_to_grey_true(color_space::grey_deepcolor* color);
		
		//! Static function that converts a grey deep color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* grey_deep_to_cmyk(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* grey_deep_to_hsv(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* grey_deep_to_hsl(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* grey_deep_to_xyz(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* grey_deep_to_lab(color_space::grey_deepcolor* color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts a cmyk color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* cmyk_to_rgb_true(color_space::cmyk* color);

		//! Static function that converts a cmyk color to rgb deep color space.
		/*!
		* The resulting components are calculated by the following formulas:
		* r = (1 - cyan) * (1 - black)
		* g = (1 - magenta) * (1 - black)
		* b = (1 - yellow) * (1 - black)
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* cmyk_to_rgb_deep(color_space::cmyk* color);

		//! Static function that converts a cmyk color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::grey_truecolor* cmyk_to_grey_true(color_space::cmyk* color);

		//! Static function that converts a cmyk color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_deepcolor* cmyk_to_grey_deep(color_space::cmyk* color);

		//! Static function that converts a cmyk color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* cmyk_to_hsv(color_space::cmyk* color);

		//! Static function that converts a cmyk color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* cmyk_to_hsl(color_space::cmyk* color);

		//! Static function that converts a cmyk color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* cmyk_to_xyz(color_space::cmyk* color);

		//! Static function that converts a cmyk color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* cmyk_to_lab(color_space::cmyk* color, reference_white reference = reference_white_presets::CIE_D65);


		//! Static function that converts a hsv color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* hsv_to_rgb_true(color_space::hsv* color);

		//! Static function that converts a hsv color to rgb deep color space.
		/*!
		* Converts the hsv input color to rgb deep by using the formula provided 
		* here: https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* hsv_to_rgb_deep(color_space::hsv* color);

		//! Static function that converts a hsv color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* hsv_to_grey_true(color_space::hsv* color);

		//! Static function that converts a hsv color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* hsv_to_grey_deep(color_space::hsv* color);

		//! Static function that converts a hsv color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* hsv_to_cmyk(color_space::hsv* color);

		//! Static function that converts a hsv color to hsl color space.
		/*!
		* Lightness is calculated as follows: ((2 - saturation) * value)
		* Saturation is calculated as follows: saturation * value. If the resulting value is
		* less or equal than 1 it will be divided by Lightness. Otherwise it will be divided 
		* by (2 - Lightness)
		* Finally Lightness will be divided by 2
		* Hue does not change during the conversion.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* hsv_to_hsl(color_space::hsv* color);

		//! Static function that converts a hsv color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* hsv_to_xyz(color_space::hsv* color);

		//! Static function that converts a hsv color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* hsv_to_lab(color_space::hsv* color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts a hsl color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* hsl_to_rgb_true(color_space::hsl* color);

		//! Static function that converts a hsl color to rgb deep color space.
		/*!
		* Converts the hsl input color to rgb deep by using the following formula:
		* temp_hue = hue / 360
		* temp1 = (lightness < 0.5) ? lightness * (1 + saturation) : lightness + saturation - (lightness * saturation)
		* temp2 = 2 * lightness - var1
		* These three temporary variables are used as input parameters for \sa hsl_to_rgb_helper() function
		* in order to calculate red, green and blue:
		* r = hsl_to_rgb_helper(temp1, temp2, temp_hue + 0.33)
		* g = hsl_to_rgb_helper(temp1, temp2, temp_hue)
		* b = hsl_to_rgb_helper(temp1, temp2, temp_hue - 0.33)
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_deepcolor* hsl_to_rgb_deep(color_space::hsl* color);

		//! Static function that converts a hsl color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* hsl_to_grey_true(color_space::hsl* color);

		//! Static function that converts a hsl color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* hsl_to_grey_deep(color_space::hsl* color);

		//! Static function that converts a hsl color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* hsl_to_cmyk(color_space::hsl* color);

		//! Static function that converts a hsl color to hsv color space.
		/*!
		* Converts the hsl input color to hsv by using the following formula:
		* temp_lightness = lightness * 2
		* If saturation is less or equal than 1, saturation = temp_lightness. Otherwise
		* saturation is 2 - temp_lightness
		* value = (temp_lightness + saturation) / 2
		* saturation = (2 * saturation) / (temp_lightness + saturation)
		* Hue does not change during the calculation.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* hsl_to_hsv(color_space::hsl* color);

		//! Static function that converts a hsl color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* hsl_to_xyz(color_space::hsl* color);

		//! Static function that converts a hsl color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* hsl_to_lab(color_space::hsl* color, reference_white reference = reference_white_presets::CIE_D65);

		//! Static function that converts a xyz color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* xyz_to_rgb_true(color_space::xyz* color);

		//! Static function that converts a xyz color to rgb deep color space.
		/*!
		* First all components are divided by 100 to convert them to the range [0,1].
		* Afterwars red, green and blue are calculated by:
		* r = x * 3.2404542 + y * -1.5371385 + z * 0.4985314
		* g = x * -0.9692660 + y * 1.8760108 + z * 0.0415560
		* b = x * 0.0556434 + y * -0.2040259 + z * 1.0572252
		* Then the resulting rgb color is converted from srgb to normal rgb by using the
		* helper function linear_srgb_deep_to_rgb_deep().
		* Finally all values are clamped to the range [0,1] (clamp_float()) and rounded 
		* to 1 decimals (by using the helper function round_float_to_n_decimals())
		* \sa linear_srgb_deep_to_rgb_deep(), clamp_float(), round_float_to_n_decimals()
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* xyz_to_rgb_deep(color_space::xyz* color);

		//! Static function that converts a xyz color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* xyz_to_grey_true(color_space::xyz* color);

		//! Static function that converts a xyz color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* xyz_to_grey_deep(color_space::xyz* color);

		//! Static function that converts a xyz color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* xyz_to_cmyk(color_space::xyz* color);

		//! Static function that converts a xyz color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* xyz_to_hsv(color_space::xyz* color);

		//! Static function that converts a xyz color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* xyz_to_hsl(color_space::xyz* color);

		//! Static function that converts a xyz color to hsl color space.
		/*!
		* The calculation is done by using the following formula (where rw is reference white)
		* L = 116 *  xyz_to_lab_helper(y / rw_y) - 16;
		* a = 500 * (xyz_to_lab_helper(x / rw_x) - xyz_to_lab_helper(y / rw_y))
		* b = 200 * (xyz_to_lab_helper(y / rw_y) - xyz_to_lab_helper(z / rw_z))
		* \sa xyz_to_lab_helper()
		* \param in_color The color to convert.
		* \param reference The reference white needed to convert to lab.
		* \return The input color converted to hsl color space.
		*/
		static color_space::lab* xyz_to_lab(color_space::xyz* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* lab_to_rgb_true(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::rgb_deepcolor* lab_to_rgb_deep(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::grey_truecolor* lab_to_grey_true(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::grey_deepcolor* lab_to_grey_deep(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::cmyk* lab_to_cmyk(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::hsv* lab_to_hsv(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::hsl* lab_to_hsl(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::xyz* lab_to_xyz(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);

	private:
		static float hsl_to_rgb_helper(float temp_component, float temp1, float temp2);
		static float xyz_to_lab_helper(float color_component);
		static float lab_to_xyz_helper(float color_component, bool out_y_component = false);
		static float round_float_to_n_decimals(float in_float, float n);
		static float clamp_float(float in_float, float bottom, float top);
	};
}
