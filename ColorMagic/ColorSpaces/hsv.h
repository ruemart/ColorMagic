#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class hsv : public icolor
	{
	public:
		hsv();
		hsv(float hue, float saturation, float value);
		hsv(const hsv& other);

		color_type get_color_type() override { return color_type::HSV; }

		hsv& operator=(const hsv& other);
		friend bool operator==(const hsv& lhs, const hsv& rhs);
		friend bool operator!=(const hsv& lhs, const hsv& rhs);

		float m_hue;
		float m_saturation;
		float m_value;

	private:

	};
}