#include "stdafx.h"
#include "color_calculation.h"

color_space::color_base * color_manipulation::color_calculation::add(color_space::color_base * color1, color_space::color_base * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	switch (color1->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_rgb_true(color1), color_manipulation::color_converter::to_rgb_true(color2), weight1, weight2, include_alpha);
	case color_type::RGB_DEEP:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_rgb_deep(color1), color_manipulation::color_converter::to_rgb_deep(color2), weight1, weight2, include_alpha);
	case color_type::GREY_TRUE:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_grey_true(color1), color_manipulation::color_converter::to_grey_true(color2), weight1, weight2, include_alpha);
	case color_type::GREY_DEEP:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_grey_deep(color1), color_manipulation::color_converter::to_grey_deep(color2), weight1, weight2, include_alpha);
	case color_type::CMYK:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_cmyk(color1), color_manipulation::color_converter::to_cmyk(color2), weight1, weight2, include_alpha);
	case color_type::HSV:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_hsv(color1), color_manipulation::color_converter::to_hsv(color2), weight1, weight2, include_alpha);
	case color_type::HSL:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_hsl(color1), color_manipulation::color_converter::to_hsl(color2), weight1, weight2, include_alpha);
	case color_type::XYZ:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_xyz(color1), color_manipulation::color_converter::to_xyz(color2), weight1, weight2, include_alpha);
	case color_type::LAB:
		return color_manipulation::color_calculation::add(color_manipulation::color_converter::to_lab(color1), color_manipulation::color_converter::to_lab(color2), weight1, weight2, include_alpha);
	default:
		return nullptr;
	}
}

color_space::rgb_truecolor * color_manipulation::color_calculation::add(color_space::rgb_truecolor * color1, color_space::rgb_truecolor * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto r = std::sqrtf(weight1 * std::powf(color1->red(), 2.f) + weight2 * std::powf(color2->red(), 2.f));
	auto g = std::sqrtf(weight1 * std::powf(color1->green(), 2.f) + weight2 * std::powf(color2->green(), 2.f));
	auto b = std::sqrtf(weight1 * std::powf(color1->blue(), 2.f) + weight2 * std::powf(color2->blue(), 2.f));
	auto a = include_alpha ? std::sqrtf(weight1 * std::powf(color1->alpha(), 2.f) + weight2 * std::powf(color2->alpha(), 2.f)) : color1->alpha();

	return new color_space::rgb_truecolor(fminf(fmaxf(r, 0), 255), fminf(fmaxf(g, 0), 255), fminf(fmaxf(b, 0), 255), fminf(fmaxf(a, 0), 255), color1->get_reference_white());
}

color_space::rgb_deepcolor * color_manipulation::color_calculation::add(color_space::rgb_deepcolor * color1, color_space::rgb_deepcolor * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto r = std::sqrtf(weight1 * std::powf(color1->red(), 2.f) + weight2 * std::powf(color2->red(), 2.f));
	auto g = std::sqrtf(weight1 * std::powf(color1->green(), 2.f) + weight2 * std::powf(color2->green(), 2.f));
	auto b = std::sqrtf(weight1 * std::powf(color1->blue(), 2.f) + weight2 * std::powf(color2->blue(), 2.f));
	auto a = include_alpha ? std::sqrtf(weight1 * std::powf(color1->alpha(), 2.f) + weight2 * std::powf(color2->alpha(), 2.f)) : color1->alpha();

	return new color_space::rgb_deepcolor(r, g, b, a, color1->get_reference_white());
}

color_space::grey_truecolor * color_manipulation::color_calculation::add(color_space::grey_truecolor * color1, color_space::grey_truecolor * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto v = weight1 * color1->grey() + weight2 * color2->grey();
	auto a = include_alpha ? weight1 * color1->alpha() + weight2 * color2->alpha() : color1->alpha();

	return new color_space::grey_truecolor(fminf(fmaxf(v, 0), 255), fminf(fmaxf(a, 0), 255), color1->get_reference_white());
}

