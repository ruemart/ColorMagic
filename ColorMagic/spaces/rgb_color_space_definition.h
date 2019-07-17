/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "gamma.h"
#include "white_point.h"
#include "../utils/matrix.h"
#include <array>

namespace color_space
{
	class rgb_color_space_definition
	{
	public:
		//! Default constructor.
		rgb_color_space_definition() : m_red(std::array<float, 3>()), m_green(std::array<float, 3>()), m_blue(std::array<float, 3>()), m_white(new white_point()), m_gamma(new gamma())
		{
		}

		//! Default constructor.
		/*!
		* \param red_xy The chromaticity coordinates for red. Helps define the gammut of this rgb color space.
		* \param green_xy The chromaticity coordinates for green. Helps define the gammut of this rgb color space.
		* \param blue_xy The chromaticity coordinates for blue. Helps define the gammut of this rgb color space.
		* \param ref_white Reference white containing tristimulus values that will be converted to chromaticity coordinates.
		* \param gamma Gamma curve object.
		*/
		rgb_color_space_definition(std::array<float, 2> red_xy, std::array<float, 2> green_xy, std::array<float, 2> blue_xy, white_point* ref_white, gamma* gamma) :
			rgb_color_space_definition(red_xy[0], red_xy[1], green_xy[0], green_xy[1], blue_xy[0], blue_xy[1], ref_white, gamma) {}

		//! Default constructor.
		/*!
		* \param red_x The x-part of the chromaticity coordinates for red. Helps define the gammut of this rgb color space.
		* \param red_y The y-part of the chromaticity coordinates for red. Helps define the gammut of this rgb color space.
		* \param green_x The x-part of the chromaticity coordinates for green. Helps define the gammut of this rgb color space.
		* \param green_y The y-part of the chromaticity coordinates for green. Helps define the gammut of this rgb color space.
		* \param blue_x The x-part of the chromaticity coordinates for blue. Helps define the gammut of this rgb color space.
		* \param blue_y The y-part of the chromaticity coordinates for blue. Helps define the gammut of this rgb color space.
		* \param ref_white Reference white containing tristimulus and chromaticity coordinate.
		* \param gamma Gamma curve object.
		*/
		rgb_color_space_definition(float red_x, float red_y, float green_x, float green_y, float blue_x, float blue_y, white_point* ref_white, gamma* gamma)
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
			m_gamma = gamma;

			m_transform_matrix = calculate_transformation_matrix(m_red, m_green, m_blue, m_white->get_tristimulus());
			m_inverse_transform_matrix = m_transform_matrix.invert();
		}

		//! Default copy constructor.
		rgb_color_space_definition(rgb_color_space_definition& other)
		{
			m_red = other.get_red_chromaticity_coordinate();
			m_green = other.get_green_chromaticity_coordinate();
			m_blue = other.get_blue_chromaticity_coordinate();
			m_white = other.get_white_point();
			m_transform_matrix = other.get_transform_matrix();
			m_inverse_transform_matrix = other.get_inverse_transform_matrix();
		}

		//! Default deconstructor.
		/*!
		* Default deconstructor.
		*/
		~rgb_color_space_definition()
		{
		}

