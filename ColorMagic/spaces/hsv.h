#pragma once

#include "icolor.h"
#include <string>

namespace color_space
{
	class hsv : public icolor
	{
	public:
		hsv(float hue = 0.f, float saturation = 0.f, float value = 0.f);
		hsv(const hsv& other);

		color_type get_color_type() const override { return color_type::HSV; }

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