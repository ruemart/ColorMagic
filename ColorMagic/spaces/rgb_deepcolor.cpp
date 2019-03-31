#include "stdafx.h"
#include "rgb_deepcolor.h"

color_space::rgb_deepcolor::rgb_deepcolor(float value, float alpha) : color_base(4)
{
	this->m_type = color_type::RGB_DEEP;
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

color_space::rgb_deepcolor::rgb_deepcolor(float r, float g, float b, float a) : color_base(4)
{
	this->m_type = color_type::RGB_DEEP;
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(a);
}

color_space::rgb_deepcolor::rgb_deepcolor(const color_space::rgb_deepcolor & other) : color_base(4, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.m_component_vector;
}

color_space::rgb_deepcolor & color_space::rgb_deepcolor::operator=(const color_space::rgb_deepcolor & other)
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

float color_space::rgb_deepcolor::alpha()
{
	return m_component_vector[3];
}

void color_space::rgb_deepcolor::alpha(float new_alpha)
{
	set_component(new_alpha, 3);
}
