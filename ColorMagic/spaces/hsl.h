/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once


#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents hsl colors.
		/*!
		* This class holds getters and setters for hue, saturation, lightness and various constructors.
		*/
	class hsl : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param hue The value that will be set for hue component (default 0).
		* \param saturation The value that will be set for saturation component (default 0).
		* \param lightness The value that will be set for lightness component (default 0).
		*/
		hsl(float hue = 0.f, float saturation = 0.f, float lightness = 0.f);

		//! Default copy constructor.
		/*!
		* Constructs a hsl color from a given one.
		* \param other The hsl object to construct this color from.
		*/
		hsl(const hsl& other);

		//! Default copy constructor.
		/*!
		* Constructs a hsl color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		hsl(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The hsl object to get the component values from.
		*/
		hsl& operator=(const hsl& other);
		
		//! Getter for hue component.
		//! \return The hue component of this color.
		float hue() const;

		//! Setter for hue component.
		//! \param new_hue The hue value to set.
		void hue(float new_hue);

		//! Getter for saturation component.
		//! \return The saturation component of this color.
		float saturation() const;

		//! Setter for saturation component.
		//! \param new_saturation The saturation value to set.
		void saturation(float new_saturation);

		//! Getter for lightness component.
		//! \return The lightness component of this color.
		float lightness() const;

		//! Setter for lightness component.
		//! \param new_lightness The lightness value to set.
		void lightness(float new_lightness);

	private:
		//! Specific maximum for hue component.
		/*!
		* Specific maximum for hue component.
		*/
		float m_degrees_max = 359.f;

		//! Specific minimum for hue component.
		/*!
		* Specific minimum for hue component.
		*/
		float m_degrees_min = 0.f;
	};
}