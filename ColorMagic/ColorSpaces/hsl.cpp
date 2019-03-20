#include "stdafx.h"
#include "hsl.h"

ColorSpaces::hsl::hsl() : m_hue(0.0f), m_saturation(0.0f), m_lightness(0.0f) { }

ColorSpaces::hsl::hsl(float hue, float saturation, float value) : m_hue(hue), m_saturation(saturation), m_lightness(value) {}

ColorSpaces::hsl::hsl(const ColorSpaces::hsl & other) : m_hue(other.m_hue), m_saturation(other.m_saturation), m_lightness(other.m_lightness) { }

ColorSpaces::hsl & ColorSpaces::hsl::operator=(const ColorSpaces::hsl & other)
{
	if (this != &other)
	{
		m_hue = other.m_hue;
		m_saturation = other.m_saturation;
		m_lightness = other.m_lightness;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::hsl & lhs, const ColorSpaces::hsl & rhs)
{
	return (lhs.m_hue == rhs.m_hue && lhs.m_saturation == rhs.m_saturation && lhs.m_lightness == rhs.m_lightness);
}

bool ColorSpaces::operator!=(const ColorSpaces::hsl & lhs, const ColorSpaces::hsl & rhs)
{
	return !(lhs == rhs);
}