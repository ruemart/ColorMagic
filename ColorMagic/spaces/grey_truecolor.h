/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>
#include <vector>

namespace color_space
{
	//! Color space to represents grey true colors.
		/*!
		* This class holds getters and setters for grey value, alpha and various constructors.
		*/
	class grey_truecolor : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets grey and alpha value.
		* \param value The value that will be set for grey value (default 0).
		* \param alpha The value that will be set for alpha (default 255).
		*/
		grey_truecolor(unsigned char value = ((unsigned char)0), unsigned char alpha = ((unsigned char)255));

		//! Default copy constructor.
		/*!
		* Constructs a grey color from a given one.
		* \param other The grey object to construct this color from.
		*/
		grey_truecolor(const grey_truecolor& other);

		//! Default copy constructor.
		/*!
		* Constructs a grey color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		grey_truecolor(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The grey_truecolor object to get the component values from.
		*/
		grey_truecolor& operator=(const grey_truecolor& other);

		//! Getter for grey component.
		//! \return The grey component of this color.
		unsigned char grey();

		//! Setter for grey component.
		//! \param new_grey The grey value to set.
		void grey(unsigned char new_grey);

		//! Getter for alpha component.
		//! \return The alpha component of this color.
		unsigned char alpha();

		//! Setter for alpha component.
		//! \param new_alpha The alpha value to set.
		void alpha(unsigned char new_alpha);

	private:

	};
}