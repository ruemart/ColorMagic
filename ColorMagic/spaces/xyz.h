/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>

namespace color_space
{
	class xyz : public color_base
	{
	public:
		xyz(float x = 0.f, float y = 0.f, float z = 0.f);
		xyz(const xyz& other);
		xyz(const color_base& other);

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
