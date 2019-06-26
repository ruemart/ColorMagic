#include "stdafx.h"
#include "rgb_deepcolor.h"

color_space::rgb_deepcolor::rgb_deepcolor(float value, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3)
{
	this->m_type = color_type::RGB_DEEP;
	this->red(value);
	this->green(value);
	this->blue(value);
}

color_space::rgb_deepcolor::rgb_deepcolor(float r, float g, float b, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3)
{
	this->m_type = color_type::RGB_DEEP;
	this->red(r);
	this->green(g);
	this->blue(b);
}

color_space::rgb_deepcolor::rgb_deepcolor(const color_space::rgb_deepcolor & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
}

color_space::rgb_deepcolor::rgb_deepcolor(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::RGB_DEEP && other.get_component_vector().size() == 4)
	{
		this->m_type = color_type::RGB_DEEP;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("RGB Deep: Error while creating rgb deep class from base object. Base object and this derived class have different types.");
	}
}

color_space::rgb_deepcolor & color_space::rgb_deepcolor::operator=(const color_space::rgb_deepcolor & other)
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

float color_space::rgb_deepcolor::red()
{
	return m_component_vector[0];
}

void color_space::rgb_deepcolor::red(float new_red)
{
	set_component(new_red, 0);
}

float color_space::rgb_deepcolor::green()
{
	return m_component_vector[1];
}

void color_space::rgb_deepcolor::green(float new_green)
{
	set_component(new_green, 1);
}

float color_space::rgb_deepcolor::blue()
{
	return m_component_vector[2];
}

void color_space::rgb_deepcolor::blue(float new_blue)
{
	set_component(new_blue, 2);
}