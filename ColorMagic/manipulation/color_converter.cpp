#include "stdafx.h"
#include "color_converter.h"

#define N_ROOT(x, n) std::powf(x, 1.f / n)

color_manipulation::reference_white color_manipulation::reference_white_presets::CIE_D50 = color_manipulation::reference_white::reference_white(96.42f, 100.f, 82.51f);
color_manipulation::reference_white color_manipulation::reference_white_presets::CIE_D55 = color_manipulation::reference_white::reference_white(95.68f, 100.f, 92.14f);
color_manipulation::reference_white color_manipulation::reference_white_presets::CIE_D65 = color_manipulation::reference_white::reference_white(95.04f, 100.f, 108.88f);
color_manipulation::reference_white color_manipulation::reference_white_presets::CIE_Standard_Illuminant_A = color_manipulation::reference_white::reference_white(109.85f, 100.f, 35.58f);
color_manipulation::reference_white color_manipulation::reference_white_presets::CIE_Standard_Illuminant_C = color_manipulation::reference_white::reference_white(98.07f, 100.f, 118.22f);
color_manipulation::reference_white color_manipulation::reference_white_presets::Equal_Energy_Radiator = color_manipulation::reference_white::reference_white(100.f, 100.f, 100.f);
color_manipulation::reference_white color_manipulation::reference_white_presets::ICC = color_manipulation::reference_white::reference_white(96.42f, 100.f, 82.49f);

color_space::icolor* color_manipulation::color_converter::convertTo(color_space::icolor* in_color, color_type out_color, reference_white reference)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::from_rgb_true(dynamic_cast<color_space::rgb_truecolor*>(in_color), out_color, reference);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::from_rgb_deep(dynamic_cast<color_space::rgb_deepcolor*>(in_color), out_color, reference);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::from_grey_true(dynamic_cast<color_space::grey_truecolor*>(in_color), out_color, reference);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::from_grey_deep(dynamic_cast<color_space::grey_deepcolor*>(in_color), out_color, reference);
	case color_type::CMYK:
		return color_manipulation::color_converter::from_cmyk(dynamic_cast<color_space::cmyk*>(in_color), out_color, reference);
	case color_type::HSV:
		return color_manipulation::color_converter::from_hsv(dynamic_cast<color_space::hsv*>(in_color), out_color, reference);
	case color_type::HSL:
		return color_manipulation::color_converter::from_hsl(dynamic_cast<color_space::hsl*>(in_color), out_color, reference);
	case color_type::XYZ:
		return color_manipulation::color_converter::from_xyz(dynamic_cast<color_space::xyz*>(in_color), out_color, reference);
	case color_type::LAB:
		return color_manipulation::color_converter::from_lab(dynamic_cast<color_space::lab*>(in_color), out_color, reference);
	default:
		return nullptr;
	}
}

color_space::rgb_deepcolor* color_manipulation::color_converter::rgb_true_to_rgb_deep(color_space::rgb_truecolor* color)
{
	return new color_space::rgb_deepcolor(color->red() / 255.f, color->green() / 255.f, color->blue() / 255.f, color->alpha() / 255.f);
}

color_space::grey_truecolor* color_manipulation::color_converter::rgb_true_to_grey_true(color_space::rgb_truecolor* color)
{
	auto avg = (color->red() + color->green() + color->blue()) / 3;
	return new color_space::grey_truecolor(avg, color->alpha());
}

color_space::grey_deepcolor* color_manipulation::color_converter::rgb_true_to_grey_deep(color_space::rgb_truecolor* color)
{
	auto grey_true =* color_manipulation::color_converter::rgb_true_to_grey_true(color);
	return new color_space::grey_deepcolor(grey_true.grey() / 255.f, grey_true.alpha() / 255.f);
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

color_space::lab* color_manipulation::color_converter::rgb_true_to_lab(color_space::rgb_truecolor* color, reference_white reference)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::rgb_true_to_rgb_deep(color), reference);
}

color_space::rgb_truecolor* color_manipulation::color_converter::rgb_deep_to_rgb_true(color_space::rgb_deepcolor* color)
{
	return new color_space::rgb_truecolor((unsigned char)roundf(color->red() * 255), (unsigned char)roundf(color->green() * 255), (unsigned char)roundf(color->blue() * 255), (unsigned char)roundf(color->alpha() * 255));
}

