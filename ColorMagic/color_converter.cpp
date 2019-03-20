#include "stdafx.h"
#include "color_converter.h"


ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_D50 = ColorManipulation::reference_white::reference_white(96.42f, 100.f, 82.51f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_D55 = ColorManipulation::reference_white::reference_white(95.68f, 100.f, 92.14f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_D65 = ColorManipulation::reference_white::reference_white(95.04f, 100.f, 108.88f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_Standard_Illuminant_A = ColorManipulation::reference_white::reference_white(109.85f, 100.f, 35.58f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::CIE_Standard_Illuminant_C = ColorManipulation::reference_white::reference_white(98.07f, 100.f, 118.22f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::Equal_Energy_Radiator = ColorManipulation::reference_white::reference_white(100.f, 100.f, 100.f);
ColorManipulation::reference_white ColorManipulation::reference_white_presets::ICC = ColorManipulation::reference_white::reference_white(96.42f, 100.f, 82.49f);


ColorSpaces::rgb_truecolor ColorManipulation::color_converter::hexcode_to_rgb_true(std::string hex_code)
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

	return ColorSpaces::rgb_truecolor((unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a);
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::rgb_true_to_rgb_deep(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::rgb_deepcolor(color.m_red / 255.f, color.m_green / 255.f, color.m_blue / 255.f, color.m_alpha / 255.f);
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::rgb_true_to_grey_true(ColorSpaces::rgb_truecolor color)
{
	auto avg = (color.m_red + color.m_green + color.m_blue) / 3;
	return ColorSpaces::grey_truecolor(avg, color.m_alpha);
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::rgb_true_to_grey_deep(ColorSpaces::rgb_truecolor color)
{
	auto grey_true = ColorManipulation::color_converter::rgb_true_to_grey_true(color);
	return ColorSpaces::grey_deepcolor(grey_true.m_grey / 255.f, grey_true.m_alpha / 255.f);
}

ColorSpaces::cmyk ColorManipulation::color_converter::rgb_true_to_cmyk(ColorSpaces::rgb_truecolor color)
{
	return ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::hsv ColorManipulation::color_converter::rgb_true_to_hsv(ColorSpaces::rgb_truecolor color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsv(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::hsl ColorManipulation::color_converter::rgb_true_to_hsl(ColorSpaces::rgb_truecolor color)
{
	return ColorManipulation::color_converter::rgb_deep_to_hsl(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::xyz ColorManipulation::color_converter::rgb_true_to_xyz(ColorSpaces::rgb_truecolor color)
{
	return ColorManipulation::color_converter::rgb_deep_to_xyz(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color));
}

ColorSpaces::lab ColorManipulation::color_converter::rgb_true_to_lab(ColorSpaces::rgb_truecolor color, reference_white reference)
{
	return ColorManipulation::color_converter::rgb_deep_to_lab(ColorManipulation::color_converter::rgb_true_to_rgb_deep(color), reference);
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::rgb_truecolor(color.m_red * 255.f, color.m_green * 255.f, color.m_blue * 255.f, color.m_alpha * 255.f);
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorSpaces::rgb_deepcolor color)
{
	return ColorManipulation::color_converter::rgb_true_to_grey_true(ColorManipulation::color_converter::rgb_deep_to_rgb_true(color));
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorSpaces::rgb_deepcolor color)
{
	auto avg = ((color.m_red + color.m_green + color.m_blue) / 3.f);
	return ColorSpaces::grey_deepcolor(avg, color.m_alpha);
}

ColorSpaces::cmyk ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorSpaces::rgb_deepcolor color)
{
	auto k = 1 - std::fmaxf(std::fmaxf(color.m_red, color.m_green), color.m_blue);
	auto c = (1 - color.m_red - k) / (1.f - k);
	auto m = (1 - color.m_green - k) / (1.f - k);
	auto y = (1 - color.m_blue - k) / (1.f - k);
	return ColorSpaces::cmyk(c, m, y, k);
}

ColorSpaces::hsv ColorManipulation::color_converter::rgb_deep_to_hsv(ColorSpaces::rgb_deepcolor color)
{
	auto min = std::fmin(std::fmin(color.m_red, color.m_green), color.m_blue);
	auto max = std::fmax(std::fmax(color.m_red, color.m_green), color.m_blue);
	if (max == min) // red = green = blue
	{
		return ColorSpaces::hsv(0.f, 0.f, min);
	}
	else
	{
		float delta;
		if (min == color.m_red) delta = color.m_green - color.m_blue;
		else if (min == color.m_green) delta = color.m_blue - color.m_red;
		else delta = color.m_red - color.m_green;

		float temp_h;
		if (min == color.m_red) temp_h = 3.f;
		else if (min == color.m_green) temp_h = 1.f;
		else temp_h = 5.f;

		auto hue = 60.f * (temp_h - delta / (max - min));
		auto saturation = (max - min) / max;
		auto value = max;
		return ColorSpaces::hsv(hue, saturation, value);
	}
}

ColorSpaces::hsl ColorManipulation::color_converter::rgb_deep_to_hsl(ColorSpaces::rgb_deepcolor color)
{
	return ColorManipulation::color_converter::hsv_to_hsl(ColorManipulation::color_converter::rgb_deep_to_hsv(color));
}

ColorSpaces::xyz ColorManipulation::color_converter::rgb_deep_to_xyz(ColorSpaces::rgb_deepcolor color)
{
	color = rgb_deep_to_linear_srgb_deep(color);
	auto x = color.m_red * 0.4124564f + color.m_green * 0.3575761f + color.m_blue * 0.1804375f;
	auto y = color.m_red * 0.2126729f + color.m_green * 0.7151522f + color.m_blue * 0.0721750f;
	auto z = color.m_red * 0.0193339f + color.m_green * 0.1191920f + color.m_blue * 0.9503041f;
	return ColorSpaces::xyz(x, y, z);
}

ColorSpaces::lab ColorManipulation::color_converter::rgb_deep_to_lab(ColorSpaces::rgb_deepcolor color, reference_white reference)
{
	return ColorManipulation::color_converter::xyz_to_lab(ColorManipulation::color_converter::rgb_deep_to_xyz(color), reference);
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::rgb_deep_to_linear_srgb_deep(ColorSpaces::rgb_deepcolor color)
{
	float components[3] = { color.m_red, color.m_green, color.m_blue };
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

	return ColorSpaces::rgb_deepcolor(components[0], components[1], components[2], color.m_alpha);
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::linear_srgb_deep_to_rgb_deep(ColorSpaces::rgb_deepcolor color)
{
	float components[3] = { color.m_red, color.m_green, color.m_blue };
	for (auto component : components)
	{
		if (component <= 0.0031308f)
		{
			component *= 12.92f;
		}
		else
		{
			component = std::powf(component * 1.055f, 1.f / 2.4f) - 0.055f;
		}
	}

	return ColorSpaces::rgb_deepcolor(components[0], components[1], components[2], color.m_alpha);
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::grey_true_to_rgb_true(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::grey_true_to_rgb_deep(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::grey_true_to_grey_deep(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::grey_true_to_cmyk(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::grey_true_to_hsv(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::grey_true_to_hsl(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::grey_true_to_xyz(ColorSpaces::grey_truecolor color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::grey_true_to_lab(ColorSpaces::grey_truecolor color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::grey_deep_to_rgb_true(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::grey_deep_to_rgb_deep(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::grey_deep_to_grey_true(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::grey_deep_to_cmyk(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::grey_deep_to_hsv(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::grey_deep_to_hsl(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::grey_deep_to_xyz(ColorSpaces::grey_deepcolor color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::grey_deep_to_lab(ColorSpaces::grey_deepcolor color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::cmyk_to_rgb_true(ColorSpaces::cmyk color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::cmyk_to_rgb_deep(ColorSpaces::cmyk color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::cmyk_to_grey_true(ColorSpaces::cmyk color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::cmyk_to_grey_deep(ColorSpaces::cmyk color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::hsv ColorManipulation::color_converter::cmyk_to_hsv(ColorSpaces::cmyk color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::cmyk_to_hsl(ColorSpaces::cmyk color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::cmyk_to_xyz(ColorSpaces::cmyk color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::cmyk_to_lab(ColorSpaces::cmyk color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::hsv_to_rgb_true(ColorSpaces::hsv color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::hsv_to_rgb_deep(ColorSpaces::hsv color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::hsv_to_grey_true(ColorSpaces::hsv color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::hsv_to_grey_deep(ColorSpaces::hsv color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::hsv_to_cmyk(ColorSpaces::hsv color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsl ColorManipulation::color_converter::hsv_to_hsl(ColorSpaces::hsv color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::hsv_to_xyz(ColorSpaces::hsv color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::hsv_to_lab(ColorSpaces::hsv color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::hsl_to_rgb_true(ColorSpaces::hsl color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::hsl_to_rgb_deep(ColorSpaces::hsl color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::hsl_to_grey_true(ColorSpaces::hsl color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::hsl_to_grey_deep(ColorSpaces::hsl color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::hsl_to_cmyk(ColorSpaces::hsl color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::hsl_to_hsv(ColorSpaces::hsl color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::xyz ColorManipulation::color_converter::hsl_to_xyz(ColorSpaces::hsl color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::hsl_to_lab(ColorSpaces::hsl color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::xyz_to_rgb_true(ColorSpaces::xyz color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::xyz_to_rgb_deep(ColorSpaces::xyz color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::xyz_to_grey_true(ColorSpaces::xyz color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::xyz_to_grey_deep(ColorSpaces::xyz color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::xyz_to_cmyk(ColorSpaces::xyz color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::xyz_to_hsv(ColorSpaces::xyz color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::xyz_to_hsl(ColorSpaces::xyz color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::lab ColorManipulation::color_converter::xyz_to_lab(ColorSpaces::xyz color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::lab_to_rgb_true(ColorSpaces::lab color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::lab_to_rgb_deep(ColorSpaces::lab color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::lab_to_grey_true(ColorSpaces::lab color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::lab_to_grey_deep(ColorSpaces::lab color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::lab_to_cmyk(ColorSpaces::lab color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::lab_to_hsv(ColorSpaces::lab color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::lab_to_hsl(ColorSpaces::lab color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::lab_to_xyz(ColorSpaces::lab color)
{
	return ColorSpaces::xyz();
}
