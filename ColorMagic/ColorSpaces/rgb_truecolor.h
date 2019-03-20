#pragma once

#include <string>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class COLORMAGIC_API rgb_truecolor
	{
	public:
		rgb_truecolor();
		rgb_truecolor(unsigned char value);
		rgb_truecolor(unsigned char value, unsigned char alpha);
		rgb_truecolor(unsigned char r, unsigned char g, unsigned char b);
		rgb_truecolor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
		rgb_truecolor(const rgb_truecolor& other);
		rgb_truecolor& operator=(const rgb_truecolor& other);
		friend bool operator==(const rgb_truecolor& lhs, const rgb_truecolor& rhs);
		friend bool operator!=(const rgb_truecolor& lhs, const rgb_truecolor& rhs);

		unsigned char m_red;
		unsigned char m_green;
		unsigned char m_blue;
		unsigned char m_alpha;

	private:

	};
}