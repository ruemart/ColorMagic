#include "stdafx.h"
#include "chromatic_adaptation.h"

matrix<float> color_manipulation::chromatic_adaptation::m_von_kries = matrix<float>(3, 3, std::vector<float>
{
	0.40024f, 0.7076f, -0.08081f,
		-0.2263f, 1.16532f, 0.0457f,
		0.f, 0.f, 0.91822f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_von_kries = matrix<float>(3, 3, std::vector<float>
{
	1.8599364f, -1.1293816f, 0.2198974f,
		0.3611914f, 0.6388125f, -0.0000064f,
		0.f, 0.f, 1.0890636f
});

matrix<float> color_manipulation::chromatic_adaptation::m_bradford = matrix<float>(3, 3, std::vector<float>
{
	0.8951f, 0.2664f, -0.1614f,
		-0.7502f, 1.7135f, 0.0367f,
		0.0389f, -0.0685f, 1.0296f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_bradford = matrix<float>(3, 3, std::vector<float>
{
	0.9869929f, -0.1470543f, 0.1599627f,
		0.4323053f, 0.5183603f, 0.0492912f,
		-0.0085287f, 0.0400428f, 0.9684867f
});

matrix<float> color_manipulation::chromatic_adaptation::m_xyz_scale = matrix<float>(3, 3, std::vector<float>
{
	1.f, 0.f, -0.f,
		-0.f, 1.f, 0.f,
		0.f, -0.f, 1.f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_xyz_scale = matrix<float>(3, 3, std::vector<float>
{
	1.f, -0.f, 0.f,
		0.f, 1.f, 0.f,
		-0.f, 0.f, 1.f
});

matrix<float> color_manipulation::chromatic_adaptation::m_sharp = matrix<float>(3, 3, std::vector<float>
{
	1.2694f, -0.0988f, -0.1706f,
		-0.8364f, 1.8006f, 0.0357f,
		0.0297f, -0.0315f, 1.0018f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_sharp = matrix<float>(3, 3, std::vector<float>
{
	0.81563f, 0.04715f, 0.13722f,
		0.37911f, 0.57694f, 0.044f,
		-0.01226f, 0.01674f, 0.99552f
});

matrix<float> color_manipulation::chromatic_adaptation::m_cmccat97 = matrix<float>(3, 3, std::vector<float>
{
	0.8951f, 0.2664f, -0.1614f,
		-0.7502f, 1.7135f, 0.0367f,
		0.0389f, -0.0685f, 1.0296f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_cmccat97 = matrix<float>(3, 3, std::vector<float>
{
	0.98699f, -0.14705f, 0.15996f,
		0.43231f, 0.51836f, 0.04929f,
		-0.00853f, 0.04004f, 0.96849f
});

matrix<float> color_manipulation::chromatic_adaptation::m_cmccat2000 = matrix<float>(3, 3, std::vector<float>
{
	0.7982f, 0.3389f, -0.1371f,
		-0.5918f, 1.5512f, 0.0406f,
		0.0008f, 0.0239f, 0.9753f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_cmccat2000 = matrix<float>(3, 3, std::vector<float>
{
	1.07645f, -0.23766f, 0.16121f,
		0.41096f, 0.55434f, 0.03469f,
		-0.01095f, -0.01339f, 1.02434f
});

matrix<float> color_manipulation::chromatic_adaptation::m_cat02 = matrix<float>(3, 3, std::vector<float>
{
	0.7328f, 0.4296f, -0.1624f,
		-0.7036f, 1.6975f, 0.0061f,
		0.003f, 0.0136f, 0.9834f
});

matrix<float> color_manipulation::chromatic_adaptation::m_inverted_cat02 = matrix<float>(3, 3, std::vector<float>
{
	1.09612f, -0.27887f, 0.18275f,
		0.45437f, 0.47353f, 0.0721f,
		-0.00963f, -0.0057f, 1.01533f
});

color_space::color_base * color_manipulation::chromatic_adaptation::von_kries_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_von_kries, m_inverted_von_kries);
}

color_space::color_base * color_manipulation::chromatic_adaptation::bradford_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	// Convert to XYZ space and transform using bradford matrix (incl. normalization)
	auto rgb_comp = m_bradford * color_manipulation::color_converter::to_xyz(color)->get_component_vector();
	rgb_comp[0] /= color->get_component_vector()[1];
	rgb_comp[1] /= color->get_component_vector()[1];
	rgb_comp[2] /= color->get_component_vector()[1];

	// Create scaled white point vectors (incl. normalization)
	std::vector<float> source_wp = std::vector<float>();
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[0] / color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1] / color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[2] / color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);

	std::vector<float> dest_wp = std::vector<float>();
	dest_wp.push_back(target_white_point->get_tristimulus()[0] / target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[1] / target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[2] / target_white_point->get_tristimulus()[1]);

	auto scaled_source_wp = m_bradford * source_wp;
	auto scaled_dest_wp = m_bradford * dest_wp;

	// Adapt color (incl. undo of normalization)
	auto p = powf(scaled_source_wp[2] / scaled_dest_wp[2], 0.0834f);
	std::vector<float> tmp_rgb_comp;
	tmp_rgb_comp.push_back((scaled_dest_wp[0] * (rgb_comp[0] / scaled_source_wp[0])) * color->get_component_vector()[1]);
	tmp_rgb_comp.push_back((scaled_dest_wp[1] * (rgb_comp[1] / scaled_source_wp[1])) * color->get_component_vector()[1]);
	tmp_rgb_comp.push_back((scaled_dest_wp[2] * powf(rgb_comp[2] / scaled_source_wp[2], p)) * color->get_component_vector()[1]);

	auto transformed_components = m_inverted_bradford * tmp_rgb_comp;
	color->get_rgb_color_space()->set_white_point(target_white_point);
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], color->alpha(), color->get_rgb_color_space());

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}

color_space::color_base * color_manipulation::chromatic_adaptation::bradford_adaptation_simplified(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_bradford, m_inverted_bradford);
}

color_space::color_base * color_manipulation::chromatic_adaptation::xyz_scale_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_xyz_scale, m_inverted_xyz_scale);
}

color_space::color_base * color_manipulation::chromatic_adaptation::sharp_adaptation(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_sharp, m_inverted_sharp);
}

color_space::color_base * color_manipulation::chromatic_adaptation::cmccat97_adaptation_simplified(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_cmccat97, m_inverted_cmccat97);
}

