#pragma once

#include "icolor.h"
#include <string>
#include <vector>

namespace ColorSpaces
{
	class grey_truecolor : public icolor
	{
	public:
		grey_truecolor();
		grey_truecolor(unsigned char value);
		grey_truecolor(unsigned char value, unsigned char alpha);
		grey_truecolor(const grey_truecolor& other);

		color_type get_color_type() override { return color_type::GREY_TRUE; }

		grey_truecolor& operator=(const grey_truecolor& other);

		unsigned char grey();
		void grey(unsigned char new_grey);
		unsigned char alpha();
		void alpha(unsigned char new_alpha);

	private:

	};
}