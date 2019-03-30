#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class hsv : public icolor
	{
	public:
		hsv();
		hsv(float hue, float saturation, float value);
		hsv(const hsv& other);

		color_type get_color_type() override { return color_type::HSV; }

		hsv& operator=(const hsv& other);

		float hue();
		void hue(float hue);
		float saturation();
		void saturation(float saturation);
		float value();
		void value(float value);

	private:

	};
}