#pragma once

#include <string>

namespace ColorSpaces
{
	class cmyk
	{
	public:
		cmyk();
		cmyk(float value);
		cmyk(float cyan, float magenta, float yellow, float black);
		cmyk(const cmyk& other);

		color_type get_color_type() override { return color_type::CMYK; }

		cmyk& operator=(const cmyk& other);
		friend bool operator==(const cmyk& lhs, const cmyk& rhs);
		friend bool operator!=(const cmyk& lhs, const cmyk& rhs);

		float m_cyan;
		float m_magenta;
		float m_yellow;
		float m_black;

	private:

	};
}