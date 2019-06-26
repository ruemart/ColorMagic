/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

namespace color_space
{
	//! Class that represents a reference white for color conversions from or to lab color space
	/*!
	* This struct stores x, y and z values of the reference white.
	*/
	struct reference_white
	{
		//! Default constructor.
		/*!
		* \param x The x component of the reference white.
		* \param y The y component of the reference white.
		* \param z The z component of the reference white.
		*/
		reference_white(float x, float y, float z) : x(x), y(y), z(z) { }

		//! Default deconstructor.
		/*!
		* Default deconstructor.
		*/
		~reference_white()
		{
			x = -1;
			y = -1;
			z = -1;
		}

		//! The x component of the reference white.
		/*!
		* The x component of the reference white.
		*/
		float x;

		//! The y component of the reference white.
		/*!
		* The y component of the reference white.
		*/
		float y;

		//! The z component of the reference white.
		/*!
		* The z component of the reference white.
		*/
		float z;
	};

	//! Class that stores some default reference white values.
	/*!
	* This class stores reference whites like A, B, C, Equal Energy, D50, or D65.
	* The values for these reference whites were taken from https://www.easyrgb.com
	*/
	class reference_white_presets
	{
	public:
		//! CIE_D50 reference white (2°).
		/*!
		* Represents horizon light (5003 Kelvin).
		* ICC profile PCS
		*/
		static reference_white D50_2Degree;

		//! CIE_D55 reference white (2°).
		/*!
		* Represents mid-morning / mid-afternoon daylight (5503 Kelvin).
		*/
		static reference_white D55_2Degree;

		//! CIE_D65 reference white (2°).
		/*!
		* Represents noon daylight, tv, sRGB color space (6504 Kelvin).
		*/
		static reference_white D65_2Degree;

		//! CIE_D75 reference white (2°).
		/*!
		* Represents north sky daylight (7504 Kelvin).
		*/
		static reference_white D75_2Degree;

		//! CIE_A reference white (2°).
		/*!
		* Represents incandescent / tungsten (2856 Kelvin).
		*/
		static reference_white A_2Degree;

		//! CIE_B reference white (2°).
		/*!
		* Represents direct sunlight at noon (4874 Kelvin).
		* obsolete, use D50_2Degree instead
		*/
		static reference_white B_2Degree;

		//! CIE_C reference white (2°).
		/*!
		* Represents average / north sky daylight (6774 Kelvin).
		* obsolete, use D65_2Degree instead
		*/
		static reference_white C_2Degree;

		//! CIE_E reference white (2°).
		/*!
		* Represents equal energy (5454 Kelvin).
		*/
		static reference_white E_2Degree;

		//! CIE_F1 reference white (2°).
		/*!
		* Represents daylight fluorescent (6430 Kelvin).
		*/
		static reference_white F1_2Degree;

		//! CIE_F2 reference white (2°).
		/*!
		* Represents cool white fluorescent (4230 Kelvin).
		*/
		static reference_white F2_2Degree;

		//! CIE_F3 reference white (2°).
		/*!
		* Represents white fluorescent (3450 Kelvin).
		*/
		static reference_white F3_2Degree;

		//! CIE_F4 reference white (2°).
		/*!
		* Represents warm white fluorescent (2940 Kelvin).
		*/
		static reference_white F4_2Degree;

		//! CIE_F5 reference white (2°).
		/*!
		* Represents daylight fluorescent (6350 Kelvin).
		*/
		static reference_white F5_2Degree;

		//! CIE_F6 reference white (2°).
		/*!
		* Represents lite white fluorescent (4150 Kelvin).
		*/
		static reference_white F6_2Degree;

		//! CIE_F7 reference white (2°).
		/*!
		* Represents D65 simulator, daylight simulator (6500 Kelvin).
		*/
		static reference_white F7_2Degree;

		//! CIE_F8 reference white (2°).
		/*!
		* Represents D50 simulator, sylvania F40 design 50 (5000 Kelvin).
		*/
		static reference_white F8_2Degree;

		//! CIE_F9 reference white (2°).
		/*!
		* Represents cool white deluxe fluorescent (4150 Kelvin).
		*/
		static reference_white F9_2Degree;

