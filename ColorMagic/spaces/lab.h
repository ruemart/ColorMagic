#pragma once

#include "icolor.h"
#include <string>

namespace color_space
{
	class lab : public icolor
	{
	public:
		lab(float luminance = 0.f, float a = 0.f, float b = 0.f);
		lab(const lab& other);

		color_type get_color_type() const override { return color_type::LAB; }

		lab& operator=(const lab& other);

		float luminance();
		void luminance(float new_luminance);
		float a(); // green red
		void a(float new_a);
		float b(); // yellow blue
		void b(float new_b);

	private:

	};
}