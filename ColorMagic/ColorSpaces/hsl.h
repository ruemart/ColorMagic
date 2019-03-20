#pragma once

#include <string>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class COLORMAGIC_API hsl
	{
	public:
		hsl();
		hsl(float hue, float saturation, float value);
		hsl(const hsl& other);
		hsl& operator=(const hsl& other);
		friend bool operator==(const hsl& lhs, const hsl& rhs);
		friend bool operator!=(const hsl& lhs, const hsl& rhs);

		float m_hue;
		float m_saturation;
		float m_lightness;

	private:

	};
}