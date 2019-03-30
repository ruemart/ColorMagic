#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class xyz : public icolor
	{
	public:
		xyz(float x = 0.f, float y = 0.f, float z = 0.f);
		xyz(const xyz& other);

		color_type get_color_type() override { return color_type::XYZ; }

		xyz& operator=(const xyz& other);

		float x();
		void x(float new_x);
		float y();
		void y(float new_y);
		float z();
		void z(float new_z);

	private:

	};
}
