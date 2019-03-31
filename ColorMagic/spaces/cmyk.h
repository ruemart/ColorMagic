#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	class cmyk : public color_base
	{
	public:
		cmyk(float cyan = 0.f, float magenta = 0.f, float yellow = 0.f, float black = 0.f);
		cmyk(const cmyk& other);

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