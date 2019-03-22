#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class lab : public icolor
	{
	public:
		lab();
		lab(float luminance, float a, float b);
		lab(const lab& other);

		color_type get_color_type() override { return color_type::LAB; }

		lab& operator=(const lab& other);
		friend bool operator==(const lab& lhs, const lab& rhs);
		friend bool operator!=(const lab& lhs, const lab& rhs);

		float m_luminance;
		float m_a; // green red
		float m_b; // yellow blue

	private:

	};
}