color_space::grey_deepcolor * color_manipulation::color_calculation::add(color_space::grey_deepcolor * color1, color_space::grey_deepcolor * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto v = weight1 * color1->grey() + weight2 * color2->grey();
	auto a = include_alpha ? weight1 * color1->alpha() + weight2 * color2->alpha() : color1->alpha();

	return new color_space::grey_deepcolor(v, a, color1->get_reference_white());
}

color_space::cmyk * color_manipulation::color_calculation::add(color_space::cmyk * color1, color_space::cmyk * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto c = weight1 * color1->cyan() + weight2 * color2->cyan();
	auto m = weight1 * color1->magenta() + weight2 * color2->magenta();
	auto y = weight1 * color1->yellow() + weight2 * color2->yellow();
	auto k = weight1 * color1->black() + weight2 * color2->black();
	auto a = include_alpha ? weight1 * color1->alpha() + weight2 * color2->alpha() : color1->alpha();

	return new color_space::cmyk(c, m, y, k, a, color1->get_reference_white());
}

color_space::hsv * color_manipulation::color_calculation::add(color_space::hsv * color1, color_space::hsv * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto vector1 = convert_to_vector(color1->hue(), color1->saturation(), color1->value());
	auto vector2 = convert_to_vector(color2->hue(), color2->saturation(), color2->value());

	auto x = weight1 * vector1[0] + weight2 * vector2[0];
	auto y = weight1 * vector1[1] + weight2 * vector2[1];
	auto z = weight1 * vector1[2] + weight2 * vector2[2];
	auto a = include_alpha ? weight1 * color1->alpha() + weight2 * color2->alpha() : color1->alpha();
	vector2 = convert_from_vector(new float[3]{ x, y, z });

	return new color_space::hsv(vector2[0], vector2[1], vector2[2], a, color1->get_reference_white());
}

color_space::hsl * color_manipulation::color_calculation::add(color_space::hsl * color1, color_space::hsl * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	return color_manipulation::color_converter::to_hsl(color_manipulation::color_calculation::add(color_manipulation::color_converter::to_hsv(color1), color_manipulation::color_converter::to_hsv(color2), weight1, weight2, include_alpha));
}

color_space::xyz * color_manipulation::color_calculation::add(color_space::xyz * color1, color_space::xyz * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	auto x = weight1 * color1->x() + weight2 * color2->x();
	auto y = weight1 * color1->y() + weight2 * color2->y();
	auto z = weight1 * color1->z() + weight2 * color2->z();
	auto a = include_alpha ? weight1 * color1->alpha() + weight2 * color2->alpha() : color1->alpha();

	return new color_space::xyz(x, y, z, a, color1->get_reference_white());
}

color_space::lab * color_manipulation::color_calculation::add(color_space::lab * color1, color_space::lab * color2, float weight1, float weight2, bool include_alpha)
{
	if (weight1 < 0.f || weight1 > 1.f) throw new std::invalid_argument("Parameter weight1 has to be in the range [0,1].");
	if (weight2 < 0.f || weight2 > 1.f) throw new std::invalid_argument("Parameter weight2 has to be in the range [0,1].");

	return color_manipulation::color_converter::to_lab(color_manipulation::color_calculation::add(color_manipulation::color_converter::to_xyz(color1), color_manipulation::color_converter::to_xyz(color2), weight1, weight2, include_alpha));
}

