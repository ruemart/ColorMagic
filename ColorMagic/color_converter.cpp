#include "stdafx.h"
#include "color_converter.h"

#define N_ROOT(x, n) std::powf(x, 1.f / n)

ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_D50 = ColorManipulation::reference_white::reference_white(96.42f, 100.f, 82.51f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_D55 = ColorManipulation::reference_white::reference_white(95.68f, 100.f, 92.14f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_D65 = ColorManipulation::reference_white::reference_white(95.04f, 100.f, 108.88f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_Standard_Illuminant_A = ColorManipulation::reference_white::reference_white(109.85f, 100.f, 35.58f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_Standard_Illuminant_C = ColorManipulation::reference_white::reference_white(98.07f, 100.f, 118.22f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::Equal_Energy_Radiator = ColorManipulation::reference_white::reference_white(100.f, 100.f, 100.f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::ICC = ColorManipulation::reference_white::reference_white(96.42f, 100.f, 82.49f);

ColorSpaces::icolor* ColorManipulation::color_converter::convertTo(ColorSpaces::icolor* in_color, ColorSpaces::color_type out_color, reference_white reference)
{
	switch (in_color->get_color_type())
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::from_rgb_true(dynamic_cast<ColorSpaces::rgb_truecolor*>(in_color), out_color, reference);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::from_rgb_deep(dynamic_cast<ColorSpaces::rgb_deepcolor*>(in_color), out_color, reference);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::from_grey_true(dynamic_cast<ColorSpaces::grey_truecolor*>(in_color), out_color, reference);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::from_grey_deep(dynamic_cast<ColorSpaces::grey_deepcolor*>(in_color), out_color, reference);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::from_cmyk(dynamic_cast<ColorSpaces::cmyk*>(in_color), out_color, reference);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::from_hsv(dynamic_cast<ColorSpaces::hsv*>(in_color), out_color, reference);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::from_hsl(dynamic_cast<ColorSpaces::hsl*>(in_color), out_color, reference);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::from_xyz(dynamic_cast<ColorSpaces::xyz*>(in_color), out_color, reference);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::from_lab(dynamic_cast<ColorSpaces::lab*>(in_color), out_color, reference);
	default:
		return nullptr;
	}
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::rgb_true_to_rgb_deep(ColorSpaces::rgb_truecolor* color)
{
	return new ColorSpaces::rgb_deepcolor(color->red() / 255.f, color->green() / 255.f, color->blue() / 255.f, color->alpha() / 255.f);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::rgb_true_to_grey_true(ColorSpaces::rgb_truecolor* color)
{
	auto avg = (color->red() + color->green() + color->blue()) / 3;
	return new ColorSpaces::grey_truecolor(avg, color->alpha());
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::rgb_true_to_grey_deep(ColorSpaces::rgb_truecolor* color)
{
	auto grey_true =* ColorManipulation::color_converter::rgb_true_to_grey_true(color);
	return new ColorSpaces::grey_deepcolor(grey_true.grey() / 255.f, grey_true.alpha() / 255.f);
}

ColorSpaces::cmyk* ColorManipulation::color_converter::rgb_true_to_cmyk(ColorSpaces::rgb_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::hsv* ColorManipulation::color_converter::rgb_true_to_hsv(ColorSpaces::rgb_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsv(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::hsl* ColorManipulation::color_converter::rgb_true_to_hsl(ColorSpaces::rgb_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsl(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::xyz* ColorManipulation::color_converter::rgb_true_to_xyz(ColorSpaces::rgb_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::rgb_true_to_lab(ColorSpaces::rgb_truecolor* color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorSpaces::rgb_deepcolor* color)
{
	return new ColorSpaces::rgb_truecolor((unsigned char)roundf(color->red() * 255), (unsigned char)roundf(color->green() * 255), (unsigned char)roundf(color->blue() * 255), (unsigned char)roundf(color->alpha() * 255));
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorSpaces::rgb_deepcolor* color)
{
	return ColorManipulation::color_converter::rgb_true_to_grey_true(ColorManipulation::color_converter::rgb_deep_to_rgb_true(color));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorSpaces::rgb_deepcolor* color)
{
	auto avg = ((color->red() + color->green() + color->blue()) / 3.f);
	return new ColorSpaces::grey_deepcolor(avg, color->alpha());
}

ColorSpaces::cmyk* ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorSpaces::rgb_deepcolor* color)
{
	auto k = 1 - std::fmaxf(std::fmaxf(color->red(), color->green()), color->blue());
	auto c = (1 - color->red() - k) / (1.f - k);
	auto m = (1 - color->green() - k) / (1.f - k);
	auto y = (1 - color->blue() - k) / (1.f - k);
	return new ColorSpaces::cmyk(c, m, y, k);
}

ColorSpaces::hsv* ColorManipulation::color_converter::rgb_deep_to_hsv(ColorSpaces::rgb_deepcolor* color)
{
	auto min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	auto max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new ColorSpaces::hsv(0.f, 0.f, min);
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
		return new ColorSpaces::hsv(hue, saturation, value);
	}
}

ColorSpaces::hsl* ColorManipulation::color_converter::rgb_deep_to_hsl(ColorSpaces::rgb_deepcolor* color)
{
	return ColorManipulation::color_converter::hsv_to_hsl(ColorManipulation::color_converter::rgb_deep_to_hsv(color));
}

ColorSpaces::xyz* ColorManipulation::color_converter::rgb_deep_to_xyz(ColorSpaces::rgb_deepcolor* color)
{
	color = rgb_deep_to_linear_srgb_deep(color);
	auto x = color->red() * 0.4124564f + color->green() * 0.3575761f + color->blue() * 0.1804375f;
	auto y = color->red() * 0.2126729f + color->green() * 0.7151522f + color->blue() * 0.0721750f;
	auto z = color->red() * 0.0193339f + color->green() * 0.1191920f + color->blue() * 0.9503041f;
	return new ColorSpaces::xyz(x * 100.f, y * 100.f, z * 100.f);
}

ColorSpaces::lab* ColorManipulation::color_converter::rgb_deep_to_lab(ColorSpaces::rgb_deepcolor* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_lab(ColorManipulation::color_converter::rgb_deep_to_xyz(color), reference);
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::rgb_deep_to_linear_srgb_deep(ColorSpaces::rgb_deepcolor* color)
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

	return new ColorSpaces::rgb_deepcolor(components[0], components[1], components[2], color->alpha());
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::linear_srgb_deep_to_rgb_deep(ColorSpaces::rgb_deepcolor* color)
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

	return new ColorSpaces::rgb_deepcolor(components[0], components[1], components[2], color->alpha());
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::grey_true_to_rgb_true(ColorSpaces::grey_truecolor* color)
{
	return new ColorSpaces::rgb_truecolor(color->grey(), color->alpha());
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::grey_true_to_rgb_deep(ColorSpaces::grey_truecolor* color)
{
	return new ColorSpaces::rgb_deepcolor(color->grey() / 255.f, color->alpha() / 255.f);
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::grey_true_to_grey_deep(ColorSpaces::grey_truecolor* color)
{
	return new ColorSpaces::grey_deepcolor(color->grey() / 255.f, color->alpha() / 255.f);
}

ColorSpaces::cmyk* ColorManipulation::color_converter::grey_true_to_cmyk(ColorSpaces::grey_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::grey_true_to_rgb_deep(color));
}

ColorSpaces::hsv* ColorManipulation::color_converter::grey_true_to_hsv(ColorSpaces::grey_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsv(ColorManipulation::color_converter::grey_true_to_rgb_deep(color));
}

ColorSpaces::hsl* ColorManipulation::color_converter::grey_true_to_hsl(ColorSpaces::grey_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsl(ColorManipulation::color_converter::grey_true_to_rgb_deep(color));
}

ColorSpaces::xyz* ColorManipulation::color_converter::grey_true_to_xyz(ColorSpaces::grey_truecolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::grey_true_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::grey_true_to_lab(ColorSpaces::grey_truecolor* color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::grey_true_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::grey_deep_to_rgb_true(ColorSpaces::grey_deepcolor* color)
{
	return new ColorSpaces::rgb_truecolor((unsigned char)roundf(color->grey() * 255), (unsigned char)roundf(color->alpha() * 255));
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::grey_deep_to_rgb_deep(ColorSpaces::grey_deepcolor* color)
{
	return new ColorSpaces::rgb_deepcolor(color->grey(), color->alpha());
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::grey_deep_to_grey_true(ColorSpaces::grey_deepcolor* color)
{
	return new ColorSpaces::grey_truecolor((unsigned char)roundf(color->grey() * 255), (unsigned char)roundf(color->alpha() * 255));
}

ColorSpaces::cmyk* ColorManipulation::color_converter::grey_deep_to_cmyk(ColorSpaces::grey_deepcolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::grey_deep_to_rgb_deep(color));
}

ColorSpaces::hsv* ColorManipulation::color_converter::grey_deep_to_hsv(ColorSpaces::grey_deepcolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsv(ColorManipulation::color_converter::grey_deep_to_rgb_deep(color));
}

ColorSpaces::hsl* ColorManipulation::color_converter::grey_deep_to_hsl(ColorSpaces::grey_deepcolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsl(ColorManipulation::color_converter::grey_deep_to_rgb_deep(color));
}

ColorSpaces::xyz* ColorManipulation::color_converter::grey_deep_to_xyz(ColorSpaces::grey_deepcolor* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::grey_deep_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::grey_deep_to_lab(ColorSpaces::grey_deepcolor* color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::grey_deep_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::cmyk_to_rgb_true(ColorSpaces::cmyk* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorManipulation::color_converter::cmyk_to_rgb_deep(color));
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::cmyk_to_rgb_deep(ColorSpaces::cmyk* color)
{
	auto r = (1 - color->cyan()) * (1 - color->black());
	auto g = (1 - color->magenta()) * (1 - color->black());
	auto b = (1 - color->yellow()) * (1 - color->black());
	return new ColorSpaces::rgb_deepcolor(r, g, b);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::cmyk_to_grey_true(ColorSpaces::cmyk* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorManipulation::color_converter::cmyk_to_rgb_deep(color));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::cmyk_to_grey_deep(ColorSpaces::cmyk* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorManipulation::color_converter::cmyk_to_rgb_deep(color));
}

ColorSpaces::hsv* ColorManipulation::color_converter::cmyk_to_hsv(ColorSpaces::cmyk* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsv(ColorManipulation::color_converter::cmyk_to_rgb_deep(color));
}

ColorSpaces::hsl* ColorManipulation::color_converter::cmyk_to_hsl(ColorSpaces::cmyk* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsl(ColorManipulation::color_converter::cmyk_to_rgb_deep(color));
}

ColorSpaces::xyz* ColorManipulation::color_converter::cmyk_to_xyz(ColorSpaces::cmyk* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::cmyk_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::cmyk_to_lab(ColorSpaces::cmyk* color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::cmyk_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::hsv_to_rgb_true(ColorSpaces::hsv* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorManipulation::color_converter::hsv_to_rgb_deep(color));
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::hsv_to_rgb_deep(ColorSpaces::hsv* color)
{
	auto chroma = color->value * color->saturation();
	auto h_temp = (int)(color->hue() / 60.f);
	auto x = chroma * (1 - std::abs((h_temp % 2) - 1));
	auto m = color->value - chroma;
	float r_temp, g_temp, b_temp;
	if (h_temp >= 0 && h_temp <= 1) { r_temp = chroma;	g_temp = x;			b_temp = 0.f; }
	else if (h_temp > 1 && h_temp <= 2) { r_temp = x;		g_temp = chroma;	b_temp = 0.f; }
	else if (h_temp > 2 && h_temp <= 3) { r_temp = 0.f;		g_temp = chroma;	b_temp = x; }
	else if (h_temp > 3 && h_temp <= 4) { r_temp = 0.f;		g_temp = x;			b_temp = chroma; }
	else if (h_temp > 4 && h_temp <= 5) { r_temp = x;		g_temp = 0.f;		b_temp = chroma; }
	else if (h_temp > 5 && h_temp <= 6) { r_temp = chroma;	g_temp = 0.f;		b_temp = x; }
	else { r_temp = 0.f;		g_temp = 0.f;		b_temp = 0.f; }
	return new ColorSpaces::rgb_deepcolor(r_temp + m, g_temp + m, b_temp + m);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::hsv_to_grey_true(ColorSpaces::hsv* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorManipulation::color_converter::hsv_to_rgb_deep(color));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::hsv_to_grey_deep(ColorSpaces::hsv* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorManipulation::color_converter::hsv_to_rgb_deep(color));
}

ColorSpaces::cmyk* ColorManipulation::color_converter::hsv_to_cmyk(ColorSpaces::hsv* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::hsv_to_rgb_deep(color));
}

ColorSpaces::hsl* ColorManipulation::color_converter::hsv_to_hsl(ColorSpaces::hsv* color)
{
	auto l = (2.f - color->saturation()) * color->value;
	auto s = color->saturation() * color->value;
	s /= (l <= 1.f) ? l : 2.f - l;
	l /= 2.f;
	return new ColorSpaces::hsl(color->hue(), s, l);
}

ColorSpaces::xyz* ColorManipulation::color_converter::hsv_to_xyz(ColorSpaces::hsv* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::hsv_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::hsv_to_lab(ColorSpaces::hsv* color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::hsv_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::hsl_to_rgb_true(ColorSpaces::hsl* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorManipulation::color_converter::hsl_to_rgb_deep(color));
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::hsl_to_rgb_deep(ColorSpaces::hsl* color)
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
	return new ColorSpaces::rgb_deepcolor(r_temp + m, g_temp + m, b_temp + m);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::hsl_to_grey_true(ColorSpaces::hsl* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorManipulation::color_converter::hsl_to_rgb_deep(color));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::hsl_to_grey_deep(ColorSpaces::hsl* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorManipulation::color_converter::hsl_to_rgb_deep(color));
}

ColorSpaces::cmyk* ColorManipulation::color_converter::hsl_to_cmyk(ColorSpaces::hsl* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::hsl_to_rgb_deep(color));
}

ColorSpaces::hsv* ColorManipulation::color_converter::hsl_to_hsv(ColorSpaces::hsl* color)
{
	auto l_temp = color->lightness() * 2.f;
	auto m_sat = color->saturation() * (l_temp <= 1.f) ? l_temp : (2.f - l_temp);
	auto v = (l_temp + m_sat) / 2.f;
	auto s = (2.f * m_sat) / (l_temp + m_sat);
	return new ColorSpaces::hsv(color->hue(), s, v);
}

ColorSpaces::xyz* ColorManipulation::color_converter::hsl_to_xyz(ColorSpaces::hsl* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::hsl_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::hsl_to_lab(ColorSpaces::hsl* color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::hsl_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::xyz_to_rgb_true(ColorSpaces::xyz* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorManipulation::color_converter::xyz_to_rgb_deep(color));
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::xyz_to_rgb_deep(ColorSpaces::xyz* color)
{
	auto x_temp = color->x() / 100.f;
	auto y_temp = color->y() / 100.f;
	auto z_temp = color->z() / 100.f;

	auto r = x_temp * 3.2404542f + y_temp * -1.5371385f + z_temp * 0.4985314f;
	auto g = x_temp * -0.9692660f + y_temp * 1.8760108f + z_temp * 0.0415560f;
	auto b = x_temp * 0.0556434f + y_temp * -0.2040259f + z_temp * 1.0572252f;
	auto rgb_deep = linear_srgb_deep_to_rgb_deep(new ColorSpaces::rgb_deepcolor(r, g, b));
	rgb_deep->red = round_float_to_n_decimals(clamp_float(rgb_deep->red, 0.f, 1.f), 1);
	rgb_deep->green = round_float_to_n_decimals(clamp_float(rgb_deep->green, 0.f, 1.f), 1);
	rgb_deep->blue = round_float_to_n_decimals(clamp_float(rgb_deep->blue, 0.f, 1.f), 1);
	return rgb_deep;
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::xyz_to_grey_true(ColorSpaces::xyz* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorManipulation::color_converter::xyz_to_rgb_deep(color));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::xyz_to_grey_deep(ColorSpaces::xyz* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorManipulation::color_converter::xyz_to_rgb_deep(color));
}

ColorSpaces::cmyk* ColorManipulation::color_converter::xyz_to_cmyk(ColorSpaces::xyz* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::xyz_to_rgb_deep(color));
}

ColorSpaces::hsv* ColorManipulation::color_converter::xyz_to_hsv(ColorSpaces::xyz* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsv(ColorManipulation::color_converter::xyz_to_rgb_deep(color));
}

ColorSpaces::hsl* ColorManipulation::color_converter::xyz_to_hsl(ColorSpaces::xyz* color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsl(ColorManipulation::color_converter::xyz_to_rgb_deep(color));
}

ColorSpaces::lab* ColorManipulation::color_converter::xyz_to_lab(ColorSpaces::xyz* color, reference_white reference)
{
	auto l = 116.f * xyz_to_lab_helper(color->y() / reference.y) - 16.f;
	auto a = 500.f * (xyz_to_lab_helper(color->x() / reference.x) - xyz_to_lab_helper(color->y() / reference.y));
	auto b = 200.f * (xyz_to_lab_helper(color->y() / reference.y) - xyz_to_lab_helper(color->z() / reference.z));
	return new ColorSpaces::lab(l, a, b);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::lab_to_rgb_true(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_rgb_true(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::lab_to_rgb_deep(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_rgb_deep(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::lab_to_grey_true(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_grey_true(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::lab_to_grey_deep(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_grey_deep(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::cmyk* ColorManipulation::color_converter::lab_to_cmyk(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_cmyk(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::hsv* ColorManipulation::color_converter::lab_to_hsv(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_hsv(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::hsl* ColorManipulation::color_converter::lab_to_hsl(ColorSpaces::lab* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_hsl(ColorManipulation::color_converter::lab_to_xyz(color, reference));
}

ColorSpaces::xyz* ColorManipulation::color_converter::lab_to_xyz(ColorSpaces::lab* color, reference_white reference)
{
	auto f_y = (color->luminance() + 16.f) / 116.f;
	auto y_temp = lab_to_xyz_helper(color->luminance(), true);
	auto x_temp = lab_to_xyz_helper((color->a() / 500.f) + f_y);
	auto z_temp = lab_to_xyz_helper(f_y - (color->b() / 200.f));
	
	return new ColorSpaces::xyz(x_temp * reference.x, y_temp * reference.y, z_temp * reference.z);
}

float ColorManipulation::color_converter::xyz_to_lab_helper(float color_component)
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

float ColorManipulation::color_converter::lab_to_xyz_helper(float color_component, bool out_y_component)
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

float ColorManipulation::color_converter::round_float_to_n_decimals(float in_float, int n)
{
	auto factor = pow(10, n);
	return ((int)(in_float * factor + 0.5f) / factor);
}

float ColorManipulation::color_converter::clamp_float(float in_float, float bottom, float top)
{
	return fminf(fmaxf(in_float, bottom), top);
}

ColorSpaces::icolor* ColorManipulation::color_converter::from_rgb_true(ColorSpaces::rgb_truecolor* in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return in_color;
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::rgb_true_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::rgb_true_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::rgb_true_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::rgb_true_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::rgb_true_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::rgb_true_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::rgb_true_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::rgb_true_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_rgb_deep(ColorSpaces::rgb_deepcolor * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::rgb_deep_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return in_color;
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::rgb_deep_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::rgb_deep_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::rgb_deep_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::rgb_deep_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::rgb_deep_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::rgb_deep_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::rgb_deep_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_grey_true(ColorSpaces::grey_truecolor * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::grey_true_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::grey_true_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return in_color;
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::grey_true_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::grey_true_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::grey_true_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::grey_true_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::grey_true_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::grey_true_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_grey_deep(ColorSpaces::grey_deepcolor * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::grey_deep_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::grey_deep_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::grey_deep_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return in_color;
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::grey_deep_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::grey_deep_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::grey_deep_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::grey_deep_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::grey_deep_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_cmyk(ColorSpaces::cmyk * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::cmyk_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::cmyk_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::cmyk_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::cmyk_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return in_color;
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::cmyk_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::cmyk_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::cmyk_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::cmyk_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_hsv(ColorSpaces::hsv * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::hsv_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::hsv_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::hsv_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::hsv_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::hsv_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return in_color;
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::hsv_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::hsv_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::hsv_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_hsl(ColorSpaces::hsl * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::hsl_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::hsl_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::hsl_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::hsl_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::hsl_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::hsl_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return in_color;
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::hsl_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::hsl_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_xyz(ColorSpaces::xyz * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::xyz_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::xyz_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::xyz_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::xyz_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::xyz_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::xyz_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::xyz_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return in_color;
	case ColorSpaces::color_type::LAB:
		return ColorManipulation::color_converter::xyz_to_lab(in_color);
	default:
		return nullptr;
	}
}

ColorSpaces::icolor * ColorManipulation::color_converter::from_lab(ColorSpaces::lab * in_color, ColorSpaces::color_type out_type, reference_white reference)
{
	switch (out_type)
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::lab_to_rgb_true(in_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::lab_to_rgb_deep(in_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::lab_to_grey_true(in_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::lab_to_grey_deep(in_color);
	case ColorSpaces::color_type::CMYK:
		return ColorManipulation::color_converter::lab_to_cmyk(in_color);
	case ColorSpaces::color_type::HSV:
		return ColorManipulation::color_converter::lab_to_hsv(in_color);
	case ColorSpaces::color_type::HSL:
		return ColorManipulation::color_converter::lab_to_hsl(in_color);
	case ColorSpaces::color_type::XYZ:
		return ColorManipulation::color_converter::lab_to_xyz(in_color);
	case ColorSpaces::color_type::LAB:
		return in_color;
	default:
		return nullptr;
	}
}
