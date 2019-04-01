#include "stdafx.h"
#include "color_distance.h"
#include "color_converter.h"

float color_manipulation::color_distance::euclidean_distance_squared(color_space::color_base * color1, color_space::color_base * color2)
{
	auto color1_rgb_d = convert_to_rgb_deep(color1);
	auto color2_rgb_d = convert_to_rgb_deep(color2);
	
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

float color_manipulation::color_distance::euclidean_distance_weighted(color_space::color_base * color1, color_space::color_base * color2)
{
	auto color1_rgb_d = convert_to_rgb_deep(color1);
	auto color2_rgb_d = convert_to_rgb_deep(color2);

	if (color1_rgb_d == color2_rgb_d) return 0.f;
	
	// Equation source: https://www.compuphase.com/cmetric.htm
	auto avg_r = ((color1_rgb_d->red() + color2_rgb_d->red()) / 2.f) * 255.f;
	auto delta_r_t = (color1_rgb_d->red() - color2_rgb_d->red()) * 255.f; // to rgb true
	auto delta_g_t = (color1_rgb_d->green() - color2_rgb_d->green()) * 255.f; // to rgb true
	auto delta_b_t = (color1_rgb_d->blue() - color2_rgb_d->blue()) * 255.f; // to rgb true

	return sqrtf((2.f + avg_r / 256.f) * powf(delta_r_t, 2.f) + 4.f * powf(delta_g_t, 2.f) + (2.f + (255.f - avg_r) / 256.f) * powf(delta_b_t, 2.f)) / 255.f; // back to rgb deep
}

color_space::rgb_deepcolor * color_manipulation::color_distance::convert_to_rgb_deep(color_space::color_base * color)
{
	if (color->get_color_type() != color_type::RGB_DEEP)
	{
		return dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color, color_type::RGB_DEEP));
	}
	else
	{
		return dynamic_cast<color_space::rgb_deepcolor*>(color);
	}
}
