#include "stdafx.h"
#include "xyz.h"

color_space::xyz::xyz(float x, float y, float z) : icolor(3)
{
	this->x(x);
	this->y(y);
	this->z(z);
}

color_space::xyz::xyz(const xyz & other) : icolor(3)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::xyz & color_space::xyz::operator=(const color_space::xyz & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::xyz::x()
{
	return m_component_vector[0];
}

void color_space::xyz::x(float new_x)
{
	m_component_vector[0] = new_x;
}

float color_space::xyz::y()
{
	return m_component_vector[1];
}

void color_space::xyz::y(float new_y)
{
	m_component_vector[1] = new_y;
}

float color_space::xyz::z()
{
	return m_component_vector[2];
}

void color_space::xyz::z(float new_z)
{
	m_component_vector[2] = new_z;
}