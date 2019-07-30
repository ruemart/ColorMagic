#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\spaces\gamma.h"

using namespace color_space;

class Gamma_Test : public ::testing::Test {
protected:
	gamma_part* part1;
	gamma_part* part2;
	gamma_part* part3;

	gamma* g1;
	gamma* g2;
	gamma* g3;

	virtual void SetUp()
	{
		part1 = new gamma_part();
		part2 = new gamma_part([](float input) {return input * 2; });
		part3 = new gamma_part([](float input) {return input * 3; }, 0.5f);

		std::vector<gamma_part*> parts;
		parts.push_back(part2);
		parts.push_back(part3);

		g1 = new gamma();
		g2 = new gamma(parts, parts);
		g3 = new gamma(std::vector<gamma_part*> { new gamma_part() }, std::vector<gamma_part*>{ nullptr });
	}
};

TEST_F(Gamma_Test, GammaPartConstructor_Tests)
{
	EXPECT_EQ(1.f, part1->get_upper_border());
	EXPECT_FALSE((part1->get_gamma_function()) ? true : false);
	EXPECT_EQ(1.f, part2->get_upper_border());
	EXPECT_TRUE((part2->get_gamma_function()) ? true : false);
	EXPECT_EQ(0.5f, part3->get_upper_border());
	EXPECT_TRUE((part3->get_gamma_function()) ? true : false);
}

TEST_F(Gamma_Test, GammaPartOperator_Tests)
{
	EXPECT_FALSE((*part1) == (*part2));
	part1 = part2;
	EXPECT_TRUE((*part1) == (*part2));

	EXPECT_TRUE((*part2) > (*part3));
	EXPECT_TRUE((*part3) <= (*part2));
}

TEST_F(Gamma_Test, GammaConstructor_Tests)
{
	EXPECT_EQ(0, g1->get_gamma_curve_parts().size());
	EXPECT_EQ(0, g1->get_inverse_gamma_curve_parts().size());

	EXPECT_EQ(2, g2->get_gamma_curve_parts().size());
	EXPECT_EQ(2, g2->get_inverse_gamma_curve_parts().size());

	// Check if sorting the parts works
	EXPECT_EQ(0.5f, g2->get_gamma_curve_parts()[0]->get_upper_border());
	EXPECT_EQ(1.f, g2->get_gamma_curve_parts()[1]->get_upper_border());
}

TEST_F(Gamma_Test, GammaOperator_Tests)
{
	EXPECT_FALSE(g1 == g2);
	g1 = g2;
	EXPECT_TRUE(g1 == g2);
}

TEST_F(Gamma_Test, GammaCorrection_Tests)
{
	EXPECT_EQ(0.5f, g3->gamma_correction(0.5f));
	EXPECT_EQ(0.5f, g3->inverse_gamma_correction(0.5f));
	EXPECT_EQ(0.75f, g2->gamma_correction(0.25f));
	EXPECT_EQ(1.2f, g2->gamma_correction(0.6f));
}