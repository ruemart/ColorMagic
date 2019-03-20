#include "stdafx.h"
#include "lab.h"

ColorSpaces::lab::lab() : m_luminance(0), m_a(0.0f), m_b(0.0f) { }

ColorSpaces::lab::lab(float luminance, float a, float b) : m_luminance(luminance), m_a(a), m_b(b) {}

ColorSpaces::lab::lab(const ColorSpaces::lab & other) : m_luminance(other.m_luminance), m_a(other.m_a), m_b(other.m_b) { }

ColorSpaces::lab & ColorSpaces::lab::operator=(const ColorSpaces::lab & other)
{
	if (this != &other)
	{
		m_luminance = other.m_luminance;
		m_a = other.m_a;
		m_b = other.m_b;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::lab & lhs, const ColorSpaces::lab & rhs)
{
	return (lhs.m_luminance == rhs.m_luminance && lhs.m_a == rhs.m_a && lhs.m_b == rhs.m_b);
}

bool ColorSpaces::operator!=(const ColorSpaces::lab & lhs, const ColorSpaces::lab & rhs)
{
	return !(lhs == rhs);
}