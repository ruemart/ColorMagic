/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents lab colors.
		/*!
		* This class holds getters and setters for luminance, a, b and various constructors.
		*/
	class lab : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param l The value that will be set for luminance component (default 0).
		* \param a The value that will be set for a component (default 0).
		* \param b The value that will be set for b component (default 0).
		* \param ref_white The reference_white used for conversions from or to lab color space.
		*/
		lab(float luminance, float a, float b, reference_white* ref_white);

		//! Default copy constructor.
		/*!
		* Constructs a lab color from a given one.
		* \param other The lab object to construct this color from.
		*/
		lab(const lab& other);

		//! Default copy constructor.
		/*!
		* Constructs a lab color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		lab(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The lab object to get the component values from.
		*/
		lab& operator=(const lab& other);

		//! Getter for luminance component.
		//! \return The luminance component of this color.
		float luminance();

		//! Setter for x component.
		//! \param new_luminance The luminance value to set.
		void luminance(float new_luminance);

		//! Getter for a component.
		//! \return The a component of this color.
		float a(); // green red

		//! Setter for a component.
		//! \param new_a The a value to set.
		void a(float new_a);

		//! Getter for b component.
		//! \return The b component of this color.
		float b(); // yellow blue

		//! Setter for b component.
		//! \param new_b The a value to set.
		void b(float new_b);

	private:
		float m_lightness_max = 100.f;
		float m_lightness_min = 0.f;
	};
}