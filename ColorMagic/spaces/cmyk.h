/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	//! Color space to represents cmyk colors.
		/*!
		* This class holds getters and setters for cyan, magenta, yellow, black and various constructors.
		*/
	class cmyk : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets the value of each component.
		* \param cyan The value that will be set for cyan component.
		* \param magenta The value that will be set for magenta component.
		* \param yellow The value that will be set for yellow component.
		* \param black The value that will be set for black component.
		* \param black The alpha value for this color.
		* \param ref_white The reference_white used for conversions from or to lab color space.
		*/
		cmyk(float cyan, float magenta, float yellow, float black, float alpha, reference_white* ref_white);

		//! Default copy constructor.
		/*!
		* Constructs a cmyk color from a given one.
		* \param other The cmyk object to construct this color from.
		*/
		cmyk(const cmyk& other);

		//! Default copy constructor.
		/*!
		* Constructs a cmyk color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		cmyk(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The cmyk object to get the component values from.
		*/
		cmyk& operator=(const cmyk& other);

		//! Getter for cyan component.
		//! \return The cyan component of this color.
		float cyan() const;

		//! Setter for cyan component.
		//! \param new_cyan The cyan value to set.
		void cyan(float new_cyan);

		//! Getter for magenta component.
		//! \return The magenta component of this color.
		float magenta() const;

		//! Setter for magenta component.
		//! \param new_magenta The magenta value to set.
		void magenta(float new_magenta);

		//! Getter for yellow component.
		//! \return The yellow component of this color.
		float yellow() const;

		//! Setter for yellow component.
		//! \param new_yellow The yellow value to set.
		void yellow(float new_yellow);

		//! Getter for black component.
		//! \return The black component of this color.
		float black() const;

		//! Setter for black component.
		//! \param new_black The black value to set.
		void black(float new_black);

	private:

	};
}