#include "stdafx.h"
#include "chromatic_adaptation.h"

color_space::color_base * color_manipulation::color_adjustments::von_kries_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	return do_adaption(color, target_white_point, m_von_kries, m_inverted_von_kries);
}

color_space::color_base * color_manipulation::color_adjustments::bradford_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	// Convert to XYZ space and transform using cmccat2000 matrix
	auto rgb_comp = m_bradford * color_manipulation::color_converter::to_xyz(color)->get_component_vector();
	rgb_comp[0] = rgb_comp[0] / color->get_component_vector()[1];
	rgb_comp[1] = rgb_comp[1] / color->get_component_vector()[1];
	rgb_comp[2] = rgb_comp[2] / color->get_component_vector()[1];

	// Create scaled white point vectors
	auto scaled_source_wp = m_bradford * std::vector<float> { color->get_rgb_color_space()->get_white_point()->get_tristimulus().begin(), color->get_rgb_color_space()->get_white_point()->get_tristimulus().end() };
	auto scaled_dest_wp = m_bradford * std::vector<float> { target_white_point->get_tristimulus().begin(), target_white_point->get_tristimulus().end() };

	// Adapt color
	auto p = powf(scaled_dest_wp[2] / scaled_source_wp[2], 0.0834f);
	std::vector<float> tmp_rgb_comp;
	tmp_rgb_comp.push_back((scaled_source_wp[0] * (rgb_comp[0] / scaled_dest_wp[0])) * color->get_component_vector()[1]);
	tmp_rgb_comp.push_back((scaled_source_wp[1] * (rgb_comp[1] / scaled_dest_wp[1])) * color->get_component_vector()[1]);
	tmp_rgb_comp.push_back((scaled_source_wp[2] * powf(rgb_comp[2] / scaled_dest_wp[2], p)) * color->get_component_vector()[1]);

	auto transformed_components = m_inverted_bradford * tmp_rgb_comp;
	color->get_rgb_color_space()->set_white_point(target_white_point);
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], color->alpha(), color->get_rgb_color_space());

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}

color_space::color_base * color_manipulation::color_adjustments::bradford_adaptation_simplified(color_space::color_base * color, color_space::white_point * target_white_point)
{
	return do_adaption(color, target_white_point, m_bradford, m_inverted_bradford);
}

color_space::color_base * color_manipulation::color_adjustments::xyz_scale_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	return do_adaption(color, target_white_point, m_xyz_scale, m_inverted_xyz_scale);
}

color_space::color_base * color_manipulation::color_adjustments::sharp_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	return do_adaption(color, target_white_point, m_sharp, m_inverted_sharp);
}

color_space::color_base * color_manipulation::color_adjustments::cmccat2000_adaptation_simplified(color_space::color_base * color, color_space::white_point * target_white_point)
{
	return do_adaption(color, target_white_point, m_cmccat2000, m_inverted_cmccat2000);
}

color_space::color_base * color_manipulation::color_adjustments::cmccat2000_adaptation(color_space::color_base * color, color_space::white_point * target_white_point, float f, float adapting_field_luminance, float reference_field_luminance)
{
	// Convert to XYZ space and transform using cmccat2000 matrix
	auto tmp_xyz_comp = m_cmccat2000 * color_manipulation::color_converter::to_xyz(color)->get_component_vector();
	
	// Create scaled white point vectors
	auto scaled_source_wp = m_cmccat2000 * std::vector<float> { color->get_rgb_color_space()->get_white_point()->get_tristimulus().begin(), color->get_rgb_color_space()->get_white_point()->get_tristimulus().end() };
	auto scaled_dest_wp = m_cmccat2000 * std::vector<float> { target_white_point->get_tristimulus().begin(), target_white_point->get_tristimulus().end() };

	// Compute degree of adaption
	auto d = f * (0.08f * log10f(0.5f * (adapting_field_luminance + reference_field_luminance)) + 0.76f - 0.45f * ((adapting_field_luminance - reference_field_luminance) / (adapting_field_luminance + reference_field_luminance)));
	if (d < 0.f) d = 0.f;
	if (d > 1.f) d = 1.f;

	auto wp_y_factor = d * (color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() / target_white_point->get_tristimulus_y());

	// Adapt color
	std::vector<float> rgbc;
	rgbc.push_back((wp_y_factor * (scaled_dest_wp[0] / scaled_source_wp[0]) + 1.f - d) * tmp_xyz_comp[0]);
	rgbc.push_back((wp_y_factor * (scaled_dest_wp[1] / scaled_source_wp[1]) + 1.f - d) * tmp_xyz_comp[1]);
	rgbc.push_back((wp_y_factor * (scaled_dest_wp[2] / scaled_source_wp[2]) + 1.f - d) * tmp_xyz_comp[2]);

	auto transformed_components = m_inverted_cmccat2000 * rgbc;
	color->get_rgb_color_space()->set_white_point(target_white_point);
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], color->alpha(), color->get_rgb_color_space());

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}

color_space::color_base * color_manipulation::color_adjustments::do_adaption(color_space::color_base * color, color_space::white_point * target_white_point, matrix<float> mat, matrix<float> inverted_mat)
{
	// Convert to XYZ space
	auto tmp_color = color_manipulation::color_converter::to_xyz(color);

	// Create scaled white point vectors
	auto scaled_source_wp = mat * std::vector<float> { color->get_rgb_color_space()->get_white_point()->get_tristimulus().begin(), color->get_rgb_color_space()->get_white_point()->get_tristimulus().end() };
	auto scaled_dest_wp = mat * std::vector<float> { target_white_point->get_tristimulus().begin(), target_white_point->get_tristimulus().end() };

	// Create white point matrix from scaled white point vectors
	auto wp_matrix = matrix<float>(3, 3, std::vector<float>
	{
		scaled_dest_wp[0] / scaled_source_wp[0], 0.f, 0.f,
		0.f, scaled_dest_wp[1] / scaled_source_wp[1], 0.f,
		0.f, 0.f, scaled_dest_wp[2] / scaled_source_wp[2]
	});

	// Transform the input color and create a new xyz space object
	auto transformed_components = (inverted_mat * wp_matrix * mat) * tmp_color->get_component_vector();
	color->get_rgb_color_space()->set_white_point(target_white_point);
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], tmp_color->alpha(), color->get_rgb_color_space());

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}
