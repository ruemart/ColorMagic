#include "stdafx.h"
#include "color_distance.h"
#include "color_converter.h"

float color_manipulation::color_distance::euclidean_distance_squared(color_space::color_base * color1, color_space::color_base * color2)
{
	color_space::rgb_deepcolor *color1_rgb_d, *color2_rgb_d;
	if (color1->get_color_type() != color_type::RGB_DEEP)
	{
		color1_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color1, color_type::RGB_DEEP));
	}
	else
	{
		color1_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color1);
	}

	if (color2->get_color_type() != color_type::RGB_DEEP)
	{
		color2_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color2, color_type::RGB_DEEP));
	}
	else
	{
		color2_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color2);
	}

	if (color1_rgb_d == color2_rgb_d)
	{
		return 0.f;
	}
	else
	{
		float squared_distance = 0.f;
		for (std::vector<float>::size_type i = 0; i < color1_rgb_d->m_component_vector.size() - 1; ++i) // -1 because alpha gets ignored
		{
			squared_distance += powf(color1_rgb_d->m_component_vector[i] - color2_rgb_d->m_component_vector[i], 2.f);
		}

		return squared_distance;
	}
}

float color_manipulation::color_distance::euclidean_distance(color_space::color_base * color1, color_space::color_base * color2)
{
	return sqrtf(euclidean_distance_squared(color1, color2));
}