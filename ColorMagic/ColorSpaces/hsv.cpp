#include "stdafx.h"
#include "hsv.h"

ColorSpaces::hsv::hsv(float hue, float saturation, float value) : icolor(3)
{
	this->hue(hue);
	this->saturation(saturation);
	this->value(value);
}

ColorSpaces::hsv::hsv(const ColorSpaces::hsv & other) : icolor(3)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::hsv & ColorSpaces::hsv::operator=(const ColorSpaces::hsv & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::hsv::hue()
{
	return component_vector[0];
}

void ColorSpaces::hsv::hue(float new_hue)
{
	component_vector[0] = new_hue;
}

float ColorSpaces::hsv::saturation()
{
	return component_vector[1];
}

void ColorSpaces::hsv::saturation(float new_saturation)
{
	component_vector[1] = new_saturation;
}

float ColorSpaces::hsv::value()
{
	return component_vector[2];
}

void ColorSpaces::hsv::value(float new_value)
{
	component_vector[2] = new_value;
}