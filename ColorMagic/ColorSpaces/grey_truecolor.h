#pragma once

#include "icolor.h"
#include <string>
#include <vector>

namespace ColorSpaces
{
	class grey_truecolor : public icolor
	{
	public:
		grey_truecolor(unsigned char value = 0);
		grey_truecolor(unsigned char value = 0, unsigned char alpha = 1);
		grey_truecolor(const grey_truecolor& other);

		color_type get_color_type() const override { return color_type::GREY_TRUE; }

		grey_truecolor& operator=(const grey_truecolor& other);

		unsigned char grey();
		void grey(unsigned char new_grey);
		unsigned char alpha();
		void alpha(unsigned char new_alpha);

	private:

	};
}