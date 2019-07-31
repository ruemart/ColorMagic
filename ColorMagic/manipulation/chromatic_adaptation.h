/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "..\spaces\color_base.h"
#include "color_converter.h"
#include "..\utils\matrix.h"

namespace color_manipulation
{
	//! Static class for chromatic adaptation.
	/*!
	* This static class implements von Kries, Bradford and XYZ Scaling as chromatic adaptation methods.
	*/
	class color_adjustments
	{
	public:
		//! Transforms a given color to the given target color space definition by using von Kies method.
		/*!
		* Transforms a given color to the given target color space definition. The color will first be converted to xyz space.
		* Afterwards the transformation is done using von Kies matrices and finally the result is converted back to input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_color_space The target color space definition containing the target white point definition.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* von_kries_adaptation(color_space::color_base* color, color_space::rgb_color_space_definition* target_color_space);

		//! Transforms a given color with the given target white point by using von Kies method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using von Kies matrices and finally the result is converted back to 
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* von_kries_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);
	protected:

		//! Helper method that calculates the transformation matrix.
		/*!
		* Helper method that calculates the transformation matrix.
		* \param source_wp The input colors white point.
		* \param dest_wp The target white point.
		* \param mat The adaptation matrix of the chosen method.
		* \param inverted_mat The inverted adaptation matrix of the chosen method.
		* \return The calculated transformation matrix for the chosen method.
		*/
		matrix<float> calculate_transform_matrix(color_space::white_point* source_wp, color_space::white_point* dest_wp, matrix<float> mat, matrix<float> inverted_mat);

		//! Adaptation matrix of the von Kries method.
		/*!
		* Adaptation matrix of the von Kries method.
		*/
		matrix<float> m_von_kries = matrix<float>(3, 3, std::vector<float> 
		{
			0.40024f, 0.7076f, -0.08081f, 
			-0.2263f, 1.16532f, 0.0457f, 
			0.f, 0.f, 0.91822f
		});

		//! Inverted adaptation matrix of the von Kries method.
		/*!
		* Inverted adaptation matrix of the von Kries method.
		*/
		matrix<float> m_inverted_von_kries = matrix<float>(3, 3, std::vector<float> 
		{
			1.8599364f, -1.1293816f, 0.2198974f,
			0.3611914f, 0.6388125f, -0.0000064f,
			0.f, 0.f, 1.0890636f 
		});
	};
}