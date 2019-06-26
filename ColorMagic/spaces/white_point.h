/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once
#include <array>

namespace color_space
{
	//! Class that represents a tristimulus and a chromaticity coordinate for color conversions from or to lab and xyz color space.
	/*!
	* This class stores x, y and z values of the tristimulus and x and y of the chromaticity coordinate.
	*/
	class white_point
	{
	public:
		//! Default constructor.
		white_point()
		{

		}

		//! Default constructor.
		/*!
		* \param tx The x component of the tristimulus.
		* \param ty The y component of the tristimulus.
		* \param tz The z component of the tristimulus.
		* \param cx The x component of the chromaticity coordinate.
		* \param cy The y component of the chromaticity coordinate.
		*/
		white_point(float tx, float ty, float tz, float cx, float cy)
		{
			m_chromaticity_coordinate[0] = cx;
			m_chromaticity_coordinate[1] = cy;
			m_chromaticity_coordinate[2] = 1.f - cx - cy;

			m_tristimulus[0] = tx;
			m_tristimulus[1] = ty;
			m_tristimulus[2] = tz;
		}

		//! Default constructor.
		/*!
		* \param tristimulus The tristimulus.
		* \param chromaticity_coordinate The chromaticity coordinate.
		*/
		white_point(std::array<float, 3> tristimulus, std::array<float, 2> chromaticity_coordinate) :
			white_point(tristimulus[0], tristimulus[1], tristimulus[2], chromaticity_coordinate[0], chromaticity_coordinate[1]) {}

		//! Default constructor to create a white point with just the chromaticity coordinate.
		/*!
		* \param cx The x component of the chromaticity coordinate.
		* \param cy The y component of the chromaticity coordinate.
		*/
		white_point(float cx, float cy)
		{
			m_chromaticity_coordinate[0] = cx;
			m_chromaticity_coordinate[1] = cy;
			m_chromaticity_coordinate[2] = 1.f - cx - cy;

			m_tristimulus = chromaticity_coordinate_to_tristimulus(m_chromaticity_coordinate);
		}

		//! Default constructor to create a white point with just the tristimulus.
		/*!
		* \param tx The x component of the tristimulus.
		* \param ty The y component of the tristimulus.
		* \param tz The z component of the tristimulus.
		*/
		white_point(float tx, float ty, float tz)
		{
			m_tristimulus[0] = tx;
			m_tristimulus[1] = ty;
			m_tristimulus[2] = tz;

			m_chromaticity_coordinate = tristimulus_to_chromaticity_coordinate(m_tristimulus);
		}

		//! Default copy constructor.
		white_point(white_point& other)
		{
			m_tristimulus = other.get_tristimulus();
			m_chromaticity_coordinate = other.get_chromaticity_coordinate();
		}

		//! Default deconstructor.
		/*!
		* Default deconstructor.
		*/
		~white_point()
		{
			
		}

		//! Convert an array of tristimulus values XYZ to an array of chromaticity coordinates xyz.
		/*!
		* Convert an array of tristimulus values XYZ to an array of chromaticity coordinates xyz.
		* /param tristimulus The XYZ array of tristimulus values that have to be converted.
		* /return The tristimulus values XYZ converted to an array of chromaticity coordinates xyz.
		*/
		static std::array<float, 3> tristimulus_to_chromaticity_coordinate(std::array<float, 3> tristimulus)
		{
			std::array<float, 3> result;
			result[0] = tristimulus[0] / (tristimulus[0] + tristimulus[1] + tristimulus[2]);
			result[1] = tristimulus[1] / (tristimulus[0] + tristimulus[1] + tristimulus[2]);
			result[2] = tristimulus[2] / (tristimulus[0] + tristimulus[1] + tristimulus[2]);
			return result;
		}

		//! Convert an array of chromaticity coordinates values xyz to an array of tristimulus values XYZ.
		/*!
		* Convert an array of chromaticity coordinates xyz to an array of tristimulus values XYZ.
		* /param chromaticity_coordinates The xyz array of chromaticity coordinates values that have to be converted.
		* /param Y The fixed Y value of the resulting tristimulus (common values are 1 or 100).
		* /return The chromaticity coordinates xyz converted to an array of tristimulus XYZ.
		*/
		static std::array<float, 3> chromaticity_coordinate_to_tristimulus(std::array<float, 3> chromaticity_coordinates, float Y = 1.f)
		{
			float factor = Y / chromaticity_coordinates[1];

			std::array<float, 3> result;
			result[0] = factor * chromaticity_coordinates[0];
			result[1] = factor * chromaticity_coordinates[1];
			result[2] = factor * chromaticity_coordinates[2];
			return result;
		}

