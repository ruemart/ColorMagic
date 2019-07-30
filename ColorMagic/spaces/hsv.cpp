#include "stdafx.h"
#include "hsv.h"

color_space::hsv::hsv(float hue, float saturation, float value, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3)
{
	this->m_type = color_type::HSV;
	this->hue(hue);
	this->saturation(saturation);
	this->value(value);
}

color_space::hsv::hsv(const color_space::hsv & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::hsv::hsv(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::HSV && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::HSV;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("HSV: Error while creating hsv class from base object. Base object and this derived class have different types.");
	}
}

color_space::hsv & color_space::hsv::operator=(const color_space::hsv & other)
{
	if (this != &other)
	{
		this->m_type = other.get_color_type();
		this->m_component_vector = other.get_component_vector();
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
	new_hue = fmod(new_hue, 360.f);
	while (new_hue < 0.f)
	{
		new_hue += 360.0f;
	}

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