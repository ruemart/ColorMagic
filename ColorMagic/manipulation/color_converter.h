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
#include "..\spaces\hsi.h"
#include "..\spaces\hsv.h"
#include "..\spaces\hsl.h"
#include "..\spaces\hcy.h"
#include "..\spaces\lab.h"
#include "..\spaces\lch_ab.h"
#include "..\spaces\lch_uv.h"
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

		//! Static function that converts an arbitrary color to hsi color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* to_hsi(color_space::color_base* in_color);

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

		//! Static function that converts an arbitrary color to hcy color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* to_hcy(color_space::color_base* in_color);

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

		//! Static function that converts an arbitrary color to lch(ab) color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* to_lch_ab(color_space::color_base* in_color);

		//! Static function that converts an arbitrary color to lch(uv) color space.
		/*!
		* Wrapper function that calls the correct converter function depending on the input colors type.
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* to_lch_uv(color_space::color_base* in_color);

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

		//! Static function that converts a rgb true color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* rgb_true_to_hsi(color_space::rgb_truecolor* color);

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

		//! Static function that converts a rgb true color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* rgb_true_to_hcy(color_space::rgb_truecolor* color);

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

		//! Static function that converts a rgb true color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* rgb_true_to_lch_ab(color_space::rgb_truecolor* color);

		//! Static function that converts a rgb true color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* rgb_true_to_lch_uv(color_space::rgb_truecolor* color);

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

		//! Static function that converts a rgb deep color to hsi color space.
		/*!
		* Static function that converts a rgb deep color to hsi color space.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* rgb_deep_to_hsi(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to hsv color space.
		/*!
		* Static function that converts a rgb deep color to hsv color space.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* rgb_deep_to_hsv(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to hsl color space.
		/*!
		* Function that converts the input color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* rgb_deep_to_hsl(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to hcy color space.
		/*!
		* Function that converts a rgb deep color to hcy color space.
		* Note that this conversion is not exactly revertable. That means 
		* after doing a round trip conversion (RGB -> HCY -> RGB) the 
		* result will differ from the input. 
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* rgb_deep_to_hcy(color_space::rgb_deepcolor* color);

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

		//! Static function that converts a rgb deep color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* rgb_deep_to_lch_ab(color_space::rgb_deepcolor* color);

		//! Static function that converts a rgb deep color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* rgb_deep_to_lch_uv(color_space::rgb_deepcolor* color);

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

		//! Static function that converts a grey true color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* grey_true_to_hsi(color_space::grey_truecolor* color);

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

		//! Static function that converts a grey true color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* grey_true_to_hcy(color_space::grey_truecolor* color);

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

		//! Static function that converts a grey true color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* grey_true_to_lch_ab(color_space::grey_truecolor* color);

		//! Static function that converts a grey true color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* grey_true_to_lch_uv(color_space::grey_truecolor* color);

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

		//! Static function that converts a grey deep color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* grey_deep_to_hsi(color_space::grey_deepcolor* color);

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

		//! Static function that converts a grey deep color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* grey_deep_to_hcy(color_space::grey_deepcolor* color);

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

		//! Static function that converts a grey deep color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* grey_deep_to_lch_ab(color_space::grey_deepcolor* color);

		//! Static function that converts a grey deep color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* grey_deep_to_lch_uv(color_space::grey_deepcolor* color);

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

		//! Static function that converts a cmyk color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* cmyk_to_hsi(color_space::cmyk* color);

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

		//! Static function that converts a cmyk color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* cmyk_to_hcy(color_space::cmyk* color);

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

		//! Static function that converts a cmyk color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* cmyk_to_lch_ab(color_space::cmyk* color);

		//! Static function that converts a cmyk color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* cmyk_to_lch_uv(color_space::cmyk* color);

#pragma endregion


#pragma region HSI CONVERTER FUNCTIONS

		//! Static function that converts a hsi color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* hsi_to_rgb_true(color_space::hsi* color);

		//! Static function that converts a hsi color to rgb deep color space.
		/*!
		* Converts the hsv input color to rgb deep by using the formula provided
		* here: https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* hsi_to_rgb_deep(color_space::hsi* color);

		//! Static function that converts a hsi color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* hsi_to_grey_true(color_space::hsi* color);

		//! Static function that converts a hsi color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* hsi_to_grey_deep(color_space::hsi* color);

		//! Static function that converts a hsi color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* hsi_to_cmyk(color_space::hsi* color);

		//! Static function that converts a hsi color to hsv color space.
		/*!
		* Static function that converts a hsi color to hsv color space.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* hsi_to_hsv(color_space::hsi* color);

		//! Static function that converts a hsi color to hsl color space.
		/*!
		* Static function that converts a hsi color to hsl color space.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* hsi_to_hsl(color_space::hsi* color);

		//! Static function that converts a hsi color to hcy color space.
		/*!
		* Static function that converts a hsi color to hcy color space.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* hsi_to_hcy(color_space::hsi* color);

		//! Static function that converts a hsi color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* hsi_to_xyz(color_space::hsi* color);

		//! Static function that converts a hsi color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* hsi_to_xyy(color_space::hsi* color);

		//! Static function that converts a hsi color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* hsi_to_cieluv(color_space::hsi* color);

		//! Static function that converts a hsi color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* hsi_to_lab(color_space::hsi* color);

		//! Static function that converts a hsi color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* hsi_to_lch_ab(color_space::hsi* color);

		//! Static function that converts a hsi color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* hsi_to_lch_uv(color_space::hsi* color);

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

		//! Static function that converts a hsv color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* hsv_to_hsi(color_space::hsv* color);

		//! Static function that converts a hsv color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* hsv_to_hsl(color_space::hsv* color);

		//! Static function that converts a hsv color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* hsv_to_hcy(color_space::hsv* color);

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

		//! Static function that converts a hsv color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* hsv_to_lch_ab(color_space::hsv* color);

		//! Static function that converts a hsv color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* hsv_to_lch_uv(color_space::hsv* color);

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
		* Function that converts the hsl input color to rgb deep.
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

		//! Static function that converts a hsl color to hsi color space.
		/*!
		* function that converts the hsl input color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* hsl_to_hsi(color_space::hsl* color);

		//! Static function that converts a hsl color to hsv color space.
		/*!
		* function that converts the hsl input color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* hsl_to_hsv(color_space::hsl* color);

		//! Static function that converts a hsl color to hcy color space.
		/*!
		* function that converts the hsl input color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* hsl_to_hcy(color_space::hsl* color);

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

		//! Static function that converts a hsl color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* hsl_to_lch_ab(color_space::hsl* color);

		//! Static function that converts a hsl color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* hsl_to_lch_uv(color_space::hsl* color);

#pragma endregion


#pragma region HCL CONVERTER FUNCTIONS

		//! Static function that converts a hcy color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* hcy_to_rgb_true(color_space::hcy* color);

		//! Static function that converts a hcy color to rgb deep color space.
		/*!
		* Function that converts the hcy input color to rgb deep.
		* Note that this conversion is not exactly revertable. That means
		* after doing a round trip conversion (RGB -> HCY -> RGB) the
		* result will differ from the input.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_deepcolor* hcy_to_rgb_deep(color_space::hcy* color);

		//! Static function that converts a hcy color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* hcy_to_grey_true(color_space::hcy* color);

		//! Static function that converts a hcy color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* hcy_to_grey_deep(color_space::hcy* color);

		//! Static function that converts a hcy color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* hcy_to_cmyk(color_space::hcy* color);

		//! Static function that converts a hcy color to hsi color space.
		/*!
		* function that converts the hcy input color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* hcy_to_hsi(color_space::hcy* color);

		//! Static function that converts a hcy color to hsv color space.
		/*!
		* function that converts the hcy input color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* hcy_to_hsv(color_space::hcy* color);

		//! Static function that converts a hcy color to hsl color space.
		/*!
		* function that converts the hcy input color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* hcy_to_hsl(color_space::hcy* color);

		//! Static function that converts a hcy color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyz color space.
		*/
		static color_space::xyz* hcy_to_xyz(color_space::hcy* color);

		//! Static function that converts a hcy color to xyY color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to xyY.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyy* hcy_to_xyy(color_space::hcy* color);

		//! Static function that converts a hcy color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* hcy_to_cieluv(color_space::hcy* color);

		//! Static function that converts a hcy color to lab color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* hcy_to_lab(color_space::hcy* color);

		//! Static function that converts a hcy color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* hcy_to_lch_ab(color_space::hcy* color);

		//! Static function that converts a hcy color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* hcy_to_lch_uv(color_space::hcy* color);

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
		* Function that converts a xyz color to rgb deep color space.
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

		//! Static function that converts a xyz color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* xyz_to_hsi(color_space::xyz* color);

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

		//! Static function that converts a xyz color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to rgb deep and afterwards
		* the rgb deep color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* xyz_to_hcy(color_space::xyz* color);

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

		//! Static function that converts a xyz color to lab color space.
		/*!
		* Static function that converts a xyz color to lab color space.
		* \param in_color The color to convert.
		* \return The input color converted to lab color space.
		*/
		static color_space::lab* xyz_to_lab(color_space::xyz* color);

		//! Static function that converts a xyz color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* xyz_to_lch_ab(color_space::xyz* color);

		//! Static function that converts a xyz color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* xyz_to_lch_uv(color_space::xyz* color);

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

		//! Static function that converts a xyY color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* xyy_to_hsi(color_space::xyy* color);

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

		//! Static function that converts a xyY color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* xyy_to_hcy(color_space::xyy* color);

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

		//! Static function that converts a xyy color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* xyy_to_lch_ab(color_space::xyy* color);

		//! Static function that converts a xyy color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* xyy_to_lch_uv(color_space::xyy* color);

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

		//! Static function that converts a cieluv color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* cieluv_to_hsi(color_space::cieluv* color);

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

		//! Static function that converts a cieluv color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* cieluv_to_hcy(color_space::cieluv* color);

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

		//! Static function that converts a cieluv color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* cieluv_to_lch_ab(color_space::cieluv* color);

		//! Static function that converts a cieluv color to lch(uv) color space.
		/*!
		* Static function that converts a cieluv color to lch(uv) color space.
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* cieluv_to_lch_uv(color_space::cieluv* color);

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

		//! Static function that converts a lab color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* lab_to_hsi(color_space::lab* color);

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

		//! Static function that converts a lab color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to xyz and afterwards
		* the xyz color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* lab_to_hcy(color_space::lab* color);

		//! Static function that converts a lab color to xyz color space.
		/*!
		* Function that converts a lab color to xyz color space.
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

		//! Static function that converts a lab color to lch(ab) color space.
		/*!
		* Static function that converts a lab color to lch(ab) color space.
		* \param in_color The color to convert.
		* \return The input color converted to lch(ab) color space.
		*/
		static color_space::lch_ab* lab_to_lch_ab(color_space::lab* color);

		//! Static function that converts a lab color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* lab_to_lch_uv(color_space::lab* color);

