#include "stdafx.h"
#include "rgb_truecolor.h"

ColorSpaces::rgb_truecolor::rgb_truecolor() : icolor(4)
{
	this->red(0);
	this->green(0);
	this->blue(0);
	this->alpha(255);
}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char value) : icolor(4)
{
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(255);
}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char value, unsigned char alpha) : icolor(4)
{
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char r, unsigned char g, unsigned char b) : icolor(4)
{
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(255);
}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : icolor(4)
{
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(a);
}

ColorSpaces::rgb_truecolor::rgb_truecolor(std::string hex_code) : icolor(4)
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

ColorSpaces::rgb_truecolor::rgb_truecolor(int hex_code)
{
	this->alpha((hex_code >> 24) & 0xff);
	this->red((hex_code >> 16) & 0xff);
	this->green((hex_code >> 8) & 0xff);
	this->blue((hex_code) & 0xff);
}

ColorSpaces::rgb_truecolor::rgb_truecolor(const ColorSpaces::rgb_truecolor & other) : icolor(4)
{
	this->component_vector = other.component_vector;
}

ColorSpaces::rgb_truecolor & ColorSpaces::rgb_truecolor::operator=(const ColorSpaces::rgb_truecolor & other)
{
	if (this != &other)
	{
		this->component_vector = other.component_vector;
	}
	return *this;
}

unsigned char ColorSpaces::rgb_truecolor::red()
{
	return (unsigned char)component_vector[0];
}

void ColorSpaces::rgb_truecolor::red(unsigned char new_red)
{
	component_vector[0] = new_red;
}

unsigned char ColorSpaces::rgb_truecolor::green()
{
	return (unsigned char)component_vector[1];
}

void ColorSpaces::rgb_truecolor::green(unsigned char new_green)
{
	component_vector[1] = new_green;
}

unsigned char ColorSpaces::rgb_truecolor::blue()
{
	return (unsigned char)component_vector[2];
}

void ColorSpaces::rgb_truecolor::blue(unsigned char new_blue)
{
	component_vector[2] = new_blue;
}

unsigned char ColorSpaces::rgb_truecolor::alpha()
{
	return (unsigned char)component_vector[3];
}

void ColorSpaces::rgb_truecolor::alpha(unsigned char new_alpha)
{
	component_vector[3] = new_alpha;
}