		//! Return the x component of the tristimulus.
		/*!
		* Return the x component of the tristimulus.
		*/
		float get_tristimulus_x() { return m_tristimulus[0]; }

		//! Return the y component of the tristimulus.
		/*!
		* Return the y component of the tristimulus.
		*/
		float get_tristimulus_y() { return m_tristimulus[1]; }

		//! Return the z component of the tristimulus.
		/*!
		* Return the z component of the tristimulus.
		*/
		float get_tristimulus_z() { return m_tristimulus[2]; }

		//! Return the x component of the chromaticity_coordinate.
		/*!
		* Return the x component of the chromaticity_coordinate.
		*/
		float get_chromaticity_x() { return m_chromaticity_coordinate[0]; }

		//! Return the y component of the chromaticity_coordinate.
		/*!
		* Return the y component of the chromaticity_coordinate.
		*/
		float get_chromaticity_y() { return m_chromaticity_coordinate[1]; }

		//! Return the z component of the chromaticity_coordinate.
		/*!
		* Return the z component of the chromaticity_coordinate. 
		* The value will be automatically calculated during construction (1 - x - y).
		*/
		float get_chromaticity_z() { return m_chromaticity_coordinate[2]; }

		//! Returns the chromaticity coordinate.
		/*!
		* Returns the chromaticity coordinate.
		*/
		std::array<float, 3> get_chromaticity_coordinate() { return m_chromaticity_coordinate; }

		//! Returns the tristimulus.
		/*!
		* Returns the tristimulus.
		*/
		std::array<float, 3> get_tristimulus() { return m_tristimulus; }

	private:
		//! The chromaticity coordinate.
		/*!
		* The chromaticity coordinate.
		*/
		std::array<float, 3> m_chromaticity_coordinate;

		//! The tristimulus.
		/*!
		* The tristimulus.
		*/
		std::array<float, 3> m_tristimulus;
	};

	//! Class that stores some default tristimulus and chromaticity coordinates.
	/*!
	* This class stores tristimulus objects and chromaticity coordinates like A, B, C, Equal Energy, D50, or D65.
	* The values for these tristimulus objects were taken from https://www.easyrgb.com
	*/
	class white_point_presets
	{
	public:
		//! CIE_D50 tristimulus white (2°).
		/*!
		* Represents horizon light (5003 Kelvin).
		* ICC profile PCS
		*/
		white_point* D50_2Degree() { return new white_point(0.9642f, 1.f, 82.51f, 0.3456f, 0.3585f); }

		//! CIE_D55 tristimulus white (2°).
		/*!
		* Represents mid-morning / mid-afternoon daylight (5503 Kelvin).
		*/
		white_point* D55_2Degree() { return new white_point(0.9568f, 1.f, 0.9214f, 0.3324f, 0.3474f); }

		//! CIE_D65 tristimulus white (2°)
		/*!
		* Represents noon daylight, tv, sRGB color space (6504 Kelvin)
		*/
		white_point* D65_2Degree() { return new white_point(0.9504f, 1.f, 1.0888f, 0.3127f, 0.3290f); }

		//! CIE_D75 tristimulus white (2°)
		/*!
		* Represents north sky daylight (7504 Kelvin)
		*/
		white_point* D75_2Degree() { return new white_point(0.9497f, 1.f, 1.2264f, 0.2990f, 0.3148f); }

		//! CIE_A tristimulus white (2°)
		/*!
		* Represents incandescent / tungsten (2856 Kelvin)
		*/
		white_point* A_2Degree() { return new white_point(0.10985f, 1.f, 0.3558f, 0.4475f, 0.4074f); }

		//! CIE_B tristimulus white (2°)
		/*!
		* Represents direct sunlight at noon (4874 Kelvin)
		* obsolete, use D50_2Degree instead
		*/
		white_point* B_2Degree() { return new white_point(0.9909f, 1.f, 0.8531f, 0.3484f, 0.3516f); }

		//! CIE_C tristimulus white (2°)
		/*!
		* Represents average / north sky daylight (6774 Kelvin)
		* obsolete, use D65_2Degree instead
		*/
		white_point* C_2Degree() { return new white_point(0.9807f, 1.f, 1.1823f, 0.3100f, 0.3161f); }

		//! CIE_E tristimulus white (2°)
		/*!
		* Represents equal energy (5454 Kelvin)
		*/
		white_point* E_2Degree() { return new white_point(0.1f, 1.f, 0.1f, 0.3333f, 0.3333f); }

