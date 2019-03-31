#include "stdafx.h"
#include "hsl.h"

color_space::hsl::hsl(float hue, float saturation, float lightness) : icolor(3)
{
	this->hue(hue);
	this->saturation(saturation);
	this->lightness(lightness);
}

color_space::hsl::hsl(const color_space::hsl & other) : icolor(3, other.get_component_max(), other.get_component_min())
{
	this->m_component_vector = other.m_component_vector;
}

color_space::hsl & color_space::hsl::operator=(const color_space::hsl & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

float color_space::hsl::hue()
{
	return m_component_vector[0];
}

void color_space::hsl::hue(float new_hue)
{
	set_component((int)new_hue % 360, 0, m_degrees_max, m_degrees_min);
}

float color_space::hsl::saturation()
{
	return m_component_vector[1];
}

void color_space::hsl::saturation(float new_saturation)
{
	set_component(new_saturation, 1);
}

float color_space::hsl::lightness()
{
	return m_component_vector[2];
}

void color_space::hsl::lightness(float new_lightness)
{
	set_component(new_lightness, 2);
}