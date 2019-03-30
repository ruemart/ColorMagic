#include "stdafx.h"
#include "grey_deepcolor.h"

ColorSpaces::grey_deepcolor::grey_deepcolor() : icolor(2)
{
	this->grey(0.f);
	this->alpha(1.f);
}

ColorSpaces::grey_deepcolor::grey_deepcolor(float value) : icolor(2)
{
	this->grey(value);
	this->alpha(1.f);
}

ColorSpaces::grey_deepcolor::grey_deepcolor(float value, float alpha) : icolor(2)
{
	this->grey(value);
	this->alpha(alpha);
}

ColorSpaces::grey_deepcolor::grey_deepcolor(const ColorSpaces::grey_deepcolor & other) : icolor(2) 
{
	this->component_vector = other.component_vector;
}

ColorSpaces::grey_deepcolor & ColorSpaces::grey_deepcolor::operator=(const ColorSpaces::grey_deepcolor & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::grey_deepcolor::grey()
{
	return component_vector[0];
}

void ColorSpaces::grey_deepcolor::grey(float new_grey)
{
	component_vector[0] = new_grey;
}

float ColorSpaces::grey_deepcolor::alpha()
{
	return component_vector[1];
}

void ColorSpaces::grey_deepcolor::alpha(float new_alpha)
{
	component_vector[1] = new_alpha;
}