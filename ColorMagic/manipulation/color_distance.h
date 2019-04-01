#pragma once

#include "..\utils\color_type.h"
#include "..\spaces\color_base.h"
#include "..\spaces\cmyk.h"
#include "..\spaces\grey_deepcolor.h"
#include "..\spaces\grey_truecolor.h"
#include "..\spaces\hsl.h"
#include "..\spaces\hsv.h"
#include "..\spaces\lab.h"
#include "..\spaces\rgb_deepcolor.h"
#include "..\spaces\rgb_truecolor.h"
#include "..\spaces\xyz.h"
#include "..\manipulation\color_converter.h"


namespace color_manipulation
{
	class color_distance
	{
	public:
		static float euclidean_distance_squared(color_space::color_base* color1, color_space::color_base* color2);

		static float euclidean_distance(color_space::color_base* color1, color_space::color_base* color2);

	private:
		
	};
}