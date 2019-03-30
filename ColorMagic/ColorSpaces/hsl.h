#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class hsl : public icolor
	{
	public:
		hsl();
		hsl(float hue, float saturation, float lightness);
		hsl(const hsl& other);

		color_type get_color_type() override { return color_type::HSL; }

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