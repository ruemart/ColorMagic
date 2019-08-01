#include "stdafx.h"
#include "chromatic_adaptation.h"

color_space::color_base * color_manipulation::color_adjustments::von_kries_adaptation(color_space::color_base * color, color_space::rgb_color_space_definition * target_color_space)
{
	do_adaption(color, target_color_space, m_von_kries, m_inverted_von_kries);
}

color_space::color_base * color_manipulation::color_adjustments::von_kries_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	auto color_space_def = new color_space::rgb_color_space_definition(color->get_rgb_color_space()->get_red_x(), color->get_rgb_color_space()->get_red_y(),
		color->get_rgb_color_space()->get_green_x(), color->get_rgb_color_space()->get_green_y(),
		color->get_rgb_color_space()->get_blue_x(), color->get_rgb_color_space()->get_blue_y(),
		target_white_point, color->get_rgb_color_space()->get_gamma_curve());

	return von_kries_adaptation(color, color_space_def);
}

color_space::color_base * color_manipulation::color_adjustments::bradford_adaptation(color_space::color_base * color, color_space::rgb_color_space_definition * target_color_space)
{
	do_adaption(color, target_color_space, m_bradford, m_inverted_bradford);
}

color_space::color_base * color_manipulation::color_adjustments::bradford_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	auto color_space_def = new color_space::rgb_color_space_definition(color->get_rgb_color_space()->get_red_x(), color->get_rgb_color_space()->get_red_y(),
		color->get_rgb_color_space()->get_green_x(), color->get_rgb_color_space()->get_green_y(),
		color->get_rgb_color_space()->get_blue_x(), color->get_rgb_color_space()->get_blue_y(),
		target_white_point, color->get_rgb_color_space()->get_gamma_curve());

	return bradford_adaptation(color, color_space_def);
}

color_space::color_base * color_manipulation::color_adjustments::xyz_scale_adaptation(color_space::color_base * color, color_space::rgb_color_space_definition * target_color_space)
{
	do_adaption(color, target_color_space, m_xyz_scale, m_inverted_xyz_scale);
}

color_space::color_base * color_manipulation::color_adjustments::xyz_scale_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	auto color_space_def = new color_space::rgb_color_space_definition(color->get_rgb_color_space()->get_red_x(), color->get_rgb_color_space()->get_red_y(),
		color->get_rgb_color_space()->get_green_x(), color->get_rgb_color_space()->get_green_y(),
		color->get_rgb_color_space()->get_blue_x(), color->get_rgb_color_space()->get_blue_y(),
		target_white_point, color->get_rgb_color_space()->get_gamma_curve());

	return xyz_scale_adaptation(color, color_space_def);
}

color_space::color_base * color_manipulation::color_adjustments::sharp_adaptation(color_space::color_base * color, color_space::rgb_color_space_definition * target_color_space)
{
	do_adaption(color, target_color_space, m_sharp, m_inverted_sharp);
}

color_space::color_base * color_manipulation::color_adjustments::sharp_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	auto color_space_def = new color_space::rgb_color_space_definition(color->get_rgb_color_space()->get_red_x(), color->get_rgb_color_space()->get_red_y(),
		color->get_rgb_color_space()->get_green_x(), color->get_rgb_color_space()->get_green_y(),
		color->get_rgb_color_space()->get_blue_x(), color->get_rgb_color_space()->get_blue_y(),
		target_white_point, color->get_rgb_color_space()->get_gamma_curve());

	return sharp_adaptation(color, color_space_def);
}

color_space::color_base * color_manipulation::color_adjustments::do_adaption(color_space::color_base * color, color_space::rgb_color_space_definition * target_color_space, matrix<float> mat, matrix<float> inverted_mat)
{
	// Convert to XYZ space
	auto tmp_color = color_manipulation::color_converter::to_xyz(color);

	// Create scaled white point vectors
	auto scaled_source_wp = m_von_kries * std::vector<float> { color->get_rgb_color_space()->get_white_point()->get_tristimulus().begin(), color->get_rgb_color_space()->get_white_point()->get_tristimulus().end() };
	auto scaled_dest_wp = m_von_kries * std::vector<float> { target_color_space->get_white_point()->get_tristimulus().begin(), target_color_space->get_white_point()->get_tristimulus().end() };

	// Create white point matrix from scaled white point vectors
	auto wp_matrix = matrix<float>(3, 3, std::vector<float>
	{
		scaled_dest_wp[0] / scaled_source_wp[0], 0.f, 0.f,
		0.f, scaled_dest_wp[1] / scaled_source_wp[1], 0.f,
		0.f, 0.f, scaled_dest_wp[2] / scaled_source_wp[2]
	});

	// Transform the input color and create a new xyz space object
	auto transformed_components = (inverted_mat * wp_matrix * mat) * tmp_color->get_component_vector();
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], tmp_color->alpha(), target_color_space);

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}
