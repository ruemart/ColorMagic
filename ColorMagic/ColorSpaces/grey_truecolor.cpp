#include "stdafx.h"
#include "grey_truecolor.h"

ColorSpaces::grey_truecolor::grey_truecolor() : m_grey(0), m_alpha(255) { }

ColorSpaces::grey_truecolor::grey_truecolor(unsigned char value) : m_grey(value), m_alpha(255) {}

ColorSpaces::grey_truecolor::grey_truecolor(unsigned char value, unsigned char alpha) : m_grey(value),  m_alpha(alpha) {}

ColorSpaces::grey_truecolor::grey_truecolor(const ColorSpaces::grey_truecolor & other) : m_grey(other.m_grey), m_alpha(other.m_alpha) { }

ColorSpaces::grey_truecolor & ColorSpaces::grey_truecolor::operator=(const ColorSpaces::grey_truecolor & other)
{
	if (this != &other)
	{
		m_grey = other.m_grey;
		m_alpha = other.m_alpha;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::grey_truecolor & lhs, const ColorSpaces::grey_truecolor & rhs)
{
	return (lhs.m_grey == rhs.m_grey && lhs.m_alpha == rhs.m_alpha);
}

bool ColorSpaces::operator!=(const ColorSpaces::grey_truecolor & lhs, const ColorSpaces::grey_truecolor & rhs)
{
	return !(lhs == rhs);
}