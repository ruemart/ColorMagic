#include "stdafx.h"
#include "rgb_truecolor.h"

ColorSpaces::rgb_truecolor::rgb_truecolor() : m_red(0), m_green(0), m_blue(0), m_alpha(255) { }

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char value) : m_red(value), m_green(value), m_blue(value), m_alpha(255) {}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char value, unsigned char alpha) : m_red(value), m_green(value), m_blue(value), m_alpha(alpha) {}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char r, unsigned char g, unsigned char b) : m_red(r), m_green(g), m_blue(b), m_alpha(255) {}

ColorSpaces::rgb_truecolor::rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : m_red(r), m_green(g), m_blue(b), m_alpha(a) {}

ColorSpaces::rgb_truecolor::rgb_truecolor(std::string hex_code) 
{
	if (hex_code[0] == '#')
	{
		hex_code = hex_code.substr(1);
	}

	if (hex_code.length() == 6)
	{
		scanf_s(hex_code.c_str(), "%02x%02x%02x", &m_red, &m_green, &m_blue);
		m_alpha = 255;
	}
	else if (hex_code.length() == 8)
	{
		scanf_s(hex_code.c_str(), "%02x%02x%02x", &m_red, &m_green, &m_blue, &m_alpha);
	}
	else
	{
		throw std::invalid_argument("Wrong hex code format. Use one of the following formats: #AARRGGBB, #RRGGBB, AARRGGBB, RRGGBB");
	}
}

ColorSpaces::rgb_truecolor::rgb_truecolor(int hex_code)
{
	m_alpha = (hex_code >> 24) & 0xff;
	m_red = (hex_code >> 16) & 0xff;
	m_green = (hex_code >> 8) & 0xff;
	m_blue = (hex_code) & 0xff;
}

ColorSpaces::rgb_truecolor::rgb_truecolor(const ColorSpaces::rgb_truecolor & other) : m_red(other.m_red), m_green(other.m_green), m_blue(other.m_blue), m_alpha(other.m_alpha) { }

ColorSpaces::rgb_truecolor & ColorSpaces::rgb_truecolor::operator=(const ColorSpaces::rgb_truecolor & other)
{
	if (this != &other)
	{
		m_red = other.m_red;
		m_green = other.m_green;
		m_blue = other.m_blue;
		m_alpha = other.m_alpha;
	}
	return *this;
}

bool ColorSpaces::operator==(const ColorSpaces::rgb_truecolor & lhs, const ColorSpaces::rgb_truecolor & rhs)
{
	return (lhs.m_red == rhs.m_red && lhs.m_green == rhs.m_green && lhs.m_blue == rhs.m_blue && lhs.m_alpha == rhs.m_alpha);
}

bool ColorSpaces::operator!=(const ColorSpaces::rgb_truecolor & lhs, const ColorSpaces::rgb_truecolor & rhs)
{
	return !(lhs == rhs);
}