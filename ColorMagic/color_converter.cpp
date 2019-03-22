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

ColorSpaces::icolor* ColorManipulation::color_converter::convertTo(ColorSpaces::icolor* in_color, ColorSpaces::color_type out_color)
{
	switch (in_color->get_color_type())
	{
	case ColorSpaces::color_type::RGB_TRUE:
		return ColorManipulation::color_converter::from_rgb_true(dynamic_cast<ColorSpaces::rgb_truecolor*>(in_color), out_color);
	case ColorSpaces::color_type::RGB_DEEP:
		return ColorManipulation::color_converter::from_rgb_deep(dynamic_cast<ColorSpaces::rgb_deepcolor*>(in_color), out_color);
	case ColorSpaces::color_type::GREY_TRUE:
		return ColorManipulation::color_converter::from_grey_true(dynamic_cast<ColorSpaces::grey_truecolor*>(in_color), out_color);
	case ColorSpaces::color_type::GREY_DEEP:
		return ColorManipulation::color_converter::from_grey_deep(dynamic_cast<ColorSpaces::grey_deepcolor*>(in_color), out_color);
	case ColorSpaces::color_type::CMYK:
		break;
	case ColorSpaces::color_type::HSV:
		break;
	case ColorSpaces::color_type::HSL:
		break;
	case ColorSpaces::color_type::XYZ:
		break;
	case ColorSpaces::color_type::LAB:
		break;
	default:
		return nullptr;
	}
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::hexcode_to_rgb_true(std::string hex_code)
{
	if (hex_code[0] == '#')
	{
		hex_code = hex_code.substr(1);
	}

	unsigned short r, g, b, a;
	if (hex_code.length() == 6)
	{
		scanf_s(hex_code.c_str(), "%02x%02x%02x", &r, &g, &b);
		a = 255;
	}
	else if (hex_code.length() == 8)
	{
		scanf_s(hex_code.c_str(), "%02x%02x%02x", &r, &g, &b, &a);
	}
	else
	{
		throw std::invalid_argument("Wrong hex code format. Use one of the following formats: #AARRGGBB, #RRGGBB, AARRGGBB, RRGGBB");
	}

	return new ColorSpaces::rgb_truecolor((unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a);
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::rgb_true_to_rgb_deep(ColorSpaces::rgb_truecolor* color)
{
	return new ColorSpaces::rgb_deepcolor(color->m_red / 255.f, color->m_green / 255.f, color->m_blue / 255.f, color->m_alpha / 255.f);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::rgb_true_to_grey_true(ColorSpaces::rgb_truecolor* color)
{
	auto avg = (color->m_red + color->m_green + color->m_blue) / 3;
	return new ColorSpaces::grey_truecolor(avg, color->m_alpha);
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::rgb_true_to_grey_deep(ColorSpaces::rgb_truecolor* color)
{
	auto grey_true =* ColorManipulation::color_converter::rgb_true_to_grey_true(color);
	return new ColorSpaces::grey_deepcolor(grey_true.m_grey / 255.f, grey_true.m_alpha / 255.f);
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
	return new ColorSpaces::rgb_truecolor((unsigned char)color->m_red * 255, (unsigned char)color->m_green * 255, (unsigned char)color->m_blue * 255, (unsigned char)color->m_alpha * 255);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorSpaces::rgb_deepcolor* color)
{
	return ColorManipulation::color_converter::rgb_true_to_grey_true(ColorManipulation::color_converter::rgb_deep_to_rgb_true(color));
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorSpaces::rgb_deepcolor* color)
{
	auto avg = ((color->m_red + color->m_green + color->m_blue) / 3.f);
	return new ColorSpaces::grey_deepcolor(avg, color->m_alpha);
}

ColorSpaces::cmyk* ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorSpaces::rgb_deepcolor* color)
{
	auto k = 1 - std::fmaxf(std::fmaxf(color->m_red, color->m_green), color->m_blue);
	auto c = (1 - color->m_red - k) / (1.f - k);
	auto m = (1 - color->m_green - k) / (1.f - k);
	auto y = (1 - color->m_blue - k) / (1.f - k);
	return new ColorSpaces::cmyk(c, m, y, k);
}

ColorSpaces::hsv* ColorManipulation::color_converter::rgb_deep_to_hsv(ColorSpaces::rgb_deepcolor* color)
{
	auto min = std::fmin(std::fmin(color->m_red, color->m_green), color->m_blue);
	auto max = std::fmax(std::fmax(color->m_red, color->m_green), color->m_blue);
	if (max == min) // red = green = blue
	{
		return new ColorSpaces::hsv(0.f, 0.f, min);
	}
	else
	{
		float delta;
		if (min == color->m_red) delta = color->m_green - color->m_blue;
		else if (min == color->m_green) delta = color->m_blue - color->m_red;
		else delta = color->m_red - color->m_green;

		float temp_h;
		if (min == color->m_red) temp_h = 3.f;
		else if (min == color->m_green) temp_h = 1.f;
		else temp_h = 5.f;

		auto hue = 60.f * (temp_h - delta / (max - min));
		auto saturation = (max - min) / max;
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
	auto x = color->m_red * 0.4124564f + color->m_green * 0.3575761f + color->m_blue * 0.1804375f;
	auto y = color->m_red * 0.2126729f + color->m_green * 0.7151522f + color->m_blue * 0.0721750f;
	auto z = color->m_red * 0.0193339f + color->m_green * 0.1191920f + color->m_blue * 0.9503041f;
	return new ColorSpaces::xyz(x, y, z);
}

ColorSpaces::lab* ColorManipulation::color_converter::rgb_deep_to_lab(ColorSpaces::rgb_deepcolor* color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_lab(ColorManipulation::color_converter::rgb_deep_to_xyz(color), reference);
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::rgb_deep_to_linear_srgb_deep(ColorSpaces::rgb_deepcolor* color)
{
	float components[3] = { color->m_red, color->m_green, color->m_blue };
	for (auto component : components)
	{
		if (component <= 0.04045f)
		{
			component /= 12.92f;
		}
		else
		{
			component = std::powf((component + 0.055f) / 1.055f, 2.4f);
		}
	}

	return new ColorSpaces::rgb_deepcolor(components[0], components[1], components[2], color->m_alpha);
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::linear_srgb_deep_to_rgb_deep(ColorSpaces::rgb_deepcolor* color)
{
	float components[3] = { color->m_red, color->m_green, color->m_blue };
	for (auto component : components)
	{
		if (component <= 0.0031308f)
		{
			component *= 12.92f;
		}
		else
		{
			component = N_ROOT(component * 1.055f, 2.4f) - 0.055f;
		}
	}

	return new ColorSpaces::rgb_deepcolor(components[0], components[1], components[2], color->m_alpha);
}

ColorSpaces::rgb_truecolor* ColorManipulation::color_converter::grey_true_to_rgb_true(ColorSpaces::grey_truecolor* color)
{
	return new ColorSpaces::rgb_truecolor(color->m_grey, color->m_alpha);
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::grey_true_to_rgb_deep(ColorSpaces::grey_truecolor* color)
{
	return new ColorSpaces::rgb_deepcolor(color->m_grey / 255.f, color->m_alpha / 255.f);
}

ColorSpaces::grey_deepcolor* ColorManipulation::color_converter::grey_true_to_grey_deep(ColorSpaces::grey_truecolor* color)
{
	return new ColorSpaces::grey_deepcolor(color->m_grey / 255.f, color->m_alpha / 255.f);
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
	return new ColorSpaces::rgb_truecolor((unsigned char)color->m_grey * 255, (unsigned char)color->m_alpha * 255);
}

ColorSpaces::rgb_deepcolor* ColorManipulation::color_converter::grey_deep_to_rgb_deep(ColorSpaces::grey_deepcolor* color)
{
	return new ColorSpaces::rgb_deepcolor(color->m_grey, color->m_alpha);
}

ColorSpaces::grey_truecolor* ColorManipulation::color_converter::grey_deep_to_grey_true(ColorSpaces::grey_deepcolor* color)
{
	return new ColorSpaces::grey_truecolor((unsigned char)color->m_grey * 255, (unsigned char)color->m_alpha * 255);
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
	auto r = (1 - color->m_cyan) * (1 - color->m_black);
	auto g = (1 - color->m_magenta) * (1 - color->m_black);
	auto b = (1 - color->m_yellow) * (1 - color->m_black);
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
	auto chroma = color->m_value * color->m_saturation;
	auto h_temp = (int)(color->m_hue / 60.f);
	auto x = chroma * (1 - std::abs((h_temp % 2) - 1));
	auto m = color->m_value - chroma;
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
	auto l = (2.f - color->m_saturation) * color->m_value;
	auto s = color->m_saturation * color->m_value;
	s /= (l <= 1.f) ? l : 2.f - l;
	l /= 2.f;
	return new ColorSpaces::hsl(color->m_hue, s, l);
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
	auto chroma = (1.f - std::abs(2.f * color->m_lightness - 1.f)) * color->m_saturation;
	auto h_temp = (int)(color->m_hue / 60.f);
	auto x = chroma * (1.f - std::abs((h_temp % 2) - 1.f));
	auto m = color->m_lightness - chroma / 2.f;
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
	color->m_lightness *= 2.f;
	color->m_saturation *= (color->m_lightness <= 1.f) ? color->m_lightness : (2.f - color->m_lightness);
	auto v = (color->m_lightness + color->m_saturation) / 2.f;
	auto s = (2.f * color->m_saturation) / (color->m_lightness + color->m_saturation);
	return new ColorSpaces::hsv(color->m_hue, s, v);
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
	auto r = color->m_x * 3.2404542f + color->m_y * -1.5371385f + color->m_z * 0.4985314f;
	auto g = color->m_x * -0.9692660f + color->m_y * 1.8760108f + color->m_z * 0.0415560f;
	auto b = color->m_x * 0.0556434f + color->m_y * -0.2040259f + color->m_z * 1.0572252f;
	return linear_srgb_deep_to_rgb_deep(new ColorSpaces::rgb_deepcolor(r, g, b));
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
	auto l = 116.f * xyz_to_lab_helper(color->m_y / reference.y) - 16.f;
	auto a = 500.f * (xyz_to_lab_helper(color->m_x / reference.x) - xyz_to_lab_helper(color->m_y / reference.y));
	auto b = 200.f * (xyz_to_lab_helper(color->m_y / reference.y) - xyz_to_lab_helper(color->m_z / reference.z));
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
	auto f_y = (color->m_luminance + 16.f) / 116.f;
	auto y_temp = lab_to_xyz_helper(color->m_luminance, true);
	auto x_temp = lab_to_xyz_helper((color->m_a / 500.f) + f_y);
	auto z_temp = lab_to_xyz_helper(f_y - (color->m_b / 200.f));
	
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

ColorSpaces::icolor* ColorManipulation::color_converter::from_rgb_true(ColorSpaces::rgb_truecolor* in_color, ColorSpaces::color_type out_type)
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

ColorSpaces::icolor * ColorManipulation::color_converter::from_rgb_deep(ColorSpaces::rgb_deepcolor * in_color, ColorSpaces::color_type out_type)
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

ColorSpaces::icolor * ColorManipulation::color_converter::from_grey_true(ColorSpaces::grey_truecolor * in_color, ColorSpaces::color_type out_type)
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

ColorSpaces::icolor * ColorManipulation::color_converter::from_grey_deep(ColorSpaces::grey_deepcolor * in_color, ColorSpaces::color_type out_type)
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
