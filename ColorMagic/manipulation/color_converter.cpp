#include "stdafx.h"
#include "color_converter.h"

#define N_ROOT(x, n) std::powf(x, 1.f / n)

color_space::color_base* color_manipulation::color_converter::convertTo(color_space::color_base* in_color, color_type out_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::from_rgb_true(dynamic_cast<color_space::rgb_truecolor*>(in_color), out_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::from_rgb_deep(dynamic_cast<color_space::rgb_deepcolor*>(in_color), out_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::from_grey_true(dynamic_cast<color_space::grey_truecolor*>(in_color), out_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::from_grey_deep(dynamic_cast<color_space::grey_deepcolor*>(in_color), out_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::from_cmyk(dynamic_cast<color_space::cmyk*>(in_color), out_color);
	case color_type::HSV:
		return color_manipulation::color_converter::from_hsv(dynamic_cast<color_space::hsv*>(in_color), out_color);
	case color_type::HSL:
		return color_manipulation::color_converter::from_hsl(dynamic_cast<color_space::hsl*>(in_color), out_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::from_xyz(dynamic_cast<color_space::xyz*>(in_color), out_color);
	case color_type::LAB:
		return color_manipulation::color_converter::from_lab(dynamic_cast<color_space::lab*>(in_color), out_color);
	default:
		return nullptr;
	}
}

color_space::rgb_deepcolor* color_manipulation::color_converter::rgb_true_to_rgb_deep(color_space::rgb_truecolor* color)
{
	return new color_space::rgb_deepcolor(color->red() / 255.f, color->green() / 255.f, color->blue() / 255.f, color->alpha() / 255.f, color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::rgb_true_to_grey_true(color_space::rgb_truecolor* color)
{
	auto avg = (color->red() + color->green() + color->blue()) / 3;
	return new color_space::grey_truecolor(avg, color->alpha(), color->get_rgb_color_space());
}

color_space::grey_deepcolor* color_manipulation::color_converter::rgb_true_to_grey_deep(color_space::rgb_truecolor* color)
{
	auto grey_true = *color_manipulation::color_converter::rgb_true_to_grey_true(color);
	return new color_space::grey_deepcolor(grey_true.grey() / 255.f, grey_true.alpha() / 255.f, color->get_rgb_color_space());
}

color_space::cmyk* color_manipulation::color_converter::rgb_true_to_cmyk(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::rgb_true_to_hsv(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::rgb_true_to_hsl(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::rgb_true_to_xyz(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::rgb_true_to_lab(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::rgb_deep_to_rgb_true(color_space::rgb_deepcolor* color)
{
	return new color_space::rgb_truecolor(roundf(color->red() * 255.f), roundf(color->green() * 255.f), roundf(color->blue() * 255.f), roundf(color->alpha() * 255.f), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::rgb_deep_to_grey_true(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_true_to_grey_true(color_manipulation::color_converter::rgb_deep_to_rgb_true(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::rgb_deep_to_grey_deep(color_space::rgb_deepcolor* color)
{
	auto avg = ((color->red() + color->green() + color->blue()) / 3.f);
	return new color_space::grey_deepcolor(avg, color->alpha(), color->get_rgb_color_space());
}

color_space::cmyk* color_manipulation::color_converter::rgb_deep_to_cmyk(color_space::rgb_deepcolor* color)
{
	auto k = 1 - std::fmaxf(std::fmaxf(color->red(), color->green()), color->blue());
	auto c = (1 - color->red() - k) / (1.f - k);
	auto m = (1 - color->green() - k) / (1.f - k);
	auto y = (1 - color->blue() - k) / (1.f - k);
	return new color_space::cmyk(c, m, y, k, color->alpha(), color->get_rgb_color_space());
}

color_space::hsv* color_manipulation::color_converter::rgb_deep_to_hsv(color_space::rgb_deepcolor* color)
{
	auto min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	auto max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new color_space::hsv(0.f, 0.f, min, color->alpha(), color->get_rgb_color_space());
	}
	else
	{
		float delta = max - min;
		int hue;
		if (max == color->red())
		{
			hue = 60 * (((int)((color->green() - color->blue()) / delta)) % 6);
		}
		else if (max == color->green())
		{
			hue = 60 * (int)(((color->blue() - color->red()) / delta) + 2);
		}
		else
		{
			hue = 60 * (int)(((color->red() - color->green()) / delta) + 4);
		}

		auto saturation = delta / max;
		auto value = max;
		return new color_space::hsv((float)hue, saturation, value, color->alpha(), color->get_rgb_color_space());
	}
}

color_space::hsl* color_manipulation::color_converter::rgb_deep_to_hsl(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::hsv_to_hsl(color_manipulation::color_converter::rgb_deep_to_hsv(color));
}

color_space::xyz* color_manipulation::color_converter::rgb_deep_to_xyz(color_space::rgb_deepcolor* color)
{
	color = rgb_deep_to_linear_srgb_deep(color);

	auto xyz_components = color->get_rgb_color_space()->get_transform_matrix() * color->get_component_vector();
	return new color_space::xyz(xyz_components[0], xyz_components[1], xyz_components[2], color->alpha(), color->get_rgb_color_space());
}

color_space::lab* color_manipulation::color_converter::rgb_deep_to_lab(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::xyz_to_lab(color_manipulation::color_converter::rgb_deep_to_xyz(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::rgb_deep_to_linear_srgb_deep(color_space::rgb_deepcolor* color)
{
	float components[3] = { color->red(), color->green(), color->blue() };
	for (auto i = 0; i < 3; ++i)
	{
		if (components[i] <= 0.04045f)
		{
			components[i] /= 12.92f;
		}
		else
		{
			components[i] = std::powf((components[i] + 0.055f) / 1.055f, 2.4f);
		}
	}

	return new color_space::rgb_deepcolor(components[0], components[1], components[2], color->alpha(), color->get_rgb_color_space());
}

color_space::rgb_deepcolor* color_manipulation::color_converter::linear_srgb_deep_to_rgb_deep(color_space::rgb_deepcolor* color)
{
	float components[3] = { color->red(), color->green(), color->blue() };
	for (auto i = 0; i < 3; ++i)
	{
		if (components[i] <= 0.0031308f)
		{
			components[i] *= 12.92f;
		}
		else
		{
			components[i] = N_ROOT(components[i] * 1.055f, 2.4f) - 0.055f;
		}
	}

	return new color_space::rgb_deepcolor(components[0], components[1], components[2], color->alpha(), color->get_rgb_color_space());
}

color_space::rgb_truecolor* color_manipulation::color_converter::grey_true_to_rgb_true(color_space::grey_truecolor* color)
{
	return new color_space::rgb_truecolor(color->grey(), color->alpha(), color->get_rgb_color_space());
}

color_space::rgb_deepcolor* color_manipulation::color_converter::grey_true_to_rgb_deep(color_space::grey_truecolor* color)
{
	return new color_space::rgb_deepcolor(color->grey() / 255.f, color->alpha() / 255.f, color->get_rgb_color_space());
}

color_space::grey_deepcolor* color_manipulation::color_converter::grey_true_to_grey_deep(color_space::grey_truecolor* color)
{
	return new color_space::grey_deepcolor(color->grey() / 255.f, color->alpha() / 255.f, color->get_rgb_color_space());
}

color_space::cmyk* color_manipulation::color_converter::grey_true_to_cmyk(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::grey_true_to_hsv(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::grey_true_to_hsl(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::grey_true_to_xyz(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::grey_true_to_lab(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::grey_deep_to_rgb_true(color_space::grey_deepcolor* color)
{
	return new color_space::rgb_truecolor(roundf(color->grey() * 255.f), roundf(color->alpha() * 255.f), color->get_rgb_color_space());
}

color_space::rgb_deepcolor* color_manipulation::color_converter::grey_deep_to_rgb_deep(color_space::grey_deepcolor* color)
{
	return new color_space::rgb_deepcolor(color->grey(), color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::grey_deep_to_grey_true(color_space::grey_deepcolor* color)
{
	return new color_space::grey_truecolor(roundf(color->grey() * 255.f), roundf(color->alpha() * 255.f), color->get_rgb_color_space());
}

color_space::cmyk* color_manipulation::color_converter::grey_deep_to_cmyk(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::grey_deep_to_hsv(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::grey_deep_to_hsl(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::grey_deep_to_xyz(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::grey_deep_to_lab(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::cmyk_to_rgb_true(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::cmyk_to_rgb_deep(color_space::cmyk* color)
{
	auto r = (1 - color->cyan()) * (1 - color->black());
	auto g = (1 - color->magenta()) * (1 - color->black());
	auto b = (1 - color->yellow()) * (1 - color->black());
	return new color_space::rgb_deepcolor(r, g, b, color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::cmyk_to_grey_true(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_true(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::cmyk_to_grey_deep(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_deep(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::cmyk_to_hsv(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::cmyk_to_hsl(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::cmyk_to_xyz(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::cmyk_to_lab(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::hsv_to_rgb_true(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hsv_to_rgb_deep(color_space::hsv* color)
{
	auto chroma = color->value() * color->saturation();
	auto h_temp = (int)(color->hue() / 60.f);
	auto x = chroma * (1 - std::abs((h_temp % 2) - 1));
	auto m = color->value() - chroma;
	float r_temp, g_temp, b_temp;
	if (h_temp >= 0 && h_temp <= 1) { r_temp = chroma;	g_temp = x;			b_temp = 0.f; }
	else if (h_temp > 1 && h_temp <= 2) { r_temp = x;		g_temp = chroma;	b_temp = 0.f; }
	else if (h_temp > 2 && h_temp <= 3) { r_temp = 0.f;		g_temp = chroma;	b_temp = x; }
	else if (h_temp > 3 && h_temp <= 4) { r_temp = 0.f;		g_temp = x;			b_temp = chroma; }
	else if (h_temp > 4 && h_temp <= 5) { r_temp = x;		g_temp = 0.f;		b_temp = chroma; }
	else if (h_temp > 5 && h_temp <= 6) { r_temp = chroma;	g_temp = 0.f;		b_temp = x; }
	else { r_temp = 0.f;		g_temp = 0.f;		b_temp = 0.f; }
	return new color_space::rgb_deepcolor(r_temp + m, g_temp + m, b_temp + m, color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::hsv_to_grey_true(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_true(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::hsv_to_grey_deep(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_deep(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::cmyk* color_manipulation::color_converter::hsv_to_cmyk(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::hsv_to_hsl(color_space::hsv* color)
{
	auto l = (2.f - color->saturation()) * color->value();
	auto s = color->saturation() * color->value();
	s /= (l <= 1.f) ? l : 2.f - l;
	l /= 2.f;
	return new color_space::hsl(color->hue(), s, l, color->alpha(), color->get_rgb_color_space());
}

color_space::xyz* color_manipulation::color_converter::hsv_to_xyz(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::hsv_to_lab(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::hsl_to_rgb_true(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hsl_to_rgb_deep(color_space::hsl* color)
{
	if (color->lightness() == 0.f) return new color_space::rgb_deepcolor(0.f, 0.f, color->get_rgb_color_space());

	float temp_h = color->hue() / 360.f;

	float var1, var2;
	if (color->lightness() < 0.5f)
	{
		var1 = color->lightness() * (1.f + color->saturation());
	}
	else
	{
		var1 = color->lightness() + color->saturation() - (color->lightness() * color->saturation());
	}
	var2 = 2.f * color->lightness() - var1;

	auto r = hsl_to_rgb_helper(var1, var2, temp_h + 1.f / 3.f);
	auto g = hsl_to_rgb_helper(var1, var2, temp_h);
	auto b = hsl_to_rgb_helper(var1, var2, temp_h - 1.f / 3.f);

	return new color_space::rgb_deepcolor(r, g, b, color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::hsl_to_grey_true(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_true(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::hsl_to_grey_deep(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_deep(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::cmyk* color_manipulation::color_converter::hsl_to_cmyk(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::hsl_to_hsv(color_space::hsl* color)
{
	auto l_temp = color->lightness() * 2.f;
	auto m_sat = color->saturation() * (l_temp <= 1.f) ? l_temp : (2.f - l_temp);
	auto v = (l_temp + m_sat) / 2.f;
	auto s = (2.f * m_sat) / (l_temp + m_sat);
	return new color_space::hsv(color->hue(), s, v, color->alpha(), color->get_rgb_color_space());
}

color_space::xyz* color_manipulation::color_converter::hsl_to_xyz(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::hsl_to_lab(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::xyz_to_rgb_true(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::xyz_to_rgb_deep(color_space::xyz* color)
{
	auto rgb_components = color->get_rgb_color_space()->get_inverse_transform_matrix() * color->get_component_vector();

	auto rgb_deep = linear_srgb_deep_to_rgb_deep(new color_space::rgb_deepcolor(rgb_components[0], rgb_components[1], rgb_components[2], 0, color->get_rgb_color_space()));
	rgb_deep->alpha(transform_range(color->alpha(), color->get_component_min(), color->get_component_max(), rgb_deep->get_component_min(), rgb_deep->get_component_max()));
	rgb_deep->red(round_float_to_n_decimals(clamp_float(rgb_deep->red(), 0.f, 1.f), 1));
	rgb_deep->green(round_float_to_n_decimals(clamp_float(rgb_deep->green(), 0.f, 1.f), 1));
	rgb_deep->blue(round_float_to_n_decimals(clamp_float(rgb_deep->blue(), 0.f, 1.f), 1));
	return rgb_deep;
}

color_space::grey_truecolor* color_manipulation::color_converter::xyz_to_grey_true(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_true(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::xyz_to_grey_deep(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_deep(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::cmyk* color_manipulation::color_converter::xyz_to_cmyk(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::xyz_to_hsv(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::xyz_to_hsl(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::xyz_to_lab(color_space::xyz* color)
{
	auto func_x = xyz_to_lab_helper(color->x() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_x());
	auto func_y = xyz_to_lab_helper(color->y() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_y());
	auto func_z = xyz_to_lab_helper(color->z() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_z());

	auto l = 116.f * func_y - 16.f;
	auto a = 500.f * (func_x - func_y);
	auto b = 200.f * (func_y - func_z);

	auto lab = new color_space::lab(l, a, b, 0, color->get_rgb_color_space());
	lab->alpha(transform_range(color->alpha(), color->get_component_min(), color->get_component_max(), lab->get_component_min(), lab->get_component_max()));
	return lab;
}

color_space::rgb_truecolor* color_manipulation::color_converter::lab_to_rgb_true(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_rgb_true(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::lab_to_rgb_deep(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_rgb_deep(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::grey_truecolor* color_manipulation::color_converter::lab_to_grey_true(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_grey_true(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::lab_to_grey_deep(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_grey_deep(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::cmyk* color_manipulation::color_converter::lab_to_cmyk(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_cmyk(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::hsv* color_manipulation::color_converter::lab_to_hsv(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_hsv(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::hsl* color_manipulation::color_converter::lab_to_hsl(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_hsl(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::xyz* color_manipulation::color_converter::lab_to_xyz(color_space::lab* color)
{
	auto f_y = (color->luminance() + 16.f) / 116.f;
	auto y_temp = lab_to_xyz_helper(color->luminance(), true);
	auto x_temp = lab_to_xyz_helper((color->a() / 500.f) + f_y);
	auto z_temp = lab_to_xyz_helper(f_y - (color->b() / 200.f));

	auto xyz = new color_space::xyz(x_temp * color->get_rgb_color_space()->get_white_point()->get_tristimulus_x(), y_temp * color->get_rgb_color_space()->get_white_point()->get_tristimulus_y(), z_temp * color->get_rgb_color_space()->get_white_point()->get_tristimulus_z(), 0.f, color->get_rgb_color_space());
	xyz->alpha(transform_range(color->alpha(), color->get_component_min(), color->get_component_max(), xyz->get_component_min(), xyz->get_component_max()));
	return xyz;
}

float color_manipulation::color_converter::hsl_to_rgb_helper(float var1, float var2, float var3)
{
	if (var3 < 0.f) var3 += 1.f;
	if (var3 > 1.f) var3 -= 1.f;

	if (var3 < 1.f / 6.f)
	{
		return var2 + (var1 - var2) * 6.f * var3;
	}

	if (var3 < 0.5f)
	{
		return var1;
	}

	if (var3 < 2.f / 3.f)
	{
		return var2 + ((var1 - var2) * ((2.f / 3.f) - var3) * 6.f);
	}

	return var2;
}

float color_manipulation::color_converter::xyz_to_lab_helper(float color_component)
{
	return color_component > (216.f / 24389.f) ? N_ROOT(color_component, 3.f) : ((24389.f / 27.f) * color_component + 16.f) / 116.f;
}

float color_manipulation::color_converter::lab_to_xyz_helper(float color_component, bool out_y_component)
{
	auto epsilon = 216.f / 24389.f;
	auto k = 24389.f / 27.f;

	if (out_y_component)
	{
		if (color_component > epsilon * k)
		{
			return std::powf(((color_component + 16.f) / 116.f), 3.f);
		}
		else
		{
			return color_component / k;
		}
	}
	else
	{
		auto component = std::powf(color_component, 3.f);
		if (component > epsilon)
		{
			return component;
		}
		else
		{
			return (116.f * color_component - 16.f) / k;
		}
	}
}

float color_manipulation::color_converter::round_float_to_n_decimals(float in_float, float n)
{
	auto factor = powf(10.f, n);
	return ((int)(in_float * factor + 0.5f) / factor);
}

float color_manipulation::color_converter::clamp_float(float in_float, float min, float max)
{
	return fminf(fmaxf(in_float, min), max);
}

float color_manipulation::color_converter::transform_range(float value, float old_min, float old_max, float new_min, float new_max)
{
	auto old_range = old_max - old_min;
	auto new_range = new_max - new_min;
	return (((value - old_min) * new_range) / old_range) + new_min;
}

color_space::color_base* color_manipulation::color_converter::from_rgb_true(color_space::rgb_truecolor* in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return in_color;
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_true_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::rgb_true_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::rgb_true_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::rgb_true_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::rgb_true_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::rgb_true_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::rgb_true_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::rgb_true_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_rgb_deep(color_space::rgb_deepcolor * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_deep_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return in_color;
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::rgb_deep_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::rgb_deep_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::rgb_deep_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::rgb_deep_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::rgb_deep_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::rgb_deep_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_grey_true(color_space::grey_truecolor * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::grey_true_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::grey_true_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return in_color;
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_true_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::grey_true_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::grey_true_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::grey_true_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::grey_true_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::grey_true_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_grey_deep(color_space::grey_deepcolor * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::grey_deep_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::grey_deep_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_deep_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return in_color;
	case color_type::CMYK:
		return color_manipulation::color_converter::grey_deep_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::grey_deep_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::grey_deep_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::grey_deep_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::grey_deep_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_cmyk(color_space::cmyk * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::cmyk_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::cmyk_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::cmyk_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::cmyk_to_grey_deep(in_color);
	case color_type::CMYK:
		return in_color;
	case color_type::HSV:
		return color_manipulation::color_converter::cmyk_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::cmyk_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::cmyk_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::cmyk_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_hsv(color_space::hsv * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::hsv_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::hsv_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::hsv_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::hsv_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::hsv_to_cmyk(in_color);
	case color_type::HSV:
		return in_color;
	case color_type::HSL:
		return color_manipulation::color_converter::hsv_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::hsv_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::hsv_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_hsl(color_space::hsl * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::hsl_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::hsl_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::hsl_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::hsl_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::hsl_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::hsl_to_hsv(in_color);
	case color_type::HSL:
		return in_color;
	case color_type::XYZ:
		return color_manipulation::color_converter::hsl_to_xyz(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::hsl_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_xyz(color_space::xyz * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::xyz_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::xyz_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::xyz_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::xyz_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::xyz_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::xyz_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::xyz_to_hsl(in_color);
	case color_type::XYZ:
		return in_color;
	case color_type::LAB:
		return color_manipulation::color_converter::xyz_to_lab(in_color);
	default:
		return nullptr;
	}
}

color_space::color_base * color_manipulation::color_converter::from_lab(color_space::lab * in_color, color_type out_type)
{
	switch (out_type)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::lab_to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::lab_to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::lab_to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::lab_to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::lab_to_cmyk(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::lab_to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::lab_to_hsl(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::lab_to_xyz(in_color);
	case color_type::LAB:
		return in_color;
	default:
		return nullptr;
	}
}

color_space::rgb_truecolor * color_manipulation::color_converter::to_rgb_true(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return dynamic_cast<color_space::rgb_truecolor*>(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_rgb_true(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_rgb_true(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_rgb_true(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_rgb_true(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_rgb_true(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_rgb_true(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_rgb_true(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_rgb_true(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::rgb_deepcolor * color_manipulation::color_converter::to_rgb_deep(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_rgb_deep(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return dynamic_cast<color_space::rgb_deepcolor*>(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_rgb_deep(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_rgb_deep(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_rgb_deep(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_rgb_deep(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_rgb_deep(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_rgb_deep(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_rgb_deep(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::grey_truecolor * color_manipulation::color_converter::to_grey_true(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_grey_true(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_grey_true(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return dynamic_cast<color_space::grey_truecolor*>(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_grey_true(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_grey_true(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_grey_true(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_grey_true(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_grey_true(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_grey_true(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::grey_deepcolor * color_manipulation::color_converter::to_grey_deep(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_grey_deep(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_grey_deep(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_grey_deep(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return dynamic_cast<color_space::grey_deepcolor*>(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_grey_deep(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_grey_deep(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_grey_deep(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_grey_deep(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_grey_deep(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::cmyk * color_manipulation::color_converter::to_cmyk(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_cmyk(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_cmyk(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_cmyk(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_cmyk(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return dynamic_cast<color_space::cmyk*>(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_cmyk(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_cmyk(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_cmyk(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_cmyk(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::hsv * color_manipulation::color_converter::to_hsv(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_hsv(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_hsv(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_hsv(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_hsv(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_hsv(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return dynamic_cast<color_space::hsv*>(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_hsv(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_hsv(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_hsv(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::hsl * color_manipulation::color_converter::to_hsl(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_hsl(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_hsl(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_hsl(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_hsl(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_hsl(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_hsl(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return dynamic_cast<color_space::hsl*>(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_hsl(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_hsl(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::xyz * color_manipulation::color_converter::to_xyz(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_xyz(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_xyz(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_xyz(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_xyz(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_xyz(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_xyz(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_xyz(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return dynamic_cast<color_space::xyz*>(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_xyz(dynamic_cast<color_space::lab*>(in_color));
	default:
		return nullptr;
	}
}

color_space::lab * color_manipulation::color_converter::to_lab(color_space::color_base * in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_lab(dynamic_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_lab(dynamic_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_lab(dynamic_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_lab(dynamic_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_lab(dynamic_cast<color_space::cmyk*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_lab(dynamic_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_lab(dynamic_cast<color_space::hsl*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_lab(dynamic_cast<color_space::xyz*>(in_color));
	case color_type::LAB:
		return dynamic_cast<color_space::lab*>(in_color);
	default:
		return nullptr;
	}
}

