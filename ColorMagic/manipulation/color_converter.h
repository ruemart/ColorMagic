#pragma once

#include "..\utils\color_type.h"
#include "..\spaces\icolor.h"
#include "..\spaces\cmyk.h"
#include "..\spaces\grey_deepcolor.h"
#include "..\spaces\grey_truecolor.h"
#include "..\spaces\hsl.h"
#include "..\spaces\hsv.h"
#include "..\spaces\lab.h"
#include "..\spaces\rgb_deepcolor.h"
#include "..\spaces\rgb_truecolor.h"
#include "..\spaces\xyz.h"

#include <string>
#include <algorithm>

namespace color_manipulation
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
		static color_space::icolor* convertTo(color_space::icolor* in_color, color_type out_color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_rgb_true(color_space::rgb_truecolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_rgb_deep(color_space::rgb_deepcolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_grey_true(color_space::grey_truecolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_grey_deep(color_space::grey_deepcolor* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_cmyk(color_space::cmyk* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_hsv(color_space::hsv* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_hsl(color_space::hsl* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_xyz(color_space::xyz* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::icolor* from_lab(color_space::lab* in_color, color_type out_type, reference_white reference = reference_white_presets::CIE_D65);

	protected:
		static color_space::rgb_deepcolor* rgb_true_to_rgb_deep(color_space::rgb_truecolor* color);
		static color_space::grey_truecolor* rgb_true_to_grey_true(color_space::rgb_truecolor* color);
		static color_space::grey_deepcolor* rgb_true_to_grey_deep(color_space::rgb_truecolor* color);
		static color_space::cmyk* rgb_true_to_cmyk(color_space::rgb_truecolor* color);
		static color_space::hsv* rgb_true_to_hsv(color_space::rgb_truecolor* color);
		static color_space::hsl* rgb_true_to_hsl(color_space::rgb_truecolor* color);
		static color_space::xyz* rgb_true_to_xyz(color_space::rgb_truecolor* color);
		static color_space::lab* rgb_true_to_lab(color_space::rgb_truecolor* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* rgb_deep_to_rgb_true(color_space::rgb_deepcolor* color);
		static color_space::grey_truecolor* rgb_deep_to_grey_true(color_space::rgb_deepcolor* color);
		static color_space::grey_deepcolor* rgb_deep_to_grey_deep(color_space::rgb_deepcolor* color);
		static color_space::cmyk* rgb_deep_to_cmyk(color_space::rgb_deepcolor* color);
		static color_space::hsv* rgb_deep_to_hsv(color_space::rgb_deepcolor* color);
		static color_space::hsl* rgb_deep_to_hsl(color_space::rgb_deepcolor* color);
		static color_space::xyz* rgb_deep_to_xyz(color_space::rgb_deepcolor* color);
		static color_space::lab* rgb_deep_to_lab(color_space::rgb_deepcolor* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::rgb_deepcolor* rgb_deep_to_linear_srgb_deep(color_space::rgb_deepcolor* color);
		static color_space::rgb_deepcolor* linear_srgb_deep_to_rgb_deep(color_space::rgb_deepcolor* color);

		static color_space::rgb_truecolor* grey_true_to_rgb_true(color_space::grey_truecolor* color);
		static color_space::rgb_deepcolor* grey_true_to_rgb_deep(color_space::grey_truecolor* color);
		static color_space::grey_deepcolor* grey_true_to_grey_deep(color_space::grey_truecolor* color);
		static color_space::cmyk* grey_true_to_cmyk(color_space::grey_truecolor* color);
		static color_space::hsv* grey_true_to_hsv(color_space::grey_truecolor* color);
		static color_space::hsl* grey_true_to_hsl(color_space::grey_truecolor* color);
		static color_space::xyz* grey_true_to_xyz(color_space::grey_truecolor* color);
		static color_space::lab* grey_true_to_lab(color_space::grey_truecolor* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* grey_deep_to_rgb_true(color_space::grey_deepcolor* color);
		static color_space::rgb_deepcolor* grey_deep_to_rgb_deep(color_space::grey_deepcolor* color);
		static color_space::grey_truecolor* grey_deep_to_grey_true(color_space::grey_deepcolor* color);
		static color_space::cmyk* grey_deep_to_cmyk(color_space::grey_deepcolor* color);
		static color_space::hsv* grey_deep_to_hsv(color_space::grey_deepcolor* color);
		static color_space::hsl* grey_deep_to_hsl(color_space::grey_deepcolor* color);
		static color_space::xyz* grey_deep_to_xyz(color_space::grey_deepcolor* color);
		static color_space::lab* grey_deep_to_lab(color_space::grey_deepcolor* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* cmyk_to_rgb_true(color_space::cmyk* color);
		static color_space::rgb_deepcolor* cmyk_to_rgb_deep(color_space::cmyk* color);
		static color_space::grey_truecolor* cmyk_to_grey_true(color_space::cmyk* color);
		static color_space::grey_deepcolor* cmyk_to_grey_deep(color_space::cmyk* color);
		static color_space::hsv* cmyk_to_hsv(color_space::cmyk* color);
		static color_space::hsl* cmyk_to_hsl(color_space::cmyk* color);
		static color_space::xyz* cmyk_to_xyz(color_space::cmyk* color);
		static color_space::lab* cmyk_to_lab(color_space::cmyk* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* hsv_to_rgb_true(color_space::hsv* color);
		static color_space::rgb_deepcolor* hsv_to_rgb_deep(color_space::hsv* color);
		static color_space::grey_truecolor* hsv_to_grey_true(color_space::hsv* color);
		static color_space::grey_deepcolor* hsv_to_grey_deep(color_space::hsv* color);
		static color_space::cmyk* hsv_to_cmyk(color_space::hsv* color);
		static color_space::hsl* hsv_to_hsl(color_space::hsv* color);
		static color_space::xyz* hsv_to_xyz(color_space::hsv* color);
		static color_space::lab* hsv_to_lab(color_space::hsv* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* hsl_to_rgb_true(color_space::hsl* color);
		static color_space::rgb_deepcolor* hsl_to_rgb_deep(color_space::hsl* color);
		static color_space::grey_truecolor* hsl_to_grey_true(color_space::hsl* color);
		static color_space::grey_deepcolor* hsl_to_grey_deep(color_space::hsl* color);
		static color_space::cmyk* hsl_to_cmyk(color_space::hsl* color);
		static color_space::hsv* hsl_to_hsv(color_space::hsl* color);
		static color_space::xyz* hsl_to_xyz(color_space::hsl* color);
		static color_space::lab* hsl_to_lab(color_space::hsl* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* xyz_to_rgb_true(color_space::xyz* color);
		static color_space::rgb_deepcolor* xyz_to_rgb_deep(color_space::xyz* color);
		static color_space::grey_truecolor* xyz_to_grey_true(color_space::xyz* color);
		static color_space::grey_deepcolor* xyz_to_grey_deep(color_space::xyz* color);
		static color_space::cmyk* xyz_to_cmyk(color_space::xyz* color);
		static color_space::hsv* xyz_to_hsv(color_space::xyz* color);
		static color_space::hsl* xyz_to_hsl(color_space::xyz* color);
		static color_space::lab* xyz_to_lab(color_space::xyz* color, reference_white reference = reference_white_presets::CIE_D65);

		static color_space::rgb_truecolor* lab_to_rgb_true(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::rgb_deepcolor* lab_to_rgb_deep(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::grey_truecolor* lab_to_grey_true(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::grey_deepcolor* lab_to_grey_deep(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::cmyk* lab_to_cmyk(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::hsv* lab_to_hsv(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::hsl* lab_to_hsl(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);
		static color_space::xyz* lab_to_xyz(color_space::lab* color, reference_white reference = reference_white_presets::CIE_D65);

	private:
		static float xyz_to_lab_helper(float color_component);
		static float lab_to_xyz_helper(float color_component, bool out_y_component = false);
		static float round_float_to_n_decimals(float in_float, float n);
		static float clamp_float(float in_float, float bottom, float top);
	};
}