color_space::color_base * color_manipulation::chromatic_adaptation::cmccat97_adaptation(color_space::color_base * color, color_space::white_point * target_white_point, float f, float adapting_field_luminance)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	// Convert to XYZ space and transform using cmccat97 matrix (incl. normalization)
	auto rgb_comp = m_cmccat97 * color_manipulation::color_converter::to_xyz(color)->get_component_vector();
	rgb_comp[0] /= color->get_component_vector()[1];
	rgb_comp[1] /= color->get_component_vector()[1];
	rgb_comp[2] /= color->get_component_vector()[1];

	// Create scaled white point vectors (incl. normalization)
	std::vector<float> source_wp = std::vector<float>();
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[0] / color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1] / color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[2] / color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);

	std::vector<float> dest_wp = std::vector<float>();
	dest_wp.push_back(target_white_point->get_tristimulus()[0] / target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[1] / target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[2] / target_white_point->get_tristimulus()[1]);
	
	auto scaled_source_wp = m_cmccat97 * source_wp;
	auto scaled_dest_wp = m_cmccat97 * dest_wp;

	// Compute degree of adaption
	auto d = f - (f / (1.f + 2.f * powf(adapting_field_luminance, 0.25f) + powf(adapting_field_luminance, 2.f) / 300.f));
	if (d < 0.f) d = 0.f;
	if (d > 1.f) d = 1.f;

	// Adapt color (incl. undo of normalization)
	auto p = powf(scaled_source_wp[2] / scaled_dest_wp[2], 0.0834f);
	std::vector<float> rgbc;
	rgbc.push_back(color->get_component_vector()[1] * (rgb_comp[0] * (d * (scaled_dest_wp[0] / scaled_source_wp[0]) + 1.f - d)));
	rgbc.push_back(color->get_component_vector()[1] * (rgb_comp[1] * (d * (scaled_dest_wp[1] / scaled_source_wp[1]) + 1.f - d)));
	rgbc.push_back(color->get_component_vector()[1] * (powf(fabsf(rgb_comp[2]), p) * (d * (scaled_dest_wp[2] / powf(scaled_source_wp[2], p)) + 1.f - d)));

	auto transformed_components = m_inverted_cmccat97 * rgbc;
	color->get_rgb_color_space()->set_white_point(target_white_point);
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], color->alpha(), color->get_rgb_color_space());

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}

