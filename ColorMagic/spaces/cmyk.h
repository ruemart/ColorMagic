/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

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
		cmyk(const color_base& other);

		cmyk& operator=(const cmyk& other);
		cmyk operator+(const cmyk& other);

		float cyan() const;
		void cyan(float new_cyan);
		float magenta() const;
		void magenta(float new_magenta);
		float yellow() const;
		void yellow(float new_yellow);
		float black() const;
		void black(float new_black);

	private:

	};
}