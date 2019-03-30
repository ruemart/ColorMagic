#include "stdafx.h"
#include "hsv.h"

color_space::hsv::hsv(float hue, float saturation, float value) : icolor(3)
{
	this->hue(hue);
	this->saturation(saturation);
	this->value(value);
}

color_space::hsv::hsv(const color_space::hsv & other) : icolor(3, other.get_component_max(), other.get_component_min())
{
	this->m_component_vector = other.m_component_vector;
}

color_space::hsv & color_space::hsv::operator=(const color_space::hsv & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

float color_space::hsv::hue()
{
	return m_component_vector[0];
}

void color_space::hsv::hue(float new_hue)
{
	set_component(new_hue, 0, m_degrees_max, m_degrees_min);
}

float color_space::hsv::saturation()
{
	return m_component_vector[1];
}

void color_space::hsv::saturation(float new_saturation)
{
	set_component(new_saturation, 1);
}

float color_space::hsv::value()
{
	return m_component_vector[2];
}

void color_space::hsv::value(float new_value)
{
	set_component(new_value, 2);
}