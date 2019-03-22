#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class hsl : public icolor
	{
	public:
		hsl();
		hsl(float hue, float saturation, float value);
		hsl(const hsl& other);

		color_type get_color_type() override { return color_type::HSL; }

		hsl& operator=(const hsl& other);
		friend bool operator==(const hsl& lhs, const hsl& rhs);
		friend bool operator!=(const hsl& lhs, const hsl& rhs);

		float m_hue;
		float m_saturation;
		float m_lightness;

	private:

	};
}