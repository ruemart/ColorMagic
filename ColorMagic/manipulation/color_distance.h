/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// (See accompanying file LICENSE.txt

#pragma once

#include "..\utils\color_type.h"
#include "..\spaces\color_base.h"
#include "..\manipulation\color_converter.h"


namespace color_manipulation
{
	//! Static class for color distance calculation.
	/*!
	* This static class implements euclidean distance as well as CIELABs and CMCs delta E calculation methods. 
	*/
	class color_distance
	{
	public:
		//! Static function that calculates the distance of the two given colors by using euclidean distance without the square root.
		/*!
		* The calculation is done in RGB deep color space and returns distances in the range of [0,3] where 0 means equality and 3 means
		* maximum distance (black - white). This method is the fastest but most inaccurate method to calculate the distance of two colors.
		* \sa euclidean_distance(), euclidean_distance_weighted()
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to RGB deep before doing 
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to RGB deep before doing 
		* any calculation.
		* \return The calculated euclidean distance in the range [0,3].
		*/
		static float euclidean_distance_squared(color_space::color_base* color1, color_space::color_base* color2);

		//! Static function that calculates the distance of the two given colors by using euclidean distance.
		/*!
		* The calculation is done in RGB deep color space. By using this function the square root is part of the calculation. The results
		* are in a range of [0,sqrt(3)] where 0 means equality and sqrt(3) means maximum distance (black - white).
		* \sa euclidean_distance_squared(), euclidean_distance_weighted()
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to RGB deep before doing 
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to RGB deep before doing 
		* any calculation.
		* \return The calculated euclidean distance in the range [0,sqrt(3)].
		*/
		static float euclidean_distance(color_space::color_base* color1, color_space::color_base* color2);

		//! Static function that calculates the distance of the two given colors by using weighted euclidean distance.
		/*!
		* The calculation is done in RGB deep color space. By using this function weight factors are used to achieve a better fit to the 
		* perception of the human eye. Therefore the factors 2, 4 and 3 are applied to the three color chanels (RGB).
		* \sa euclidean_distance_squared(), euclidean_distance() 
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to RGB deep before doing
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to RGB deep before doing
		* any calculation.
		* \return The calculated euclidean distance.
		*/
		static float euclidean_distance_weighted(color_space::color_base* color1, color_space::color_base* color2);

		//! Static function that calculates the distance of the two given colors by using CIELABS delta E formula from 1976.
		/*!
		* The calculation is done in LAB color space and equals euclidean distance.
		* \sa cielab_delta_e_cie94(), cielab_delta_e_cie00(), cmc_delta_e_lc84()
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \return The calculated delta E value.
		*/
		static float cielab_delta_e_cie76(color_space::color_base* color1, color_space::color_base* color2);
		
		//! Static function that calculates the distance of the two given colors by using CIELABS delta E formula from 1994.
		/*!
		* The calculation is done in LAB color space and is far more complex than the euclidean distance. This way it is more accurate but
		* also slower.
		* \sa cielab_delta_e_cie76(), cielab_delta_e_cie00(), cmc_delta_e_lc84()
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param kL identifies the application the distance will be calculated for. Use 1 for graphic arts and 2 for textiles.
		* \param k1 a weight factor that changes depending on the application the distance will be calculated for. Use 0.045 for graphic arts and 0.048 for textiles.
		* \param k2 a weight factor that changes depending on the application the distance will be calculated for. Use 0.015 for graphic arts and 0.014 for textiles.
		* \param kC a weight factor that is usually 1 but may be changed to adjust the formula on different applications.
		* \param kH a weight factor that is usually 1 but may be changed to adjust the formula on different applications.
		* \return The calculated delta E value.
		*/
		static float cielab_delta_e_cie94(color_space::color_base* color1, color_space::color_base* color2, float kL = 1.f, float k1 = 0.045f, float k2 = 0.015f, float kC = 1.f, float kH = 1.f);

		//! Static function that calculates the distance of the two given colors by using CIELABS delta E formula from 2000.
		/*!
		* The calculation is done in LAB color space and is the most complex distance formula. This way it is also the most accurate and slowest one.
		* \sa cielab_delta_e_cie76(), cielab_delta_e_cie94(), cmc_delta_e_lc84()
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param kL identifies the application the distance will be calculated for. Use 1 for graphic arts and 2 for textiles.
		* \param k1 a weight factor that changes depending on the application the distance will be calculated for. Use 0.045 for graphic arts and 0.048 for textiles.
		* \param k2 a weight factor that changes depending on the application the distance will be calculated for. Use 0.015 for graphic arts and 0.014 for textiles.
		* \param kC a weight factor that is usually 1 but may be changed to adjust the formula on different applications.
		* \param kH a weight factor that is usually 1 but may be changed to adjust the formula on different applications.
		* \return The calculated delta E value.
		*/
		static float cielab_delta_e_cie00(color_space::color_base* color1, color_space::color_base* color2, float kL = 1.f, float k1 = 0.045f, float k2 = 0.015f, float kC = 1.f, float kH = 1.f);

		//! Static function that calculates the distance of the two given colors by using CMCs delta E formula from 1984.
		/*!
		* The calculation is done in LAB color space and has similar complexity to the CIELAB delte E formula from 2000. This way it is also rather slow.
		* \sa cielab_delta_e_cie76(), cielab_delta_e_cie94(), cielab_delta_e_cie00()
		* \param color1 the first of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param color2 the second of the two colors to compare. Color space does not matter since it will be converted to LAB before doing
		* any calculation.
		* \param lightness factor for weighting the result of the formula. Commonly used values are 1 and 2.
		* \param chroma factor for weighting the result of the formula. Default value is 1.
		* \return The calculated delta E value.
		*/
		static float cmc_delta_e_lc84(color_space::color_base* color1, color_space::color_base* color2, float lightness = 2.f, float chroma = 1.f);

	protected:
		//! Static function that converts from degree to radians.
		/*!
		* Conversion is done via degree * (M_PI / 180).
		* \param degree the degrees value that should be converted to radians.
		* \return The result of the conversion in radians.
		*/
		static float to_rad(float degree);

		//! Static function that converts from radians to degree.
		/*!
		* Conversion is done via degree * (180 / M_PI).
		* \param radians the radians value that should be converted to degree.
		* \return The result of the conversion in degree.
		*/
		static float to_deg(float radians);
	};
}
