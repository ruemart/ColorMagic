#include "stdafx.h"
#include "cmyk.h"

ColorSpaces::cmyk::cmyk(float value) : icolor(4)
{
	this->cyan(value);
	this->magenta(value);
	this->yellow(value);
	this->black(value);
}

ColorSpaces::cmyk::cmyk(float cyan, float magenta, float yellow, float black) : icolor(4)
{
	this->cyan(cyan);
	this->magenta(magenta);
	this->yellow(yellow);
	this->black(black);
}

ColorSpaces::cmyk::cmyk(const ColorSpaces::cmyk & other) : icolor(4)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::cmyk & ColorSpaces::cmyk::operator=(const cmyk & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::cmyk::cyan()
{
	return component_vector[0];
}

void ColorSpaces::cmyk::cyan(float new_cyan)
{
	component_vector[0] = new_cyan;
}

float ColorSpaces::cmyk::magenta()
{
	return component_vector[1];
}

void ColorSpaces::cmyk::magenta(float new_magenta)
{
	component_vector[1] = new_magenta;
}

float ColorSpaces::cmyk::yellow()
{
	return component_vector[2];
}

void ColorSpaces::cmyk::yellow(float new_yellow)
{
	component_vector[2] = new_yellow;
}

float ColorSpaces::cmyk::black()
{
	return component_vector[3];
}

void ColorSpaces::cmyk::black(float new_black)
{
	component_vector[3] = new_black;
}
