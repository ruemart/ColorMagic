#include "stdafx.h"
#include "hsl.h"

color_space::hsl::hsl(float hue, float saturation, float lightness) : color_base(3)
{
	this->m_type = color_type::HSL;
	this->hue(hue);
	this->saturation(saturation);
	this->lightness(lightness);
}

color_space::hsl::hsl(const color_space::hsl & other) : color_base(3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.m_component_vector;
}

color_space::hsl::hsl(const color_base & other) : color_base(3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::HSL && other.m_component_vector.size() == 3)
	{
		this->m_type = color_type::HSL;
		this->m_component_vector = other.m_component_vector;
	}
	else
	{
		throw new std::invalid_argument("HSL: Error while creating hsl class from base object. Base object and this derived class have different types.");
	}
}

color_space::hsl & color_space::hsl::operator=(const color_space::hsl & other)
{
	if (this != &other)
	{
		this->m_type = other.get_color_type();
		this->m_component_vector = other.m_component_vector;
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

color_space::hsl color_space::hsl::operator+(const hsl & rhs)
{
	auto this_color = convert_to_vector_format(*this);
	auto other_color = convert_to_vector_format(rhs);

	std::vector<float> combined_color;
	combined_color.push_back((this_color[0] + other_color[0]) / 2); // new x component
	combined_color.push_back((this_color[1] + other_color[1]) / 2); // new y component
	combined_color.push_back((this_color[2] + other_color[2]) / 2); // new z component

	return convert_from_vector_format(combined_color);
}

float color_space::hsl::hue() const
{
	return m_component_vector[0];
}

void color_space::hsl::hue(float new_hue)
{
	set_component((int)new_hue % 360, 0, m_degrees_max, m_degrees_min);
}

float color_space::hsl::saturation() const
{
	return m_component_vector[1];
}

void color_space::hsl::saturation(float new_saturation)
{
	set_component(new_saturation, 1);
}

float color_space::hsl::lightness() const
{
	return m_component_vector[2];
}

void color_space::hsl::lightness(float new_lightness)
{
	set_component(new_lightness, 2);
}

std::vector<float> color_space::hsl::convert_to_vector_format(const hsl & color)
{
	std::vector<float> result;

	result.push_back(cosf(color.hue() / 180.f * M_PI) * color.saturation()); // x component of vector
	result.push_back(sinf(color.hue() / 180.f * M_PI) * color.saturation()); // y component of vector
	result.push_back(color.lightness()); // y component of vector

	return result;
}

color_space::hsl color_space::hsl::convert_from_vector_format(const std::vector<float> color)
{
	if (color.size() != 3)
	{
		throw new std::invalid_argument("HSL: Error while converting from color vector back to hsl. The vector does not have 3 components.");
	}

	auto h = atan2f(color[1], color[0]) * 180.f / M_PI;
	auto s = sqrtf(color[0] * color[0] + color[1] * color[1]);
	return hsl(h, s, color[2]);
}
