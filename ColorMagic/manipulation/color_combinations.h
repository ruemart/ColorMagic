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

		//! Static function that returns a color quartet.
		/*!
		* This function converts the given color to hsl space and adds three times 90 degrees to its hue.
		* Afterwards it converts the new colors back to input color space.
		* \param color The base color for the triplet.
		* \return A vector containing all four colors. The input color is at index 0.
		*/
		static std::vector<color_space::color_base*> create_quartet(color_space::color_base* color);

		//! Static function that returns a color quintet.
		/*!
		* This function converts the given color to hsl space and adds four times 72 degrees to its hue.
		* Afterwards it converts the new colors back to input color space.
		* \param color The base color for the triplet.
		* \return A vector containing all five colors. The input color is at index 0.
		*/
		static std::vector<color_space::color_base*> create_quintet(color_space::color_base* color);

		//! Static function that returns a arbitrary color combination.
		/*!
		* This function converts the given color to hsl space and adds n times 360/n degrees to its hue.
		* Afterwards it converts the new colors back to input color space.
		* \param color The base color for the triplet.
		* \param number_of_elements The number of colors in the combination to create.
		* \return A vector containing all colors. The input color is at index 0.
		*/
		static std::vector<color_space::color_base*> create_combination(color_space::color_base* color, int number_of_elements);

		//! Static function that returns an analogous color triplet.
		/*!
		* This function converts the given color to hsl space and calculates two analogous colors.
		* Afterwards it converts the new colors back to input color space.
		* \param color The base color for the triplet.
		* \param distance_between The hue distance in degrees between the three analogous colors.
		* \return A vector containing all five colors. The input color is at index 0.
		*/
		static std::vector<color_space::color_base*> create_analogous(color_space::color_base* base_color, float distance_between);
	};
}