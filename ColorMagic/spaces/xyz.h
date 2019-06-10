/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents xyz colors.
		/*!
		* This class holds getters and setters for x, y, z and various constructors.
		*/
	class xyz : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param x The value that will be set for x component.
		* \param y The value that will be set for y component.
		* \param z The value that will be set for z component.
		* \param ref_white The reference_white used for conversions from or to lab color space.
		*/
		xyz(float x, float y, float z, reference_white* ref_white);

		//! Default copy constructor.
		/*!
		* Constructs a xyz color from a given one.
		* \param other The xyz object to construct this color from.
		*/
		xyz(const xyz& other);

		//! Default copy constructor.
		/*!
		* Constructs a hsl color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		xyz(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The xyz object to get the component values from.
		*/
		xyz& operator=(const xyz& other);

		//! Getter for x component.
		//! \return The x component of this color.
		float x();
		
		//! Setter for x component.
		//! \param new_x The x value to set.
		void x(float new_x);

		//! Getter for y component.
		//! \return The y component of this color.
		float y();

		//! Setter for y component.
		//! \param new_y The y value to set.
		void y(float new_y);

		//! Getter for z component.
		//! \return The z component of this color.
		float z();

		//! Setter for z component.
		//! \param new_z The z value to set.
		void z(float new_z);

	private:

	};
}
