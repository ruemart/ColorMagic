#include "stdafx.h"
#include "hsl.h"

color_space::hsl::hsl(float hue, float saturation, float lightness) : icolor(3)
{
	this->hue(hue);
	this->saturation(saturation);
	this->lightness(lightness);
}

color_space::hsl::hsl(const color_space::hsl & other) : icolor(3)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::hsl & color_space::hsl::operator=(const color_space::hsl & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::hsl::hue()
{
	return m_component_vector[0];
}

void color_space::hsl::hue(float new_hue)
{
	m_component_vector[0] = new_hue;
}

float color_space::hsl::saturation()
{
	return m_component_vector[1];
}

void color_space::hsl::saturation(float new_saturation)
{
	m_component_vector[1] = new_saturation;
}

float color_space::hsl::lightness()
{
	return m_component_vector[2];
}

void color_space::hsl::lightness(float new_lightness)
{
	m_component_vector[2] = new_lightness;
}