/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "..\spaces\color_base.h"
#include "color_converter.h"

namespace color_manipulation
{
	//! Static class for color calculations like mixing two of them.
		/*!
		* This static class implements various functions for color calculations.
		*/
	class color_calculation
	{
	public:
		//! Static function that adds two colors.
		/*!
		* Depending on the type of the first input color the calculation is done differently
		* (additive or subtractive). The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::color_base* add(color_space::color_base* color1, color_space::color_base* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two rgb true colors.
		/*!
		* Adds both rgb true colors in an additive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_truecolor* add(color_space::rgb_truecolor* color1, color_space::rgb_truecolor* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two rgb deep colors.
		/*!
		* Adds both rgb deep colors in an additive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_deepcolor* add(color_space::rgb_deepcolor* color1, color_space::rgb_deepcolor* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two grey true colors.
		/*!
		* Adds both grey true colors in an additive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_truecolor* add(color_space::grey_truecolor* color1, color_space::grey_truecolor* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two grey deep colors.
		/*!
		* Adds both grey deep colors in an additive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_deepcolor* add(color_space::grey_deepcolor* color1, color_space::grey_deepcolor* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two cmyk colors.
		/*!
		* Adds both cmyk colors in a subtractive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::cmyk* add(color_space::cmyk* color1, color_space::cmyk* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two hsv colors.
		/*!
		* Adds both hsv colors in an additive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsv* add(color_space::hsv* color1, color_space::hsv* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two hsl colors.
		/*!
		* Converts both colors to hsv space and adds them. Afterwards the resulting color is converted back to hsl.
		* The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsl* add(color_space::hsl* color1, color_space::hsl* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two xyz colors.
		/*!
		* Adds both xyz colors in an additive way. The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::xyz* add(color_space::xyz* color1, color_space::xyz* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that adds two lab colors.
		/*!
		* Converts both colors to xyz space (which is linear) and adds them. Afterwards the resulting color is converted back to lab.
		* The amount of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight1 The first colors weight in the range [0,1].
		* \param weight2 The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::lab* add(color_space::lab* color1, color_space::lab* color2, float weight1 = 1.f, float weight2 = 1.f, bool include_alpha = false);

		//! Static function that mixes two colors.
		/*!
		* Depending on the type of the first input color the calculation is done differently
		* (additive or subtractive). The mix ratio of the two colors can be varied in the range [0,1] by using their corresponding weights.
		* \param color1 The first of the two colors to add.
		* \param color2 The second of the two colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::color_base* mix(color_space::color_base* color1, color_space::color_base* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in rgb true color space.
		/*!
		* Performs an additive color mix of both rgb true colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two rgb true colors to add.
		* \param color2 The second of the two rgb true colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_truecolor* mix(color_space::rgb_truecolor* color1, color_space::rgb_truecolor* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in rgb deep color space.
		/*!
		* Performs an additive color mix of both rgb deep colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two rgb deep colors to add.
		* \param color2 The second of the two rgb deep colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_deepcolor* mix(color_space::rgb_deepcolor* color1, color_space::rgb_deepcolor* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in grey true color space.
		/*!
		* Performs an additive color mix of both grey true colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two grey true colors to add.
		* \param color2 The second of the two grey true colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_truecolor* mix(color_space::grey_truecolor* color1, color_space::grey_truecolor* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in grey deep color space.
		/*!
		* Performs an additive color mix of both grey deep colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two grey deep colors to add.
		* \param color2 The second of the two grey deep colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_deepcolor* mix(color_space::grey_deepcolor* color1, color_space::grey_deepcolor* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in cmyk color space.
		/*!
		* Performs an subtractive color mix of both cmyk colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two cmyk colors to add.
		* \param color2 The second of the two cmyk colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::cmyk* mix(color_space::cmyk* color1, color_space::cmyk* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in hsv color space.
		/*!
		* Performs an additive color mix of both hsv colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two hsv colors to add.
		* \param color2 The second of the two hsv colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsv* mix(color_space::hsv* color1, color_space::hsv* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in hsl color space.
		/*!
		* Performs an additive color mix of both hsl colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two hsl colors to add.
		* \param color2 The second of the two hsl colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsl* mix(color_space::hsl* color1, color_space::hsl* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in xyz color space.
		/*!
		* Performs an additive color mix of both xyz colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two xyz colors to add.
		* \param color2 The second of the two xyz colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::xyz* mix(color_space::xyz* color1, color_space::xyz* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors in lab color space.
		/*!
		* Performs an additive color mix of both lab colors. The mix ratio of the two colors can be varied in the range [0,1]
		* by using their corresponding weights.
		* \param color1 The first of the two lab colors to add.
		* \param color2 The second of the two lab colors to add.
		* \param weight The first colors weight in the range [0,1]. The second colors weight will be 1 - weight.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::lab* mix(color_space::lab* color1, color_space::lab* color2, float weight = 0.5f, bool include_alpha = false);

		//! Static function that mixes two colors.
		/*!
		* Subtracts both rgb true colors. Depending on the type of the first input color the calculation is done differently.
		* \param color1 The first of the two colors to subtract.
		* \param color2 The second of the two colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::color_base* subtract(color_space::color_base* color1, color_space::color_base* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in rgb true color space.
		/*!
		* Subtracts both rgb true colors.
		* \param color1 The first of the two rgb true colors to subtract.
		* \param color2 The second of the two rgb true colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_truecolor* subtract(color_space::rgb_truecolor* color1, color_space::rgb_truecolor* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in rgb deep color space.
		/*!
		* Subtracts both rgb deep colors.
		* \param color1 The first of the two rgb deep colors to subtract.
		* \param color2 The second of the two rgb deep colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_deepcolor* subtract(color_space::rgb_deepcolor* color1, color_space::rgb_deepcolor* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in grey true color space.
		/*!
		* Subtracts both grey true colors.
		* \param color1 The first of the two grey true colors to subtract.
		* \param color2 The second of the two grey true colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_truecolor* subtract(color_space::grey_truecolor* color1, color_space::grey_truecolor* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in grey deep color space.
		/*!
		* Subtracts both grey deep colors.
		* \param color1 The first of the two grey deep colors to subtract.
		* \param color2 The second of the two grey deep colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_deepcolor* subtract(color_space::grey_deepcolor* color1, color_space::grey_deepcolor* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in cmyk color space.
		/*!
		* Subtracts both cmyk colors.
		* \param color1 The first of the two cmyk colors to subtract.
		* \param color2 The second of the two cmyk colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::cmyk* subtract(color_space::cmyk* color1, color_space::cmyk* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in hsv color space.
		/*!
		* Subtracts both hsv colors.
		* \param color1 The first of the two hsv colors to subtract.
		* \param color2 The second of the two hsv colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsv* subtract(color_space::hsv* color1, color_space::hsv* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in hsl color space.
		/*!
		* Subtracts both hsl colors.
		* \param color1 The first of the two hsl colors to subtract.
		* \param color2 The second of the two hsl colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsl* subtract(color_space::hsl* color1, color_space::hsl* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in xyz color space.
		/*!
		* Subtracts both xyz colors.
		* \param color1 The first of the two xyz colors to subtract.
		* \param color2 The second of the two xyz colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::xyz* subtract(color_space::xyz* color1, color_space::xyz* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that subtracts two colors in lab color space.
		/*!
		* Subtracts both lab colors.
		* \param color1 The first of the two lab colors to subtract.
		* \param color2 The second of the two lab colors to subtract.
		* \param weight The second colors weight in the range [0,1].
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::lab* subtract(color_space::lab* color1, color_space::lab* color2, float weight = 1.f, bool include_alpha = false);

		//! Static function that averages a vector of rgb true colors.
		/*!
		* Averages each rgb component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_truecolor* average_rgb_true(std::vector<color_space::rgb_truecolor*> colors, bool include_alpha = false);

		//! Static function that averages a vector of rgb deep colors.
		/*!
		* Averages each rgb component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::rgb_deepcolor* average_rgb_deep(std::vector<color_space::rgb_deepcolor*> colors, bool include_alpha = false);

		//! Static function that averages a vector of grey true colors.
		/*!
		* Averages the grey component of the colors.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_truecolor* average_grey_true(std::vector<color_space::grey_truecolor*> colors, bool include_alpha = false);

		//! Static function that averages a vector of grey deep colors.
		/*!
		* Averages the grey component of the colors.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::grey_deepcolor* average_grey_deep(std::vector<color_space::grey_deepcolor*> colors, bool include_alpha = false);

		//! Static function that averages a vector of cmyk colors.
		/*!
		* Averages each cmyk component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::cmyk* average_cmyk(std::vector<color_space::cmyk*> colors, bool include_alpha = false);

		//! Static function that averages a vector of hsv colors.
		/*!
		* Averages each hsv component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsv* average_hsv(std::vector<color_space::hsv*> colors, bool include_alpha = false);

		//! Static function that averages a vector of hsl colors.
		/*!
		* Averages each hsl component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::hsl* average_hsl(std::vector<color_space::hsl*> colors, bool include_alpha = false);

		//! Static function that averages a vector of xyz colors.
		/*!
		* Averages each xyz component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::xyz* average_xyz(std::vector<color_space::xyz*> colors, bool include_alpha = false);

		//! Static function that averages a vector of lab colors.
		/*!
		* Averages each lab component of the colors seperately.
		* \param colors The vector of colors to average.
		* \param include_alpha Whether alpha should be included in the calculation or not.
		*/
		static color_space::lab* average_lab(std::vector<color_space::lab*> colors, bool include_alpha = false);

	private:
		//! Converts a hsl or hsv color to a vector.
		/*!
		* Converts a hsl or hsv color to a vector.
		* \param color The color to convert.
		* \return The hsl or hsv color converted to a float array.
		*/
		static float* convert_to_vector(float hue, float saturation, float third_component);

		//! Converts a float array to a hsl or hsv color.
		/*!
		* Converts a float array to a hsl or hsv color.
		* \param color The color to convert as float array.
		* \return The hsl or hsv color as float array.
		*/
		static float* convert_from_vector(float* color);
	};
}
