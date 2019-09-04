#include "stdafx.h"
#include "hsi.h"

color_space::hsi::hsi(float hue, float saturation, float intensity, float alpha, rgb_color_space_definition * color_space) : color_base(alpha, color_space, 3)
{
	this->m_type = color_type::HSL;
	this->hue(hue);
	this->saturation(saturation);
	this->intensity(intensity);
}

color_space::hsi::hsi(const color_space::hsi & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::hsi::hsi(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::HSI && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::HSI;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("HSI: Error while creating hsi class from base object. Base object and this derived class have different types.");
	}
}

color_space::hsi & color_space::hsi::operator=(const color_space::hsi & other)
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

float color_space::hsi::hue() const
{
	return m_component_vector[0];
}

void color_space::hsi::hue(float new_hue)
{
	new_hue = fmod(new_hue, 360.f);
	while (new_hue < 0.f)
	{
		new_hue += 360.0f;
	}

	set_component(new_hue, 0, m_degrees_max, m_degrees_min);
}

float color_space::hsi::saturation() const
{
	return m_component_vector[1];
}

void color_space::hsi::saturation(float new_saturation)
{
	set_component(new_saturation, 1);
}

float color_space::hsi::intensity() const
{
	return m_component_vector[2];
}

void color_space::hsi::intensity(float new_intensity)
{
	set_component(new_intensity, 2);
}
