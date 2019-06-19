/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "white_point.h"
#include "../utils/matrix.h"
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
		rgb_color_space_definition(std::array<float, 2> red_xy, std::array<float, 2> green_xy, std::array<float, 2> blue_xy, white_point* ref_white) :
			rgb_color_space_definition(red_xy[0], red_xy[1], green_xy[0], green_xy[1], blue_xy[0], blue_xy[1], ref_white) {}
		
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
			m_red[0] = red_x;
			m_red[1] = red_y;
			m_red[2] = 1.f - red_x - red_y;

			m_green[0] = green_x;
			m_green[1] = green_y;
			m_green[2] = 1.f - green_x - green_y;

			m_blue[0] = blue_x;
			m_blue[1] = blue_y;
			m_blue[2] = 1.f - blue_x - blue_y;

			m_white = ref_white;

			m_transform_matrix = calculate_transformation_matrix(m_red, m_green, m_blue, m_white->chromaticity_coordinate());
			m_transform_matrix = calculate_inverse_transformation_matrix(m_transform_matrix);
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
			return m_red[0];
		}

		//! Access the red coordinates y value.
		float get_red_y()
		{
			return m_red[1];
		}

		//! Access the red coordinates z value.
		/*!
		* Access the red coordinates z value.
		* The value will be automatically calculated during construction (1 - x - y).
		*/
		float get_red_z()
		{
			return m_red[2];
		}

		//! Access the green coordinates x value.
		float get_green_x()
		{
			return m_green[0];
		}

		//! Access the green coordinates y value.
		float get_green_y()
		{
			return m_green[1];
		}

		//! Access the green coordinates z value.
		/*!
		* Access the green coordinates z value.
		* The value will be automatically calculated during construction (1 - x - y).
		*/
		float get_green_z()
		{
			return m_green[2];
		}

		//! Access the blue coordinates x value.
		float get_blue_x()
		{
			return m_blue[0];
		}

		//! Access the blue coordinates y value.
		float get_blue_y()
		{
			return m_blue[1];
		}

		//! Access the blue coordinates z value.
		/*!
		* Access the blue coordinates z value.
		* The value will be automatically calculated during construction (1 - x - y).
		*/
		float get_blue_z()
		{
			return m_blue[2];
		}

		//! Access the white point.
		white_point* get_white_point_x()
		{
			return m_white;
		}

	private:
		static matrix<float> calculate_transformation_matrix(std::array<float, 3> red, std::array<float, 3> green, std::array<float, 3> blue, std::array<float, 3> white)
		{

		}

		static matrix<float> calculate_inverse_transformation_matrix(matrix<float> transform_matrix)
		{

		}

		//! The chromaticity coordinates for red.
		/*!
		* The chromaticity coordinates for red.
		*/
		std::array<float, 3> m_red;

		//! The chromaticity coordinates for green.
		/*!
		* The chromaticity coordinates for green.
		*/
		std::array<float, 3> m_green;

		//! The chromaticity coordinates for blue.
		/*!
		* The chromaticity coordinates for blue.
		*/
		std::array<float, 3> m_blue;

		//! The chromaticity coordinates for the white point.
		/*!
		* The chromaticity coordinates for the white point.
		*/
		white_point* m_white;

		//! Transformation matrix to convert from rgb to xyz.
		/*!
		* Transformation matrix to convert from rgb to xyz. 
		* The matrix will be calculated inside the constructor 
		* by using the chromaticity coordinates of red, green, 
		* blue and white. 
		*/
		matrix<float> m_transform_matrix;

		//! Transformation matrix to convert from xyz to rgb.
		/*!
		* Transformation matrix to convert from xyz to rgb.
		* The matrix will be calculated inside the constructor
		* by inverting m_transform_matrix. 
		*/
		matrix<float> m_inverse_transform_matrix;
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
