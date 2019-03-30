#include "stdafx.h"
#include "rgb_deepcolor.h"

color_space::rgb_deepcolor::rgb_deepcolor(float value, float alpha) : icolor(4)
{
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

color_space::rgb_deepcolor::rgb_deepcolor(float r, float g, float b, float a) : icolor(4)
{
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(a);
}

color_space::rgb_deepcolor::rgb_deepcolor(const color_space::rgb_deepcolor & other) : icolor(4)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::rgb_deepcolor & color_space::rgb_deepcolor::operator=(const color_space::rgb_deepcolor & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

float color_space::rgb_deepcolor::red()
{
	return m_component_vector[0];
}

void color_space::rgb_deepcolor::red(float new_red)
{
	m_component_vector[0] = new_red;
}

float color_space::rgb_deepcolor::green()
{
	return m_component_vector[1];
}

void color_space::rgb_deepcolor::green(float new_green)
{
	m_component_vector[1] = new_green;
}

float color_space::rgb_deepcolor::blue()
{
	return m_component_vector[2];
}

void color_space::rgb_deepcolor::blue(float new_blue)
{
	m_component_vector[2] = new_blue;
}

float color_space::rgb_deepcolor::alpha()
{
	return m_component_vector[3];
}

void color_space::rgb_deepcolor::alpha(float new_alpha)
{
	m_component_vector[3] = new_alpha;
}
