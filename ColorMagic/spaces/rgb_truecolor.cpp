#include "stdafx.h"
#include "rgb_truecolor.h"

color_space::rgb_truecolor::rgb_truecolor(float value, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3, 255.f, 0.f)
{
	this->m_type = color_type::RGB_TRUE;
	this->red(value);
	this->green(value);
	this->blue(value);
	this->alpha(alpha);
}

color_space::rgb_truecolor::rgb_truecolor(float r, float g, float b, float alpha, rgb_color_space_definition* color_space) : color_base(alpha, color_space, 3, 255.f, 0.f)
{
	this->m_type = color_type::RGB_TRUE;
	this->red(r);
	this->green(g);
	this->blue(b);
	this->alpha(alpha);
}

color_space::rgb_truecolor::rgb_truecolor(std::string hex_code, rgb_color_space_definition* color_space) : color_base(0, color_space, 3, 255.f, 0.f)
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
		this->alpha(255.f);
		this->red((float)r);
		this->green((float)g);
		this->blue((float)b);
	}
	else if (hex_code.length() == 8)
	{
		int a, r, g, b;
		sscanf_s(hex_code.c_str(), "%02x%02x%02x%02x", &a, &r, &g, &b);
		this->m_type = color_type::RGB_TRUE;
		this->alpha((float)a);
		this->red((float)r);
		this->green((float)g);
		this->blue((float)b);
	}
	else
	{
		throw std::invalid_argument("Wrong hex code format. Use one of the following formats: #AARRGGBB, #RRGGBB, AARRGGBB, RRGGBB");
	}
}

color_space::rgb_truecolor::rgb_truecolor(int hex_code, rgb_color_space_definition* color_space) : color_base(0, color_space, 3, 255.f, 0.f)
{
	this->m_type = color_type::RGB_TRUE;
	this->alpha((float)((hex_code >> 24) & 0xff));
	this->red((float)((hex_code >> 16) & 0xff));
	this->green((float)((hex_code >> 8) & 0xff));
	this->blue((float)((hex_code) & 0xff));
}

color_space::rgb_truecolor::rgb_truecolor(const color_space::rgb_truecolor & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	this->m_type = other.get_color_type();
	this->m_component_vector = other.get_component_vector();
	this->alpha(other.alpha());
}

color_space::rgb_truecolor::rgb_truecolor(const color_base & other) : color_base(other.alpha(), other.get_rgb_color_space(), 3, other.get_component_max(), other.get_component_min())
{
	if (other.get_color_type() == color_type::RGB_TRUE && other.get_component_vector().size() == 4)
	{
		this->m_type = color_type::RGB_TRUE;
		this->m_component_vector = other.get_component_vector();
	}
	else
	{
		throw new std::invalid_argument("RGB True: Error while creating rgb true class from base object. Base object and this derived class have different types.");
	}
}

color_space::rgb_truecolor & color_space::rgb_truecolor::operator=(const color_space::rgb_truecolor & other)
{
	if (this != &other)
	{
		this->m_type = other.get_color_type();
		this->m_component_vector = other.get_component_vector();
		this->m_max = other.get_component_max();
		this->m_min = other.get_component_min();
	}
	return *this;
}

float color_space::rgb_truecolor::red()
{
	return m_component_vector[0];
}

void color_space::rgb_truecolor::red(float new_red)
{
	set_component(new_red, 0);
}

float color_space::rgb_truecolor::green()
{
	return m_component_vector[1];
}

void color_space::rgb_truecolor::green(float new_green)
{
	set_component(new_green, 1);
}

float color_space::rgb_truecolor::blue()
{
	return m_component_vector[2];
}

void color_space::rgb_truecolor::blue(float new_blue)
{
	set_component(new_blue, 2);
}

float color_space::rgb_truecolor::alpha() const
{
	return color_base::alpha() * 255.f;
}

void color_space::rgb_truecolor::alpha(float new_alpha)
{
	color_base::alpha(new_alpha / 255.f);
}