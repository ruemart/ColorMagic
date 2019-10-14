#include "stdafx.h"
#include "hcy.h"

color_space::hcy::hcy(float hue, float chroma, float luma, float alpha, rgb_color_space_definition * color_space) : color_base(alpha, color_space, 3)
{
	this->m_type = color_type::HCY;
	this->hue(hue);
	this->chroma(chroma);
	this->luma(luma);
}

color_space::hcy::hcy(const color_space::hcy & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::hcy::hcy(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::HCY && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::HCY;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("HCL: Error while creating hcy class from base object. Base object and this derived class have different types.");
	}
}

color_space::hcy & color_space::hcy::operator=(const color_space::hcy & other)
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

float color_space::hcy::hue() const
{
	return m_component_vector[0];
}

void color_space::hcy::hue(float new_hue)
{
	new_hue = fmod(new_hue, 360.f);
	while (new_hue < 0.f)
	{
		new_hue += 360.0f;
	}

	set_component(new_hue, 0, m_degrees_max, m_degrees_min);
}

float color_space::hcy::chroma() const
{
	return m_component_vector[1];
}

void color_space::hcy::chroma(float new_chroma)
{
	set_component(new_chroma, 1);
}

float color_space::hcy::luma() const
{
	return m_component_vector[2];
}

void color_space::hcy::luma(float new_luma)
{
	set_component(new_luma, 2);
}
