/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// (See accompanying file LICENSE.txt

#pragma once

//! Enum that defines the color space a color is located in.
enum color_type
{
	RGB_TRUE = 0, /*!< RGB_TRUE - for rgb true color spaces */  
	RGB_DEEP, /*!< RGB_DEEP - for rgb deep color spaces */  
	GREY_TRUE, /*!< GREY_TRUE - for grey true color spaces */  
	GREY_DEEP, /*!< GREY_DEEP - for grey deep color spaces */  
	CMYK, /*!< CMYK - for cmyk color spaces */  
	HSV, /*!< HSV - for hsv color spaces */  
	HSL, /*!< HSL - for hsl color spaces */  
	XYZ, /*!< XYZ - for xyz color spaces */  
	XYY, /*!< XYY - for xyY color spaces */
	CIELUV, /*!< CIELUV - for cieluv color spaces */
	LAB, /*!< LAB - for lab color spaces */ 
	LCH_AB, /*!< LCH_AB - for LAB colors in polar coordinate space */
	LCH_UV, /*!< LCH_UV - for LUV colors in polar coordinate space */
	UNDEFINED /*!< UNDEFINED - Default value of color_base objects */  
};