color_space::color_base * color_manipulation::chromatic_adaptation::cmccat2000_adaptation_simplified(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_cmccat2000, m_inverted_cmccat2000);
}

color_space::color_base * color_manipulation::chromatic_adaptation::cmccat2000_adaptation(color_space::color_base * color, color_space::white_point * target_white_point, float f, float adapting_field_luminance, float reference_field_luminance)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	// Convert to XYZ space and transform using cmccat2000 matrix
	auto tmp_xyz_comp = m_cmccat2000 * color_manipulation::color_converter::to_xyz(color)->get_component_vector();
	
	// Create scaled white point vectors
	std::vector<float> source_wp = std::vector<float>();
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[0]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[2]);

	std::vector<float> dest_wp = std::vector<float>();
	dest_wp.push_back(target_white_point->get_tristimulus()[0]);
	dest_wp.push_back(target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[2]);

	auto scaled_source_wp = m_cmccat2000 * source_wp;
	auto scaled_dest_wp = m_cmccat2000 * dest_wp;

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

color_space::color_base * color_manipulation::chromatic_adaptation::cat02_adaptation_simplified(color_space::color_base * color, color_space::white_point * target_white_point)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	return do_adaption(color, target_white_point, m_cat02, m_inverted_cat02);
}

color_space::color_base * color_manipulation::chromatic_adaptation::cat02_adaptation(color_space::color_base * color, color_space::white_point * target_white_point, float f, float adapting_field_luminance)
{
	if (color->get_rgb_color_space()->get_white_point() == target_white_point)
	{
		return color;
	}

	// Convert to XYZ space and transform using cmccat2000 matrix
	auto tmp_xyz_comp = m_cat02 * color_manipulation::color_converter::to_xyz(color)->get_component_vector();

	// Create scaled white point vectors
	std::vector<float> source_wp = std::vector<float>();
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[0]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[2]);

	std::vector<float> dest_wp = std::vector<float>();
	dest_wp.push_back(target_white_point->get_tristimulus()[0]);
	dest_wp.push_back(target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[2]);

	auto scaled_source_wp = m_cat02 * source_wp;
	auto scaled_dest_wp = m_cat02 * dest_wp;

	// Compute degree of adaption
	auto d = f * (1.f - (1.f / 3.6f) * expf((-adapting_field_luminance - 42.f) / 92.f));
	if (d < 0.f) d = 0.f;
	if (d > 1.f) d = 1.f;

	auto wp_y_factor = d * (color->get_rgb_color_space()->get_white_point()->get_tristimulus_y() / target_white_point->get_tristimulus_y());

	// Adapt color
	std::vector<float> rgbc;
	rgbc.push_back(tmp_xyz_comp[0] * (d * (scaled_dest_wp[0] / scaled_source_wp[0]) + 1.f - d));
	rgbc.push_back(tmp_xyz_comp[1] * (d * (scaled_dest_wp[1] / scaled_source_wp[1]) + 1.f - d));
	rgbc.push_back(tmp_xyz_comp[2] * (d * (scaled_dest_wp[2] / scaled_source_wp[2]) + 1.f - d));

	auto transformed_components = m_inverted_cat02 * rgbc;
	color->get_rgb_color_space()->set_white_point(target_white_point);
	auto tmp_trans_color = new color_space::xyz(transformed_components[0], transformed_components[1], transformed_components[2], color->alpha(), color->get_rgb_color_space());

	// Convert transformed color back to input color space
	return color_manipulation::color_converter::convertTo(tmp_trans_color, color->get_color_type());
}

color_space::color_base * color_manipulation::chromatic_adaptation::do_adaption(color_space::color_base * color, color_space::white_point * target_white_point, matrix<float> mat, matrix<float> inverted_mat)
{
	// Convert to XYZ space
	auto tmp_color = color_manipulation::color_converter::to_xyz(color);

	// Create scaled white point vectors
	std::vector<float> source_wp = std::vector<float>();
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[0]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[1]);
	source_wp.push_back(color->get_rgb_color_space()->get_white_point()->get_tristimulus()[2]);

	std::vector<float> dest_wp = std::vector<float>();
	dest_wp.push_back(target_white_point->get_tristimulus()[0]);
	dest_wp.push_back(target_white_point->get_tristimulus()[1]);
	dest_wp.push_back(target_white_point->get_tristimulus()[2]);

	auto scaled_source_wp = mat * source_wp;
	auto scaled_dest_wp = mat * dest_wp;

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
