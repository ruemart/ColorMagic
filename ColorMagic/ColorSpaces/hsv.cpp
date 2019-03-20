#include "stdafx.h"
#include "hsv.h"

ColorSpaces::hsv::hsv() : m_hue(0.0f), m_saturation(0.0f), m_value(0.0f) { }

ColorSpaces::hsv::hsv(float hue, float saturation, float value) : m_hue(hue), m_saturation(saturation), m_value(value) {}

ColorSpaces::hsv::hsv(const ColorSpaces::hsv & other) : m_hue(other.m_hue), m_saturation(other.m_saturation), m_value(other.m_value) { }

ColorSpaces::hsv & ColorSpaces::hsv::operator=(const ColorSpaces::hsv & other)
{
	if (this != &other)
	{
		m_hue = other.m_hue;
		m_saturation = other.m_saturation;
		m_value = other.m_value;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::hsv & lhs, const ColorSpaces::hsv & rhs)
{
	return (lhs.m_hue == rhs.m_hue && lhs.m_saturation == rhs.m_saturation && lhs.m_value == rhs.m_value);
}

bool ColorSpaces::operator!=(const ColorSpaces::hsv & lhs, const ColorSpaces::hsv & rhs)
{
	return !(lhs == rhs);
}