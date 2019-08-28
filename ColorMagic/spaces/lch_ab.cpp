#include "stdafx.h"
#include "lch_ab.h"

color_space::lch_ab::lch_ab(float luminance, float chroma, float hue, float alpha, rgb_color_space_definition * color_space) : color_base(alpha, color_space, 3, 100.f, 0.f)
{
	this->m_type = color_type::LCH_AB;
	this->luminance(luminance);
	this->chroma(chroma);
	this->hue(hue);
}

color_space::lch_ab::lch_ab(const lch_ab & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::lch_ab::lch_ab(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::LCH_AB && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::LCH_AB;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("LCH(ab): Error while creating LCH(ab) class from base object. Base object and this derived class have different types.");
	}
}

color_space::lch_ab& color_space::lch_ab::operator=(const lch_ab & other)
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

float color_space::lch_ab::luminance()
{
	return m_component_vector[0];
}

void color_space::lch_ab::luminance(float new_luminance)
{
	set_component(new_luminance, 0);
}

float color_space::lch_ab::chroma()
{
	return m_component_vector[1];
}

void color_space::lch_ab::chroma(float new_chroma)
{
	set_component(new_chroma, 1);
}

float color_space::lch_ab::hue()
{
	return m_component_vector[2];
}

void color_space::lch_ab::hue(float new_hue)
{
	set_component(new_hue, 2, m_degrees_max, m_degrees_min);
}
