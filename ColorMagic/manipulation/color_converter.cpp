#include "stdafx.h"
#include "color_converter.h"

#define N_ROOT(x, n) std::powf(x, 1.f / n)

color_space::color_base* color_manipulation::color_converter::convertTo(color_space::color_base* in_color, color_type out_color)
{
	switch (out_color)
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::to_rgb_true(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::to_rgb_deep(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::to_grey_true(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::to_grey_deep(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::to_cmyk(in_color);
	case color_type::HSI:
		return color_manipulation::color_converter::to_hsi(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::to_hsv(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::to_hsl(in_color);
	case color_type::HCY:
		return color_manipulation::color_converter::to_hcy(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::to_xyz(in_color);
	case color_type::XYY:
		return color_manipulation::color_converter::to_xyy(in_color);
	case color_type::CIELUV:
		return color_manipulation::color_converter::to_cieluv(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::to_lab(in_color);
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

color_space::hsi* color_manipulation::color_converter::rgb_true_to_hsi(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::rgb_true_to_hsv(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::rgb_true_to_hsl(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::hcy* color_manipulation::color_converter::rgb_true_to_hcy(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::rgb_true_to_xyz(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::rgb_true_to_xyy(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::rgb_true_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::rgb_true_to_cieluv(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::rgb_true_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::rgb_true_to_lab(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::rgb_true_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::rgb_true_to_lch_ab(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::rgb_true_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::rgb_true_to_lch_uv(color_space::rgb_truecolor* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::rgb_true_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::rgb_deep_to_rgb_true(color_space::rgb_deepcolor* color)
{
	return new color_space::rgb_truecolor(roundf(color->red()* 255.f), roundf(color->green()* 255.f), roundf(color->blue()* 255.f), roundf(color->alpha()* 255.f), color->get_rgb_color_space());
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

color_space::hsi* color_manipulation::color_converter::rgb_deep_to_hsi(color_space::rgb_deepcolor* color)
{
	float min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	float max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new color_space::hsi(0.f, 0.f, min, color->alpha(), color->get_rgb_color_space());
	}
	else
	{
		float delta = max - min;
		float hue = hue_from_rgb_helper(color->red(), color->green(), color->blue(), max, min, delta);
		float intensity = (color->red() + color->green() + color->blue()) / 3.f;
		float saturation = 1.f - (min / intensity);
		return new color_space::hsi(hue, saturation, intensity, color->alpha(), color->get_rgb_color_space());
	}
}

color_space::hsv* color_manipulation::color_converter::rgb_deep_to_hsv(color_space::rgb_deepcolor* color)
{
	float min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	float max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new color_space::hsv(0.f, 0.f, min, color->alpha(), color->get_rgb_color_space());
	}
	else
	{
		float delta = max - min;
		float hue = hue_from_rgb_helper(color->red(), color->green(), color->blue(), max, min, delta);
		float value = max;
		float saturation = delta / value;
		return new color_space::hsv(hue, saturation, value, color->alpha(), color->get_rgb_color_space());
	}
}

color_space::hsl* color_manipulation::color_converter::rgb_deep_to_hsl(color_space::rgb_deepcolor* color)
{
	float min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	float max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new color_space::hsl(0.f, 0.f, min, color->alpha(), color->get_rgb_color_space());
	}
	else
	{
		float delta = max - min;
		float lightness = 0.5f* (max + min);
		float hue = hue_from_rgb_helper(color->red(), color->green(), color->blue(), max, min, delta);
		float saturation = (lightness == 0.f || lightness == 1.f) ? 0.f : (delta / (1.f - fabsf(2.f* lightness - 1.f)));
		return new color_space::hsl(hue, saturation, lightness, color->alpha(), color->get_rgb_color_space());
	}
}

color_space::hcy* color_manipulation::color_converter::rgb_deep_to_hcy(color_space::rgb_deepcolor* color)
{
	float min = std::fmin(std::fmin(color->red(), color->green()), color->blue());
	float max = std::fmax(std::fmax(color->red(), color->green()), color->blue());
	if (max == min) // red = green = blue
	{
		return new color_space::hcy(0.f, 0.f, min, color->alpha(), color->get_rgb_color_space());
	}
	else
	{
		float chroma = max - min;
		float hue = hue_from_rgb_helper(color->red(), color->green(), color->blue(), max, min, chroma);

		// Only support Rec.709 primaries used in sRGB at the moment.
		// Maybe implement switch to Rec.601 later (NTSC)
		// see: "https://en.wikipedia.org/wiki/Luma_(video)" for more information
		float luma = 0.2126f* color->red() + 0.7152f* color->green() + 0.0722f* color->blue();

		return new color_space::hcy(hue, chroma, luma, color->alpha(), color->get_rgb_color_space());
	}
}

color_space::xyz* color_manipulation::color_converter::rgb_deep_to_xyz(color_space::rgb_deepcolor* color)
{
	color->do_inverse_gamma_correction();

	auto xyz_components = color->get_rgb_color_space()->get_transform_matrix()* color->get_component_vector();
	return new color_space::xyz(xyz_components[0], xyz_components[1], xyz_components[2], color->alpha(), color->get_rgb_color_space());
}

color_space::xyy* color_manipulation::color_converter::rgb_deep_to_xyy(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::rgb_deep_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::rgb_deep_to_cieluv(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::rgb_deep_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::rgb_deep_to_lab(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::xyz_to_lab(color_manipulation::color_converter::rgb_deep_to_xyz(color));
}

color_space::lch_ab* color_manipulation::color_converter::rgb_deep_to_lch_ab(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::rgb_deep_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::rgb_deep_to_lch_uv(color_space::rgb_deepcolor* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::rgb_deep_to_cieluv(color));
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

color_space::hsi* color_manipulation::color_converter::grey_true_to_hsi(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::grey_true_to_hsv(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::grey_true_to_hsl(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::hcy* color_manipulation::color_converter::grey_true_to_hcy(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::grey_true_to_xyz(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::grey_true_to_xyy(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::grey_true_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::grey_true_to_cieluv(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::grey_true_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::grey_true_to_lab(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::grey_true_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::grey_true_to_lch_ab(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::grey_true_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::grey_true_to_lch_uv(color_space::grey_truecolor* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::grey_true_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::grey_deep_to_rgb_true(color_space::grey_deepcolor* color)
{
	return new color_space::rgb_truecolor(roundf(color->grey()* 255.f), roundf(color->alpha()* 255.f), color->get_rgb_color_space());
}

color_space::rgb_deepcolor* color_manipulation::color_converter::grey_deep_to_rgb_deep(color_space::grey_deepcolor* color)
{
	return new color_space::rgb_deepcolor(color->grey(), color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::grey_deep_to_grey_true(color_space::grey_deepcolor* color)
{
	return new color_space::grey_truecolor(roundf(color->grey()* 255.f), roundf(color->alpha()* 255.f), color->get_rgb_color_space());
}

color_space::cmyk* color_manipulation::color_converter::grey_deep_to_cmyk(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::hsi* color_manipulation::color_converter::grey_deep_to_hsi(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::grey_deep_to_hsv(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::grey_deep_to_hsl(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::hcy* color_manipulation::color_converter::grey_deep_to_hcy(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::grey_deep_to_xyz(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::grey_deep_to_xyy(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::grey_deep_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::grey_deep_to_cieluv(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::grey_deep_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::grey_deep_to_lab(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::grey_deep_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::grey_deep_to_lch_ab(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::grey_deep_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::grey_deep_to_lch_uv(color_space::grey_deepcolor* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::grey_deep_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::cmyk_to_rgb_true(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::cmyk_to_rgb_deep(color_space::cmyk* color)
{
	auto r = (1 - color->cyan())* (1 - color->black());
	auto g = (1 - color->magenta())* (1 - color->black());
	auto b = (1 - color->yellow())* (1 - color->black());
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

color_space::hsi* color_manipulation::color_converter::cmyk_to_hsi(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::cmyk_to_hsv(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::cmyk_to_hsl(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::hcy* color_manipulation::color_converter::cmyk_to_hcy(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::cmyk_to_xyz(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::cmyk_to_xyy(color_space::cmyk* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::cmyk_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::cmyk_to_cieluv(color_space::cmyk* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::cmyk_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::cmyk_to_lab(color_space::cmyk* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::cmyk_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::cmyk_to_lch_ab(color_space::cmyk* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::cmyk_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::cmyk_to_lch_uv(color_space::cmyk* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::cmyk_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::hsi_to_rgb_true(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hsi_to_rgb_deep(color_space::hsi* color)
{
	if (color->saturation() == 0.f)
	{
		return new color_space::rgb_deepcolor(color->intensity(), color->alpha(), color->get_rgb_color_space());
	}

	auto h_temp = color->hue() / 60.f;
	auto Z = 1.f - std::fabsf(std::fmodf(h_temp, 2.f) - 1.f);
	auto chroma = (3.f* color->intensity()* color->saturation()) / (1.f + Z);
	auto x = chroma * Z;

	float r_temp, g_temp, b_temp;
	if (h_temp >= 0.f && h_temp <= 1.f) { r_temp = chroma;	g_temp = x;			b_temp = 0.f; }
	else if (h_temp > 1.f && h_temp <= 2.f) { r_temp = x;		g_temp = chroma;	b_temp = 0.f; }
	else if (h_temp > 2.f && h_temp <= 3.f) { r_temp = 0.f;		g_temp = chroma;	b_temp = x; }
	else if (h_temp > 3.f && h_temp <= 4.f) { r_temp = 0.f;		g_temp = x;			b_temp = chroma; }
	else if (h_temp > 4.f && h_temp <= 5.f) { r_temp = x;		g_temp = 0.f;		b_temp = chroma; }
	else if (h_temp > 5.f && h_temp <= 6.f) { r_temp = chroma;	g_temp = 0.f;		b_temp = x; }
	else { r_temp = 0.f;		g_temp = 0.f;		b_temp = 0.f; }

	return new color_space::rgb_deepcolor(r_temp, g_temp, b_temp, color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::hsi_to_grey_true(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_true(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::hsi_to_grey_deep(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_deep(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::cmyk* color_manipulation::color_converter::hsi_to_cmyk(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::hsi_to_hsv(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::hsi_to_hsl(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::hcy* color_manipulation::color_converter::hsi_to_hcy(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::hsi_to_xyz(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::hsi_to_xyy(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyy(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::cieluv* color_manipulation::color_converter::hsi_to_cieluv(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cieluv(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::hsi_to_lab(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::hsi_to_lch_ab(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lch_ab(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::lch_uv* color_manipulation::color_converter::hsi_to_lch_uv(color_space::hsi* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lch_uv(color_manipulation::color_converter::hsi_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::hsv_to_rgb_true(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hsv_to_rgb_deep(color_space::hsv* color)
{
	/*
	auto chroma = color->value()* color->saturation();
	auto h_temp = color->hue() / 60.f;
	auto x = chroma * (1.f - std::fabsf(std::fmodf(h_temp, 2.f) - 1.f));
	auto m = color->value() - chroma;
	float r_temp, g_temp, b_temp;
	if (h_temp >= 0.f && h_temp <= 1.f) { r_temp = chroma;	g_temp = x;			b_temp = 0.f; }
	else if (h_temp > 1.f && h_temp <= 2.f) { r_temp = x;		g_temp = chroma;	b_temp = 0.f; }
	else if (h_temp > 2.f && h_temp <= 3.f) { r_temp = 0.f;		g_temp = chroma;	b_temp = x; }
	else if (h_temp > 3.f && h_temp <= 4.f) { r_temp = 0.f;		g_temp = x;			b_temp = chroma; }
	else if (h_temp > 4.f && h_temp <= 5.f) { r_temp = x;		g_temp = 0.f;		b_temp = chroma; }
	else if (h_temp > 5.f && h_temp <= 6.f) { r_temp = chroma;	g_temp = 0.f;		b_temp = x; }
	else { r_temp = 0.f;		g_temp = 0.f;		b_temp = 0.f; }

	return new color_space::rgb_deepcolor(r_temp + m, g_temp + m, b_temp + m, color->alpha(), color->get_rgb_color_space());
	*/

	float r_temp = hsv_to_rgb_helper(color, 5.f);
	float g_temp = hsv_to_rgb_helper(color, 3.f);
	float b_temp = hsv_to_rgb_helper(color, 1.f);

	return new color_space::rgb_deepcolor(r_temp, g_temp, b_temp, color->alpha(), color->get_rgb_color_space());
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

color_space::hsi* color_manipulation::color_converter::hsv_to_hsi(color_space::hsv* color)
{
	// Since intensity is defined as (R + G + B) / 3 a conversion to rgb is necessarry.
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::hsv_to_hsl(color_space::hsv* color)
{
	auto l = (2.f - color->saturation())* color->value();
	auto s = color->saturation()* color->value();
	s /= (l <= 1.f) ? l : 2.f - l;
	l /= 2.f;
	return new color_space::hsl(color->hue(), s, l, color->alpha(), color->get_rgb_color_space());
}

color_space::hcy* color_manipulation::color_converter::hsv_to_hcy(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::hsv_to_xyz(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::hsv_to_xyy(color_space::hsv* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::hsv_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::hsv_to_cieluv(color_space::hsv* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::hsv_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::hsv_to_lab(color_space::hsv* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsv_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::hsv_to_lch_ab(color_space::hsv* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::hsv_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::hsv_to_lch_uv(color_space::hsv* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::hsv_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::hsl_to_rgb_true(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hsl_to_rgb_deep(color_space::hsl* color)
{
	if (color->lightness() == 0.f) return new color_space::rgb_deepcolor(0.f, 0.f, color->get_rgb_color_space());

	/* Old not optimized version

	float temp_h = color->hue() / 360.f;

	float var1, var2;
	if (color->lightness() < 0.5f)
	{
		var1 = color->lightness()* (1.f + color->saturation());
	}
	else
	{
		var1 = color->lightness() + color->saturation() - (color->lightness()* color->saturation());
	}
	var2 = 2.f* color->lightness() - var1;

	auto r = hsl_to_rgb_helper(var1, var2, temp_h + 1.f / 3.f);
	auto g = hsl_to_rgb_helper(var1, var2, temp_h);
	auto b = hsl_to_rgb_helper(var1, var2, temp_h - 1.f / 3.f);

	*/

	float r = hsl_to_rgb_helper(color, 0.f);
	float g = hsl_to_rgb_helper(color, 8.f);
	float b = hsl_to_rgb_helper(color, 4.f);

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

color_space::hsi* color_manipulation::color_converter::hsl_to_hsi(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::hsl_to_hsv(color_space::hsl* color)
{
	auto l_temp = color->lightness()* 2.f;
	auto m_sat = color->saturation()* (l_temp <= 1.f) ? l_temp : (2.f - l_temp);
	auto v = (l_temp + m_sat) / 2.f;
	auto s = (2.f* m_sat) / (l_temp + m_sat);
	return new color_space::hsv(color->hue(), s, v, color->alpha(), color->get_rgb_color_space());
}

color_space::hcy* color_manipulation::color_converter::hsl_to_hcy(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::hsl_to_xyz(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::hsl_to_xyy(color_space::hsl* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::hsl_to_xyz(color));
}

color_space::cieluv* color_manipulation::color_converter::hsl_to_cieluv(color_space::hsl* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::hsl_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::hsl_to_lab(color_space::hsl* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hsl_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::hsl_to_lch_ab(color_space::hsl* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::hsl_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::hsl_to_lch_uv(color_space::hsl* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::hsl_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::hcy_to_rgb_true(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::hcy_to_rgb_deep(color_space::hcy* color)
{
	float unit_hue = color->hue() / 360.f;
	float r = clamp_float(fabsf(unit_hue* 6.f - 3.f) - 1.f, 0.f, 1.f);
	float g = clamp_float(2.f - fabsf(unit_hue* 6.f - 2.f), 0.f, 1.f);
	float b = clamp_float(2.f - fabsf(unit_hue* 6.f - 4.f), 0.f, 1.f);
	float Y = r * 0.2126f + g * 0.7152f + b * 0.0722f;
	float tmp_chroma;
	if (color->luma() < Y)
	{
		tmp_chroma = color->chroma()* (color->luma() / Y);
	}
	else if (Y < 1.f)
	{
		tmp_chroma = color->chroma()* ((1.f - color->luma()) / (1.f - Y));
	}
	r = (r - Y)* color->chroma() + color->luma();
	g = (g - Y)* color->chroma() + color->luma();
	b = (b - Y)* color->chroma() + color->luma();
	return new color_space::rgb_deepcolor(r, g, b, color->alpha(), color->get_rgb_color_space());
}

color_space::grey_truecolor* color_manipulation::color_converter::hcy_to_grey_true(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_true(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::hcy_to_grey_deep(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_grey_deep(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::cmyk* color_manipulation::color_converter::hcy_to_cmyk(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cmyk(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::hsi* color_manipulation::color_converter::hcy_to_hsi(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::hcy_to_hsv(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::hcy_to_hsl(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::xyz* color_manipulation::color_converter::hcy_to_xyz(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyz(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::hcy_to_xyy(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_xyy(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::cieluv* color_manipulation::color_converter::hcy_to_cieluv(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_cieluv(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::lab* color_manipulation::color_converter::hcy_to_lab(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lab(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::lch_ab* color_manipulation::color_converter::hcy_to_lch_ab(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lch_ab(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::lch_uv* color_manipulation::color_converter::hcy_to_lch_uv(color_space::hcy* color)
{
	return color_manipulation::color_converter::rgb_deep_to_lch_uv(color_manipulation::color_converter::hcy_to_rgb_deep(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::xyz_to_rgb_true(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_rgb_true(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::xyz_to_rgb_deep(color_space::xyz* color)
{
	auto rgb_components = color->get_rgb_color_space()->get_inverse_transform_matrix()* color->get_component_vector();
	auto rgb_deep = new color_space::rgb_deepcolor(rgb_components[0], rgb_components[1], rgb_components[2], color->alpha(), color->get_rgb_color_space());
	rgb_deep->red(clamp_float(rgb_deep->red(), 0.f, 1.f));
	rgb_deep->green(clamp_float(rgb_deep->green(), 0.f, 1.f));
	rgb_deep->blue(clamp_float(rgb_deep->blue(), 0.f, 1.f));

	rgb_deep->do_gamma_correction();
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

color_space::hsi* color_manipulation::color_converter::xyz_to_hsi(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsi(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::hsv* color_manipulation::color_converter::xyz_to_hsv(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsv(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::hsl* color_manipulation::color_converter::xyz_to_hsl(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hsl(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::hcy* color_manipulation::color_converter::xyz_to_hcy(color_space::xyz* color)
{
	return color_manipulation::color_converter::rgb_deep_to_hcy(color_manipulation::color_converter::xyz_to_rgb_deep(color));
}

color_space::xyy* color_manipulation::color_converter::xyz_to_xyy(color_space::xyz* color)
{
	if (color->x() == 0 && color->y() == 0 && color->z() == 0)
	{
		// special case for black (use reference white chromaticity coordinates for x and y)
		return new color_space::xyy(color->get_rgb_color_space()->get_white_point()->get_chromaticity_x(), color->get_rgb_color_space()->get_white_point()->get_chromaticity_y(), color->y(), color->alpha(), color->get_rgb_color_space());
	}

	auto x = color->x() / (color->x() + color->y() + color->z());
	auto y = color->y() / (color->x() + color->y() + color->z());

	return new color_space::xyy(x, y, color->y(), color->alpha(), color->get_rgb_color_space());
}

color_space::cieluv* color_manipulation::color_converter::xyz_to_cieluv(color_space::xyz* color)
{
	auto y_temp = color->x() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_y();
	auto u_temp = 4.f* color->x() / (color->x() + 15.f* color->y() + 3.f* color->z());
	auto v_temp = 9.f* color->y() / (color->x() + 15.f* color->y() + 3.f* color->z());

	auto u_w_temp = 4.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_x() /
		(color->get_rgb_color_space()->get_white_point()->get_tristimulus_x() +
			15.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() +
			3.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_z());

	auto v_w_temp = 4.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() /
		(color->get_rgb_color_space()->get_white_point()->get_tristimulus_x() +
			15.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() +
			3.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_z());

	auto L = y_temp > 0.008856f ? 116.f* N_ROOT(y_temp, 3) - 16.f : 903.3f* y_temp;
	auto u = 13.f* L* (u_temp - u_w_temp);
	auto v = 13.f* L* (v_temp - v_w_temp);

	return new color_space::cieluv(L, u, v, color->alpha(), color->get_rgb_color_space());
}

color_space::lab* color_manipulation::color_converter::xyz_to_lab(color_space::xyz* color)
{
	auto func_x = xyz_to_lab_helper(color->x() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_x());
	auto func_y = xyz_to_lab_helper(color->y() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_y());
	auto func_z = xyz_to_lab_helper(color->z() / color->get_rgb_color_space()->get_white_point()->get_tristimulus_z());

	auto l = 116.f* func_y - 16.f;
	auto a = 500.f* (func_x - func_y);
	auto b = 200.f* (func_y - func_z);

	auto lab = new color_space::lab(l, a, b, 0, color->get_rgb_color_space());
	lab->alpha(color->alpha());
	return lab;
}

color_space::lch_ab* color_manipulation::color_converter::xyz_to_lch_ab(color_space::xyz* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::xyz_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::xyz_to_lch_uv(color_space::xyz* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::xyz_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::xyy_to_rgb_true(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_rgb_true(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::xyy_to_rgb_deep(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_rgb_deep(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::grey_truecolor* color_manipulation::color_converter::xyy_to_grey_true(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_grey_true(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::xyy_to_grey_deep(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_grey_deep(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::cmyk* color_manipulation::color_converter::xyy_to_cmyk(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_cmyk(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::hsi* color_manipulation::color_converter::xyy_to_hsi(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_hsi(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::hsv* color_manipulation::color_converter::xyy_to_hsv(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_hsv(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::hsl* color_manipulation::color_converter::xyy_to_hsl(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_hsl(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::hcy* color_manipulation::color_converter::xyy_to_hcy(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_hcy(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::xyz* color_manipulation::color_converter::xyy_to_xyz(color_space::xyy* color)
{
	if (color->y() == 0)
	{
		// special case for black (set X, Y and Z to 0)
		return new color_space::xyz(0.f, 0.f, 0.f, color->alpha(), color->get_rgb_color_space());
	}

	auto x = color->x()* color->Y() / color->y();
	auto z = (1.f - color->x() - color->y())* color->Y() / color->y();
	return new color_space::xyz(x, color->Y(), z, color->alpha(), color->get_rgb_color_space());
}

color_space::cieluv* color_manipulation::color_converter::xyy_to_cieluv(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::xyy_to_lab(color_space::xyy* color)
{
	return color_manipulation::color_converter::xyz_to_lab(color_manipulation::color_converter::xyy_to_xyz(color));
}

color_space::lch_ab* color_manipulation::color_converter::xyy_to_lch_ab(color_space::xyy* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::xyy_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::xyy_to_lch_uv(color_space::xyy* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::xyy_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::cieluv_to_rgb_true(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_rgb_true(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::cieluv_to_rgb_deep(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_rgb_deep(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::grey_truecolor* color_manipulation::color_converter::cieluv_to_grey_true(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_grey_true(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::cieluv_to_grey_deep(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_grey_deep(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::cmyk* color_manipulation::color_converter::cieluv_to_cmyk(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_cmyk(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::hsi* color_manipulation::color_converter::cieluv_to_hsi(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_hsi(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::hsv* color_manipulation::color_converter::cieluv_to_hsv(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_hsv(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::hsl* color_manipulation::color_converter::cieluv_to_hsl(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_hsl(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::hcy* color_manipulation::color_converter::cieluv_to_hcy(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_hcy(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::xyz* color_manipulation::color_converter::cieluv_to_xyz(color_space::cieluv* color)
{
	auto u_temp = 4.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_x() /
		(color->get_rgb_color_space()->get_white_point()->get_tristimulus_x() +
			15.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() +
			3.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_z());

	auto v_temp = 9.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() /
		(color->get_rgb_color_space()->get_white_point()->get_tristimulus_x() +
			15.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() +
			3.f* color->get_rgb_color_space()->get_white_point()->get_tristimulus_z());

	auto Y = color->L() > 903.3f* 0.008856f ? powf((color->L() + 16.f) / 116.f, 3.f) : color->L() / 903.3f;
	auto a = 1.f / 3.f* ((52.f* color->L() / (color->u() + 13.f* color->L()* u_temp)) - 1.f);
	auto b = -5.f* Y;
	auto c = -1.f / 3.f;
	auto d = Y * ((39.f* color->L() / (color->v() + 13.f* color->L()* v_temp)) - 5.f);

	auto X = (d - b) / (a - c);
	auto Z = X * a + b;
	return new color_space::xyz(X, Y, Z, color->alpha(), color->get_rgb_color_space());
}

color_space::xyy* color_manipulation::color_converter::cieluv_to_xyy(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::lab* color_manipulation::color_converter::cieluv_to_lab(color_space::cieluv* color)
{
	return color_manipulation::color_converter::xyz_to_lab(color_manipulation::color_converter::cieluv_to_xyz(color));
}

color_space::lch_ab* color_manipulation::color_converter::cieluv_to_lch_ab(color_space::cieluv* color)
{
	return color_manipulation::color_converter::lab_to_lch_ab(color_manipulation::color_converter::cieluv_to_lab(color));
}

color_space::lch_uv* color_manipulation::color_converter::cieluv_to_lch_uv(color_space::cieluv* color)
{
	auto chroma = sqrtf(powf(color->u(), 2.f) + powf(color->v(), 2.f));
	chroma = transform_range(chroma, color->get_component_min(), color->get_component_max(), 0.f, 100.f);
	auto hue = atan2f(color->v(), color->u());
	if (hue < 0.f) hue += 360.f;

	auto lch = new color_space::lch_uv(color->L(), chroma, hue, 0.f, color->get_rgb_color_space());
	lch->alpha(color->alpha()); // Clamp alpha
	return lch;
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

color_space::hsi* color_manipulation::color_converter::lab_to_hsi(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_hsi(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::hsv* color_manipulation::color_converter::lab_to_hsv(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_hsv(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::hsl* color_manipulation::color_converter::lab_to_hsl(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_hsl(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::hcy* color_manipulation::color_converter::lab_to_hcy(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_hcy(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::xyz* color_manipulation::color_converter::lab_to_xyz(color_space::lab* color)
{
	auto f_y = (color->luminance() + 16.f) / 116.f;
	auto y_temp = lab_to_xyz_helper(color->luminance(), true);
	auto x_temp = lab_to_xyz_helper((color->a() / 500.f) + f_y);
	auto z_temp = lab_to_xyz_helper(f_y - (color->b() / 200.f));

	auto xyz = new color_space::xyz(x_temp* color->get_rgb_color_space()->get_white_point()->get_tristimulus_x(), y_temp* color->get_rgb_color_space()->get_white_point()->get_tristimulus_y(), z_temp* color->get_rgb_color_space()->get_white_point()->get_tristimulus_z(), 0.f, color->get_rgb_color_space());
	xyz->alpha(color->alpha());
	return xyz;
}

color_space::cieluv* color_manipulation::color_converter::lab_to_cieluv(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_cieluv(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::xyy* color_manipulation::color_converter::lab_to_xyy(color_space::lab* color)
{
	return color_manipulation::color_converter::xyz_to_xyy(color_manipulation::color_converter::lab_to_xyz(color));
}

color_space::lch_ab* color_manipulation::color_converter::lab_to_lch_ab(color_space::lab* color)
{
	auto chroma = sqrtf(powf(color->a(), 2.f) + powf(color->b(), 2.f));
	chroma = transform_range(chroma, color->get_component_min(), color->get_component_max(), 0.f, 100.f);
	auto hue = atan2f(color->b(), color->a());
	if (hue < 0.f) hue += 360.f;

	auto lch = new color_space::lch_ab(color->luminance(), chroma, hue, 0.f, color->get_rgb_color_space());
	lch->alpha(color->alpha()); // Clamp alpha
	return lch;
}

color_space::lch_uv* color_manipulation::color_converter::lab_to_lch_uv(color_space::lab* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::lab_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::lch_ab_to_rgb_true(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_rgb_true(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::lch_ab_to_rgb_deep(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_rgb_deep(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::grey_truecolor* color_manipulation::color_converter::lch_ab_to_grey_true(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_grey_true(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::lch_ab_to_grey_deep(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_grey_deep(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::cmyk* color_manipulation::color_converter::lch_ab_to_cmyk(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_cmyk(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::hsi* color_manipulation::color_converter::lch_ab_to_hsi(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_hsi(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::hsv* color_manipulation::color_converter::lch_ab_to_hsv(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_hsv(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::hsl* color_manipulation::color_converter::lch_ab_to_hsl(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_hsl(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::hcy* color_manipulation::color_converter::lch_ab_to_hcy(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_hcy(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::xyz* color_manipulation::color_converter::lch_ab_to_xyz(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_xyz(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::xyy* color_manipulation::color_converter::lch_ab_to_xyy(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_xyy(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::cieluv* color_manipulation::color_converter::lch_ab_to_cieluv(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::lab_to_cieluv(color_manipulation::color_converter::lch_ab_to_lab(color));
}

color_space::lab* color_manipulation::color_converter::lch_ab_to_lab(color_space::lch_ab* color)
{
	auto h_rad = (float)(color->hue()* M_PI / 180.f);
	auto a = color->chroma()* cosf(h_rad);
	auto b = color->chroma()* sinf(h_rad);

	auto lab = new color_space::lab(color->luminance(), a, b, 0.f, color->get_rgb_color_space());
	lab->alpha(color->alpha()); // Clamp alpha
	return lab;
}

color_space::lch_uv* color_manipulation::color_converter::lch_ab_to_lch_uv(color_space::lch_ab* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_uv(color_manipulation::color_converter::lch_ab_to_cieluv(color));
}

color_space::rgb_truecolor* color_manipulation::color_converter::lch_uv_to_rgb_true(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_rgb_true(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::rgb_deepcolor* color_manipulation::color_converter::lch_uv_to_rgb_deep(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_rgb_deep(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::grey_truecolor* color_manipulation::color_converter::lch_uv_to_grey_true(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_grey_true(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::grey_deepcolor* color_manipulation::color_converter::lch_uv_to_grey_deep(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_grey_deep(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::cmyk* color_manipulation::color_converter::lch_uv_to_cmyk(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_cmyk(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::hsi* color_manipulation::color_converter::lch_uv_to_hsi(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_hsi(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::hsv* color_manipulation::color_converter::lch_uv_to_hsv(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_hsv(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::hsl* color_manipulation::color_converter::lch_uv_to_hsl(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_hsl(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::hcy* color_manipulation::color_converter::lch_uv_to_hcy(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_hcy(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::xyz* color_manipulation::color_converter::lch_uv_to_xyz(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_xyz(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::xyy* color_manipulation::color_converter::lch_uv_to_xyy(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_xyy(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::cieluv* color_manipulation::color_converter::lch_uv_to_cieluv(color_space::lch_uv* color)
{
	auto h_rad = (float)(color->hue()* M_PI / 180.f);
	auto u = color->chroma()* cosf(h_rad);
	auto v = color->chroma()* sinf(h_rad);

	auto luv = new color_space::cieluv(color->luminance(), u, v, 0.f, color->get_rgb_color_space());
	luv->alpha(color->alpha()); // Clamp alpha
	return luv;
}

color_space::lab* color_manipulation::color_converter::lch_uv_to_lab(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_lab(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

color_space::lch_ab* color_manipulation::color_converter::lch_uv_to_lch_ab(color_space::lch_uv* color)
{
	return color_manipulation::color_converter::cieluv_to_lch_ab(color_manipulation::color_converter::lch_uv_to_cieluv(color));
}

float color_manipulation::color_converter::hue_from_rgb_helper(float red, float green, float blue, float max, float min, float delta)
{
	if (max == red)
	{
		return 60.f* fmod(((green - blue) / delta), 6.f);
	}
	else if (max == green)
	{
		return 60.f* (((blue - red) / delta) + 2.f);
	}
	else
	{
		return 60.f* (((red - green) / delta) + 4.f);
	}
}

float color_manipulation::color_converter::hsv_to_rgb_helper(color_space::hsv * color, float n)
{
	float k = fmodf(n + color->hue() / 60.f, 6.f);
	return color->value() - color->value() * color->saturation() * fmaxf(fminf(k, fminf(4.f - k, 1.f)), 0.f);
}

float color_manipulation::color_converter::hsl_to_rgb_helper(float var1, float var2, float var3)
{
	if (var3 < 0.f) var3 += 1.f;
	if (var3 > 1.f) var3 -= 1.f;

	if (var3 < 1.f / 6.f)
	{
		return var2 + (var1 - var2)* 6.f* var3;
	}

	if (var3 < 0.5f)
	{
		return var1;
	}

	if (var3 < 2.f / 3.f)
	{
		return var2 + ((var1 - var2)* ((2.f / 3.f) - var3)* 6.f);
	}

	return var2;
}

float color_manipulation::color_converter::hsl_to_rgb_helper(color_space::hsl * color, float n)
{
	float k = fmodf(n + color->hue() / 30.f, 12.f);
	float a = color->saturation() * fminf(color->lightness(), 1.f - color->lightness());

	return color->lightness() - a * fmaxf(fminf(k - 3.f, fminf(9.f - k, 1.f)), -1.f);
}

float color_manipulation::color_converter::xyz_to_lab_helper(float color_component)
{
	return color_component > (216.f / 24389.f) ? N_ROOT(color_component, 3.f) : ((24389.f / 27.f)* color_component + 16.f) / 116.f;
}

float color_manipulation::color_converter::lab_to_xyz_helper(float color_component, bool out_y_component)
{
	auto epsilon = 216.f / 24389.f;
	auto k = 24389.f / 27.f;

	if (out_y_component)
	{
		if (color_component > epsilon* k)
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
			return (116.f* color_component - 16.f) / k;
		}
	}
}

float color_manipulation::color_converter::round_float_to_n_decimals(float in_float, float n)
{
	auto factor = powf(10.f, n);
	return ((int)(in_float* factor + 0.5f) / factor);
}

float color_manipulation::color_converter::clamp_float(float in_float, float min, float max)
{
	return fminf(fmaxf(in_float, min), max);
}

float color_manipulation::color_converter::transform_range(float value, float old_min, float old_max, float new_min, float new_max)
{
	auto old_range = old_max - old_min;
	auto new_range = new_max - new_min;
	return (((value - old_min)* new_range) / old_range) + new_min;
}

color_space::rgb_truecolor* color_manipulation::color_converter::to_rgb_true(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return static_cast<color_space::rgb_truecolor*>(in_color);
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_rgb_true(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_rgb_true(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_rgb_true(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_rgb_true(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_rgb_true(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_rgb_true(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_rgb_true(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_rgb_true(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_rgb_true(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_rgb_true(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_rgb_true(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_rgb_true(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_rgb_true(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_rgb_true(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::rgb_deepcolor* color_manipulation::color_converter::to_rgb_deep(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_rgb_deep(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return static_cast<color_space::rgb_deepcolor*>(in_color);
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_rgb_deep(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_rgb_deep(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_rgb_deep(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_rgb_deep(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_rgb_deep(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_rgb_deep(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_rgb_deep(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_rgb_deep(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_rgb_deep(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_rgb_deep(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_rgb_deep(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_rgb_deep(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_rgb_deep(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::grey_truecolor* color_manipulation::color_converter::to_grey_true(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_grey_true(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_grey_true(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return static_cast<color_space::grey_truecolor*>(in_color);
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_grey_true(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_grey_true(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_grey_true(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_grey_true(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_grey_true(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_grey_true(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_grey_true(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_grey_true(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_grey_true(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_grey_true(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_grey_true(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_grey_true(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::grey_deepcolor* color_manipulation::color_converter::to_grey_deep(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_grey_deep(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_grey_deep(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_grey_deep(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return static_cast<color_space::grey_deepcolor*>(in_color);
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_grey_deep(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_grey_deep(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_grey_deep(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_grey_deep(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_grey_deep(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_grey_deep(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_grey_deep(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_grey_deep(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_grey_deep(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_grey_deep(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_grey_deep(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::cmyk* color_manipulation::color_converter::to_cmyk(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_cmyk(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_cmyk(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_cmyk(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_cmyk(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return static_cast<color_space::cmyk*>(in_color);
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_cmyk(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_cmyk(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_cmyk(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_cmyk(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_cmyk(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_cmyk(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_cmyk(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_cmyk(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_cmyk(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_cmyk(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::hsi* color_manipulation::color_converter::to_hsi(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_hsi(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_hsi(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_hsi(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_hsi(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_hsi(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return static_cast<color_space::hsi*>(in_color);
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_hsi(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_hsi(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_hsi(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_hsi(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_hsi(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_hsi(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_hsi(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_hsi(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_hsi(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::hsv* color_manipulation::color_converter::to_hsv(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_hsv(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_hsv(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_hsv(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_hsv(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_hsv(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_hsv(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return static_cast<color_space::hsv*>(in_color);
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_hsv(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_hsv(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_hsv(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_hsv(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_hsv(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_hsv(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_hsv(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_hsv(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::hsl* color_manipulation::color_converter::to_hsl(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_hsl(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_hsl(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_hsl(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_hsl(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_hsl(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_hsl(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_hsl(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return static_cast<color_space::hsl*>(in_color);
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_hsl(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_hsl(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_hsl(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_hsl(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_hsl(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_hsl(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_hsl(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::hcy* color_manipulation::color_converter::to_hcy(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_hcy(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_hcy(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_hcy(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_hcy(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_hcy(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_hcy(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_hcy(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_hcy(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return static_cast<color_space::hcy*>(in_color);
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_hcy(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_hcy(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_hcy(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_hcy(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_hcy(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_hcy(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::xyz* color_manipulation::color_converter::to_xyz(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_xyz(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_xyz(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_xyz(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_xyz(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_xyz(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_xyz(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_xyz(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_xyz(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_xyz(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return static_cast<color_space::xyz*>(in_color);
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_xyz(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_xyz(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_xyz(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_xyz(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_xyz(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::xyy* color_manipulation::color_converter::to_xyy(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_xyy(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_xyy(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_xyy(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_xyy(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_xyy(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_xyy(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_xyy(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_xyy(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_xyy(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_xyy(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return static_cast<color_space::xyy*>(in_color);
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_xyy(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_xyy(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_xyy(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_xyy(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::cieluv* color_manipulation::color_converter::to_cieluv(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_cieluv(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_cieluv(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_cieluv(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_cieluv(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_cieluv(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_cieluv(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_cieluv(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_cieluv(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_cieluv(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_cieluv(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_cieluv(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return static_cast<color_space::cieluv*>(in_color);
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_cieluv(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_cieluv(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_cieluv(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::lab* color_manipulation::color_converter::to_lab(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_lab(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_lab(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_lab(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_lab(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_lab(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_lab(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_lab(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_lab(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_lab(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_lab(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_lab(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_lab(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return static_cast<color_space::lab*>(in_color);
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_lab(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_lab(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::lch_ab* color_manipulation::color_converter::to_lch_ab(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_lch_ab(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_lch_ab(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_lch_ab(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_lch_ab(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_lch_ab(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_lch_ab(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_lch_ab(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_lch_ab(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_lch_ab(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_lch_ab(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_lch_ab(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_lch_ab(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_lch_ab(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return static_cast<color_space::lch_ab*>(in_color);
	case color_type::LCH_UV:
		return color_manipulation::color_converter::lch_uv_to_lch_ab(static_cast<color_space::lch_uv*>(in_color));
	default:
		return nullptr;
	}
}

color_space::lch_uv* color_manipulation::color_converter::to_lch_uv(color_space::color_base* in_color)
{
	switch (in_color->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_converter::rgb_true_to_lch_uv(static_cast<color_space::rgb_truecolor*>(in_color));
	case color_type::RGB_DEEP:
		return color_manipulation::color_converter::rgb_deep_to_lch_uv(static_cast<color_space::rgb_deepcolor*>(in_color));
	case color_type::GREY_TRUE:
		return color_manipulation::color_converter::grey_true_to_lch_uv(static_cast<color_space::grey_truecolor*>(in_color));
	case color_type::GREY_DEEP:
		return color_manipulation::color_converter::grey_deep_to_lch_uv(static_cast<color_space::grey_deepcolor*>(in_color));
	case color_type::CMYK:
		return color_manipulation::color_converter::cmyk_to_lch_uv(static_cast<color_space::cmyk*>(in_color));
	case color_type::HSI:
		return color_manipulation::color_converter::hsi_to_lch_uv(static_cast<color_space::hsi*>(in_color));
	case color_type::HSV:
		return color_manipulation::color_converter::hsv_to_lch_uv(static_cast<color_space::hsv*>(in_color));
	case color_type::HSL:
		return color_manipulation::color_converter::hsl_to_lch_uv(static_cast<color_space::hsl*>(in_color));
	case color_type::HCY:
		return color_manipulation::color_converter::hcy_to_lch_uv(static_cast<color_space::hcy*>(in_color));
	case color_type::XYZ:
		return color_manipulation::color_converter::xyz_to_lch_uv(static_cast<color_space::xyz*>(in_color));
	case color_type::XYY:
		return color_manipulation::color_converter::xyy_to_lch_uv(static_cast<color_space::xyy*>(in_color));
	case color_type::CIELUV:
		return color_manipulation::color_converter::cieluv_to_lch_uv(static_cast<color_space::cieluv*>(in_color));
	case color_type::LAB:
		return color_manipulation::color_converter::lab_to_lch_uv(static_cast<color_space::lab*>(in_color));
	case color_type::LCH_AB:
		return color_manipulation::color_converter::lch_ab_to_lch_uv(static_cast<color_space::lch_ab*>(in_color));
	case color_type::LCH_UV:
		return static_cast<color_space::lch_uv*>(in_color);
	default:
		return nullptr;
	}
}

