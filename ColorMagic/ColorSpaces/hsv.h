#pragma once

#include <string>

namespace ColorSpaces
{
	class hsv
	{
	public:
		hsv();
		hsv(float hue, float saturation, float value);
		hsv(const hsv& other);
		hsv& operator=(const hsv& other);
		friend bool operator==(const hsv& lhs, const hsv& rhs);
		friend bool operator!=(const hsv& lhs, const hsv& rhs);

		float m_hue;
		float m_saturation;
		float m_value;

	private:

	};
}