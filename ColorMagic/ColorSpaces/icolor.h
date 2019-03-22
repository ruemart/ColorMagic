#pragma once

#include "color_type.h"

namespace ColorSpaces
{
	class icolor
	{
	public:
		virtual color_type get_color_type() = 0;
	};
}