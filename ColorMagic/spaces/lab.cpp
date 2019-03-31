#include "stdafx.h"
#include "lab.h"

color_space::lab::lab(float luminance, float a, float b) : color_base(3, 128.f, -128.f)
{
	this->m_type = color_type::LAB;
	this->m_max = 128.f;
	this->m_min = -128.f;
	this->luminance(luminance);
	this->a(a);
	this->b(b);
}

color_space::lab::lab(const color_space::lab & other) : color_base(3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.m_component_vector;
}
color_space::lab & color_space::lab::operator=(const color_space::lab & other)
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

float color_space::lab::luminance()
{
	return m_component_vector[0];
}

void color_space::lab::luminance(float new_luminance)
{
	set_component(new_luminance, 0, m_lightness_max, m_lightness_min);
}

float color_space::lab::a()
{
	return m_component_vector[1];
}

void color_space::lab::a(float new_a)
{
	set_component(new_a, 1);
}

float color_space::lab::b()
{
	return m_component_vector[2];
}

void color_space::lab::b(float new_b)
{
	set_component(new_b, 2);
}
