#pragma once

#include "icolor.h"
#include <string>

namespace color_space
{
	class hsl : public icolor
	{
	public:
		hsl(float hue = 0.f, float saturation = 0.f, float lightness = 0.f);
		hsl(const hsl& other);

		color_type get_color_type() const override { return color_type::HSL; }

		hsl& operator=(const hsl& other);
		
		float hue();
		void hue(float new_hue);
		float saturation();
		void saturation(float new_saturation);
		float lightness();
		void lightness(float new_lightness);

	private:

	};
}