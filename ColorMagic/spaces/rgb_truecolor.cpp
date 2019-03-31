#include "stdafx.h"
#include "rgb_truecolor.h"

color_space::rgb_truecolor::rgb_truecolor(unsigned char value, unsigned char alpha) : color_base(4, 255.f, 0.f)
{
	this->m_type = color_type::RGB_TRUE;
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

color_space::rgb_truecolor::rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : color_base(4, 255.f, 0.f)
{
	this->m_type = color_type::RGB_TRUE;
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(a);
}

color_space::rgb_truecolor::rgb_truecolor(std::string hex_code) : color_base(4, 255.f, 0.f)
{
	std::regex regex("^[#0-9A-Fa-f]+$");

	if (!std::regex_match(hex_code, regex))
	{
		throw std::invalid_argument(std::string("The given hex code '" + hex_code + "' contains illegal values. Allowed are only numbers (0-9) and digits (a-f or A-F)."));
	}

	if (hex_code[0] == '#')
	{
		hex_code = hex_code.substr(1);
	}

	if (hex_code.length() == 6)
	{
		int r, g, b;
		sscanf_s(hex_code.c_str(), "%02x%02x%02x", &r, &g, &b);
		this->m_type = color_type::RGB_TRUE;
		this->alpha(255);
		this->red((unsigned char)r);
		this->green((unsigned char)g);
		this->blue((unsigned char)b);
	}
	else if (hex_code.length() == 8)
	{
		int a, r, g, b;
		sscanf_s(hex_code.c_str(), "%02x%02x%02x%02x", &a, &r, &g, &b);
		this->m_type = color_type::RGB_TRUE;
		this->alpha((unsigned char)a);
		this->red((unsigned char)r);
		this->green((unsigned char)g);
		this->blue((unsigned char)b);
	}
	else
	{
		throw std::invalid_argument("Wrong hex code format. Use one of the following formats: #AARRGGBB, #RRGGBB, AARRGGBB, RRGGBB");
	}
}

color_space::rgb_truecolor::rgb_truecolor(int hex_code) : color_base(4, 255.f, 0.f)
{
	this->m_type = color_type::RGB_TRUE;
	this->alpha((hex_code >> 24) & 0xff);
	this->red((hex_code >> 16) & 0xff);
	this->green((hex_code >> 8) & 0xff);
	this->blue((hex_code) & 0xff);
}

color_space::rgb_truecolor::rgb_truecolor(const color_space::rgb_truecolor & other) : color_base(4, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.m_component_vector;
}

color_space::rgb_truecolor & color_space::rgb_truecolor::operator=(const color_space::rgb_truecolor & other)
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

unsigned char color_space::rgb_truecolor::red()
{
	return (unsigned char)m_component_vector[0];
}

void color_space::rgb_truecolor::red(unsigned char new_red)
{
	set_component(new_red, 0);
}

unsigned char color_space::rgb_truecolor::green()
{
	return (unsigned char)m_component_vector[1];
}

void color_space::rgb_truecolor::green(unsigned char new_green)
{
	set_component(new_green, 1);
}

unsigned char color_space::rgb_truecolor::blue()
{
	return (unsigned char)m_component_vector[2];
}

void color_space::rgb_truecolor::blue(unsigned char new_blue)
{
	set_component(new_blue, 2);
}

unsigned char color_space::rgb_truecolor::alpha()
{
	return (unsigned char)m_component_vector[3];
}

void color_space::rgb_truecolor::alpha(unsigned char new_alpha)
{
	set_component(new_alpha, 3);
}
