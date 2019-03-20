#pragma once

#include <string>
#include <vector>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class COLORMAGIC_API grey_truecolor
	{
	public:
		grey_truecolor();
		grey_truecolor(unsigned char value);
		grey_truecolor(unsigned char value, unsigned char alpha);
		grey_truecolor(const grey_truecolor& other);
		grey_truecolor& operator=(const grey_truecolor& other);
		friend bool operator==(const grey_truecolor& lhs, const grey_truecolor& rhs);
		friend bool operator!=(const grey_truecolor& lhs, const grey_truecolor& rhs);

		unsigned char m_grey;
		unsigned char m_alpha;

	private:

	};
}