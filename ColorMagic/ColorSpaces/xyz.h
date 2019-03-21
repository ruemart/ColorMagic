#pragma once

#include <string>

#ifdef COLORMAGIC_EXPORTS
#define COLORMAGIC_API __declspec(dllexport)
#else
#define COLORMAGIC_API __declspec(dllimport)
#endif

namespace ColorSpaces
{
	class xyz
	{
	public:
		xyz();
		xyz(float x, float y, float z);
		xyz(const xyz& other);
		xyz& operator=(const xyz& other);
		friend bool operator==(const xyz& lhs, const xyz& rhs);
		friend bool operator!=(const xyz& lhs, const xyz& rhs);

		float m_x;
		float m_y;
		float m_z;

	private:

	};
}