color_space::color_base * color_manipulation::color_calculation::mix(color_space::color_base * color1, color_space::color_base * color2, float weight, bool include_alpha)
{
	if (weight <= 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	switch (color1->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_rgb_true(color1), color_manipulation::color_converter::to_rgb_true(color2), weight, include_alpha);
	case color_type::RGB_DEEP:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_rgb_deep(color1), color_manipulation::color_converter::to_rgb_deep(color2), weight, include_alpha);
	case color_type::GREY_TRUE:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_grey_true(color1), color_manipulation::color_converter::to_grey_true(color2), weight, include_alpha);
	case color_type::GREY_DEEP:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_grey_deep(color1), color_manipulation::color_converter::to_grey_deep(color2), weight, include_alpha);
	case color_type::CMYK:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_cmyk(color1), color_manipulation::color_converter::to_cmyk(color2), weight, include_alpha);
	case color_type::HSV:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_hsv(color1), color_manipulation::color_converter::to_hsv(color2), weight, include_alpha);
	case color_type::HSL:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_hsl(color1), color_manipulation::color_converter::to_hsl(color2), weight, include_alpha);
	case color_type::XYZ:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_xyz(color1), color_manipulation::color_converter::to_xyz(color2), weight, include_alpha);
	case color_type::LAB:
		return color_manipulation::color_calculation::mix(color_manipulation::color_converter::to_lab(color1), color_manipulation::color_converter::to_lab(color2), weight, include_alpha);
	default:
		return nullptr;
	}
}

color_space::rgb_truecolor * color_manipulation::color_calculation::mix(color_space::rgb_truecolor * color1, color_space::rgb_truecolor * color2, float weight, bool include_alpha)
{
	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::rgb_deepcolor * color_manipulation::color_calculation::mix(color_space::rgb_deepcolor * color1, color_space::rgb_deepcolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::grey_truecolor * color_manipulation::color_calculation::mix(color_space::grey_truecolor * color1, color_space::grey_truecolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::grey_deepcolor * color_manipulation::color_calculation::mix(color_space::grey_deepcolor * color1, color_space::grey_deepcolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::cmyk * color_manipulation::color_calculation::mix(color_space::cmyk * color1, color_space::cmyk * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::hsv * color_manipulation::color_calculation::mix(color_space::hsv * color1, color_space::hsv * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::hsl * color_manipulation::color_calculation::mix(color_space::hsl * color1, color_space::hsl * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::xyz * color_manipulation::color_calculation::mix(color_space::xyz * color1, color_space::xyz * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::lab * color_manipulation::color_calculation::mix(color_space::lab * color1, color_space::lab * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return add(color1, color2, weight, 1.f - weight, include_alpha);
}

color_space::color_base * color_manipulation::color_calculation::subtract(color_space::color_base * color1, color_space::color_base * color2, float weight, bool include_alpha)
{
	if (weight <= 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	switch (color1->get_color_type())
	{
	case color_type::RGB_TRUE:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_rgb_true(color1), color_manipulation::color_converter::to_rgb_true(color2), weight, include_alpha);
	case color_type::RGB_DEEP:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_rgb_deep(color1), color_manipulation::color_converter::to_rgb_deep(color2), weight, include_alpha);
	case color_type::GREY_TRUE:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_grey_true(color1), color_manipulation::color_converter::to_grey_true(color2), weight, include_alpha);
	case color_type::GREY_DEEP:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_grey_deep(color1), color_manipulation::color_converter::to_grey_deep(color2), weight, include_alpha);
	case color_type::CMYK:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_cmyk(color1), color_manipulation::color_converter::to_cmyk(color2), weight, include_alpha);
	case color_type::HSV:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_hsv(color1), color_manipulation::color_converter::to_hsv(color2), weight, include_alpha);
	case color_type::HSL:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_hsl(color1), color_manipulation::color_converter::to_hsl(color2), weight, include_alpha);
	case color_type::XYZ:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_xyz(color1), color_manipulation::color_converter::to_xyz(color2), weight, include_alpha);
	case color_type::LAB:
		return color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_lab(color1), color_manipulation::color_converter::to_lab(color2), weight, include_alpha);
	default:
		return nullptr;
	}
}

color_space::rgb_truecolor * color_manipulation::color_calculation::subtract(color_space::rgb_truecolor * color1, color_space::rgb_truecolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	auto r = color1->red() - weight * color2->red();
	auto g = color1->green() - weight * color2->green();
	auto b = color1->blue() - weight * color2->blue();
	auto a = include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha();

	return new color_space::rgb_truecolor(r, g, b, a, color1->get_reference_white());
}

