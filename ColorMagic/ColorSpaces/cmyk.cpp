#include "stdafx.h"
#include "cmyk.h"

ColorSpaces::cmyk::cmyk() : m_cyan(0.0f), m_magenta(0.0f), m_yellow(0.0f), m_black(0.0f) { }

ColorSpaces::cmyk::cmyk(float value) : m_cyan(value), m_magenta(value), m_yellow(value), m_black(value) {}

ColorSpaces::cmyk::cmyk(float cyan, float magenta, float yellow, float black) : m_cyan(cyan), m_magenta(magenta), m_yellow(yellow), m_black(black) {}

ColorSpaces::cmyk::cmyk(const ColorSpaces::cmyk & other) : m_cyan(other.m_cyan), m_magenta(other.m_magenta), m_yellow(other.m_yellow), m_black(other.m_black) { }

ColorSpaces::cmyk & ColorSpaces::cmyk::operator=(const cmyk & other)
{
	if (this != &other)
	{
		m_cyan = other.m_cyan;
		m_magenta = other.m_magenta;
		m_yellow = other.m_yellow;
		m_black = other.m_black;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::cmyk & lhs, const ColorSpaces::cmyk & rhs)
{
	return (lhs.m_cyan == rhs.m_cyan && lhs.m_magenta == rhs.m_magenta && lhs.m_yellow == rhs.m_yellow && lhs.m_black == rhs.m_black);
}

bool ColorSpaces::operator!=(const ColorSpaces::cmyk & lhs, const ColorSpaces::cmyk & rhs)
{
	return !(lhs == rhs);
}