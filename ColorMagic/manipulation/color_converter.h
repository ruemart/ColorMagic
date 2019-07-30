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
#include "..\spaces\xyy.h"
#include "..\spaces\cieluv.h"
#include "..\spaces\rgb_color_space_definition.h"

#include <string>
#include <algorithm>

namespace color_manipulation
{
	//! Static class for color conversions.
	/*!
	* This static class implements various functions to convert from one color space to another.
	*/
	class color_converter
	{
	public:
		//! Static function that converts an arbitrary color to another arbitrary color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \param out_color The desired color space of the output color.
		* \return The converted input color.
		*/
		static color_space::color_base* convertTo(color_space::color_base* in_color, color_type out_color);

		//! Static function that converts an arbitrary color to rgb true color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* to_rgb_true(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to rgb deep color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* to_rgb_deep(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to grey true color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* to_grey_true(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to grey deep color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* to_grey_deep(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to cmyk color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* to_cmyk(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to hsv color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* to_hsv(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to hsl color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* to_hsl(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to xyz color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* to_xyz(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to xyY color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* to_xyy(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to cieluv color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* to_cieluv(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to lab color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* to_lab(color_space::color_base* in_color);

	protected:

#pragma region RGB_TRUE CONVERTER FUNCTIONS

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

		//! Static function that converts a rgb true color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* rgb_true_to_xyy(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* rgb_true_to_cieluv(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* rgb_true_to_lab(color_space::rgb_truecolor* color);

#pragma endregion

#pragma region RGB_DEEP CONVERTER FUNCTIONS
		
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
		* Static function that converts a rgb deep color to xyz color space.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* rgb_deep_to_xyz(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to xyY color space.
		/*!
		* Static function that converts a rgb deep color to xyY color space.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* rgb_deep_to_xyy(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to cieluv color space.
		/*!
		* Static function that converts a rgb deep color to cieluv color space.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* rgb_deep_to_cieluv(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to lab color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* rgb_deep_to_lab(color_space::rgb_deepcolor* color);

#pragma endregion

#pragma region GREY_TRUE CONVERTER FUNCTIONS
		
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

		//! Static function that converts a grey true color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* grey_true_to_xyy(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* grey_true_to_cieluv(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* grey_true_to_lab(color_space::grey_truecolor* color);

#pragma endregion

#pragma region GREY_DEEP CONVERTER FUNCTIONS
		
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

		//! Static function that converts a grey deep color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* grey_deep_to_xyy(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* grey_deep_to_cieluv(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* grey_deep_to_lab(color_space::grey_deepcolor* color);

#pragma endregion

#pragma region CMYK CONVERTER FUNCTIONS

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

		//! Static function that converts a cmyk color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* cmyk_to_xyy(color_space::cmyk* color);

		//! Static function that converts a cmyk color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* cmyk_to_cieluv(color_space::cmyk* color);

		//! Static function that converts a cmyk color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* cmyk_to_lab(color_space::cmyk* color);

#pragma endregion

#pragma region HSV CONVERTER FUNCTIONS
				
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

		//! Static function that converts a hsv color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* hsv_to_xyy(color_space::hsv* color);

		//! Static function that converts a hsv color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* hsv_to_cieluv(color_space::hsv* color);

		//! Static function that converts a hsv color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* hsv_to_lab(color_space::hsv* color);

#pragma endregion

#pragma region HSL CONVERTER FUNCTIONS

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

		//! Static function that converts a hsl color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* hsl_to_xyy(color_space::hsl* color);

		//! Static function that converts a hsl color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* hsl_to_cieluv(color_space::hsl* color);

		//! Static function that converts a hsl color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* hsl_to_lab(color_space::hsl* color);

#pragma endregion

#pragma region XYZ CONVERTER FUNCTIONS

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

		//! Static function that converts a xyz color to xyY color space.
		/*!
		* Static function that converts a xyz color to xyY color space.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* xyz_to_xyy(color_space::xyz* color);

		//! Static function that converts a xyz color to cieluv color space.
		/*!
		* Static function that converts a xyz color to cieluv color space.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* xyz_to_cieluv(color_space::xyz* color);

		//! Static function that converts a xyz color to hsl color space.
		/*!
		* The calculation is done by using the following formula (where rw is tristimulus white)
		* L = 116 *  xyz_to_lab_helper(y / rw_y) - 16;
		* a = 500 * (xyz_to_lab_helper(x / rw_x) - xyz_to_lab_helper(y / rw_y))
		* b = 200 * (xyz_to_lab_helper(y / rw_y) - xyz_to_lab_helper(z / rw_z))
		* \sa xyz_to_lab_helper()
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::lab* xyz_to_lab(color_space::xyz* color);

#pragma endregion

#pragma region XYY CONVERTER FUNCTIONS

		//! Static function that converts a xyY color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* xyy_to_rgb_true(color_space::xyy* color);

		//! Static function that converts a xyY color to rgb deep color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to rgb deep.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* xyy_to_rgb_deep(color_space::xyy* color);

		//! Static function that converts a xyY color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* xyy_to_grey_true(color_space::xyy* color);

		//! Static function that converts a xyY color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* xyy_to_grey_deep(color_space::xyy* color);

		//! Static function that converts a xyY color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* xyy_to_cmyk(color_space::xyy* color);

		//! Static function that converts a xyY color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* xyy_to_hsv(color_space::xyy* color);

		//! Static function that converts a xyY color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* xyy_to_hsl(color_space::xyy* color);

		//! Static function that converts a xyY color to xyz color space.
		/*!
		* Static function that converts a xyY color to xyz color space.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyz* xyy_to_xyz(color_space::xyy* color);

		//! Static function that converts a xyY color to cieluv color space.
		/*!
		* Static function that converts a xyY color to xyz color space.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* xyy_to_cieluv(color_space::xyy* color);

		//! Static function that converts a xyY color to lab color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::lab* xyy_to_lab(color_space::xyy* color);

#pragma endregion

#pragma region CIELUV CONVERTER FUNCTIONS

		//! Static function that converts a cieluv color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* cieluv_to_rgb_true(color_space::cieluv* color);

		//! Static function that converts a cieluv color to rgb deep color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to rgb deep.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* cieluv_to_rgb_deep(color_space::cieluv* color);

		//! Static function that converts a cieluv color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* cieluv_to_grey_true(color_space::cieluv* color);

		//! Static function that converts a cieluv color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* cieluv_to_grey_deep(color_space::cieluv* color);

		//! Static function that converts a cieluv color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* cieluv_to_cmyk(color_space::cieluv* color);

		//! Static function that converts a cieluv color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* cieluv_to_hsv(color_space::cieluv* color);

		//! Static function that converts a cieluv color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* cieluv_to_hsl(color_space::cieluv* color);

		//! Static function that converts a cieluv color to xyz color space.
		/*!
		* Static function that converts a cieluv color to xyz color space.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::xyz* cieluv_to_xyz(color_space::cieluv* color);

		//! Static function that converts a cieluv color to xyy color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to xyy color space.
		*/
		static color_space::xyy* cieluv_to_xyy(color_space::cieluv* color);

		//! Static function that converts a cieluv color to lab color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::lab* cieluv_to_lab(color_space::cieluv* color);

#pragma endregion

#pragma region LAB CONVERTER FUNCTIONS

		//! Static function that converts a lab color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* lab_to_rgb_true(color_space::lab* color);

		//! Static function that converts a lab color to rgb deep color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to rgb deep.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* lab_to_rgb_deep(color_space::lab* color);

		//! Static function that converts a lab color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* lab_to_grey_true(color_space::lab* color);

		//! Static function that converts a lab color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* lab_to_grey_deep(color_space::lab* color);

		//! Static function that converts a lab color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* lab_to_cmyk(color_space::lab* color);

		//! Static function that converts a lab color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* lab_to_hsv(color_space::lab* color);

		//! Static function that converts a lab color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* lab_to_hsl(color_space::lab* color);

		//! Static function that converts a lab color to xyz color space.
		/*!
		* temp_y = (luminance + 16) / 116
		* y = lab_to_xyz_helper(luminance, true);
		* x = lab_to_xyz_helper((a / 500) + temp_y
		* z = lab_to_xyz_helper(temp_y - (b / 200)
		* Finally all components are multiplied by their corresponding tristimulus white components
		* \sa lab_to_xyz_helper()
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* lab_to_xyz(color_space::lab* color);

		//! Static function that converts a lab color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* lab_to_cieluv(color_space::lab* color);

		//! Static function that converts a lab color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyy* lab_to_xyy(color_space::lab* color);

#pragma endregion

	private:
		//! Static function that helps to convert from hsl to rgb
		/*!
		* Inspects value of var3 and returns a value dependent of the result.
		* \sa hsl_to_rgb_deep()
		* \param var1 The first temporary variable that is calculated in hsl_to_rgb_deep().
		* \param var2 The second temporary variable that is calculated in hsl_to_rgb_deep().
		* \param var3 The input colors hue divided by 360 (+- 1/3).
		* \return The value of one of the resulting colors components.
		*/
		static float hsl_to_rgb_helper(float var1, float var2, float var3);

		//! Static function that helps to convert from xyz to lab
		/*!
		* Inspects input parameter and returns a value dependent of the result.
		* \sa xyz_to_lab()
		* \param color_component One component of the resulting color that should be calculated.
		* \return The value of one of the resulting colors components.
		*/
		static float xyz_to_lab_helper(float color_component);

		//! Static function that helps to convert from lab to xyz
		/*!
		* Inspects input parameter and returns a value dependent of the result.
		* \sa lab_to_xyz()
		* \param color_component One component of the resulting color that should be calculated.
		* \param out_y_component Whether the current component is the y component or not.
		* \return The value of one of the resulting colors components.
		*/
		static float lab_to_xyz_helper(float color_component, bool out_y_component = false);

		//! Static function that rounds a given float value to n decimals.
		/*!
		* Rounds a given float value to n decimals.
		* \param in_float The value to round.
		* \param n The number of decimals.
		* \return The rounded value.
		*/
		static float round_float_to_n_decimals(float in_float, float n);

		//! Static function that clamps a given float between max and min values.
		/*!
		* Clamps a given float value between max and min values.
		* \param in_float The value to round.
		* \param min The minimum number to return.
		* \param max The maximum number to return.
		* \return The clamped value.
		*/
		static float clamp_float(float in_float, float min, float max);

		//! Static function that clamps a given float between max and min values.
		/*!
		* Clamps a given float value between max and min values.
		* \param value The value to transform.
		* \param old_min The old range minimum.
		* \param old_max The old range maximum.
		* \param new_min The old range minimum.
		* \param new_max The new range maximum.
		* \return The transformed value.
		*/
		static float transform_range(float value, float old_min, float old_max, float new_min, float new_max);
	};
}