		//! CIE_F1 tristimulus white (2°)
		/*!
		* Represents daylight fluorescent (6430 Kelvin)
		*/
		white_point* F1_2Degree() { return new white_point(0.9283f, 1.f, 1.0366f, 0.3130f, 0.3372f); }

		//! CIE_F2 tristimulus white (2°)
		/*!
		* Represents cool white fluorescent (4230 Kelvin)
		*/
		white_point* F2_2Degree() { return new white_point(0.9918f, 1.f, 0.6739f, 0.3720f, 0.3751f); }

		//! CIE_F3 tristimulus white (2°)
		/*!
		* Represents white fluorescent (3450 Kelvin)
		*/
		white_point* F3_2Degree() { return new white_point(0.10375f, 1.f, 0.4986f, 0.4090f, 0.3943f); }

		//! CIE_F4 tristimulus white (2°)
		/*!
		* Represents warm white fluorescent (2940 Kelvin)
		*/
		white_point* F4_2Degree() { return new white_point(0.10914f, 1.f, 0.3881f, 0.4401f, 0.4033f); }

		//! CIE_F5 tristimulus white (2°)
		/*!
		* Represents daylight fluorescent (6350 Kelvin)
		*/
		white_point* F5_2Degree() { return new white_point(0.9087f, 1.f, 0.9872f, 0.3137f, 0.3453f); }

		//! CIE_F6 tristimulus white (2°)
		/*!
		* Represents lite white fluorescent (4150 Kelvin)
		*/
		white_point* F6_2Degree() { return new white_point(0.9730f, 1.f, 0.6019f, 0.3778f, 0.3883f); }

		//! CIE_F7 tristimulus white (2°)
		/*!
		* Represents D65 simulator, daylight simulator (6500 Kelvin)
		*/
		white_point* F7_2Degree() { return new white_point(0.9504f, 1.f, 1.0875f, 0.3128f, 0.3291f); }

		//! CIE_F8 tristimulus white (2°)
		/*!
		* Represents D50 simulator, sylvania F40 design 50 (5000 Kelvin)
		*/
		white_point* F8_2Degree() { return new white_point(0.9641f, 1.f, 0.8233f, 0.3458f, 0.3587f); }

		//! CIE_F9 tristimulus white (2°)
		/*!
		* Represents cool white deluxe fluorescent (4150 Kelvin)
		*/
		white_point* F9_2Degree() { return new white_point(0.10036f, 1.f, 0.6786f, 0.3741f, 0.3728f); }

		//! CIE_F10 tristimulus white (2°)
		/*!
		* Represents Philips TL85, Ultralume 50 (5000 Kelvin)
		*/
		white_point* F10_2Degree() { return new white_point(0.9617f, 1.f, 0.8171f, 0.3460f, 0.3598f); }

		//! CIE_F11 tristimulus white (2°)
		/*!
		* Represents Philips TL84, Ultralume 40 (4000 Kelvin)
		*/
		white_point* F11_2Degree() { return new white_point(0.10096f, 1.f, 0.6437f, 0.3805f, 0.3768f); }

		//! CIE_F12 tristimulus white (2°)
		/*!
		* Represents Philips TL83, Ultralume 30 (3000 Kelvin)
		*/
		white_point* F12_2Degree() { return new white_point(0.10804f, 1.f, 0.3922f, 0.4369, 0.4044f); }


		//! CIE_D50 tristimulus white (10°)
		/*!
		* Represents horizon light (5003 Kelvin)
		* ICC profile PCS
		*/
		white_point* D50_10Degree() { return new white_point(0.9672f, 1.f, 0.8142f, 0.3477f, 0.3595f); }

		//! CIE_D55 tristimulus white (10°)
		/*!
		* Represents mid-morning / mid-afternoon daylight (5503 Kelvin)
		*/
		white_point* D55_10Degree() { return new white_point(0.9579f, 1.f, 0.9092f, 0.3341f, 0.3487f); }

		//! CIE_D65 tristimulus white (10°)
		/*!
		* Represents noon daylight, tv, sRGB color space (6504 Kelvin)
		*/
		white_point* D65_10Degree() { return new white_point(0.9481f, 1.f, 1.0730f, 0.3138f, 0.3310f); }

		//! CIE_D75 tristimulus white (10°)
		/*!
		* Represents north sky daylight (7504 Kelvin)
		*/
		white_point* D75_10Degree() { return new white_point(0.9441f, 1.f, 1.2064f, 0.2996f, 0.3174f); }

