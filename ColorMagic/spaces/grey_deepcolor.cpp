#include "stdafx.h"
#include "grey_deepcolor.h"

color_space::grey_deepcolor::grey_deepcolor(float value, float alpha) : icolor(2)
{
	this->grey(value);
	this->alpha(alpha);
}

color_space::grey_deepcolor::grey_deepcolor(const color_space::grey_deepcolor & other) : icolor(2) 
{
	this->m_component_vector = other.m_component_vector;
}

color_space::grey_deepcolor & color_space::grey_deepcolor::operator=(const color_space::grey_deepcolor & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::grey_deepcolor::grey()
{
	return m_component_vector[0];
}

void color_space::grey_deepcolor::grey(float new_grey)
{
	m_component_vector[0] = new_grey;
}

float color_space::grey_deepcolor::alpha()
{
	return m_component_vector[1];
}

void color_space::grey_deepcolor::alpha(float new_alpha)
{
	m_component_vector[1] = new_alpha;
}