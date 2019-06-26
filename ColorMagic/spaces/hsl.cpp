#include "stdafx.h"
#include "hsl.h"

color_space::hsl::hsl(float hue, float saturation, float lightness, reference_white* ref_white) : color_base(ref_white, 3)
{
	this->m_type = color_type::HSL;
	this->hue(hue);
	this->saturation(saturation);
	this->lightness(lightness);
}

color_space::hsl::hsl(const color_space::hsl & other) : color_base(other.m_reference_white, 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.m_component_vector;
}

color_space::hsl::hsl(const color_base & other) : color_base(other.m_reference_white, 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::HSL && other.m_component_vector.size() == 3)
	{
		this->m_type = color_type::HSL;
		this->m_component_vector = other.m_component_vector;
	}
	else
	{
		throw new std::invalid_argument("HSL: Error while creating hsl class from base object. Base object and this derived class have different types.");
	}
}

color_space::hsl & color_space::hsl::operator=(const color_space::hsl & other)
{
	if (this != &other)
	{
		this->m_type = other.get_color_type();
		this->m_component_vector = other.m_component_vector;
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

float color_space::hsl::hue() const
{
	return m_component_vector[0];
}

void color_space::hsl::hue(float new_hue)
{
	new_hue = fmod(new_hue, 360.f);
	while (new_hue < 0.f) 
	{ 
		new_hue += 360.0f;
	}

	set_component(new_hue, 0, m_degrees_max, m_degrees_min);
}

float color_space::hsl::saturation() const
{
	return m_component_vector[1];
}

void color_space::hsl::saturation(float new_saturation)
{
	set_component(new_saturation, 1);
}

float color_space::hsl::lightness() const
{
	return m_component_vector[2];
}

void color_space::hsl::lightness(float new_lightness)
{
	set_component(new_lightness, 2);
}