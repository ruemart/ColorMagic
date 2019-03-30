#include "stdafx.h"
#include "cmyk.h"

color_space::cmyk::cmyk(float cyan, float magenta, float yellow, float black) : icolor(4)
{
	this->cyan(cyan);
	this->magenta(magenta);
	this->yellow(yellow);
	this->black(black);
}

color_space::cmyk::cmyk(const color_space::cmyk & other) : icolor(4, other.get_component_max(), other.get_component_min())
{
	this->m_component_vector = other.m_component_vector;
}

color_space::cmyk & color_space::cmyk::operator=(const cmyk & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

float color_space::cmyk::cyan()
{
	return m_component_vector[0];
}

void color_space::cmyk::cyan(float new_cyan)
{
	set_component(new_cyan, 0);
}

float color_space::cmyk::magenta()
{
	return m_component_vector[1];
}

void color_space::cmyk::magenta(float new_magenta)
{
	set_component(new_magenta, 1);
}

float color_space::cmyk::yellow()
{
	return m_component_vector[2];
}

void color_space::cmyk::yellow(float new_yellow)
{
	set_component(new_yellow, 2);
}

float color_space::cmyk::black()
{
	return m_component_vector[3];
}

void color_space::cmyk::black(float new_black)
{
	set_component(new_black, 3);
}
