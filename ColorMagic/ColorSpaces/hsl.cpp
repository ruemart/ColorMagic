#include "stdafx.h"
#include "hsl.h"

ColorSpaces::hsl::hsl() : icolor(3)
{
	this->hue(0.f);
	this->saturation(0.f);
	this->lightness(0.f);
}

ColorSpaces::hsl::hsl(float hue, float saturation, float lightness) : icolor(3)
{
	this->hue(hue);
	this->saturation(saturation);
	this->lightness(lightness);
}

ColorSpaces::hsl::hsl(const ColorSpaces::hsl & other) : icolor(3)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::hsl & ColorSpaces::hsl::operator=(const ColorSpaces::hsl & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

float ColorSpaces::hsl::hue()
{
	return component_vector[0];
}

void ColorSpaces::hsl::hue(float new_hue)
{
	component_vector[0] = new_hue;
}

float ColorSpaces::hsl::saturation()
{
	return component_vector[1];
}

void ColorSpaces::hsl::saturation(float new_saturation)
{
	component_vector[1] = new_saturation;
}

float ColorSpaces::hsl::lightness()
{
	return component_vector[2];
}

void ColorSpaces::hsl::lightness(float new_lightness)
{
	component_vector[2] = new_lightness;
}