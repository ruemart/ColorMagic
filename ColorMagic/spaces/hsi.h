/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once


#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents hsi colors.
		/*!
		* This class holds getters and setters for hue, saturation, lightness and various constructors.
		*/
	class hsi : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param hue The value that will be set for hue component.
		* \param saturation The value that will be set for saturation component.
		* \param intensity The value that will be set for intensity component.
		* \param alpha The value that will be set for alpha.
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		hsi(float hue, float saturation, float intensity, float alpha, rgb_color_space_definition* color_space);

		//! Default copy constructor.
		/*!
		* Constructs a hsi color from a given one.
		* \param other The hsi object to construct this color from.
		*/
		hsi(const hsi& other);

		//! Default copy constructor.
		/*!
		* Constructs a hsi color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		hsi(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The hsi object to get the component values from.
		*/
		hsi& operator=(const hsi& other);

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
		float intensity() const;

		//! Setter for intensity component.
		//! \param new_intensity The intensity value to set.
		void intensity(float new_intensity);

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