color_space::rgb_deepcolor * color_manipulation::color_calculation::subtract(color_space::rgb_deepcolor * color1, color_space::rgb_deepcolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	auto r = color1->red() - weight * color2->red();
	auto g = color1->green() - weight * color2->green();
	auto b = color1->blue() - weight * color2->blue();
	auto a = include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha();

	return new color_space::rgb_deepcolor(r, g, b, a, color1->get_reference_white());
}

color_space::grey_truecolor * color_manipulation::color_calculation::subtract(color_space::grey_truecolor * color1, color_space::grey_truecolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return new color_space::grey_truecolor(color1->grey() - weight * color2->grey(), include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha(), color1->get_reference_white());
}

color_space::grey_deepcolor * color_manipulation::color_calculation::subtract(color_space::grey_deepcolor * color1, color_space::grey_deepcolor * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return new color_space::grey_deepcolor(color1->grey() - weight * color2->grey(), include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha(), color1->get_reference_white());
}

color_space::cmyk * color_manipulation::color_calculation::subtract(color_space::cmyk * color1, color_space::cmyk * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	auto c = color1->cyan() - weight * color2->cyan();
	auto m = color1->magenta() - weight * color2->magenta();
	auto y = color1->yellow() - weight * color2->yellow();
	auto k = color1->black() - weight * color2->black();
	auto a = include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha();

	return new color_space::cmyk(c, m, y, k, a, color1->get_reference_white());
}

color_space::hsv * color_manipulation::color_calculation::subtract(color_space::hsv * color1, color_space::hsv * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	auto vector1 = convert_to_vector(color1->hue(), color1->saturation(), color1->value());
	auto vector2 = convert_to_vector(color2->hue(), color2->saturation(), color2->value());

	auto x = vector1[0] - weight * vector2[0];
	auto y = vector1[1] - weight * vector2[1];
	auto z = vector1[2] - weight * vector2[2];
	vector2 = convert_from_vector(new float[3]{ x, y, z });
	auto a = include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha();

	return new color_space::hsv(vector2[0], vector2[1], vector2[2], a, color1->get_reference_white());
}

color_space::hsl * color_manipulation::color_calculation::subtract(color_space::hsl * color1, color_space::hsl * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return color_manipulation::color_converter::to_hsl(color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_hsv(color1), color_manipulation::color_converter::to_hsv(color2), weight));
}

color_space::xyz * color_manipulation::color_calculation::subtract(color_space::xyz * color1, color_space::xyz * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	auto x = color1->x() - weight * color2->x();
	auto y = color1->y() - weight * color2->y();
	auto z = color1->z() - weight * color2->z();
	auto a = include_alpha ? color1->alpha() - weight * color2->alpha() : color1->alpha();

	return new color_space::xyz(x, y, z, a, color1->get_reference_white());
}

color_space::lab * color_manipulation::color_calculation::subtract(color_space::lab * color1, color_space::lab * color2, float weight, bool include_alpha)
{
	if (weight < 0.f || weight > 1.f) throw new std::invalid_argument("Parameter weight has to be in the range [0,1].");

	return color_manipulation::color_converter::to_lab(color_manipulation::color_calculation::subtract(color_manipulation::color_converter::to_xyz(color1), color_manipulation::color_converter::to_xyz(color2), weight));
}

color_space::rgb_truecolor * color_manipulation::color_calculation::average_rgb_true(std::vector<color_space::rgb_truecolor*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[4]{ (unsigned int)0, (unsigned int)0, (unsigned int)0, (unsigned int)0 };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->red();
		sum[1] += colors[i]->green();
		sum[2] += colors[i]->blue();
		sum[3] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::rgb_truecolor(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), include_alpha ? sum[3] / colors.size() : sum[3], colors[0]->get_reference_white());
}

color_space::rgb_deepcolor * color_manipulation::color_calculation::average_rgb_deep(std::vector<color_space::rgb_deepcolor*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[4]{ 0.f, 0.f, 0.f, 0.f };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->red();
		sum[1] += colors[i]->green();
		sum[2] += colors[i]->blue();
		sum[3] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::rgb_deepcolor(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), include_alpha ? sum[3] / colors.size() : sum[3], colors[0]->get_reference_white());
}

