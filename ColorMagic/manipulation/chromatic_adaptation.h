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
		color_space::color_base* von_kries_adaptation(color_space::color_base* color, color_space::rgb_color_space_definition* target_color_space);

		color_space::color_base* von_kries_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);
	protected:
		matrix<float>* m_von_kries = new matrix<float>(3, 3, std::vector<float> { 0.40024f, 0.7076f, -0.08081f, -0.2263f, 1.16532f, 0.0457f, 0.f, 0.f, 0.91822f });
		matrix<float>* m_inverted_von_kries = new matrix<float>(3, 3, std::vector<float> { 1.8599364f, -1.1293816f, 0.2198974f,	0.3611914f, 0.6388125f, -0.0000064f, 0.f, 0.f, 1.0890636f });
	};
}