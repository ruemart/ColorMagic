#include "stdafx.h"
#include "hcl.h"

color_space::hcl::hcl(float hue, float chroma, float luma, float alpha, rgb_color_space_definition * color_space) : color_base(alpha, color_space, 3)
{
	this->m_type = color_type::HSL;
	this->hue(hue);
	this->chroma(chroma);
	this->luma(luma);
}

color_space::hcl::hcl(const color_space::hcl & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::hcl::hcl(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::HCL && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::HCL;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("HCL: Error while creating hcl class from base object. Base object and this derived class have different types.");
	}
}

color_space::hcl & color_space::hcl::operator=(const color_space::hcl & other)
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

float color_space::hcl::hue() const
{
	return m_component_vector[0];
}

void color_space::hcl::hue(float new_hue)
{
	new_hue = fmod(new_hue, 360.f);
	while (new_hue < 0.f)
	{
		new_hue += 360.0f;
	}

	set_component(new_hue, 0, m_degrees_max, m_degrees_min);
}

float color_space::hcl::chroma() const
{
	return m_component_vector[1];
}

void color_space::hcl::chroma(float new_chroma)
{
	set_component(new_chroma, 1);
}

float color_space::hcl::luma() const
{
	return m_component_vector[2];
}

void color_space::hcl::luma(float new_luma)
{
	set_component(new_luma, 2);
}
