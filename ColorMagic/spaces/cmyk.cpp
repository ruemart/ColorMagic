#include "stdafx.h"
#include "cmyk.h"

color_space::cmyk::cmyk(float cyan, float magenta, float yellow, float black) : icolor(4)
{
	this->cyan(cyan);
	this->magenta(magenta);
	this->yellow(yellow);
	this->black(black);
}

color_space::cmyk::cmyk(const color_space::cmyk & other) : icolor(4)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::cmyk & color_space::cmyk::operator=(const cmyk & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::cmyk::cyan()
{
	return m_component_vector[0];
}

void color_space::cmyk::cyan(float new_cyan)
{
	m_component_vector[0] = new_cyan;
}

float color_space::cmyk::magenta()
{
	return m_component_vector[1];
}

void color_space::cmyk::magenta(float new_magenta)
{
	m_component_vector[1] = new_magenta;
}

float color_space::cmyk::yellow()
{
	return m_component_vector[2];
}

void color_space::cmyk::yellow(float new_yellow)
{
	m_component_vector[2] = new_yellow;
}

float color_space::cmyk::black()
{
	return m_component_vector[3];
}

void color_space::cmyk::black(float new_black)
{
	m_component_vector[3] = new_black;
}
