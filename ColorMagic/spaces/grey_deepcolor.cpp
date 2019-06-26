#include "stdafx.h"
#include "grey_deepcolor.h"

color_space::grey_deepcolor::grey_deepcolor(float value, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 1)
{
	this->m_type = color_type::GREY_DEEP;
	this->grey(value);
}

color_space::grey_deepcolor::grey_deepcolor(const color_space::grey_deepcolor & other) : color_base(other.alpha(), other.get_rgb_color_space(), 1, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::grey_deepcolor::grey_deepcolor(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 1, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::GREY_DEEP && other.get_component_vector().size() == 2)
	{
		this->m_type = color_type::GREY_DEEP;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("Grey Deep: Error while creating grey deep class from base object. Base object and this derived class have different types.");
	}
}

color_space::grey_deepcolor & color_space::grey_deepcolor::operator=(const color_space::grey_deepcolor & other)
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

float color_space::grey_deepcolor::grey()
{
	return m_component_vector[0];
}

void color_space::grey_deepcolor::grey(float new_grey)
{
	set_component(new_grey, 0);
}