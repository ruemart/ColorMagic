#pragma once

#include <string>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class COLORMAGIC_API cmyk
	{
	public:
		cmyk();
		cmyk(float value);
		cmyk(float cyan, float magenta, float yellow, float black);
		cmyk(const cmyk& other);
		cmyk& operator=(const cmyk& other);
		friend bool operator==(const cmyk& lhs, const cmyk& rhs);
		friend bool operator!=(const cmyk& lhs, const cmyk& rhs);

		float m_cyan;
		float m_magenta;
		float m_yellow;
		float m_black;

	private:

	};
}