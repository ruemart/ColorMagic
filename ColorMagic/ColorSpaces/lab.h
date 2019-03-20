#pragma once

#include <string>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class lab
	{
	public:
		lab();
		lab(float luminance, float a, float b);
		lab(const lab& other);
		lab& operator=(const lab& other);
		friend bool operator==(const lab& lhs, const lab& rhs);
		friend bool operator!=(const lab& lhs, const lab& rhs);

		float m_luminance;
		float m_a; // green red
		float m_b; // yellow blue

	private:

	};
}