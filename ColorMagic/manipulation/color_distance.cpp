#include "stdafx.h"
#include "color_distance.h"
#include "color_converter.h"

float color_manipulation::color_distance::euclidean_distance_squared(color_space::color_base * color1, color_space::color_base * color2)
{
	if (color1 == color2) return 0.f; // both colors have same type and are equal

	auto color1_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color1, color_type::RGB_DEEP));
	auto color2_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color2, color_type::RGB_DEEP));

	if (color1_rgb_d == color2_rgb_d) return 0.f; // after conversion to same color space both colors are equal

	float squared_distance = 0.f;
	for (std::vector<float>::size_type i = 0; i < color1_rgb_d->get_component_vector().size(); ++i)
	{
		squared_distance += powf(color1_rgb_d->get_component_vector()[i] - color2_rgb_d->get_component_vector()[i], 2.f);
	}

	return squared_distance;
}

float color_manipulation::color_distance::euclidean_distance(color_space::color_base * color1, color_space::color_base * color2)
{
	if (color1 == color2) return 0.f; // both colors have same type and are equal

	return sqrtf(euclidean_distance_squared(color1, color2));
}

float color_manipulation::color_distance::euclidean_distance_weighted(color_space::color_base * color1, color_space::color_base * color2)
{
	if (color1 == color2) return 0.f; // both colors have same type and are equal

	auto color1_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color1, color_type::RGB_DEEP));
	auto color2_rgb_d = dynamic_cast<color_space::rgb_deepcolor*>(color_manipulation::color_converter::convertTo(color2, color_type::RGB_DEEP));

	if (color1_rgb_d == color2_rgb_d) return 0.f; // after conversion to same color space both colors are equal

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
	if (color1 == color2) return 0.f; // both colors have same type and are equal
	
	auto color1_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color1, color_type::LAB));
	auto color2_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color2, color_type::LAB));

	if (color1_lab == color2_lab) return 0.f; // after conversion to same color space both colors are equal

	float squared_distance = 0.f;
	for (std::vector<float>::size_type i = 0; i < color1_lab->get_component_vector().size(); ++i)
	{
		squared_distance += powf(color1_lab->get_component_vector()[i] - color2_lab->get_component_vector()[i], 2.f);
	}

	return sqrtf(squared_distance);
}

float color_manipulation::color_distance::cielab_delta_e_cie94(color_space::color_base * color1, color_space::color_base * color2, float kL, float k1, float k2, float kC, float kH)
{
	// Equation source: https://en.wikipedia.org/wiki/Color_difference
	if (color1 == color2) return 0.f; // both colors have same type and are equal
	
	auto color1_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color1, color_type::LAB));
	auto color2_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color2, color_type::LAB));

	if (color1_lab == color2_lab) return 0.f; // after conversion to same color space both colors are equal

	auto delta_l = color1_lab->luminance() - color2_lab->luminance();
	auto c1 = sqrtf(powf(color1_lab->a(), 2.f) + powf(color1_lab->b(), 2.f));
	auto c2 = sqrtf(powf(color2_lab->a(), 2.f) + powf(color2_lab->b(), 2.f));
	auto delta_c = c1 - c2;
	auto delta_h = sqrtf(powf(color1_lab->a() - color2_lab->a(), 2.f) + powf(color1_lab->b() - color2_lab->b(), 2.f) - powf(delta_c, 2.f));
	auto sc = 1.f + k1 * c1;
	auto sh = 1.f + k2 * c1;

	return sqrtf(powf(delta_l / (kL * 1), 2.f) + powf(delta_c / (kC * sc), 2.f) + powf(delta_h / (kH * sh), 2.f));
}

