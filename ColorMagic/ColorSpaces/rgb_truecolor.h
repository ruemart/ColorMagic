#pragma once

#include "icolor.h"
#include <string>
#include <regex>

namespace ColorSpaces
{
	class rgb_truecolor : public icolor
	{
	public:
		rgb_truecolor();
		rgb_truecolor(unsigned char value);
		rgb_truecolor(unsigned char value, unsigned char alpha);
		rgb_truecolor(unsigned char r, unsigned char g, unsigned char b);
		rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		rgb_truecolor(std::string hex_code);
		rgb_truecolor(int hex_code);
		rgb_truecolor(const rgb_truecolor& other);

		color_type get_color_type() override { return color_type::RGB_TRUE; }

		rgb_truecolor& operator=(const rgb_truecolor& other);

		unsigned char red();
		void red(unsigned char new_red);
		unsigned char green();
		void green(unsigned char new_green);
		unsigned char blue();
		void blue(unsigned char new_blue);
		unsigned char alpha();
		void alpha(unsigned char new_alpha);

	private:

	};
}