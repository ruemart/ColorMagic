#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class rgb_deepcolor : public icolor
	{
	public:
		rgb_deepcolor(float value = 0.f, float alpha = 1.f);
		rgb_deepcolor(float r, float g, float b, float a = 1.f);
		rgb_deepcolor(const rgb_deepcolor& other);

		color_type get_color_type() const override { return color_type::RGB_DEEP; }

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