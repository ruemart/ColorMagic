#include "stdafx.h"
#include "xyz.h"

ColorSpaces::xyz::xyz(float x, float y, float z) : icolor(3)
{
	this->x(x);
	this->y(y);
	this->z(z);
}

ColorSpaces::xyz::xyz(const xyz & other) : icolor(3)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::xyz & ColorSpaces::xyz::operator=(const ColorSpaces::xyz & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::xyz::x()
{
	return component_vector[0];
}

void ColorSpaces::xyz::x(float new_x)
{
	component_vector[0] = new_x;
}

float ColorSpaces::xyz::y()
{
	return component_vector[1];
}

void ColorSpaces::xyz::y(float new_y)
{
	component_vector[1] = new_y;
}

float ColorSpaces::xyz::z()
{
	return component_vector[2];
}

void ColorSpaces::xyz::z(float new_z)
{
	component_vector[2] = new_z;
}