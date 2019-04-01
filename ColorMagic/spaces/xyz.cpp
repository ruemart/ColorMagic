#include "stdafx.h"
#include "xyz.h"

color_space::xyz::xyz(float x, float y, float z) : color_base(3, 100.f, 0.f)
{
	this->m_type = color_type::XYZ;
	this->x(x);
	this->y(y);
	this->z(z);
}

color_space::xyz::xyz(const xyz & other) : color_base(3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.m_component_vector;
}

color_space::xyz::xyz(const color_base & other) : color_base(3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::XYZ && other.m_component_vector.size() == 3)
	{
		this->m_type = color_type::XYZ;
		this->m_component_vector = other.m_component_vector;
	}
	else
	{
		throw new std::invalid_argument("XYZ: Error while creating xyz class from base object. Base object and this derived class have different types.");
	}
}

color_space::xyz & color_space::xyz::operator=(const color_space::xyz & other)
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

float color_space::xyz::x()
{
	return m_component_vector[0];
}

void color_space::xyz::x(float new_x)
{
	set_component(new_x, 0);
}

float color_space::xyz::y()
{
	return m_component_vector[1];
}

void color_space::xyz::y(float new_y)
{
	set_component(new_y, 1);
}

float color_space::xyz::z()
{
	return m_component_vector[2];
}

void color_space::xyz::z(float new_z)
{
	set_component(new_z, 2);
}