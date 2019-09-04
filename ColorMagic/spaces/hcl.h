/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once


#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents hcl colors.
		/*!
		* This class holds getters and setters for hue, saturation, lightness and various constructors.
		*/
	class hcl : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param hue The value that will be set for hue component.
		* \param chroma The value that will be set for chroma component.
		* \param luma The value that will be set for luma component.
		* \param alpha The value that will be set for alpha.
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		hcl(float hue, float chroma, float luma, float alpha, rgb_color_space_definition* color_space);

		//! Default copy constructor.
		/*!
		* Constructs a hcl color from a given one.
		* \param other The hcl object to construct this color from.
		*/
		hcl(const hcl& other);

		//! Default copy constructor.
		/*!
		* Constructs a hcl color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		hcl(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The hcl object to get the component values from.
		*/
		hcl& operator=(const hcl& other);

		//! Getter for hue component.
		//! \return The hue component of this color.
		float hue() const;

		//! Setter for hue component.
		//! \param new_hue The hue value to set.
		void hue(float new_hue);

		//! Getter for chroma component.
		//! \return The chroma component of this color.
		float chroma() const;

		//! Setter for chroma component.
		//! \param new_chroma The chroma value to set.
		void chroma(float new_chroma);

		//! Getter for luma component.
		//! \return The luma component of this color.
		float luma() const;

		//! Setter for luma component.
		//! \param new_luma The luma value to set.
		void luma(float new_luma);

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