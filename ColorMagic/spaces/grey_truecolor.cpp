#include "stdafx.h"
#include "grey_truecolor.h"

color_space::grey_truecolor::grey_truecolor(unsigned char value, unsigned char alpha) : icolor(2)
{
	this->grey(value);
	this->alpha(alpha);
}

color_space::grey_truecolor::grey_truecolor(const color_space::grey_truecolor & other) : icolor(2)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::grey_truecolor & color_space::grey_truecolor::operator=(const color_space::grey_truecolor & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

unsigned char color_space::grey_truecolor::grey()
{
	return (unsigned char)m_component_vector[0];
}

void color_space::grey_truecolor::grey(unsigned char new_grey)
{
	m_component_vector[0] = new_grey;
}

unsigned char color_space::grey_truecolor::alpha()
{
	return (unsigned char)m_component_vector[1];
}

void color_space::grey_truecolor::alpha(unsigned char new_alpha)
{
	m_component_vector[1] = new_alpha;
}