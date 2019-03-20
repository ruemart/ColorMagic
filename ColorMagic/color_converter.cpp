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
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::rgb_deepcolor ColorManipulation::color_converter::rgb_true_to_rgb_deep(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::rgb_deepcolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::rgb_true_to_grey_true(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::rgb_true_to_grey_deep(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::rgb_true_to_cmyk(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::rgb_true_to_hsv(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::rgb_true_to_hsl(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::rgb_true_to_xyz(ColorSpaces::rgb_truecolor color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::rgb_true_to_lab(ColorSpaces::rgb_truecolor color, reference_white reference)
{
	return ColorSpaces::lab();
}

ColorSpaces::rgb_truecolor ColorManipulation::color_converter::rgb_deep_to_rgb_true(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::rgb_truecolor();
}

ColorSpaces::grey_truecolor ColorManipulation::color_converter::rgb_deep_to_grey_true(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::grey_truecolor();
}

ColorSpaces::grey_deepcolor ColorManipulation::color_converter::rgb_deep_to_grey_deep(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::grey_deepcolor();
}

ColorSpaces::cmyk ColorManipulation::color_converter::rgb_deep_to_cmyk(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::cmyk();
}

ColorSpaces::hsv ColorManipulation::color_converter::rgb_deep_to_hsv(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::hsv();
}

ColorSpaces::hsl ColorManipulation::color_converter::rgb_deep_to_hsl(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::hsl();
}

ColorSpaces::xyz ColorManipulation::color_converter::rgb_deep_to_xyz(ColorSpaces::rgb_deepcolor color)
{
	return ColorSpaces::xyz();
}

ColorSpaces::lab ColorManipulation::color_converter::rgb_deep_to_lab(ColorSpaces::rgb_deepcolor color, reference_white reference)
{
	return ColorSpaces::lab();
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
