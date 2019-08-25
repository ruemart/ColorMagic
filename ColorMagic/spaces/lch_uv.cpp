#include "stdafx.h"
#include "lch_uv.h"

color_space::lch_uv::lch_uv(float luminance, float chroma, float hue, float alpha, rgb_color_space_definition * color_space) : color_base(alpha, color_space, 3, 100.f, 0.f)
{
	this->m_type = color_type::LCH_UV;
	this->luminance(luminance);
	this->chroma(chroma);
	this->hue(hue);
}

color_space::lch_uv::lch_uv(const lch_uv & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::lch_uv::lch_uv(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::LCH_UV && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::LCH_UV;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("LCH(uv): Error while creating LCH(uv) class from base object. Base object and this derived class have different types.");
	}
}

color_space::lch_uv& color_space::lch_uv::operator=(const lch_uv & other)
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

float color_space::lch_uv::luminance()
{
	return m_component_vector[0];
}

void color_space::lch_uv::luminance(float new_luminance)
{
	set_component(new_luminance, 0);
}

float color_space::lch_uv::chroma()
{
	return m_component_vector[1];
}

void color_space::lch_uv::chroma(float new_chroma)
{
	set_component(new_chroma, 1);
}

float color_space::lch_uv::hue()
{
	return m_component_vector[2];
}

void color_space::lch_uv::hue(float new_hue)
{
	set_component(new_hue, 2, m_degrees_max, m_degrees_min);
}
