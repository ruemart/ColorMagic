#include "stdafx.h"
#include "xyz.h"

ColorSpaces::xyz::xyz() : m_x(0), m_y(0.0f), m_z(0.0f) { }

ColorSpaces::xyz::xyz(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}

ColorSpaces::xyz::xyz(const xyz & other) : m_x(other.m_x), m_y(other.m_y), m_z(other.m_z) { }

ColorSpaces::xyz & ColorSpaces::xyz::operator=(const ColorSpaces::xyz & other)
{
	if (this != &other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
		m_z = other.m_z;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::xyz & lhs, const ColorSpaces::xyz & rhs)
{
	return (lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y && lhs.m_z == rhs.m_z);
}

bool ColorSpaces::operator!=(const ColorSpaces::xyz & lhs, const ColorSpaces::xyz & rhs)
{
	return !(lhs == rhs);
}