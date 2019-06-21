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
		static std::array<float, 3> chromaticity_coordinate_to_tristimulus(std::array<float, 3> chromaticity_coordinates, float Y = 100)
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
		static white_point D50_2Degree;

		//! CIE_D55 tristimulus white (2°).
		/*!
		* Represents mid-morning / mid-afternoon daylight (5503 Kelvin).
		*/
		static white_point D55_2Degree;

		//! CIE_D65 tristimulus white (2°).
		/*!
		* Represents noon daylight, tv, sRGB color space (6504 Kelvin).
		*/
		static white_point D65_2Degree;

		//! CIE_D75 tristimulus white (2°).
		/*!
		* Represents north sky daylight (7504 Kelvin).
		*/
		static white_point D75_2Degree;

		//! CIE_A tristimulus white (2°).
		/*!
		* Represents incandescent / tungsten (2856 Kelvin).
		*/
		static white_point A_2Degree;

		//! CIE_B tristimulus white (2°).
		/*!
		* Represents direct sunlight at noon (4874 Kelvin).
		* obsolete, use D50_2Degree instead
		*/
		static white_point B_2Degree;

		//! CIE_C tristimulus white (2°).
		/*!
		* Represents average / north sky daylight (6774 Kelvin).
		* obsolete, use D65_2Degree instead
		*/
		static white_point C_2Degree;

		//! CIE_E tristimulus white (2°).
		/*!
		* Represents equal energy (5454 Kelvin).
		*/
		static white_point E_2Degree;

		//! CIE_F1 tristimulus white (2°).
		/*!
		* Represents daylight fluorescent (6430 Kelvin).
		*/
		static white_point F1_2Degree;

		//! CIE_F2 tristimulus white (2°).
		/*!
		* Represents cool white fluorescent (4230 Kelvin).
		*/
		static white_point F2_2Degree;

		//! CIE_F3 tristimulus white (2°).
		/*!
		* Represents white fluorescent (3450 Kelvin).
		*/
		static white_point F3_2Degree;

		//! CIE_F4 tristimulus white (2°).
		/*!
		* Represents warm white fluorescent (2940 Kelvin).
		*/
		static white_point F4_2Degree;

		//! CIE_F5 tristimulus white (2°).
		/*!
		* Represents daylight fluorescent (6350 Kelvin).
		*/
		static white_point F5_2Degree;

		//! CIE_F6 tristimulus white (2°).
		/*!
		* Represents lite white fluorescent (4150 Kelvin).
		*/
		static white_point F6_2Degree;

		//! CIE_F7 tristimulus white (2°).
		/*!
		* Represents D65 simulator, daylight simulator (6500 Kelvin).
		*/
		static white_point F7_2Degree;

		//! CIE_F8 tristimulus white (2°).
		/*!
		* Represents D50 simulator, sylvania F40 design 50 (5000 Kelvin).
		*/
		static white_point F8_2Degree;

		//! CIE_F9 tristimulus white (2°).
		/*!
		* Represents cool white deluxe fluorescent (4150 Kelvin).
		*/
		static white_point F9_2Degree;

		//! CIE_F10 tristimulus white (2°).
		/*!
		* Represents Philips TL85, Ultralume 50 (5000 Kelvin).
		*/
		static white_point F10_2Degree;

		//! CIE_F11 tristimulus white (2°).
		/*!
		* Represents Philips TL84, Ultralume 40 (4000 Kelvin).
		*/
		static white_point F11_2Degree;

		//! CIE_F12 tristimulus white (2°).
		/*!
		* Represents Philips TL83, Ultralume 30 (3000 Kelvin).
		*/
		static white_point F12_2Degree;


		//! CIE_D50 tristimulus white (10°).
		/*!
		* Represents horizon light (5003 Kelvin).
		* ICC profile PCS
		*/
		static white_point D50_10Degree;

		//! CIE_D55 tristimulus white (10°).
		/*!
		* Represents mid-morning / mid-afternoon daylight (5503 Kelvin).
		*/
		static white_point D55_10Degree;

		//! CIE_D65 tristimulus white (10°).
		/*!
		* Represents noon daylight, tv, sRGB color space (6504 Kelvin).
		*/
		static white_point D65_10Degree;

		//! CIE_D75 tristimulus white (10°).
		/*!
		* Represents north sky daylight (7504 Kelvin).
		*/
		static white_point D75_10Degree;

		//! CIE_A tristimulus white (10°).
		/*!
		* Represents incandescent / tungsten (2856 Kelvin).
		*/
		static white_point A_10Degree;

		//! CIE_B tristimulus white (10°).
		/*!
		* Represents direct sunlight at noon (4874 Kelvin).
		* obsolete, use D50_10Degree instead
		*/
		static white_point B_10Degree;

		//! CIE_C tristimulus white (10°).
		/*!
		* Represents average / north sky daylight (6774 Kelvin).
		* obsolete, use D65_10Degree instead
		*/
		static white_point C_10Degree;

		//! CIE_E tristimulus white (10°).
		/*!
		* Represents equal energy (5454 Kelvin).
		*/
		static white_point E_10Degree;

		//! CIE_F1 tristimulus white (10°).
		/*!
		* Represents daylight fluorescent (6430 Kelvin).
		*/
		static white_point F1_10Degree;

		//! CIE_F2 tristimulus white (10°).
		/*!
		* Represents cool white fluorescent (4230 Kelvin).
		*/
		static white_point F2_10Degree;

		//! CIE_F3 tristimulus white (10°).
		/*!
		* Represents white fluorescent (3450 Kelvin).
		*/
		static white_point F3_10Degree;

		//! CIE_F4 tristimulus white (10°).
		/*!
		* Represents warm white fluorescent (2940 Kelvin).
		*/
		static white_point F4_10Degree;

		//! CIE_F5 tristimulus white (10°).
		/*!
		* Represents daylight fluorescent (6350 Kelvin).
		*/
		static white_point F5_10Degree;

		//! CIE_F6 tristimulus white (10°).
		/*!
		* Represents lite white fluorescent (4150 Kelvin).
		*/
		static white_point F6_10Degree;

		//! CIE_F7 tristimulus white (10°).
		/*!
		* Represents D65 simulator, daylight simulator (6500 Kelvin).
		*/
		static white_point F7_10Degree;

		//! CIE_F8 tristimulus white (10°).
		/*!
		* Represents D50 simulator, sylvania F40 design 50 (5000 Kelvin).
		*/
		static white_point F8_10Degree;

		//! CIE_F9 tristimulus white (10°).
		/*!
		* Represents cool white deluxe fluorescent (4150 Kelvin).
		*/
		static white_point F9_10Degree;

		//! CIE_F10 tristimulus white (10°).
		/*!
		* Represents Philips TL85, Ultralume 50 (5000 Kelvin).
		*/
		static white_point F10_10Degree;

		//! CIE_F11 tristimulus white (10°).
		/*!
		* Represents Philips TL84, Ultralume 40 (4000 Kelvin).
		*/
		static white_point F11_10Degree;

		//! CIE_F12 tristimulus white (10°).
		/*!
		* Represents Philips TL83, Ultralume 30 (3000 Kelvin).
		*/
		static white_point F12_10Degree;
	};
}