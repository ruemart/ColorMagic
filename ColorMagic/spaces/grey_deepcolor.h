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
	//! Color space to represents grey deep colors.
		/*!
		* This class holds getters and setters for grey value, alpha and various constructors.
		*/
	class grey_deepcolor : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets grey and alpha value.
		* \param value The value that will be set for grey value.
		* \param alpha The value that will be set for alpha.
		* \param ref_white The reference_white used for conversions from or to lab color space.
		*/
		grey_deepcolor(float value, float alpha, reference_white* ref_white);

		//! Default copy constructor.
		/*!
		* Constructs a grey color from a given one.
		* \param other The grey object to construct this color from.
		*/
		grey_deepcolor(const grey_deepcolor& other);

		//! Default copy constructor.
		/*!
		* Constructs a grey color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		grey_deepcolor(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The grey_deepcolor object to get the component values from.
		*/
		grey_deepcolor& operator=(const grey_deepcolor& other);
		
		//! Getter for grey component.
		//! \return The grey component of this color.
		float grey();

		//! Setter for grey component.
		//! \param new_grey The grey value to set.
		void grey(float new_grey);

	private:

	};
}