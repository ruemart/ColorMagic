#pragma once

#include "icolor.h"
#include <string>

namespace color_space
{
	class cmyk : public icolor
	{
	public:
		cmyk(float value = 0.f);
		cmyk(float cyan = 0.f, float magenta = 0.f, float yellow = 0.f, float black = 0.f);
		cmyk(const cmyk& other);

		color_type get_color_type() const override { return color_type::CMYK; }

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