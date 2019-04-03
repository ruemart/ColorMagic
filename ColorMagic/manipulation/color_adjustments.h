/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "..\spaces\color_base.h"
#include "color_converter.h"

//! Static class for color adjustments like desaturation.
	/*!
	* This static class implements various functions that modify a given color.
	*/
class color_adjustments
{
public:
	//! Static function that increases or decreases the saturation of a given color.
	/*!
	* \param color The color to manipulate.
	* \param percentage The amount by which to adjust the saturation. Values between 0 and 1 
	* increase the saturation and values between 0 and -1 decrease it.
	*/
	static void saturate(color_space::color_base& color, float percentage);

	//! Static function that increases or decreases the saturation of a given color.
	/*!
	* \param color The color to manipulate.
	* \param percentage The amount by which to adjust the saturation. Values between 0 and 1
	* increase the saturation and values between 0 and -1 decrease it.
	* \return The modified color in the same color space like the input color.
	*/
	static color_space::color_base* saturate(color_space::color_base* color, float percentage);

	//! Static function that increases or decreases the saturation of a given color.
	/*!
	* This function will convert the color to hsl and adjusts the saturation in this color space.
	* Afterwards the color will be converted back to input color space.
	* \param color The color to manipulate.
	* \param percentage The amount by which to adjust the saturation. Values between 0 and 1
	* increase the saturation and values between 0 and -1 decrease it.
	*/
	static void saturate_in_hsl_space(color_space::color_base& color, float percentage);

	//! Static function that increases or decreases the saturation of a given color.
	/*!
	* This function will convert the color to hsl and adjusts the saturation in this color space.
	* Afterwards the color will be converted back to input color space.
	* \param color The color to manipulate.
	* \param percentage The amount by which to adjust the saturation. Values between 0 and 1
	* increase the saturation and values between 0 and -1 decrease it.
	* \return The modified color in the same color space like the input color.
	*/
	static color_space::color_base* saturate_in_hsl_space(color_space::color_base* color, float percentage);
};

