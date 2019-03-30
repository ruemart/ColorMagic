#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class cmyk : public icolor
	{
	public:
		cmyk();
		cmyk(float value);
		cmyk(float cyan, float magenta, float yellow, float black);
		cmyk(const cmyk& other);

		color_type get_color_type() override { return color_type::CMYK; }

		cmyk& operator=(const cmyk& other);

		float cyan();
		void cyan(float new_cyan);
		float magenta();
		void magenta(float new_magenta);
		float yellow();
		void yellow(float new_yellow);
		float black();
		void black(float new_black);

	private:

	};
}