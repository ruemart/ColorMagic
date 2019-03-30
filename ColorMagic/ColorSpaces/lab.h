#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class lab : public icolor
	{
	public:
		lab();
		lab(float luminance, float a, float b);
		lab(const lab& other);

		color_type get_color_type() override { return color_type::LAB; }

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