		//! CIE_F10 reference white (2°).
		/*!
		* Represents Philips TL85, Ultralume 50 (5000 Kelvin).
		*/
		static reference_white F10_2Degree;

		//! CIE_F11 reference white (2°).
		/*!
		* Represents Philips TL84, Ultralume 40 (4000 Kelvin).
		*/
		static reference_white F11_2Degree;

		//! CIE_F12 reference white (2°).
		/*!
		* Represents Philips TL83, Ultralume 30 (3000 Kelvin).
		*/
		static reference_white F12_2Degree;


		//! CIE_D50 reference white (10°).
		/*!
		* Represents horizon light (5003 Kelvin).
		* ICC profile PCS
		*/
		static reference_white D50_10Degree;

		//! CIE_D55 reference white (10°).
		/*!
		* Represents mid-morning / mid-afternoon daylight (5503 Kelvin).
		*/
		static reference_white D55_10Degree;

		//! CIE_D65 reference white (10°).
		/*!
		* Represents noon daylight, tv, sRGB color space (6504 Kelvin).
		*/
		static reference_white D65_10Degree;

		//! CIE_D75 reference white (10°).
		/*!
		* Represents north sky daylight (7504 Kelvin).
		*/
		static reference_white D75_10Degree;

		//! CIE_A reference white (10°).
		/*!
		* Represents incandescent / tungsten (2856 Kelvin).
		*/
		static reference_white A_10Degree;

		//! CIE_B reference white (10°).
		/*!
		* Represents direct sunlight at noon (4874 Kelvin).
		* obsolete, use D50_10Degree instead
		*/
		static reference_white B_10Degree;

		//! CIE_C reference white (10°).
		/*!
		* Represents average / north sky daylight (6774 Kelvin).
		* obsolete, use D65_10Degree instead
		*/
		static reference_white C_10Degree;

		//! CIE_E reference white (10°).
		/*!
		* Represents equal energy (5454 Kelvin).
		*/
		static reference_white E_10Degree;

		//! CIE_F1 reference white (10°).
		/*!
		* Represents daylight fluorescent (6430 Kelvin).
		*/
		static reference_white F1_10Degree;

		//! CIE_F2 reference white (10°).
		/*!
		* Represents cool white fluorescent (4230 Kelvin).
		*/
		static reference_white F2_10Degree;

		//! CIE_F3 reference white (10°).
		/*!
		* Represents white fluorescent (3450 Kelvin).
		*/
		static reference_white F3_10Degree;

		//! CIE_F4 reference white (10°).
		/*!
		* Represents warm white fluorescent (2940 Kelvin).
		*/
		static reference_white F4_10Degree;

		//! CIE_F5 reference white (10°).
		/*!
		* Represents daylight fluorescent (6350 Kelvin).
		*/
		static reference_white F5_10Degree;

		//! CIE_F6 reference white (10°).
		/*!
		* Represents lite white fluorescent (4150 Kelvin).
		*/
		static reference_white F6_10Degree;

		//! CIE_F7 reference white (10°).
		/*!
		* Represents D65 simulator, daylight simulator (6500 Kelvin).
		*/
		static reference_white F7_10Degree;

		//! CIE_F8 reference white (10°).
		/*!
		* Represents D50 simulator, sylvania F40 design 50 (5000 Kelvin).
		*/
		static reference_white F8_10Degree;

		//! CIE_F9 reference white (10°).
		/*!
		* Represents cool white deluxe fluorescent (4150 Kelvin).
		*/
		static reference_white F9_10Degree;

		//! CIE_F10 reference white (10°).
		/*!
		* Represents Philips TL85, Ultralume 50 (5000 Kelvin).
		*/
		static reference_white F10_10Degree;

		//! CIE_F11 reference white (10°).
		/*!
		* Represents Philips TL84, Ultralume 40 (4000 Kelvin).
		*/
		static reference_white F11_10Degree;

		//! CIE_F12 reference white (10°).
		/*!
		* Represents Philips TL83, Ultralume 30 (3000 Kelvin).
		*/
		static reference_white F12_10Degree;
	};
}