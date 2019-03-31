#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	class hsv : public color_base
	{
	public:
		hsv(float hue = 0.f, float saturation = 0.f, float value = 0.f);
		hsv(const hsv& other);

		hsv& operator=(const hsv& other);

		float hue();
		void hue(float hue);
		float saturation();
		void saturation(float saturation);
		float value();
		void value(float value);

	private:
		float m_degrees_max = 359.f;
		float m_degrees_min = 0.f;
	};
}