color_space::grey_truecolor* color_manipulation::color_converter::rgb_deep_to_grey_true(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_true_to_grey_true(color_manipulation::color_converter::rgb_deep_to_rgb_true(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::rgb_deep_to_grey_deep(color_space::rgb_deepcolor* color)
{
	auto avg = ((color->red() + color->green() + color->blue()) / 3.f);
	return new color_space::grey_deepcolor(avg, color->alpha());
}

color_space::cmyk* color_manipulation::color_converter::rgb_deep_to_cmyk(color_space::rgb_deepcolor* color)
{
	auto k = 1 - std::fmaxf(std::fmaxf(color->red(), color->green()), color->blue());
	auto c = (1 - color->red() - k) / (1.f - k);
	auto m = (1 - color->green() - k) / (1.f - k);
	auto y = (1 - color->blue() - k) / (1.f - k);
	return new color_space::cmyk(c, m, y, k);
}

color_space::hsv* color_manipulation::color_converter::rgb_deep_to_hsv(color_space::rgb_deepcolor* color)
{
	auto min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	auto max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new color_space::hsv(0.f, 0.f, min);
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
		return new color_space::hsv((float)hue, saturation, value);
	}
}

color_space::hsl* color_manipulation::color_converter::rgb_deep_to_hsl(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::hsv_to_hsl(color_manipulation::color_converter::rgb_deep_to_hsv(color));
}

color_space::xyz* color_manipulation::color_converter::rgb_deep_to_xyz(color_space::rgb_deepcolor* color)
{
	color = rgb_deep_to_linear_srgb_deep(color);
	auto x = color->red() * 0.4124564f + color->green() * 0.3575761f + color->blue() * 0.1804375f;
	auto y = color->red() * 0.2126729f + color->green() * 0.7151522f + color->blue() * 0.0721750f;
	auto z = color->red() * 0.0193339f + color->green() * 0.1191920f + color->blue() * 0.9503041f;
	return new color_space::xyz(x * 100.f, y * 100.f, z * 100.f);
}

color_space::lab* color_manipulation::color_converter::rgb_deep_to_lab(color_space::rgb_deepcolor* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_lab(color_manipulation::color_converter::rgb_deep_to_xyz(color), reference);
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

	return new color_space::rgb_deepcolor(components[0], components[1], components[2], color->alpha());
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

	return new color_space::rgb_deepcolor(components[0], components[1], components[2], color->alpha());
}

color_space::rgb_truecolor* color_manipulation::color_converter::grey_true_to_rgb_true(color_space::grey_truecolor* color)
{
	return new color_space::rgb_truecolor(color->grey(), color->alpha());
}

color_space::rgb_deepcolor* color_manipulation::color_converter::grey_true_to_rgb_deep(color_space::grey_truecolor* color)
{
	return new color_space::rgb_deepcolor(color->grey() / 255.f, color->alpha() / 255.f);
}

color_space::grey_deepcolor* color_manipulation::color_converter::grey_true_to_grey_deep(color_space::grey_truecolor* color)
{
	return new color_space::grey_deepcolor(color->grey() / 255.f, color->alpha() / 255.f);
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

color_space::lab* color_manipulation::color_converter::grey_true_to_lab(color_space::grey_truecolor* color, reference_white reference)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::grey_true_to_rgb_deep(color), reference);
}

color_space::rgb_truecolor* color_manipulation::color_converter::grey_deep_to_rgb_true(color_space::grey_deepcolor* color)
{
	return new color_space::rgb_truecolor((unsigned char)roundf(color->grey() * 255), (unsigned char)roundf(color->alpha() * 255));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::grey_deep_to_rgb_deep(color_space::grey_deepcolor* color)
{
	return new color_space::rgb_deepcolor(color->grey(), color->alpha());
}

color_space::grey_truecolor* color_manipulation::color_converter::grey_deep_to_grey_true(color_space::grey_deepcolor* color)
{
	return new color_space::grey_truecolor((unsigned char)roundf(color->grey() * 255), (unsigned char)roundf(color->alpha() * 255));
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

color_space::lab* color_manipulation::color_converter::grey_deep_to_lab(color_space::grey_deepcolor* color, reference_white reference)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::grey_deep_to_rgb_deep(color), reference);
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
	return new color_space::rgb_deepcolor(r, g, b);
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

color_space::lab* color_manipulation::color_converter::cmyk_to_lab(color_space::cmyk* color, reference_white reference)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::cmyk_to_rgb_deep(color), reference);
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
	return new color_space::rgb_deepcolor(r_temp + m, g_temp + m, b_temp + m);
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
	return new color_space::hsl(color->hue(), s, l);
}

color_space::xyz* color_manipulation::color_converter::hsv_to_xyz(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::hsv_to_lab(color_space::hsv* color, reference_white reference)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsv_to_rgb_deep(color), reference);
}

