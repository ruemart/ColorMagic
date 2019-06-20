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

	EXPECT_THROW(mat_minus(10, 10), std::out_of_range);
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
	std::vector<int> data1{ 1, 0, 2, -1, 3, 0, 0, 5, 2, 1, 4, -3, 1, 0, 5, 0 };
	matrix3.insert(data1);
	matrix<int> matrix4(6, 6);
	std::vector<int> data2{ 4, 3, 2, -5, -2, 3, 0, 4, 2, -1, -3, 2, 2, -4, -4, 1, -2, 0, -4, 3, 2, -2, -1, 0, 3, -2, 1, 4, 3, 1, -2, 3, -3, 2, 0, -5 };
	matrix4.insert(data2);
	matrix<int> matrix5(2);
	std::vector<int> data3{ 4, 3, 0, 4 };
	matrix5.insert(data3);
	matrix<int> matrix6(3);
	std::vector<int> data4{ 1, 2, 3, 5, 4, 3, 2, 4, 6 };
	matrix6.insert(data4);

	EXPECT_EQ(0, matrix1.determinante());
	EXPECT_EQ(0, matrix2.determinante());
	EXPECT_EQ(30, matrix3.determinante());
	EXPECT_EQ(-459, matrix4.determinante());
	EXPECT_EQ(16, matrix5.determinante());
	EXPECT_EQ(0, matrix6.determinante());
}

TEST_F(Matrix_Test, IdentityTests)
{
	matrix<int> id = matrix<int>::create_idendity(3);
	matrix<int> id2(3, 3, 0);
	id2(0, 0) = 1;
	id2(1, 1) = 1;
	id2(2, 2) = 1;
	EXPECT_EQ(id, id2);
}