float color_manipulation::color_distance::cielab_delta_e_cie00(color_space::color_base * color1, color_space::color_base * color2, float kL, float k1, float k2, float kC, float kH)
{
	// Equation source: https://en.wikipedia.org/wiki/Color_difference
	if (color1 == color2) return 0.f; // both colors have same type and are equal
	
	auto color1_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color1, color_type::LAB));
	auto color2_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color2, color_type::LAB));

	if (color1_lab == color2_lab) return 0.f; // after conversion to same color space both colors are equal

	auto avg_l = (color1_lab->luminance() + color2_lab->luminance()) / 2.f;
	auto C1 = sqrtf(powf(color1_lab->a(), 2.f) + powf(color1_lab->b(), 2.f));
	auto C2 = sqrtf(powf(color2_lab->a(), 2.f) + powf(color2_lab->b(), 2.f));
	auto avg_c = (C1 + C2) / 2.f;
	auto sqrt_c_pow = sqrtf(powf(avg_c, 7.f) / (powf(avg_c, 7.f) + powf(25.f, 7.f)));

	auto temp_a1 = color1_lab->a() + color1_lab->a() / 2.f * (1.f - sqrt_c_pow);
	auto temp_a2 = color2_lab->a() + color2_lab->a() / 2.f * (1.f - sqrt_c_pow);
	auto temp_c1 = sqrtf(powf(temp_a1, 2.f) + powf(color1_lab->b(), 2.f));
	auto temp_c2 = sqrtf(powf(temp_a2, 2.f) + powf(color2_lab->b(), 2.f));
	auto temp_avg_c = (temp_c1 + temp_c2) / 2.f;

	auto h1 = (int)(to_deg(atan2f(color1_lab->b(), temp_a1))) % 360;
	if (h1 < 0.f) h1 += 360;
	auto h2 = (int)(to_deg(atan2f(color2_lab->b(), temp_a2))) % 360;
	if (h2 < 0.f) h2 += 360;

	float H;
	if (abs(h1 - h2) > 180.f)
	{
		H = (h1 + h2 + 360.f) / 2.f;
	}
	else
	{
		H = (h1 + h2) / 2.f;
	}

	int delta_h;
	if (abs(h2 - h1) <= 180.f)
	{
		delta_h = h2 - h1;
	}
	else if (abs(h2 - h1) > 180.f && h2 <= h1)
	{
		delta_h = h2 - h1 + 360;
	}
	else
	{
		delta_h = h2 - h1 - 360;
	}

	auto delta_L = color2_lab->luminance() - color1_lab->luminance();
	auto delta_C = C2 - C1;
	auto delta_H = 2.f * sqrtf(C1 * C2) * sinf(to_rad(delta_h / 2.f));

	auto sC = 1.f + k1 * avg_c;
	auto sH = 1.f + k2 * avg_c * (1.f - 0.17f * cosf(to_rad(H - 30.f)) + 0.24f * cosf(to_rad(2.f * H)) + 0.32f * cosf(to_rad(3.f * H + 6.f)) - 0.2f * cosf(to_rad(4.f * H - 63.f)));
	auto sL = 1.f + ((k2 * powf(avg_l - 50.f, 2.f)) / sqrtf(20.f + powf(avg_l - 50.f, 2.f)));
	auto rt = -2.f * sqrt_c_pow * sinf(to_rad(60.f * expf(powf(-(H - 275.f) / 25.f, 2.f))));

	return sqrtf(powf(delta_L / (kL * sL), 2.f) + powf(delta_C / (kC * sC), 2.f) + powf(delta_H / (kH * sH), 2.f) + rt * (delta_C / (kC * sC)) * (delta_H / (kH * sH)));
}

float color_manipulation::color_distance::cmc_delta_e_lc84(color_space::color_base * color1, color_space::color_base * color2, float lightness, float chroma)
{
	// Equation source: https://en.wikipedia.org/wiki/Color_difference
	if (color1 == color2) return 0.f; // both colors have same type and are equal
	
	auto color1_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color1, color_type::LAB));
	auto color2_lab = dynamic_cast<color_space::lab*>(color_manipulation::color_converter::convertTo(color2, color_type::LAB));

	if (color1_lab == color2_lab) return 0.f; // after conversion to same color space both colors are equal

	auto C1 = sqrtf(powf(color1_lab->a(), 2.f) + powf(color1_lab->b(), 2.f));
	auto C2 = sqrtf(powf(color2_lab->a(), 2.f) + powf(color2_lab->b(), 2.f));
	auto delta_C = C1 - C2;
	auto delta_a = color1_lab->a() - color2_lab->a();
	auto delta_b = color1_lab->b() - color2_lab->b();
	auto delta_H = sqrtf(powf(delta_a, 2.f) + powf(delta_b, 2.f) - powf(delta_C, 2.f));
	auto delta_L = color1_lab->luminance() - color2_lab->luminance();

	auto H = to_deg(atan2(color1_lab->b(), color1_lab->a()));
	if (H < 0) H += 360.f;

	auto F = sqrtf(powf(C1, 4.f) / (powf(C1, 4.f) + 1900.f));
	float T;
	if (H > 164.f && H <= 345.f)
	{
		T = 0.56f + abs(0.2f * cosf(to_rad(H + 168.f)));
	}
	else
	{
		T = 0.36f + abs(0.4f * cosf(to_rad(H + 35.f)));
	}

	float sL;
	if (color1_lab->luminance() < 16.f)
	{
		sL = 0.511f;
	}
	else
	{
		sL = (0.040975f * color1_lab->luminance()) / (1.f + 0.01765f * color1_lab->luminance());
	}

	auto sC = (float)((0.0638f * C1) / (1.f + 0.0131f * C1) + 0.638f);
	auto sH = sC * (F * T + 1.f - F);

	return sqrtf(powf(delta_L / (lightness * sL), 2.f) + powf(delta_C / (chroma * sC), 2.f) + powf(delta_H / sH, 2.f));
}

float color_manipulation::color_distance::to_rad(float degree)
{
	return degree * ((float)M_PI / 180.f);
}

float color_manipulation::color_distance::to_deg(float radians)
{
	return radians * (180.f / (float)M_PI);
}