		//! Access the red chromaticity coordinate.
		std::array<float, 3> get_red_chromaticity_coordinate()
		{
			return m_red;
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

		//! Access the green chromaticity coordinate.
		std::array<float, 3> get_green_chromaticity_coordinate()
		{
			return m_green;
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

		//! Access the blue chromaticity coordinate.
		std::array<float, 3> get_blue_chromaticity_coordinate()
		{
			return m_blue;
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
		white_point* get_white_point()
		{
			return m_white;
		}

		//! Access the matrix to transform from rgb space to xyz.
		matrix<float> get_transform_matrix()
		{
			return m_transform_matrix;
		}

		//! Access the matrix to transform from xyz space to rgb.
		matrix<float> get_inverse_transform_matrix()
		{
			return m_inverse_transform_matrix;
		}

		//! Access the gamma curve.
		gamma* get_gamma_curve()
		{
			return m_gamma;
		}

		//! Set a new gamma curve.
		void set_gamma_curve(gamma* new_gamma)
		{
			m_gamma = new_gamma;
		}

	private:
		//! Calculate the matrix used to transform from RGB space to XYZ space by using this rgb color space definition.
		/*!
		* Calculate the matrix used to transform from RGB space to XYZ space by using this rgb color space definition.
		* /param red The x and y chormaticity values for red.
		* /param green The x and y chormaticity values for green.
		* /param blue The x and y chormaticity values for blue.
		* /param white_XYZ The XYZ tristimulus values for white.
		* /return The calculated transformation matrix.
		*/
		static matrix<float> calculate_transformation_matrix(std::array<float, 3> red, std::array<float, 3> green, std::array<float, 3> blue, std::array<float, 3> white_XYZ)
		{
			std::vector<float>cc_values{ red[0], green[0], blue[0], red[1], green[1], blue[1], red[2], green[2], blue[2] };
			matrix<float> cc(3, cc_values);

			auto cc_inv = cc.invert();
			auto tmp_vec = cc_inv * std::vector<float>(white_XYZ.begin(), white_XYZ.end());

			std::vector<float>tmp_mat_data{ tmp_vec[0], 0, 0, 0, tmp_vec[1], 0, 0, 0, tmp_vec[2] };
			matrix<float> tmp_mat(3, tmp_mat_data);

			return cc * tmp_mat;
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

		//! The gamma curve of this rgb color space definition.
		/*!
		* The gamma curve of this rgb color space definition.
		*/
		gamma* m_gamma;
	};

	//! Class that stores some default reference white values.
	/*!
	* This class stores reference whites like A, B, C, Equal Energy, D50, or D65.
	* The values for these reference whites were taken from https://www.easyrgb.com
	*/
	class rgb_color_space_definition_presets
	{
	private:
		color_space::white_point_presets m_white_presets;
		color_space::gamma_presets m_gamma_presets;

	public:
		//! sRGB is an RGB color space.
		/*!
		* sRGB is an RGB color space that HP and Microsoft created cooperatively in 1996
		* to use on monitors, printers, and the Internet.
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* sRGB() { return new rgb_color_space_definition(0.64f, 0.33f, 0.3f, 0.6f, 0.15f, 0.06f, m_white_presets.D65_2Degree(), m_gamma_presets.sRGB()); }

		//! The Adobe RGB (1998) color space.
		/*!
		* The Adobe RGB (1998) color space is an RGB color space developed by Adobe Systems, Inc.
		* in 1998. It was designed to encompass most of the colors achievable on CMYK color printers,
		* but by using RGB primary colors on a device such as a computer display.
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* adobeRGB() { return new rgb_color_space_definition(0.64f, 0.33f, 0.21f, 0.71f, 0.15f, 0.06f, m_white_presets.D65_2Degree(), m_gamma_presets.gammaAdobe()); }

		//! The PAL/SECAM color space.
		/*!
		* The PAL/SECAM color space is used for television in Europe, Asia, Afrika, Australia and parts of
		* South America.
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* pal_secam() { return new rgb_color_space_definition(0.64f, 0.33f, 0.29f, 0.6f, 0.15f, 0.06f, m_white_presets.D65_2Degree(), m_gamma_presets.gamma2_8()); }

		//! The NTSC color space used in America.
		/*!
		* The NTSC color space is used for television in North America and parts of South America.
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* americaNTSC() { return new rgb_color_space_definition(0.63f, 0.34f, 0.31f, 0.595f, 0.155f, 0.07f, m_white_presets.D65_2Degree(), m_gamma_presets.gamma2_2()); }

		//! The NTSC color space from 1953.
		/*!
		* Old version of the NTSC color space from 1953.
		* It uses the C reference white.
		*/
		rgb_color_space_definition* oldNTSC() { return new rgb_color_space_definition(0.67f, 0.33f, 0.21f, 0.71f, 0.14f, 0.08f, m_white_presets.C_2Degree(), m_gamma_presets.gamma2_2()); }

		//! The Apple RGB color space.
		/*!
		* The Apple RGB color space is an RGB color space developed by Apple.
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* appleRGB() { return new rgb_color_space_definition(0.625f, 0.34f, 0.28f, 0.595f, 0.155f, 0.07f, m_white_presets.D65_2Degree(), m_gamma_presets.gamma1_8()); }

		//! The DCI-P3 color space.
		/*!
		* DCI-P3, or DCI/P3, is a common RGB color space for digital movie projection
		* from the American film industry.
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* dci_p3() { return new rgb_color_space_definition(0.68f, 0.32f, 0.265f, 0.69f, 0.15f, 0.06f, m_white_presets.D65_2Degree(), m_gamma_presets.gamma2_6()); }

		//! The UHDTV color space.
		/*!
		* ITU - R Recommendation BT.2020, more commonly known by the abbreviations Rec. 2020
		* or BT.2020, defines various aspects of ultra - high - definition television(UHDTV)
		* with standard dynamic range(SDR) and wide color gamut(WCG)
		* It uses the D65 reference white.
		*/
		rgb_color_space_definition* uhdtv() { return new rgb_color_space_definition(0.708f, 0.292f, 0.17f, 0.797f, 0.131f, 0.046f, m_white_presets.D65_2Degree(), m_gamma_presets.gammaUHDTV()); }

		//! The Adobe wide gammut RGB color space.
		/*!
		* The wide-gamut RGB color space is an RGB color space developed by Adobe Systems, that
		* offers a large gamut by using pure spectral primary colors. It is able to store a
		* wider range of color values than sRGB or Adobe RGB color spaces.
		* It uses the D50 reference white.
		*/
		rgb_color_space_definition* adobeWideGammutRGB() { return new rgb_color_space_definition(0.735f, 0.265f, 0.115f, 0.826f, 0.157f, 0.018f, m_white_presets.D50_2Degree(), m_gamma_presets.gammaAdobe()); }

		//! The ROMM-RGB color space.
		/*!
		* The ProPhoto RGB color space, also known as ROMM RGB, is an output referred RGB color
		* space developed by Kodak. It offers an especially large gamut designed for use with
		* photographic output in mind. The ProPhoto RGB color space encompasses over 90% of
		* possible surface colors
		* It uses the D50 reference white.
		*/
		rgb_color_space_definition* rommRGB() { return new rgb_color_space_definition(0.7347f, 0.2653f, 0.1596f, 0.8404f, 0.0366f, 0.0001f, m_white_presets.D50_2Degree(), m_gamma_presets.gammaRomm()); }

		//! The CIE RGB (1931) color space.
		/*!
		* The CIE 1931 color spaces were the first defined quantitative links between distributions
		* of wavelengths in the electromagnetic visible spectrum, and physiologically perceived colors
		* in human color vision.
		* It uses the E reference white.
		*/
		rgb_color_space_definition* cieRGB() { return new rgb_color_space_definition(0.7347f, 0.2653f, 0.2738f, 0.7174f, 0.1666f, 0.0089f, m_white_presets.E_2Degree(), m_gamma_presets.gamma2_2()); }

		//! The CIE XYZ (1931) color space.
		/*!
		* The CIE 1931 color spaces were the first defined quantitative links between distributions
		* of wavelengths in the electromagnetic visible spectrum, and physiologically perceived colors
		* in human color vision. This gammut of this color space covers the whole xyz area.
		* It uses the E reference white.
		*/
		rgb_color_space_definition* cieXYZ() { return new rgb_color_space_definition(1.f, 0.f, 0.f, 1.f, 0.f, 0.f, m_white_presets.E_2Degree(), m_gamma_presets.gamma2_2()); }
	};
}
