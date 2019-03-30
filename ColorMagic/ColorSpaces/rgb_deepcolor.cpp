#include "stdafx.h"
#include "rgb_deepcolor.h"

ColorSpaces::rgb_deepcolor::rgb_deepcolor() : icolor(4)
{
	this->red(0.f);
	this->green(0.f);
	this->blue(0.f);
	this->alpha(1.f);
}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float value) : icolor(4)
{
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(1.f);
}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float value, float alpha) : icolor(4)
{
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float r, float g, float b) : icolor(4)
{
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(1.f);
}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(float r, float g, float b, float a) : icolor(4)
{
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(a);
}

ColorSpaces::rgb_deepcolor::rgb_deepcolor(const ColorSpaces::rgb_deepcolor & other) : icolor(4)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::rgb_deepcolor & ColorSpaces::rgb_deepcolor::operator=(const ColorSpaces::rgb_deepcolor & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::rgb_deepcolor::red()
{
	return component_vector[0];
}

void ColorSpaces::rgb_deepcolor::red(float new_red)
{
	component_vector[0] = new_red;
}

float ColorSpaces::rgb_deepcolor::green()
{
	return component_vector[1];
}

void ColorSpaces::rgb_deepcolor::green(float new_green)
{
	component_vector[1] = new_green;
}

float ColorSpaces::rgb_deepcolor::blue()
{
	return component_vector[2];
}

void ColorSpaces::rgb_deepcolor::blue(float new_blue)
{
	component_vector[2] = new_blue;
}

float ColorSpaces::rgb_deepcolor::alpha()
{
	return component_vector[3];
}

void ColorSpaces::rgb_deepcolor::alpha(float new_alpha)
{
	component_vector[3] = new_alpha;
}
