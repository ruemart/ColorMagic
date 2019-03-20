#pragma once

#include <string>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class COLORMAGIC_API hsv
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