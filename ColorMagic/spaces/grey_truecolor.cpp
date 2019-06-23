#include "stdafx.h"
#include "grey_truecolor.h"

color_space::grey_truecolor::grey_truecolor(float value, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 1, 255.f, 0.f)
{
	this->m_type = color_type::GREY_TRUE;
	this->grey(value);
}

color_space::grey_truecolor::grey_truecolor(const color_space::grey_truecolor & other) : color_base(other.alpha(), other.get_rgb_color_space(), 1, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
}

color_space::grey_truecolor::grey_truecolor(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 1, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::GREY_TRUE && other.get_component_vector().size() == 2)
	{
		this->m_type = color_type::GREY_TRUE;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("Grey True: Error while creating grey true class from base object. Base object and this derived class have different types.");
	}
}

color_space::grey_truecolor & color_space::grey_truecolor::operator=(const color_space::grey_truecolor & other)
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

float color_space::grey_truecolor::grey()
{
	return (float)m_component_vector[0];
}

void color_space::grey_truecolor::grey(float new_grey)
{
	set_component(new_grey, 0);
}