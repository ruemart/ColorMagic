#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class xyz : public icolor
	{
	public:
		xyz();
		xyz(float x, float y, float z);
		xyz(const xyz& other);

		color_type get_color_type() override { return color_type::XYZ; }

		xyz& operator=(const xyz& other);
		friend bool operator==(const xyz& lhs, const xyz& rhs);
		friend bool operator!=(const xyz& lhs, const xyz& rhs);

		float m_x;
		float m_y;
		float m_z;

	private:

	};
}
