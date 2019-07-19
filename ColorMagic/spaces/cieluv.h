/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents cieluv colors.
	/*!
	* This class holds getters and setters for cyan, magenta, yellow, black and various constructors.
	*/
	class cieluv : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param L The value that will be set for L component.
		* \param u The value that will be set for u component.
		* \param v The value that will be set for v component.
		* \param alpha The alpha value for this color.
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		cieluv(float L, float u, float v, float alpha, rgb_color_space_definition* color_space);

		//! Default copy constructor.
		/*!
		* Constructs a cieluv color from a given one.
		* \param other The cieluv object to construct this color from.
		*/
		cieluv(const cieluv& other);

		//! Default copy constructor.
		/*!
		* Constructs a cieluv color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		cieluv(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The cieluv object to get the component values from.
		*/
		cieluv& operator=(const cieluv& other);

		//! Getter for L component.
		//! \return The L component of this color.
		float L() const;

		//! Setter for L component.
		//! \param new_L The L value to set.
		void L(float new_L);

		//! Getter for u component.
		//! \return The u component of this color.
		float u() const;

		//! Setter for u component.
		//! \param new_u The u value to set.
		void u(float new_u);

		//! Getter for v component.
		//! \return The v component of this color.
		float v() const;

		//! Setter for v component.
		//! \param new_v The v value to set.
		void v(float new_v);

	private:

	};
}
