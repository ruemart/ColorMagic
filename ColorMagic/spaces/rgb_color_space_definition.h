/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "white_point.h"
#include <array>

namespace color_space
{
	class rgb_color_space_definition
	{
	public:
		//! Default constructor.
		/*!
		* \param red_xy The chromaticity coordinates for red. Helps define the gammut of this rgb color space.
		* \param green_xy The chromaticity coordinates for green. Helps define the gammut of this rgb color space.
		* \param blue_xy The chromaticity coordinates for blue. Helps define the gammut of this rgb color space.
		* \param ref_white Reference white containing tristimulus values that will be converted to chromaticity coordinates.
		*/
		rgb_color_space_definition(std::array<float, 2> red_xy, std::array<float, 2> green_xy, std::array<float, 2> blue_xy, white_point* ref_white)
		{
			red = red_xy;
			green = green_xy;
			blue = blue_xy;
			white = ref_white;
		}

		//! Default constructor.
		/*!
		* \param red_x The x-part of the chromaticity coordinates for red. Helps define the gammut of this rgb color space.
		* \param red_y The y-part of the chromaticity coordinates for red. Helps define the gammut of this rgb color space.
		* \param green_x The x-part of the chromaticity coordinates for green. Helps define the gammut of this rgb color space.
		* \param green_y The y-part of the chromaticity coordinates for green. Helps define the gammut of this rgb color space.
		* \param blue_x The x-part of the chromaticity coordinates for blue. Helps define the gammut of this rgb color space.
		* \param blue_y The y-part of the chromaticity coordinates for blue. Helps define the gammut of this rgb color space.
		* \param ref_white Reference white containing tristimulus and chromaticity coordinate.
		*/
		rgb_color_space_definition(float red_x, float red_y, float green_x, float green_y, float blue_x, float blue_y, white_point* ref_white)
		{
			red[0] = red_x;
			red[1] = red_y;

			green[0] = green_x;
			green[1] = green_y;

			blue[0] = blue_x;
			blue[1] = blue_y;

			white = ref_white;
		}

		//! Default deconstructor.
		/*!
		* Default deconstructor.
		*/
		~rgb_color_space_definition()
		{
		}

		//! Access the red coordinates x value.
		float get_red_x()
		{
			return red[0];
		}

		//! Access the red coordinates y value.
		float get_red_y()
		{
			return red[1];
		}

		//! Access the green coordinates x value.
		float get_green_x()
		{
			return green[0];
		}

		//! Access the green coordinates y value.
		float get_green_y()
		{
			return green[1];
		}

		//! Access the blue coordinates x value.
		float get_blue_x()
		{
			return blue[0];
		}

		//! Access the blue coordinates y value.
		float get_blue_y()
		{
			return blue[1];
		}

		//! Access the white point.
		white_point* get_white_point_x()
		{
			return white;
		}

	private:
		//! The chromaticity coordinates for red.
		/*!
		* The chromaticity coordinates for red.
		*/
		std::array<float, 2> red;

		//! The chromaticity coordinates for green.
		/*!
		* The chromaticity coordinates for green.
		*/
		std::array<float, 2> green;

		//! The chromaticity coordinates for blue.
		/*!
		* The chromaticity coordinates for blue.
		*/
		std::array<float, 2> blue;

		//! The chromaticity coordinates for the white point.
		/*!
		* The chromaticity coordinates for the white point.
		*/
		white_point* white;
	};

	//! Class that stores some default reference white values.
	/*!
	* This class stores reference whites like A, B, C, Equal Energy, D50, or D65.
	* The values for these reference whites were taken from https://www.easyrgb.com
	*/
	class rgb_color_space_definition_presets
	{
	public:
		//! sRGB is an RGB color space.
		/*!
		* sRGB is an RGB color space that HP and Microsoft created cooperatively in 1996
		* to use on monitors, printers, and the Internet.
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition sRGB;

		//! The Adobe RGB (1998) color space.
		/*!
		* The Adobe RGB (1998) color space is an RGB color space developed by Adobe Systems, Inc.
		* in 1998. It was designed to encompass most of the colors achievable on CMYK color printers,
		* but by using RGB primary colors on a device such as a computer display.
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition adobeRGB;

		//! The PAL/SECAM color space.
		/*!
		* The PAL/SECAM color space is used for television in Europe, Asia, Afrika, Australia and parts of
		* South America.
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition pal_secam;

		//! The NTSC color space used in America.
		/*!
		* The NTSC color space is used for television in North America and parts of South America.
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition americaNTSC;
		
		//! The NTSC color space from 1953.
		/*!
		* Old version of the NTSC color space from 1953.
		* It uses the C reference white.
		*/
		static rgb_color_space_definition oldNTSC;

		//! The Apple RGB color space.
		/*!
		* The Apple RGB color space is an RGB color space developed by Apple.
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition appleRGB;

		//! The DCI-P3 color space.
		/*!
		* DCI-P3, or DCI/P3, is a common RGB color space for digital movie projection
		* from the American film industry.
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition dci_p3;

		//! The UHDTV color space.
		/*!
		* ITU - R Recommendation BT.2020, more commonly known by the abbreviations Rec. 2020
		* or BT.2020, defines various aspects of ultra - high - definition television(UHDTV)
		* with standard dynamic range(SDR) and wide color gamut(WCG)
		* It uses the D65 reference white.
		*/
		static rgb_color_space_definition uhdtv;

		//! The Adobe wide gammut RGB color space.
		/*!
		* The wide-gamut RGB color space is an RGB color space developed by Adobe Systems, that
		* offers a large gamut by using pure spectral primary colors. It is able to store a
		* wider range of color values than sRGB or Adobe RGB color spaces.
		* It uses the D50 reference white.
		*/
		static rgb_color_space_definition adobeWideGammutRGB;

		//! The ROMM-RGB color space.
		/*!
		* The ProPhoto RGB color space, also known as ROMM RGB, is an output referred RGB color
		* space developed by Kodak. It offers an especially large gamut designed for use with
		* photographic output in mind. The ProPhoto RGB color space encompasses over 90% of
		* possible surface colors
		* It uses the D50 reference white.
		*/
		static rgb_color_space_definition rommRGB;

		//! The CIE RGB (1931) color space.
		/*!
		* The CIE 1931 color spaces were the first defined quantitative links between distributions
		* of wavelengths in the electromagnetic visible spectrum, and physiologically perceived colors
		* in human color vision.
		* It uses the E reference white.
		*/
		static rgb_color_space_definition cieRGB;

		//! The CIE XYZ (1931) color space.
		/*!
		* The CIE 1931 color spaces were the first defined quantitative links between distributions
		* of wavelengths in the electromagnetic visible spectrum, and physiologically perceived colors
		* in human color vision. This gammut of this color space covers the whole xyz area.
		* It uses the E reference white.
		*/
		static rgb_color_space_definition cieXYZ;
	};
}
