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

		static float euclidean_distance_weighted(color_space::color_base* color1, color_space::color_base* color2);

		static float cielab_delta_e_cie76(color_space::color_base* color1, color_space::color_base* color2);
		
		static float cielab_delta_e_cie94(color_space::color_base* color1, color_space::color_base* color2, float kL = 1.f, float kC = 1.f, float kH = 1.f, float k1 = 0.45f, float k2 = 0.015f);

		static float cielab_delta_e_cie00(color_space::color_base* color1, color_space::color_base* color2, float kL = 1.f, float kC = 1.f, float kH = 1.f, float k1 = 0.45f, float k2 = 0.015f);
	private:
		static float to_rad(float degree);

		static float to_deg(float radians);
	};
}
