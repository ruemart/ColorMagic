#include "stdafx.h"
#include "color_distance.h"
#include "color_converter.h"

float color_manipulation::color_distance::euclidean_distance_squared(color_space::color_base * color1, color_space::color_base * color2)
{
	auto color1_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color1, color_type::RGB_DEEP));
	auto color2_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color2, color_type::RGB_DEEP));
	
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
	auto color1_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color1, color_type::RGB_DEEP));
	auto color2_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color2, color_type::RGB_DEEP));

	if (color1_rgb_d == color2_rgb_d) return 0.f;
	
	// Equation source: https://www.compuphase.com/cmetric.htm
	auto avg_r = ((color1_rgb_d->red() + color2_rgb_d->red()) / 2.f) * 255.f;
	auto delta_r_t = (color1_rgb_d->red() - color2_rgb_d->red()) * 255.f; // to rgb true
	auto delta_g_t = (color1_rgb_d->green() - color2_rgb_d->green()) * 255.f; // to rgb true
	auto delta_b_t = (color1_rgb_d->blue() - color2_rgb_d->blue()) * 255.f; // to rgb true

	return sqrtf((2.f + avg_r / 256.f) * powf(delta_r_t, 2.f) + 4.f * powf(delta_g_t, 2.f) + (2.f + (255.f - avg_r) / 256.f) * powf(delta_b_t, 2.f)) / 255.f; // back to rgb deep
}

float color_manipulation::color_distance::cielab_delta_e_cie76(color_space::color_base * color1, color_space::color_base * color2)
{
	// Equation source: https://en.wikipedia.org/wiki/Color_difference
	auto color1_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color1, color_type::LAB));
	auto color2_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color2, color_type::LAB));

	if (color1_lab == color2_lab)
	{
		return 0.f;
	}
	else
	{
		float squared_distance = 0.f;
		for (std::vector<float>::size_type i = 0; i < color1_lab->m_component_vector.size(); ++i)
		{
			squared_distance += powf(color1_lab->m_component_vector[i] - color2_lab->m_component_vector[i], 2.f);
		}

		return sqrtf(squared_distance);
	}
}

float color_manipulation::color_distance::cielab_delta_e_cie94(color_space::color_base * color1, color_space::color_base * color2, float kL, float kC, float kH, float k1, float k2)
{
	// Equation source: https://en.wikipedia.org/wiki/Color_difference
	auto color1_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color1, color_type::LAB));
	auto color2_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color2, color_type::LAB));

	auto delta_l = color1_lab->luminance() - color2_lab->luminance();
	auto c1 = sqrtf(powf(color1_lab->a(), 2.f) + powf(color1_lab->b(), 2.f));
	auto c2 = sqrtf(powf(color2_lab->a(), 2.f) + powf(color2_lab->b(), 2.f));
	auto delta_c = c1 - c2;
	auto delta_h = sqrtf(powf(color1_lab->a() - color2_lab->a(), 2.f) + powf(color1_lab->b() - color2_lab->b(), 2.f) - powf(delta_c, 2.f));
	auto sc = 1.f + k1 * c1;
	auto sh = 1.f + k2 * c1;

	return sqrtf(powf(delta_l / (kL*1), 2.f) + powf(delta_c / (kC * sc), 2.f) + powf(delta_h / (kH * sh), 2.f));
}
