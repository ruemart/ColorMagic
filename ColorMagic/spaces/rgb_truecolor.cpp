#include "stdafx.h"
#include "rgb_truecolor.h"

color_space::rgb_truecolor::rgb_truecolor(unsigned char value, unsigned char alpha) : icolor(4)
{
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

color_space::rgb_truecolor::rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : icolor(4)
{
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(a);
}

color_space::rgb_truecolor::rgb_truecolor(std::string hex_code) : icolor(4)
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
		this->alpha(255);
		this->red((unsigned char)r);
		this->green((unsigned char)g);
		this->blue((unsigned char)b);
	}
	else if (hex_code.length() == 8)
	{
		int a, r, g, b;
		sscanf_s(hex_code.c_str(), "%02x%02x%02x%02x", &a, &r, &g, &b);
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

color_space::rgb_truecolor::rgb_truecolor(int hex_code) : icolor(4)
{
	this->alpha((hex_code >> 24) & 0xff);
	this->red((hex_code >> 16) & 0xff);
	this->green((hex_code >> 8) & 0xff);
	this->blue((hex_code) & 0xff);
}

color_space::rgb_truecolor::rgb_truecolor(const color_space::rgb_truecolor & other) : icolor(4)
{
	this->m_component_vector = other.m_component_vector;
}

color_space::rgb_truecolor & color_space::rgb_truecolor::operator=(const color_space::rgb_truecolor & other)
{
	if (this != &other)
	{
		this->m_component_vector = other.m_component_vector;
	}
	return *this;
}

unsigned char color_space::rgb_truecolor::red()
{
	return (unsigned char)m_component_vector[0];
}

void color_space::rgb_truecolor::red(unsigned char new_red)
{
	m_component_vector[0] = new_red;
}

unsigned char color_space::rgb_truecolor::green()
{
	return (unsigned char)m_component_vector[1];
}

void color_space::rgb_truecolor::green(unsigned char new_green)
{
	m_component_vector[1] = new_green;
}

unsigned char color_space::rgb_truecolor::blue()
{
	return (unsigned char)m_component_vector[2];
}

void color_space::rgb_truecolor::blue(unsigned char new_blue)
{
	m_component_vector[2] = new_blue;
}

unsigned char color_space::rgb_truecolor::alpha()
{
	return (unsigned char)m_component_vector[3];
}

void color_space::rgb_truecolor::alpha(unsigned char new_alpha)
{
	m_component_vector[3] = new_alpha;
}