#pragma endregion

#pragma region LCH(AB) CONVERTER FUNCTIONS

		//! Static function that converts a lch(ab) color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* lch_ab_to_rgb_true(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to rgb deep color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to rgb deep.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* lch_ab_to_rgb_deep(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* lch_ab_to_grey_true(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* lch_ab_to_grey_deep(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* lch_ab_to_cmyk(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* lch_ab_to_hsi(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* lch_ab_to_hsv(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* lch_ab_to_hsl(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* lch_ab_to_hcy(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyz* lch_ab_to_xyz(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to xyy color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to xyy.
		* \param in_color The color to convert.
		* \return The input color converted to xyy color space.
		*/
		static color_space::xyy* lch_ab_to_xyy(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to cieluv color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to cieluv.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* lch_ab_to_cieluv(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to lab color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::lab* lch_ab_to_lab(color_space::lch_ab* color);

		//! Static function that converts a lch(ab) color to lch(uv) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(uv).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_uv* lch_ab_to_lch_uv(color_space::lch_ab* color);

#pragma endregion

#pragma region LCH(UV) CONVERTER FUNCTIONS

		//! Static function that converts a lch(uv) color to rgb true color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to rgb true.
		* \param in_color The color to convert.
		* \return The input color converted to rgb true color space.
		*/
		static color_space::rgb_truecolor* lch_uv_to_rgb_true(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to rgb deep color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to rgb deep.
		* \param in_color The color to convert.
		* \return The input color converted to rgb deep color space.
		*/
		static color_space::rgb_deepcolor* lch_uv_to_rgb_deep(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to grey true color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to grey true.
		* \param in_color The color to convert.
		* \return The input color converted to grey true color space.
		*/
		static color_space::grey_truecolor* lch_uv_to_grey_true(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to grey deep color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to grey deep.
		* \param in_color The color to convert.
		* \return The input color converted to grey deep color space.
		*/
		static color_space::grey_deepcolor* lch_uv_to_grey_deep(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to cmyk color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to cmyk.
		* \param in_color The color to convert.
		* \return The input color converted to cmyk color space.
		*/
		static color_space::cmyk* lch_uv_to_cmyk(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to hsi color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to hsi.
		* \param in_color The color to convert.
		* \return The input color converted to hsi color space.
		*/
		static color_space::hsi* lch_uv_to_hsi(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to hsv color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to hsv.
		* \param in_color The color to convert.
		* \return The input color converted to hsv color space.
		*/
		static color_space::hsv* lch_uv_to_hsv(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to hsl color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to hsl.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::hsl* lch_uv_to_hsl(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to hcy color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to hcy.
		* \param in_color The color to convert.
		* \return The input color converted to hcy color space.
		*/
		static color_space::hcy* lch_uv_to_hcy(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to xyz color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to xyz.
		* \param in_color The color to convert.
		* \return The input color converted to xyY color space.
		*/
		static color_space::xyz* lch_uv_to_xyz(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to xyy color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to xyy.
		* \param in_color The color to convert.
		* \return The input color converted to xyy color space.
		*/
		static color_space::xyy* lch_uv_to_xyy(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to cieluv color space.
		/*!
		* Static function that converts a lch(uv) color to cieluv color space.
		* \param in_color The color to convert.
		* \return The input color converted to cieluv color space.
		*/
		static color_space::cieluv* lch_uv_to_cieluv(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to lab color space.
		/*!
		* Wrapper function that first converts the input color to cieluv and afterwards
		* the cieluv color to lab.
		* \param in_color The color to convert.
		* \return The input color converted to hsl color space.
		*/
		static color_space::lab* lch_uv_to_lab(color_space::lch_uv* color);

		//! Static function that converts a lch(uv) color to lch(ab) color space.
		/*!
		* Wrapper function that first converts the input color to lab and afterwards
		* the lab color to lch(ab).
		* \param in_color The color to convert.
		* \return The input color converted to lch(uv) color space.
		*/
		static color_space::lch_ab* lch_uv_to_lch_ab(color_space::lch_uv* color);

#pragma endregion

	private:
		//! Static function that calculates hue for hsi, hsv, hsl and hcy color spaces.
		/*!
		* \param red The value of the rgb deep red component.
		* \param green The value of the rgb deep green component.
		* \param blue The value of the rgb deep blue component.
		* \param max The maximum component value.
		* \param min The minimum component value.
		* \param delta The difference of max and min.
		* \return The calculated hue value.
		*/
		static float hue_from_rgb_helper(float red, float green, float blue, float max, float min, float delta);

		//! Static function that helps to convert from hsv to rgb
		/*!
		* Implements function that converts hsv in an optimized way to rgb. Call this
		* function for each component.
		* \param color The hsv color to convert to rgb
		* \param n Input factor for conversion (R: n=0, G: n=8, B: n=4).
		* \return The value of one of the resulting colors components.
		*/
		static float hsv_to_rgb_helper(color_space::hsv* color, float n);

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

		//! Static function that helps to convert from hsl to rgb
		/*!
		* Implements function that converts hsl in an optimized way to rgb. Call this 
		* function for each component.
		* \param color The hsl color to convert to rgb
		* \param n Input factor for conversion (R: n=0, G: n=8, B: n=4).
		* \return The value of one of the resulting colors components.
		*/
		static float hsl_to_rgb_helper(color_space::hsl* color, float n);

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
