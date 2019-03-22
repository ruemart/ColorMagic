#pragma once

#include <string>

namespace ColorSpaces
{
	class rgb_deepcolor
	{
	public:
		rgb_deepcolor();
		rgb_deepcolor(float value);
		rgb_deepcolor(float value, float alpha);
		rgb_deepcolor(float r, float g, float b);
		rgb_deepcolor(float r, float g, float b, float a);
		rgb_deepcolor(const rgb_deepcolor& other);
		rgb_deepcolor& operator=(const rgb_deepcolor& other);
		friend bool operator==(const rgb_deepcolor& lhs, const rgb_deepcolor& rhs);
		friend bool operator!=(const rgb_deepcolor& lhs, const rgb_deepcolor& rhs);

		float m_red;
		float m_green;
		float m_blue;
		float m_alpha;

	private:

	};
}