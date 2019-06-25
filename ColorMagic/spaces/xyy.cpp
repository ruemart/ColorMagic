#include "stdafx.h"
#include "xyy.h"

color_space::xyy::xyy(float x, float y, float Y, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3, 100.f, 0.f)
{
	this->m_type = color_type::XYY;
	this->x(x);
	this->y(y);
	this->Y(Y);
}

color_space::xyy::xyy(const xyy & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::xyy::xyy(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::XYY && other.get_component_vector().size() == 3)
	{
		this->m_type = color_type::XYY;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("xyy: Error while creating xyy class from base object. Base object and this derived class have different types.");
	}
}

color_space::xyy & color_space::xyy::operator=(const color_space::xyy & other)
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

float color_space::xyy::x()
{
	return m_component_vector[0];
}

void color_space::xyy::x(float new_x)
{
	set_component(new_x, 0);
}

float color_space::xyy::y()
{
	return m_component_vector[1];
}

void color_space::xyy::y(float new_y)
{
	set_component(new_y, 1);
}

float color_space::xyy::Y()
{
	return m_component_vector[2];
}

void color_space::xyy::Y(float new_Y)
{
	set_component(new_Y, 2);
}