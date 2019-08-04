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
	class color_adjustments
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
		color_space::color_base* von_kries_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using Bradford method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using Bradford matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* bradford_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using Bradford method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using Bradford matrices and finally the result is converted back to
		* input color space. This version of Bradford igonores the non-linear correction in the blue area. 
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* bradford_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using XYZ Scale method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using XYZ Scale matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* xyz_scale_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using Sharp method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using Sharp matrices and finally the result is converted back to
		* input color space.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* sharp_adaptation(color_space::color_base* color, color_space::white_point* target_white_point);

		//! Transforms a given color with the given target white point by using CMCCAT97 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CMCCAT97 matrices and finally the result is converted back to
		* input color space. This version of CMCCAT97 igonores the degree of adaption.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* cmccat97_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

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
		color_space::color_base* cmccat97_adaptation(color_space::color_base* color, color_space::white_point* target_white_point, float f, float adapting_field_luminance = 100.f);

		//! Transforms a given color with the given target white point by using CMCCAT2000 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CMCCAT2000 matrices and finally the result is converted back to
		* input color space. This version of CMCCAT2000 igonores the degree of adaption. 
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* cmccat2000_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

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
		color_space::color_base* cmccat2000_adaptation(color_space::color_base* color, color_space::white_point* target_white_point, float f, float adapting_field_luminance = 100.f, float reference_field_luminance = 100.f);

		//! Transforms a given color with the given target white point by using CAT02 method.
		/*!
		* Transforms a given color with the given target white point. The color will first be converted to xyz space.
		* Afterwards the transformation is done using CAT02 matrices and finally the result is converted back to
		* input color space. This version of CAT02 igonores the degree of adaption.
		* \param color The color to convert. If the color is not in xyz space it will be converted first.
		* \param target_white_point The target white point.
		* \return The transformed color in the input color space.
		*/
		color_space::color_base* cat02_adaptation_simplified(color_space::color_base* color, color_space::white_point* target_white_point);

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
		color_space::color_base* cat02_adaptation(color_space::color_base* color, color_space::white_point* target_white_point, float f, float adapting_field_luminance = 100.f);

		//! Helper method to calculate the adapting luminance needed in the non-simplified versions of CMCCAT97 and CMCCAT2000.
		/*!
		* Helper method to calculate the adapting luminance needed in the non-simplified versions of CMCCAT97 and CMCCAT2000.
		* \param luminance The luminance of the target white point under the test illuminant (in cd/m^2).
		* \param bg_luminance_factor The luminance factor of the background. If assuming the perfect diffusor for the source 
		* and target whites their luminance factors both will be 100.
		* \return The adapting luminance.
		*/
		float calculate_adapting_luminance(float luminance, float bg_luminance_factor = 100.f)
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
		color_space::color_base* do_adaption(color_space::color_base* color, color_space::white_point* target_white_point, matrix<float> mat, matrix<float> inverted_mat);

		//! Adaptation matrix of the von Kries method.
		/*!
		* Adaptation matrix of the von Kries method.
		*/
		matrix<float> m_von_kries = matrix<float>(3, 3, std::vector<float> 
		{
			0.40024f, 0.7076f, -0.08081f, 
			-0.2263f, 1.16532f, 0.0457f, 
			0.f, 0.f, 0.91822f
		});

		//! Inverted adaptation matrix of the von Kries method.
		/*!
		* Inverted adaptation matrix of the von Kries method.
		*/
		matrix<float> m_inverted_von_kries = matrix<float>(3, 3, std::vector<float> 
		{
			1.8599364f, -1.1293816f, 0.2198974f,
			0.3611914f, 0.6388125f, -0.0000064f,
			0.f, 0.f, 1.0890636f 
		});

		//! Adaptation matrix of the Bradford method.
		/*!
		* Adaptation matrix of the Bradford method.
		*/
		matrix<float> m_bradford = matrix<float>(3, 3, std::vector<float>
		{
			0.8951f, 0.2664f, -0.1614f,
			-0.7502f, 1.7135f, 0.0367f,
			0.0389f, -0.0685f, 1.0296f
		});

		//! Inverted adaptation matrix of the Bradford method.
		/*!
		* Inverted adaptation matrix of the Bradford method.
		*/
		matrix<float> m_inverted_bradford = matrix<float>(3, 3, std::vector<float>
		{
			0.9869929f, -0.1470543f, 0.1599627f,
			0.4323053f, 0.5183603f, 0.0492912f,
			-0.0085287f, 0.0400428f, 0.9684867f
		});

		//! Adaptation matrix of the XYZ Scale method.
		/*!
		* Adaptation matrix of the XYZ Scale method.
		*/
		matrix<float> m_xyz_scale = matrix<float>(3, 3, std::vector<float>
		{
			1.f, 0.f, -0.f,
			-0.f, 1.f, 0.f,
			0.f, -0.f, 1.f
		});

		//! Inverted adaptation matrix of the XYZ Scale method.
		/*!
		* Inverted adaptation matrix of the XYZ Scale method.
		*/
		matrix<float> m_inverted_xyz_scale = matrix<float>(3, 3, std::vector<float>
		{
			1.f, -0.f, 0.f,
			0.f, 1.f, 0.f,
			-0.f, 0.f, 1.f
		});

		//! Adaptation matrix of the Sharp method.
		/*!
		* Adaptation matrix of the Sharp method.
		*/
		matrix<float> m_sharp = matrix<float>(3, 3, std::vector<float>
		{
			1.2694f, -0.0988f, -0.1706f,
			-0.8364f, 1.8006f, 0.0357f,
			0.0297f, -0.0315f, 1.0018f
		});

		//! Inverted adaptation matrix of the Sharp method.
		/*!
		* Inverted adaptation matrix of the Sharp method.
		*/
		matrix<float> m_inverted_sharp = matrix<float>(3, 3, std::vector<float>
		{
			0.81563f, 0.04715f, 0.13722f,
			0.37911f, 0.57694f, 0.044f,
			-0.01226f, 0.01674f, 0.99552f
		});

		//! Adaptation matrix of the CMCCAT97 method.
		/*!
		* Adaptation matrix of the CMCCAT97 method.
		*/
		matrix<float> m_cmccat97 = matrix<float>(3, 3, std::vector<float>
		{
			0.8951f, 0.2664f, -0.1614f,
			-0.7502f, 1.7135f, 0.0367f,
			0.0389f, -0.0685f, 1.0296f
		});

		//! Inverted adaptation matrix of the CMCCAT97 method.
		/*!
		* Inverted adaptation matrix of the CMCCAT97 method.
		* Although the matrix equals bradford I added it to avoid confusion.
		*/
		matrix<float> m_inverted_cmccat97 = matrix<float>(3, 3, std::vector<float>
		{
			0.98699f, -0.14705f, 0.15996f,
			0.43231f, 0.51836f, 0.04929f,
			-0.00853f, 0.04004f, 0.96849f
		});

		//! Adaptation matrix of the CMCCAT2000 method.
		/*!
		* Adaptation matrix of the CMCCAT2000 method.
		* Although the matrix equals bradford I added it to avoid confusion.
		*/
		matrix<float> m_cmccat2000 = matrix<float>(3, 3, std::vector<float>
		{
			0.7982f, 0.3389f, -0.1371f,
			-0.5918f, 1.5512f, 0.0406f,
			0.0008f, 0.0239f, 0.9753f
		});

		//! Inverted adaptation matrix of the CMCCAT2000 method.
		/*!
		* Inverted adaptation matrix of the CMCCAT2000 method.
		*/
		matrix<float> m_inverted_cmccat2000 = matrix<float>(3, 3, std::vector<float>
		{
			1.07645f, -0.23766f, 0.16121f,
			0.41096f, 0.55434f, 0.03469f,
			-0.01095f, -0.01339f, 1.02434f
		});

		//! Adaptation matrix of the CAT02 method.
		/*!
		* Adaptation matrix of the CAT02 method.
		*/
		matrix<float> m_cat02 = matrix<float>(3, 3, std::vector<float>
		{
			0.7328f, 0.4296f, -0.1624f,
			-0.7036f, 1.6975f, 0.0061f,
			0.003f, 0.0136f, 0.9834f
		});

		//! Inverted adaptation matrix of the CAT02 method.
		/*!
		* Inverted adaptation matrix of the CAT02 method.
		*/
		matrix<float> m_inverted_cat02 = matrix<float>(3, 3, std::vector<float>
		{
			1.09612f, -0.27887f, 0.18275f,
			0.45437f, 0.47353f, 0.0721f
			-0.00963f, -0.0057f, 1.01533f
		});
	};
}