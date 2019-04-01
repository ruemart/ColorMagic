#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	class lab : public color_base
	{
	public:
		lab(float luminance = 0.f, float a = 0.f, float b = 0.f);
		lab(const lab& other);
		lab(const color_base& other);

		lab& operator=(const lab& other);

		float luminance();
		void luminance(float new_luminance);
		float a(); // green red
		void a(float new_a);
		float b(); // yellow blue
		void b(float new_b);

	private:
		float m_lightness_max = 100.f;
		float m_lightness_min = 0.f;
	};
}