color_space::rgb_truecolor* color_manipulation::color_converter::hsl_to_rgb_true(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hsl_to_rgb_deep(color_space::hsl* color)
{
	auto chroma = (1.f - std::abs(2.f * color->lightness() - 1.f)) * color->saturation();
	auto h_temp = (int)(color->hue() / 60.f);
	auto x = chroma * (1.f - std::abs((h_temp % 2) - 1.f));
	auto m = color->lightness() - chroma / 2.f;
	float r_temp, g_temp, b_temp;
	if (h_temp >= 0 && h_temp <= 1)		{ r_temp = chroma;	g_temp = x;			b_temp = 0.f; }
	else if (h_temp > 1 && h_temp <= 2) { r_temp = x;		g_temp = chroma;	b_temp = 0.f; }
	else if (h_temp > 2 && h_temp <= 3) { r_temp = 0.f;		g_temp = chroma;	b_temp = x; }
	else if (h_temp > 3 && h_temp <= 4) { r_temp = 0.f;		g_temp = x;			b_temp = chroma; }
	else if (h_temp > 4 && h_temp <= 5) { r_temp = x;		g_temp = 0.f;		b_temp = chroma; }
	else if (h_temp > 5 && h_temp <= 6) { r_temp = chroma;	g_temp = 0.f;		b_temp = x; }
	else								{ r_temp = 0.f;		g_temp = 0.f;		b_temp = 0.f; }
	return new color_space::rgb_deepcolor(r_temp + m, g_temp + m, b_temp + m);
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
	return new color_space::hsv(color->hue(), s, v);
}

color_space::xyz* color_manipulation::color_converter::hsl_to_xyz(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::hsl_to_lab(color_space::hsl* color, reference_white reference)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsl_to_rgb_deep(color), reference);
}

color_space::rgb_truecolor* color_manipulation::color_converter::xyz_to_rgb_true(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::xyz_to_rgb_deep(color_space::xyz* color)
{
	auto x_temp = color->x() / 100.f;
	auto y_temp = color->y() / 100.f;
	auto z_temp = color->z() / 100.f;

	auto r = x_temp * 3.2404542f + y_temp * -1.5371385f + z_temp * 0.4985314f;
	auto g = x_temp * -0.9692660f + y_temp * 1.8760108f + z_temp * 0.0415560f;
	auto b = x_temp * 0.0556434f + y_temp * -0.2040259f + z_temp * 1.0572252f;
	auto rgb_deep = linear_srgb_deep_to_rgb_deep(new color_space::rgb_deepcolor(r, g, b));
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

color_space::lab* color_manipulation::color_converter::xyz_to_lab(color_space::xyz* color, reference_white reference)
{
	auto l = 116.f * xyz_to_lab_helper(color->y() / reference.y) - 16.f;
	auto a = 500.f * (xyz_to_lab_helper(color->x() / reference.x) - xyz_to_lab_helper(color->y() / reference.y));
	auto b = 200.f * (xyz_to_lab_helper(color->y() / reference.y) - xyz_to_lab_helper(color->z() / reference.z));
	return new color_space::lab(l, a, b);
}

color_space::rgb_truecolor* color_manipulation::color_converter::lab_to_rgb_true(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_rgb_true(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::lab_to_rgb_deep(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_rgb_deep(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::grey_truecolor* color_manipulation::color_converter::lab_to_grey_true(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_grey_true(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::grey_deepcolor* color_manipulation::color_converter::lab_to_grey_deep(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_grey_deep(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::cmyk* color_manipulation::color_converter::lab_to_cmyk(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_cmyk(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::hsv* color_manipulation::color_converter::lab_to_hsv(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_hsv(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::hsl* color_manipulation::color_converter::lab_to_hsl(color_space::lab* color, reference_white reference)
{
	return color_manipulation::color_converter::xyz_to_hsl(color_manipulation::color_converter::lab_to_xyz(color, reference));
}

color_space::xyz* color_manipulation::color_converter::lab_to_xyz(color_space::lab* color, reference_white reference)
{
	auto f_y = (color->luminance() + 16.f) / 116.f;
	auto y_temp = lab_to_xyz_helper(color->luminance(), true);
	auto x_temp = lab_to_xyz_helper((color->a() / 500.f) + f_y);
	auto z_temp = lab_to_xyz_helper(f_y - (color->b() / 200.f));
	
	return new color_space::xyz(x_temp * reference.x, y_temp * reference.y, z_temp * reference.z);
}

float color_manipulation::color_converter::xyz_to_lab_helper(float color_component)
{
	if (color_component > 216.f / 24389.f)
	{
		return N_ROOT(color_component, 3.f);
	}
	else
	{
		return ((24389.f / 27.f) * color_component + 16.f) / 116.f;
	}
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

float color_manipulation::color_converter::clamp_float(float in_float, float bottom, float top)
{
	return fminf(fmaxf(in_float, bottom), top);
}

color_space::icolor* color_manipulation::color_converter::from_rgb_true(color_space::rgb_truecolor* in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_rgb_deep(color_space::rgb_deepcolor * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_grey_true(color_space::grey_truecolor * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_grey_deep(color_space::grey_deepcolor * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_cmyk(color_space::cmyk * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_hsv(color_space::hsv * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_hsl(color_space::hsl * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_xyz(color_space::xyz * in_color, color_type out_type, reference_white reference)
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

color_space::icolor * color_manipulation::color_converter::from_lab(color_space::lab * in_color, color_type out_type, reference_white reference)
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
