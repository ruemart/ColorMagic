#include "stdafx.h"
#include "grey_truecolor.h"

color_space::grey_truecolor::grey_truecolor(unsigned char value, unsigned char alpha) : icolor(2, 255.f, 0.f)
{
	this->grey(value);
	this->alpha(alpha);
}

color_space::grey_truecolor::grey_truecolor(const color_space::grey_truecolor & other) : icolor(2, other.get_component_max(), other.get_component_min())
{
	this->m_component_vector = other.m_component_vector;
}

color_space::grey_truecolor & color_space::grey_truecolor::operator=(const color_space::grey_truecolor & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

unsigned char color_space::grey_truecolor::grey()
{
	return (unsigned char)m_component_vector[0];
}

void color_space::grey_truecolor::grey(unsigned char new_grey)
{
	set_component(new_grey, 0);
}

unsigned char color_space::grey_truecolor::alpha()
{
	return (unsigned char)m_component_vector[1];
}

void color_space::grey_truecolor::alpha(unsigned char new_alpha)
{
	set_component(new_alpha, 1);
}