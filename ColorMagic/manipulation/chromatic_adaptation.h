/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_converter.h"
#include "..\spaces\color_base.h"
#include "..\utils\matrix.h"

#include <math.h>

namespace color_manipulation
{
	//! Static class for chromatic adaptation.
	/*!
	* This static class implements von Kries, Bradford, XYZ Scaling and CMCCAT2000 as chromatic adaptation methods.
	*/
	class chromatic_adaptation
	{
	public:
		//! Transforms a given color with the given target white point by using von Kies method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using von Kies matrices and finally the result is converted back to 
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* von_kries_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using Bradford method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using Bradford matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* bradford_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using Bradford method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using Bradford matrices and finally the result is converted back to
		* input color space. This version of Bradford igonores the non-linear correction in the blue area. 
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* bradford_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using XYZ Scale method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using XYZ Scale matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* xyz_scale_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using Sharp method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using Sharp matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* sharp_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using CMCCAT97 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CMCCAT97 matrices and finally the result is converted back to
		* input color space. This version of CMCCAT97 igonores the degree of adaption.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* cmccat97_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using CMCCAT97 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CMCCAT97 matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \param f Defines the surrounding conditions. Use 1.f for normal, 0.9f for dim and 0.8f for dark conditions.
		* \param adapting_field_luminance The luminance of the adapting field (\sa calculate_adapting_luminance()). Default value = 100
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* cmccat97_adaptation(color_space::color_base* color, color_space::white_point* target_white_point, float f, float adapting_field_luminance = 100.f);

		//! Transforms a given color with the given target white point by using CMCCAT2000 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CMCCAT2000 matrices and finally the result is converted back to
		* input color space. This version of CMCCAT2000 igonores the degree of adaption. 
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* cmccat2000_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using CMCCAT2000 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CMCCAT2000 matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \param f Defines the surrounding conditions. Use 1.f for normal, 0.9f for dim and 0.8f for dark conditions.
		* \param adapting_field_luminance The luminance of the adapting field (\sa calculate_adapting_luminance()). Default value = 100 
		* \param reference_field_luminance The luminance of the reference field. Default value = 100
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* cmccat2000_adaptation(color_space::color_base* color, color_space::white_point* target_white_point, float f, float adapting_field_luminance = 100.f, float reference_field_luminance = 100.f);

		//! Transforms a given color with the given target white point by using CAT02 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CAT02 matrices and finally the result is converted back to
		* input color space. This version of CAT02 igonores the degree of adaption.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* cat02_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using CAT02 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CAT02 matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \param f Defines the surrounding conditions. Use 1.f for normal, 0.9f for dim and 0.8f for dark conditions.
		* \param adapting_field_luminance The luminance of the adapting field (\sa calculate_adapting_luminance()). Default value = 100
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* cat02_adaptation(color_space::color_base* color, color_space::white_point* target_white_point, float f, float adapting_field_luminance = 100.f);

		//! Helper method to calculate the adapting luminance needed in the non-simplified versions of CMCCAT97 and CMCCAT2000.
		/*!
		* Helper method to calculate the adapting luminance needed in the non-simplified versions of CMCCAT97 and CMCCAT2000.
		* \param luminance The luminance of the target white point under the test illuminant (in cd/m^2).
		* \param bg_luminance_factor The luminance factor of the background. If assuming the perfect diffusor for the source 
		* and target whites their luminance factors both will be 100.
		* \return The adapting luminance.
		*/
		static float calculate_adapting_luminance(float luminance, float bg_luminance_factor = 100.f)
		{
			return luminance * bg_luminance_factor / 100.f;
		}

	protected:

		//! Helper method that actually does the transformation while the public methods are just container functions.
		/*!
		* Helper method that calculates the transformation matrix.
		* \param color The color to transform.
		* \param target_color_space The target color space definition containing the target white point definition.
		* \param mat The adaptation matrix of the chosen method.
		* \param inverted_mat The inverted adaptation matrix of the chosen method.
		* \return The transformed color in the input color space.
		*/
		static color_space::color_base* do_adaption(color_space::color_base* color, color_space::white_point* target_white_point, matrix<float> mat, matrix<float> inverted_mat);

		//! Adaptation matrix of the von Kries method.
		/*!
		* Adaptation matrix of the von Kries method.
		*/
		static matrix<float> m_von_kries;

		//! Inverted adaptation matrix of the von Kries method.
		/*!
		* Inverted adaptation matrix of the von Kries method.
		*/
		static matrix<float> m_inverted_von_kries;

		//! Adaptation matrix of the Bradford method.
		/*!
		* Adaptation matrix of the Bradford method.
		*/
		static matrix<float> m_bradford;

		//! Inverted adaptation matrix of the Bradford method.
		/*!
		* Inverted adaptation matrix of the Bradford method.
		*/
		static matrix<float> m_inverted_bradford;

		//! Adaptation matrix of the XYZ Scale method.
		/*!
		* Adaptation matrix of the XYZ Scale method.
		*/
		static matrix<float> m_xyz_scale;

		//! Inverted adaptation matrix of the XYZ Scale method.
		/*!
		* Inverted adaptation matrix of the XYZ Scale method.
		*/
		static matrix<float> m_inverted_xyz_scale;

		//! Adaptation matrix of the Sharp method.
		/*!
		* Adaptation matrix of the Sharp method.
		*/
		static matrix<float> m_sharp;

		//! Inverted adaptation matrix of the Sharp method.
		/*!
		* Inverted adaptation matrix of the Sharp method.
		*/
		static matrix<float> m_inverted_sharp;

		//! Adaptation matrix of the CMCCAT97 method.
		/*!
		* Adaptation matrix of the CMCCAT97 method.
		*/
		static matrix<float> m_cmccat97;

		//! Inverted adaptation matrix of the CMCCAT97 method.
		/*!
		* Inverted adaptation matrix of the CMCCAT97 method.
		* Although the matrix equals bradford I added it to avoid confusion.
		*/
		static matrix<float> m_inverted_cmccat97;

		//! Adaptation matrix of the CMCCAT2000 method.
		/*!
		* Adaptation matrix of the CMCCAT2000 method.
		* Although the matrix equals bradford I added it to avoid confusion.
		*/
		static matrix<float> m_cmccat2000;

		//! Inverted adaptation matrix of the CMCCAT2000 method.
		/*!
		* Inverted adaptation matrix of the CMCCAT2000 method.
		*/
		static matrix<float> m_inverted_cmccat2000;

		//! Adaptation matrix of the CAT02 method.
		/*!
		* Adaptation matrix of the CAT02 method.
		*/
		static matrix<float> m_cat02;

		//! Inverted adaptation matrix of the CAT02 method.
		/*!
		* Inverted adaptation matrix of the CAT02 method.
		*/
		static matrix<float> m_inverted_cat02;
	};
}