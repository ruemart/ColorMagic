#include "stdafx.h"
#include "lab.h"

color_space::lab::lab(float luminance, float a, float b) : icolor(3)
{
	this->luminance(luminance);
	this->a(a);
	this->b(b);
}

color_space::lab::lab(const color_space::lab & other) : icolor(3)
{
	this->m_component_vector = other.m_component_vector;
}
color_space::lab & color_space::lab::operator=(const color_space::lab & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::lab::luminance()
{
	return m_component_vector[0];
}

void color_space::lab::luminance(float new_luminance)
{
	m_component_vector[0] = new_luminance;
}

float color_space::lab::a()
{
	return m_component_vector[1];
}

void color_space::lab::a(float new_a)
{
	m_component_vector[1] = new_a;
}

float color_space::lab::b()
{
	return m_component_vector[2];
}

void color_space::lab::b(float new_b)
{
	m_component_vector[2] = new_b;
}
