#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\color_base.h"
#include "..\ColorMagic\spaces\rgb_truecolor.h"
#include "..\ColorMagic\manipulation\chromatic_adaptation.h"
#include "..\ColorMagic\manipulation\color_converter.h"

using namespace color_space;
using namespace color_manipulation;

class ChromaticAdaptation_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;
	rgb_color_space_definition* srgb;
	white_point* target_d75;

	xyz* orange;

	virtual void SetUp()
	{
		srgb = rgb_color_space_definition_presets().sRGB();
		target_d75 = white_point_presets().D75_2Degree();
		orange = new xyz(100.f, 60.f, 0.f, 1.f, srgb);
	}

	virtual void TearDown()
	{
	}
};

TEST_F(ChromaticAdaptation_Test, VonKries_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::von_kries_adaptation(orange, target_d75));
	ASSERT_NEAR(97.9f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(59.85f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.f, simple_adapted_xyz->z(), avg_error);
}

TEST_F(ChromaticAdaptation_Test, Bradford_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::bradford_adaptation_simplified(orange, target_d75));
	ASSERT_NEAR(97.45f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(58.97f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.f, simple_adapted_xyz->z(), avg_error);
	
	auto adapted_xyz = color_converter::to_xyz(chromatic_adaptation::bradford_adaptation(orange, target_d75));
	ASSERT_NEAR(97.44f, adapted_xyz->x(), avg_error);
	ASSERT_NEAR(58.96f, adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.f, adapted_xyz->z(), avg_error);
}

TEST_F(ChromaticAdaptation_Test, XYZScale_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::xyz_scale_adaptation(orange, target_d75));
	ASSERT_NEAR(99.9f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(60.f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.f, simple_adapted_xyz->z(), avg_error);
}

TEST_F(ChromaticAdaptation_Test, Sharp_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::sharp_adaptation(orange, target_d75));
	ASSERT_NEAR(97.41f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(58.86f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.17f, simple_adapted_xyz->z(), avg_error);
}

TEST_F(ChromaticAdaptation_Test, CMCCAT97_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::cmccat97_adaptation_simplified(orange, target_d75));
	ASSERT_NEAR(97.44f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(58.96f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.f, simple_adapted_xyz->z(), avg_error);

	auto adapted_xyz = color_converter::to_xyz(chromatic_adaptation::cmccat97_adaptation(orange, target_d75, 1.f, 100.f));
	ASSERT_NEAR(97.50f, adapted_xyz->x(), avg_error);
	ASSERT_NEAR(59.02f, adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.f, adapted_xyz->z(), avg_error);
}

TEST_F(ChromaticAdaptation_Test, CMCCAT2000_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::cmccat2000_adaptation_simplified(orange, target_d75));
	ASSERT_NEAR(97.77f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(59.27f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.21f, simple_adapted_xyz->z(), avg_error);

	auto adapted_xyz = color_converter::to_xyz(chromatic_adaptation::cmccat2000_adaptation(orange, target_d75, 1.f, 100.f, 100.f));
	ASSERT_NEAR(97.95f, adapted_xyz->x(), avg_error);
	ASSERT_NEAR(59.33f, adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.19f, adapted_xyz->z(), avg_error);
}

TEST_F(ChromaticAdaptation_Test, CAT02_Test)
{
	auto simple_adapted_xyz = color_converter::to_xyz(chromatic_adaptation::cat02_adaptation_simplified(orange, target_d75));
	ASSERT_NEAR(97.39f, simple_adapted_xyz->x(), avg_error);
	ASSERT_NEAR(58.94f, simple_adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.16f, simple_adapted_xyz->z(), avg_error);

	auto adapted_xyz = color_converter::to_xyz(chromatic_adaptation::cat02_adaptation(orange, target_d75, 1.f, 100.f));
	ASSERT_NEAR(97.55f, adapted_xyz->x(), avg_error);
	ASSERT_NEAR(59.f, adapted_xyz->y(), avg_error);
	ASSERT_NEAR(0.15f, adapted_xyz->z(), avg_error);
}