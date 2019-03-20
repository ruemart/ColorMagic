#include "stdafx.h"
#include "rgb_deepcolor.h"

ColorSpaces::rgb_deepcolor::rgb_deepcolor() : m_red(0.0f), m_green(0.0f), m_blue(0.0f), m_alpha(1.0f) { }

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float value) : m_red(value), m_green(value), m_blue(value), m_alpha(1.0f) {}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float value, float alpha) : m_red(value), m_green(value), m_blue(value), m_alpha(alpha) {}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float r, float g, float b) : m_red(r), m_green(g), m_blue(b), m_alpha(1.0f) {}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float r, float g, float b, float a) : m_red(r), m_green(g), m_blue(b), m_alpha(a) {}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(const ColorSpaces::rgb_deepcolor & other) : m_red(other.m_red), m_green(other.m_green), m_blue(other.m_blue), m_alpha(other.m_alpha) { }

ColorSpaces::rgb_deepcolor & ColorSpaces::rgb_deepcolor::operator=(const ColorSpaces::rgb_deepcolor & other)
{
	if (this != &other)
	{
		m_red = other.m_red;
		m_green = other.m_green;
		m_blue = other.m_blue;
		m_alpha = other.m_alpha;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::rgb_deepcolor & lhs, const ColorSpaces::rgb_deepcolor & rhs)
{
	return (lhs.m_red == rhs.m_red && lhs.m_green == rhs.m_green && lhs.m_blue == rhs.m_blue && lhs.m_alpha == rhs.m_alpha);
}

bool ColorSpaces::operator!=(const ColorSpaces::rgb_deepcolor & lhs, const ColorSpaces::rgb_deepcolor & rhs)
{
	return !(lhs == rhs);
}