#pragma once

#include "ColorSpaces\cmyk.h"
#include "ColorSpaces\grey_deepcolor.h"
#include "ColorSpaces\grey_truecolor.h"
#include "ColorSpaces\hsl.h"
#include "ColorSpaces\hsv.h"
#include "ColorSpaces\lab.h"
#include "ColorSpaces\rgb_deepcolor.h"
#include "ColorSpaces\rgb_truecolor.h"
#include "ColorSpaces\xyz.h"

#include <string>

namespace ColorManipulation
{
	struct reference_white
	{
		reference_white(float x, float y, float z) : x(x), y(y), z(z) { }
		float x;
		float y;
		float z;
	};

	class reference_white_presets
	{
	public:
		static reference_white CIE_D50;
		static reference_white CIE_D55;
		static reference_white CIE_D65;
		static reference_white CIE_Standard_Illuminant_A;
		static reference_white CIE_Standard_Illuminant_C;
		static reference_white Equal_Energy_Radiator;
		static reference_white ICC;
	};

	class color_converter
	{
	public:
		static ColorSpaces::rgb_truecolor hexcode_to_rgb_true(std::string hex_code);
		static ColorSpaces::rgb_deepcolor rgb_true_to_rgb_deep(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::grey_truecolor rgb_true_to_grey_true(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::grey_deepcolor rgb_true_to_grey_deep(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::cmyk rgb_true_to_cmyk(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::hsv rgb_true_to_hsv(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::hsl rgb_true_to_hsl(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::xyz rgb_true_to_xyz(ColorSpaces::rgb_truecolor color);
		static ColorSpaces::lab rgb_true_to_lab(ColorSpaces::rgb_truecolor color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor rgb_deep_to_rgb_true(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::grey_truecolor rgb_deep_to_grey_true(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::grey_deepcolor rgb_deep_to_grey_deep(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::cmyk rgb_deep_to_cmyk(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::hsv rgb_deep_to_hsv(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::hsl rgb_deep_to_hsl(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::xyz rgb_deep_to_xyz(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::lab rgb_deep_to_lab(ColorSpaces::rgb_deepcolor color, reference_white reference = reference_white_presets::CIE_D65);
		static ColorSpaces::rgb_deepcolor rgb_deep_to_linear_srgb_deep(ColorSpaces::rgb_deepcolor color);
		static ColorSpaces::rgb_deepcolor linear_srgb_deep_to_rgb_deep(ColorSpaces::rgb_deepcolor color);

		static ColorSpaces::rgb_truecolor grey_true_to_rgb_true(ColorSpaces::grey_truecolor color);
		static ColorSpaces::rgb_deepcolor grey_true_to_rgb_deep(ColorSpaces::grey_truecolor color);
		static ColorSpaces::grey_deepcolor grey_true_to_grey_deep(ColorSpaces::grey_truecolor color);
		static ColorSpaces::cmyk grey_true_to_cmyk(ColorSpaces::grey_truecolor color);
		static ColorSpaces::hsv grey_true_to_hsv(ColorSpaces::grey_truecolor color);
		static ColorSpaces::hsl grey_true_to_hsl(ColorSpaces::grey_truecolor color);
		static ColorSpaces::xyz grey_true_to_xyz(ColorSpaces::grey_truecolor color);
		static ColorSpaces::lab grey_true_to_lab(ColorSpaces::grey_truecolor color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor grey_deep_to_rgb_true(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::rgb_deepcolor grey_deep_to_rgb_deep(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::grey_truecolor grey_deep_to_grey_true(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::cmyk grey_deep_to_cmyk(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::hsv grey_deep_to_hsv(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::hsl grey_deep_to_hsl(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::xyz grey_deep_to_xyz(ColorSpaces::grey_deepcolor color);
		static ColorSpaces::lab grey_deep_to_lab(ColorSpaces::grey_deepcolor color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor cmyk_to_rgb_true(ColorSpaces::cmyk color);
		static ColorSpaces::rgb_deepcolor cmyk_to_rgb_deep(ColorSpaces::cmyk color);
		static ColorSpaces::grey_truecolor cmyk_to_grey_true(ColorSpaces::cmyk color);
		static ColorSpaces::grey_deepcolor cmyk_to_grey_deep(ColorSpaces::cmyk color);
		static ColorSpaces::hsv cmyk_to_hsv(ColorSpaces::cmyk color);
		static ColorSpaces::hsl cmyk_to_hsl(ColorSpaces::cmyk color);
		static ColorSpaces::xyz cmyk_to_xyz(ColorSpaces::cmyk color);
		static ColorSpaces::lab cmyk_to_lab(ColorSpaces::cmyk color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor hsv_to_rgb_true(ColorSpaces::hsv color);
		static ColorSpaces::rgb_deepcolor hsv_to_rgb_deep(ColorSpaces::hsv color);
		static ColorSpaces::grey_truecolor hsv_to_grey_true(ColorSpaces::hsv color);
		static ColorSpaces::grey_deepcolor hsv_to_grey_deep(ColorSpaces::hsv color);
		static ColorSpaces::cmyk hsv_to_cmyk(ColorSpaces::hsv color);
		static ColorSpaces::hsl hsv_to_hsl(ColorSpaces::hsv color);
		static ColorSpaces::xyz hsv_to_xyz(ColorSpaces::hsv color);
		static ColorSpaces::lab hsv_to_lab(ColorSpaces::hsv color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor hsl_to_rgb_true(ColorSpaces::hsl color);
		static ColorSpaces::rgb_deepcolor hsl_to_rgb_deep(ColorSpaces::hsl color);
		static ColorSpaces::grey_truecolor hsl_to_grey_true(ColorSpaces::hsl color);
		static ColorSpaces::grey_deepcolor hsl_to_grey_deep(ColorSpaces::hsl color);
		static ColorSpaces::cmyk hsl_to_cmyk(ColorSpaces::hsl color);
		static ColorSpaces::hsv hsl_to_hsv(ColorSpaces::hsl color);
		static ColorSpaces::xyz hsl_to_xyz(ColorSpaces::hsl color);
		static ColorSpaces::lab hsl_to_lab(ColorSpaces::hsl color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor xyz_to_rgb_true(ColorSpaces::xyz color);
		static ColorSpaces::rgb_deepcolor xyz_to_rgb_deep(ColorSpaces::xyz color);
		static ColorSpaces::grey_truecolor xyz_to_grey_true(ColorSpaces::xyz color);
		static ColorSpaces::grey_deepcolor xyz_to_grey_deep(ColorSpaces::xyz color);
		static ColorSpaces::cmyk xyz_to_cmyk(ColorSpaces::xyz color);
		static ColorSpaces::hsv xyz_to_hsv(ColorSpaces::xyz color);
		static ColorSpaces::hsl xyz_to_hsl(ColorSpaces::xyz color);
		static ColorSpaces::lab xyz_to_lab(ColorSpaces::xyz color, reference_white reference = reference_white_presets::CIE_D65);

		static ColorSpaces::rgb_truecolor lab_to_rgb_true(ColorSpaces::lab color);
		static ColorSpaces::rgb_deepcolor lab_to_rgb_deep(ColorSpaces::lab color);
		static ColorSpaces::grey_truecolor lab_to_grey_true(ColorSpaces::lab color);
		static ColorSpaces::grey_deepcolor lab_to_grey_deep(ColorSpaces::lab color);
		static ColorSpaces::cmyk lab_to_cmyk(ColorSpaces::lab color);
		static ColorSpaces::hsv lab_to_hsv(ColorSpaces::lab color);
		static ColorSpaces::hsl lab_to_hsl(ColorSpaces::lab color);
		static ColorSpaces::xyz lab_to_xyz(ColorSpaces::lab color);
	};
}