color_space::grey_truecolor * color_manipulation::color_calculation::average_grey_true(std::vector<color_space::grey_truecolor*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[2]{ (unsigned int)0, (unsigned int)0 };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->grey();
		sum[1] = include_alpha ? sum[1] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::grey_truecolor(sum[0] / colors.size(), include_alpha ? sum[1] / colors.size() : sum[1], colors[0]->get_reference_white());
}

color_space::grey_deepcolor * color_manipulation::color_calculation::average_grey_deep(std::vector<color_space::grey_deepcolor*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[2]{ 0.f, 0.f };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->grey();
		sum[1] = include_alpha ? sum[1] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::grey_deepcolor(sum[0] / colors.size(), include_alpha ? sum[1] / colors.size() : sum[1], colors[0]->get_reference_white());
}

color_space::cmyk * color_manipulation::color_calculation::average_cmyk(std::vector<color_space::cmyk*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[5]{ 0.f, 0.f, 0.f, 0.f, 0.f};
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->cyan();
		sum[1] += colors[i]->magenta();
		sum[2] += colors[i]->yellow();
		sum[3] += colors[i]->black();
		sum[4] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::cmyk(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), sum[3] / colors.size(), include_alpha ? sum[4] / colors.size() : sum[4], colors[0]->get_reference_white());
}

color_space::hsv * color_manipulation::color_calculation::average_hsv(std::vector<color_space::hsv*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[4]{ 0.f, 0.f, 0.f, 0.f };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->hue();
		sum[1] += colors[i]->saturation();
		sum[2] += colors[i]->value();
		sum[3] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::hsv(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), include_alpha ? sum[3] / colors.size() : sum[3], colors[0]->get_reference_white());
}

color_space::hsl * color_manipulation::color_calculation::average_hsl(std::vector<color_space::hsl*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[4]{ 0.f, 0.f, 0.f, 0.f };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->hue();
		sum[1] += colors[i]->saturation();
		sum[2] += colors[i]->lightness();
		sum[3] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::hsl(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), include_alpha ? sum[3] / colors.size() : sum[3], colors[0]->get_reference_white());
}

color_space::xyz * color_manipulation::color_calculation::average_xyz(std::vector<color_space::xyz*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[4]{ 0.f, 0.f, 0.f, 0.f };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->x();
		sum[1] += colors[i]->y();
		sum[2] += colors[i]->z();
		sum[3] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::xyz(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), include_alpha ? sum[3] / colors.size() : sum[3], colors[0]->get_reference_white());
}

color_space::lab * color_manipulation::color_calculation::average_lab(std::vector<color_space::lab*> colors, bool include_alpha)
{
	if (colors.empty()) throw new std::invalid_argument("Parameter colors cannot be empty.");

	auto sum = new float[4]{ 0.f, 0.f, 0.f, 0.f };
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		sum[0] += colors[i]->luminance();
		sum[1] += colors[i]->a();
		sum[2] += colors[i]->b();
		sum[3] = include_alpha ? sum[3] + colors[i]->alpha() : colors[0]->alpha();
	}
	return new color_space::lab(sum[0] / colors.size(), sum[1] / colors.size(), sum[2] / colors.size(), include_alpha ? sum[3] / colors.size() : sum[3], colors[0]->get_reference_white());
}

float * color_manipulation::color_calculation::convert_to_vector(float hue, float saturation, float third_component)
{
	auto x = cosf(hue / 180.f * (float)M_PI) * saturation;
	auto y = sinf(hue / 180.f * (float)M_PI) * saturation;
	auto z = third_component;

	return new float[3]{ x, y, z };
}

float * color_manipulation::color_calculation::convert_from_vector(float * color)
{
	auto x = std::atan2(color[1], color[0]) * 180.f / (float)M_PI;
	auto y = std::sqrtf(std::powf(color[0], 2.f) + std::powf(color[1], 2.f));
	auto z = color[2];
	return new float[3]{ (float)x, (float)y, (float)z };
}