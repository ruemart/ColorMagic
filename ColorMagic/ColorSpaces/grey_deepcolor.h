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
	class COLORMAGIC_API grey_deepcolor
	{
	public:
		grey_deepcolor();
		grey_deepcolor(float value);
		grey_deepcolor(float value, float alpha);
		grey_deepcolor(const grey_deepcolor& other);
		grey_deepcolor& operator=(const grey_deepcolor& other);
		friend bool operator==(const grey_deepcolor& lhs, const grey_deepcolor& rhs);
		friend bool operator!=(const grey_deepcolor& lhs, const grey_deepcolor& rhs);

		float m_grey;
		float m_alpha;

	private:

	};
}