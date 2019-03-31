#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	class hsl : public color_base
	{
	public:
		hsl(float hue = 0.f, float saturation = 0.f, float lightness = 0.f);
		hsl(const hsl& other);

		hsl& operator=(const hsl& other);
		
		float hue();
		void hue(float new_hue);
		float saturation();
		void saturation(float new_saturation);
		float lightness();
		void lightness(float new_lightness);

	private:
		float m_degrees_max = 359.f;
		float m_degrees_min = 0.f;
	};
}