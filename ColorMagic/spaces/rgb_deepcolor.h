/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	class rgb_deepcolor : public color_base
	{
	public:
		rgb_deepcolor(float value = 0.f, float alpha = 1.f);
		rgb_deepcolor(float r, float g, float b, float a = 1.f);
		rgb_deepcolor(const rgb_deepcolor& other);
		rgb_deepcolor(const color_base& other);

		rgb_deepcolor& operator=(const rgb_deepcolor& other);
		
		float red();
		void red(float new_red);
		float green();
		void green(float new_green);
		float blue();
		void blue(float new_blue);
		float alpha();
		void alpha(float new_alpha);

	private:

	};
}