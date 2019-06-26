#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\rgb_color_space_definition.h"

using namespace color_space;

class RGBColorSpaceDefinition_Test : public ::testing::Test {
protected:
	float avg_error = 0.05f;

	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}
};

TEST_F(RGBColorSpaceDefinition_Test, Constructor_Tests)
{
	white_point ref_white(0.3127f, 0.3290f);
	rgb_color_space_definition d65_2(0.64f, 0.33f, 0.3f, 0.6f, 0.15f, 0.06f, &ref_white);

	std::vector<float> result_data{ 0.412383f, 0.357585f, 0.18048f, 0.212635f, 0.71517f, 0.072192f, 0.01933f, 0.119195f, 0.950528f };
	matrix<float> resulting_transform(3, result_data);

	EXPECT_NEAR(resulting_transform(0, 0), d65_2.get_transform_matrix()(0, 0), avg_error);
	EXPECT_NEAR(resulting_transform(0, 1), d65_2.get_transform_matrix()(0, 1), avg_error);
	EXPECT_NEAR(resulting_transform(0, 2), d65_2.get_transform_matrix()(0, 2), avg_error);
	EXPECT_NEAR(resulting_transform(1, 0), d65_2.get_transform_matrix()(1, 0), avg_error);
	EXPECT_NEAR(resulting_transform(1, 1), d65_2.get_transform_matrix()(1, 1), avg_error);
	EXPECT_NEAR(resulting_transform(1, 2), d65_2.get_transform_matrix()(1, 2), avg_error);
	EXPECT_NEAR(resulting_transform(2, 0), d65_2.get_transform_matrix()(2, 0), avg_error);
	EXPECT_NEAR(resulting_transform(2, 1), d65_2.get_transform_matrix()(2, 1), avg_error);
	EXPECT_NEAR(resulting_transform(2, 2), d65_2.get_transform_matrix()(2, 2), avg_error);

	std::vector<float> result_invers_data{ 3.24103f, -1.53741f, -0.49862f, -0.969242f, 1.87596f, 0.041555f, 0.055632f, -0.203979f, 1.05698f };
	matrix<float> resulting_invers_transform(3, result_invers_data);
	EXPECT_NEAR(resulting_invers_transform(0, 0), d65_2.get_inverse_transform_matrix()(0, 0), avg_error);
	EXPECT_NEAR(resulting_invers_transform(0, 1), d65_2.get_inverse_transform_matrix()(0, 1), avg_error);
	EXPECT_NEAR(resulting_invers_transform(0, 2), d65_2.get_inverse_transform_matrix()(0, 2), avg_error);
	EXPECT_NEAR(resulting_invers_transform(1, 0), d65_2.get_inverse_transform_matrix()(1, 0), avg_error);
	EXPECT_NEAR(resulting_invers_transform(1, 1), d65_2.get_inverse_transform_matrix()(1, 1), avg_error);
	EXPECT_NEAR(resulting_invers_transform(1, 2), d65_2.get_inverse_transform_matrix()(1, 2), avg_error);
	EXPECT_NEAR(resulting_invers_transform(2, 0), d65_2.get_inverse_transform_matrix()(2, 0), avg_error);
	EXPECT_NEAR(resulting_invers_transform(2, 1), d65_2.get_inverse_transform_matrix()(2, 1), avg_error);
	EXPECT_NEAR(resulting_invers_transform(2, 2), d65_2.get_inverse_transform_matrix()(2, 2), avg_error);
}
