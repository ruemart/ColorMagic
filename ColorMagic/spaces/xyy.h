/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents xyY colors.
	/*!
	* This class holds getters and setters for x, y, Y and various constructors.
	*/
	class xyy : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param x The value that will be set for x component.
		* \param y The value that will be set for y component.
		* \param Y The value that will be set for Y component.
		* \param alpha The value that will be set for alpha (default 1).
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		xyy(float x, float y, float Y, float alpha, rgb_color_space_definition* color_space);

		//! Default copy constructor.
		/*!
		* Constructs a xyY color from a given one.
		* \param other The xyY object to construct this color from.
		*/
		xyy(const xyy& other);

		//! Default copy constructor.
		/*!
		* Constructs a xyY color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		xyy(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The xyY object to get the component values from.
		*/
		xyy& operator=(const xyy& other);

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

		//! Getter for Y component.
		//! \return The Y component of this color.
		float Y();

		//! Setter for Y component.
		//! \param new_Y The Y value to set.
		void Y(float new_Y);

	private:

	};
}