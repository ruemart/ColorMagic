#include "stdafx.h"
#include "hsv.h"

color_space::hsv::hsv(float hue, float saturation, float value) : icolor(3)
{
	this->hue(hue);
	this->saturation(saturation);
	this->value(value);
}

color_space::hsv::hsv(const color_space::hsv & other) : icolor(3)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::hsv & color_space::hsv::operator=(const color_space::hsv & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::hsv::hue()
{
	return m_component_vector[0];
}

void color_space::hsv::hue(float new_hue)
{
	m_component_vector[0] = new_hue;
}

float color_space::hsv::saturation()
{
	return m_component_vector[1];
}

void color_space::hsv::saturation(float new_saturation)
{
	m_component_vector[1] = new_saturation;
}

float color_space::hsv::value()
{
	return m_component_vector[2];
}

void color_space::hsv::value(float new_value)
{
	m_component_vector[2] = new_value;
}