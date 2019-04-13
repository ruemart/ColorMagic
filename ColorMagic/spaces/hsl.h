/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once


#include "color_base.h"
#include <string>

namespace color_space
{
	class hsl : public color_base
	{
	public:
		hsl(float hue = 0.f, float saturation = 0.f, float lightness = 0.f);
		hsl(const hsl& other);
		hsl(const color_base& other);

		hsl& operator=(const hsl& other);
		hsl operator+(const hsl& rhs);
		
		float hue() const;
		void hue(float new_hue);
		float saturation() const;
		void saturation(float new_saturation);
		float lightness() const;
		void lightness(float new_lightness);

	protected:
		std::vector<float> convert_to_vector_format(const hsl& color);
		hsl convert_from_vector_format(const std::vector<float> color);

	private:
		float m_degrees_max = 359.f;
		float m_degrees_min = 0.f;
	};
}