		//! CIE_A tristimulus white (10°)
		/*!
		* Represents incandescent / tungsten (2856 Kelvin)
		*/
		white_point* A_10Degree() { return new white_point(0.11114f, 1.f, 0.3520f, 0.4511f, 0.4059f); }

		//! CIE_B tristimulus white (10°)
		/*!
		* Represents direct sunlight at noon (4874 Kelvin)
		* obsolete, use D50_10Degree instead
		*/
		white_point* B_10Degree() { return new white_point(0.9917f, 1.f, 0.84349f, 0.3497f, 0.3527f); }

		//! CIE_C tristimulus white (10°)
		/*!
		* Represents average / north sky daylight (6774 Kelvin)
		* obsolete, use D65_10Degree instead
		*/
		white_point* C_10Degree() { return new white_point(0.9728f, 1.f, 1.1614f, 0.3103f, 0.3190f); }

		//! CIE_E tristimulus white (10°)
		/*!
		* Represents equal energy (5454 Kelvin)
		*/
		white_point* E_10Degree() { return new white_point(0.1f, 1.f, 0.1f, 0.3333f, 0.3333f); }

		//! CIE_F1 tristimulus white (10°)
		/*!
		* Represents daylight fluorescent (6430 Kelvin)
		*/
		white_point* F1_10Degree() { return new white_point(0.9479f, 1.f, 1.0319f, 0.3181f, 0.3355f); }

		//! CIE_F2 tristimulus white (10°)
		/*!
		* Represents cool white fluorescent (4230 Kelvin)
		*/
		white_point* F2_10Degree() { return new white_point(0.10328f, 1.f, 0.6902f, 0.3792f, 0.3672f); }

		//! CIE_F3 tristimulus white (10°)
		/*!
		* Represents white fluorescent (3450 Kelvin)
		*/
		white_point* F3_10Degree() { return new white_point(0.10896f, 1.f, 0.5196f, 0.4175f, 0.3832f); }

		//! CIE_F4 tristimulus white (10°)
		/*!
		* Represents warm white fluorescent (2940 Kelvin)
		*/
		white_point* F4_10Degree() { return new white_point(0.11496f, 1.f, 0.4096f, 0.4492f, 0.3907f); }

		//! CIE_F5 tristimulus white (10°)
		/*!
		* Represents daylight fluorescent (6350 Kelvin)
		*/
		white_point* F5_10Degree() { return new white_point(0.9336f, 1.f, 0.9863f, 0.3197f, 0.3424f); }

		//! CIE_F6 tristimulus white (10°)
		/*!
		* Represents lite white fluorescent (4150 Kelvin)
		*/
		white_point* F6_10Degree() { return new white_point(0.10214f, 1.f, 0.6207f, 0.3865f, 0.3784f); }

		//! CIE_F7 tristimulus white (10°)
		/*!
		* Represents D65 simulator, daylight simulator (6500 Kelvin)
		*/
		white_point* F7_10Degree() { return new white_point(0.9579f, 1.f, 1.0768f, 0.3156f, 0.3295f); }

		//! CIE_F8 tristimulus white (10°)
		/*!
		* Represents D50 simulator, sylvania F40 design 50 (5000 Kelvin)
		*/
		white_point* F8_10Degree() { return new white_point(0.9711f, 1.f, 0.8113f, 0.3490f, 0.3594f); }

		//! CIE_F9 tristimulus white (10°)
		/*!
		* Represents cool white deluxe fluorescent (4150 Kelvin)
		*/
		white_point* F9_10Degree() { return new white_point(0.10211f, 1.f, 0.6782f, 0.3782f, 0.3704f); }

		//! CIE_F10 tristimulus white (10°)
		/*!
		* Represents Philips TL85, Ultralume 50 (5000 Kelvin)
		*/
		white_point* F10_10Degree() { return new white_point(0.9900f, 1.f, 0.8313f, 0.3509f, 0.3544f); }

		//! CIE_F11 tristimulus white (10°)
		/*!
		* Represents Philips TL84, Ultralume 40 (4000 Kelvin)
		*/
		white_point* F11_10Degree() { return new white_point(0.10386f, 1.f, 0.6562f, 0.3854f, 0.3710f); }

		//! CIE_F12 tristimulus white (10°)
		/*!
		* Represents Philips TL83, Ultralume 30 (3000 Kelvin)
		*/
		white_point* F12_10Degree() { return new white_point(0.11142f, 1.f, 0.4035f, 0.4425f, 0.3971f); }
	};
}