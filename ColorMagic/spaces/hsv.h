/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents hsv colors.
		/*!
		* This class holds getters and setters for hue, saturation, value and various constructors.
		*/
	class hsv : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param hue The value that will be set for hue component (default 0).
		* \param saturation The value that will be set for saturation component (default 0).
		* \param value The value that will be set for value component (default 0).
		*/
		hsv(float hue = 0.f, float saturation = 0.f, float value = 0.f);

		//! Default copy constructor.
		/*!
		* Constructs a hsv color from a given one.
		* \param other The hsv object to construct this color from.
		*/
		hsv(const hsv& other);

		//! Default copy constructor.
		/*!
		* Constructs a hsv color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		hsv(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The hsv object to get the component values from.
		*/
		hsv& operator=(const hsv& other);

		//! Getter for hue component.
		//! \return The hue component of this color.
		float hue();

		//! Setter for hue component.
		//! \param hue The hue value to set.
		void hue(float hue);

		//! Getter for saturation component.
		//! \return The saturation component of this color.
		float saturation();

		//! Setter for saturation component.
		//! \param saturation The saturation value to set.
		void saturation(float saturation);

		//! Getter for value component.
		//! \return The value component of this color.
		float value();

		//! Setter for value component.
		//! \param value The value value to set.
		void value(float value);

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