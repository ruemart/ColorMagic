#include "stdafx.h"
#include "lab.h"

ColorSpaces::lab::lab() : icolor(3)
{
	this->luminance(0.f);
	this->a(0.f);
	this->b(0.f);
}

ColorSpaces::lab::lab(float luminance, float a, float b) : icolor(3)
{
	this->luminance(luminance);
	this->a(a);
	this->b(b);
}

ColorSpaces::lab::lab(const ColorSpaces::lab & other) : icolor(3)
{
	this->component_vector = other.component_vector;
}
ColorSpaces::lab & ColorSpaces::lab::operator=(const ColorSpaces::lab & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::lab::luminance()
{
	return component_vector[0];
}

void ColorSpaces::lab::luminance(float new_luminance)
{
	component_vector[0] = new_luminance;
}

float ColorSpaces::lab::a()
{
	return component_vector[1];
}

void ColorSpaces::lab::a(float new_a)
{
	component_vector[1] = new_a;
}

float ColorSpaces::lab::b()
{
	return component_vector[2];
}

void ColorSpaces::lab::b(float new_b)
{
	component_vector[2] = new_b;
}
