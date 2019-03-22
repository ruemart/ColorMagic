#pragma once

#include "icolor.h"
#include <string>

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
		rgb_truecolor(const rgb_truecolor& other);

		color_type get_color_type() override { return color_type::RGB_TRUE; }

		rgb_truecolor& operator=(const rgb_truecolor& other);
		friend bool operator==(const rgb_truecolor& lhs, const rgb_truecolor& rhs);
		friend bool operator!=(const rgb_truecolor& lhs, const rgb_truecolor& rhs);

		unsigned char m_red;
		unsigned char m_green;
		unsigned char m_blue;
		unsigned char m_alpha;

	private:

	};
}