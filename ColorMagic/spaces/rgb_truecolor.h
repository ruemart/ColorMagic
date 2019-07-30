/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>
#include <regex>

namespace color_space
{
	//! Color space to represents rgb true colors.
		/*!
		* This class holds getters and setters for red, green and blue and various constructors.
		*/
	class rgb_truecolor : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets a uniform value for each component and an alpha value.
		* \param value The value that will be set for red, green and blue (default 0).
		* \param alpha The value that will be set for alpha (default 255).
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		rgb_truecolor(float value, float alpha, rgb_color_space_definition* color_space);

		//! Default constructor.
		/*!
		* Sets red, green, blue and alpha values.
		* \param r The value that will be set for red.
		* \param g The value that will be set for green.
		* \param b The value that will be set for blue.
		* \param a The value that will be set for alpha.
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		rgb_truecolor(float r, float g, float b, float a, rgb_color_space_definition* color_space);

		//! Default constructor.
		/*!
		* Creates a rgb color from a string hex code.
		* \param hex_code The hexcode to parse. Supported formats are #RRGGBB RRGGBB #AARRGGBB AARRGGBB.
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		rgb_truecolor(std::string hex_code, rgb_color_space_definition* color_space);

		//! Default constructor.
		/*!
		* Creates a rgb color from a integer hex value.
		* \param hex_code The hexcode to parse in the format 0xaarrggbb.
		* \param color_space The rgb color space definition used for conversion to or from xyz and lab.
		*/
		rgb_truecolor(int hex_code, rgb_color_space_definition* color_space);

		//! Default copy constructor.
		/*!
		* Constructs a rgb color from a given one.
		* \param other The rgb object to construct this color from.
		*/
		rgb_truecolor(const rgb_truecolor& other);

		//! Default copy constructor.
		/*!
		* Constructs a rgb color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		rgb_truecolor(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The rgb_truecolor object to get the component values from.
		*/
		rgb_truecolor& operator=(const rgb_truecolor& other);

		//! Getter for red component.
		//! \return The red component of this color.
		float red();

		//! Setter for red component.
		//! \param new_red The red value to set.
		void red(float new_red);

		//! Getter for green component.
		//! \return The green component of this color.
		float green();

		//! Setter for green component.
		//! \param new_green The green value to set.
		void green(float new_green);

		//! Getter for blue component.
		//! \return The blue component of this color.
		float blue();

		//! Setter for blue component.
		//! \param new_blue The blue value to set.
		void blue(float new_blue);

		//! Returns the currently set alpha.
		/*! Returns the currently set alpha.
		*/
		float alpha() const override;

		//! Sets a new alpha value (0-1).
		/*! Sets a new alpha value (0-1).
		*/
		void alpha(float new_alpha) override;

	private:

	};
}