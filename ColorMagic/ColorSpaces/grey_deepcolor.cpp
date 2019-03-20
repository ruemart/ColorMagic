#include "stdafx.h"
#include "grey_deepcolor.h"

ColorSpaces::grey_deepcolor::grey_deepcolor() : m_grey(0.0f), m_alpha(1.0f) { }

ColorSpaces::grey_deepcolor::grey_deepcolor(float value) : m_grey(value), m_alpha(1.0f) {}

ColorSpaces::grey_deepcolor::grey_deepcolor(float value, float alpha) : m_grey(value), m_alpha(alpha) {}

ColorSpaces::grey_deepcolor::grey_deepcolor(const ColorSpaces::grey_deepcolor & other) : m_grey(other.m_grey), m_alpha(other.m_alpha) { }

ColorSpaces::grey_deepcolor & ColorSpaces::grey_deepcolor::operator=(const ColorSpaces::grey_deepcolor & other)
{
	if (this != &other)
	{
		m_grey = other.m_grey;
		m_alpha = other.m_alpha;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::grey_deepcolor & lhs, const ColorSpaces::grey_deepcolor & rhs)
{
	return (lhs.m_grey == rhs.m_grey && lhs.m_alpha == rhs.m_alpha);
}

bool ColorSpaces::operator!=(const ColorSpaces::grey_deepcolor & lhs, const ColorSpaces::grey_deepcolor & rhs)
{
	return !(lhs == rhs);
}