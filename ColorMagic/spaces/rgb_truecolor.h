#pragma once

#include "color_base.h"
#include <string>
#include <regex>

namespace color_space
{
	class rgb_truecolor : public color_base
	{
	public:
		rgb_truecolor(unsigned char value = (unsigned char)0, unsigned char alpha = (unsigned char)255);
		rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = (unsigned char)255);
		rgb_truecolor(std::string hex_code);
		rgb_truecolor(int hex_code);
		rgb_truecolor(const rgb_truecolor& other);
		rgb_truecolor(const color_base& other);

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