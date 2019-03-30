#include "stdafx.h"
#include "grey_truecolor.h"

ColorSpaces::grey_truecolor::grey_truecolor(unsigned char value) : icolor(2)
{
	this->grey(value);
	this->alpha(255);
}

ColorSpaces::grey_truecolor::grey_truecolor(unsigned char value, unsigned char alpha) : icolor(2)
{
	this->grey(value);
	this->alpha(alpha);
}

ColorSpaces::grey_truecolor::grey_truecolor(const ColorSpaces::grey_truecolor & other) : icolor(2)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::grey_truecolor & ColorSpaces::grey_truecolor::operator=(const ColorSpaces::grey_truecolor & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

unsigned char ColorSpaces::grey_truecolor::grey()
{
	return (unsigned char)component_vector[0];
}

void ColorSpaces::grey_truecolor::grey(unsigned char new_grey)
{
	component_vector[0] = new_grey;
}

unsigned char ColorSpaces::grey_truecolor::alpha()
{
	return (unsigned char)component_vector[1];
}

void ColorSpaces::grey_truecolor::alpha(unsigned char new_alpha)
{
	component_vector[1] = new_alpha;
}