#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\utils\matrix.h"

class Matrix_Test : public ::testing::Test {
protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}
};

TEST_F(Matrix_Test, OperatorTests)
{
	matrix<int> matrix_3x3(3, 1);

	EXPECT_EQ(1, matrix_3x3(1, 1));

	matrix_3x3(1, 2) = 5;
	EXPECT_EQ(5, matrix_3x3(1, 2));

	matrix<int> matrix_2x4(2, 4, 3);
	matrix_3x3 = matrix_2x4;
	EXPECT_EQ(matrix_2x4, matrix_3x3);

	auto mat_plus = matrix_3x3 + matrix_3x3;
	EXPECT_EQ(6, mat_plus(1, 1));

	auto mat_minus = mat_plus - matrix_3x3;
	EXPECT_EQ(3, mat_minus(1, 1));

	EXPECT_EQ(6, (mat_minus * 2)(1, 1));

	EXPECT_THROW(mat_minus(10, 10), std::exception);
}

TEST_F(Matrix_Test, AccessorTests)
{
	matrix<int> matrix_3x3(3, 1);

	EXPECT_EQ(3, matrix_3x3.columns());
	EXPECT_EQ(3, matrix_3x3.rows());
	EXPECT_EQ(9, matrix_3x3.size());
}

TEST_F(Matrix_Test, DeterminanteTests)
{
	matrix<int> matrix1(2, 1);
	matrix<int> matrix2(2, 2, 0);
	matrix<int> matrix3(4, 4);
	std::vector<int> data {1, 0, 2, -1, 3, 0, 0, 5, 2, 1, 4, -3, 1, 0, 5, 0};
	matrix3.insert(data);

	EXPECT_EQ(0, matrix1.determinante());
	EXPECT_EQ(0, matrix2.determinante());
	EXPECT_EQ(30, matrix3.determinante());
}