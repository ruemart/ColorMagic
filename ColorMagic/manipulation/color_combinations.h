#pragma once

#include "..\spaces\color_base.h"
#include "color_converter.h"
#include <vector>

namespace color_manipulation
{
	//! Static class for creating color combinations.
		/*!
		* This static class implements various functions that create sets of colors.
		*/
	class color_combinations
	{
	public:
		//! Static function that returns the opposite of the given color.
		/*!
		* This function converts the given color to hsl space and adds 180 degress to its hue. 
		* Afterwards it converts the new color back to input color space.
		* \param color The color to create the opposite of.
		* \return The complimentary color.
		*/
		static color_space::color_base* get_complimentary_color(color_space::color_base* color);

		//! Static function that returns a color triplet.
		/*!
		* This function converts the given color to hsl space and adds two times 120 degrees to its hue.
		* Afterwards it converts the new colors back to input color space.
		* \param color The base color for the triplet.
		* \return A vector containing all three colors. The input color is at index 0.
		*/
		static std::vector<color_space::color_base*> create_triplet(color_space::color_base* color);
	};
}