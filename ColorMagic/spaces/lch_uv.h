/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents lch(uv) colors.
	/*!
	* This class holds getters and setters for luminance, chroma, hue and various constructors.
	*/
	class lch_uv : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param luminance The value that will be set for luminance component (default 0).
		* \param chroma The value that will be set for chroma component (default 0).
		* \param hue The value that will be set for hue component (default 0).
		* \param alpha The value that will be set for alpha.
		* \param color_space The rgb color space definition used for conversions.
		*/
		lch_uv(float luminance, float chroma, float hue, float alpha, rgb_color_space_definition* color_space);

		//! Default copy constructor.
		/*!
		* Constructs a lch(uv) color from a given one.
		* \param other The lch(uv) object to construct this color from.
		*/
		lch_uv(const lch_uv& other);

		//! Default copy constructor.
		/*!
		* Constructs a lch(uv) color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		lch_uv(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The lch(uv) object to get the component values from.
		*/
		lch_uv& operator=(const lch_uv& other);

		//! Getter for luminance component.
		//! \return The luminance component of this color.
		float luminance();

		//! Setter for luminance component.
		//! \param new_luminance The luminance value to set.
		void luminance(float new_luminance);

		//! Getter for chroma component.
		//! \return The chroma component of this color.
		float chroma();

		//! Setter for chroma component.
		//! \param new_chroma The a value to set.
		void chroma(float new_chroma);

		//! Getter for hue component.
		//! \return The hue component of this color.
		float hue();

		//! Setter for hue component.
		//! \param new_hue The hue value to set.
		void hue(float new_hue);

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