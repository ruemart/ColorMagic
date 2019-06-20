#include "stdafx.h"

#ifndef __MATRIX_CPP
#define __MATRIX_CPP

#include "matrix.h"

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& other)
{
	if (this == &other) return *this;

	size_t new_rows = other.rows();
	size_t new_cols = other.columns();

	m_values.resize(new_rows);
	for (size_t i = 0; i < m_values.size(); i++)
	{
		m_values[i].resize(new_cols);
	}

	for (unsigned i = 0; i < new_rows; i++)
	{
		for (unsigned j = 0; j < new_cols; j++)
		{
			m_values[i][j] = other(i, j);
		}
	}
	m_rows = new_rows;
	m_columns = new_cols;

	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& other)
{
	matrix result(m_rows, m_columns);

	for (unsigned i = 0; i < m_rows; i++)
	{
		for (unsigned j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[i][j] + other(i, j);
		}
	}

	return result;
}

template<typename T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& other)
{
	matrix result = (*this) + other;
	(*this) = result;
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator-(const matrix<T>& other)
{
	matrix result(m_rows, m_columns);

	for (unsigned i = 0; i < m_rows; i++)
	{
		for (unsigned j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[i][j] - other(i, j);
		}
	}

	return result;
}

template<typename T>
matrix<T>& matrix<T>::operator-=(const matrix<T>& other)
{
	matrix result = (*this) - other;
	(*this) = result;
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& other)
{
	size_t rows = other.rows();
	size_t cols = other.columns();
	matrix result(rows, cols);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			for (size_t k = 0; k < rows; k++)
			{
				result(i, j) += this->m_values[i][k] * other(k, j);
			}
		}
	}

	return result;
}

template<typename T>
matrix<T>& matrix<T>::operator*=(const matrix<T>& other)
{
	matrix result = (*this) * other;
	(*this) = result;
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator+(const T & other)
{
	matrix result(m_rows, m_columns);

	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[i][j] + other;
		}
	}

	return result;
}

template<typename T>
matrix<T> matrix<T>::operator-(const T & other)
{
	matrix result(m_rows, m_columns);

	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[i][j] - other;
		}
	}

	return result;
}

template<typename T>
matrix<T> matrix<T>::operator*(const T & other)
{
	matrix result(m_rows, m_columns);

	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[i][j] * other;
		}
	}

	return result;
}

template<typename T>
matrix<T> matrix<T>::operator/(const T & other)
{
	matrix result(m_rows, m_columns);

	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[i][j] / other;
		}
	}

	return result;
}

template<typename T>
std::vector<T> matrix<T>::operator*(const std::vector<T>& other)
{
	std::vector<T> result(other.size());

	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_columns; j++)
		{
			result[i] = this->m_values[i][j] * other[j];
		}
	}

	return result;
}

template<typename T>
matrix<T> matrix<T>::transpose()
{
	matrix result(m_rows, m_columns);

	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_columns; j++)
		{
			result(i, j) = this->m_values[j][i];
		}
	}

	return result;
}

template<typename T>
T matrix<T>::determinante()
{
	// First check special cases to shorten calculation for this cases:
	// -------------------------------------------------------------------------

	// 1. Is the matrix quadratic (NxN)? If not calculating the determinante is impossible -> return 0.
	if (m_rows != m_columns) return 0;

	// 2. Do we have a 1x1 matrix (just one value)? -> Determinante = value
	if (m_rows == 1) return m_values[0][0];

	// 3. Is one of the rows filled with 0? -> Determinante = 0
	bool row_is_null = false;
	for (size_t row = 0; row < m_rows; ++row)
	{
		row_is_null = is_row_null(row);
		if (row_is_null) break;
	}
	if (row_is_null) return 0;

	// 4. Is one of the columns filled with 0? -> Determinante = 0
	bool col_is_null = false;
	for (size_t col = 0; col < m_rows; ++col)
	{
		col_is_null = is_column_null(col);
		if (col_is_null) break;
	}
	if (col_is_null) return 0;

	// 5. Are two rows equal? -> Determinante = 0
	bool rows_equal = false;
	for (size_t i = 0; i < m_rows; ++i)
	{
		if (rows_equal) break;
		for (size_t j = i + 1; j < m_rows; ++j)
		{
			rows_equal = are_rows_equal(i, j);
			if (rows_equal) break;
		}
	}
	if (rows_equal) return 0;

	// 6. Are two columns equal? -> Determinante = 0
	bool cols_equal = false;
	for (size_t i = 0; i < m_rows; ++i)
	{
		if (cols_equal) break;
		for (size_t j = i + 1; j < m_rows; ++j)
		{
			cols_equal = are_columns_equal(i, j);
			if (cols_equal) break;
		}
	}
	if (cols_equal) return 0;

	// I could also check if one row/column is a multiple of another row/column
	// but I will leave this. In this case the determinante would also be 0.

	// -------------------------------------------------------------------------

	// All checks failed. So we do have to calculate the determinante...
	return calculate_determinante(m_values, m_rows);
}

template<typename T>
matrix<T> matrix<T>::invert()
{
	return matrix<T>();
}

template<typename T>
matrix<T>& matrix<T>::insert(std::vector<T>& values)
{
	if (values.size() == this->size())
	{
		for (size_t i = 0; i < m_rows; i++)
		{
			for (size_t j = 0; j < m_columns; j++)
			{
				this->m_values[i][j] = values[i * j];
			}
		}
	}
	return *this;
}

template<typename T>
bool matrix<T>::is_row_null(int row_index)
{
	if (row_index >= m_rows) return false;

	for (size_t i = 0; i < m_columns; ++i)
	{
		if (m_values[row_index][i] != 0) return false;
	}
	return true;
}

template<typename T>
bool matrix<T>::is_column_null(int col_index)
{
	if (col_index >= m_columns) return false;

	for (size_t i = 0; i < m_rows; ++i)
	{
		if (m_values[i][col_index] != 0) return false;
	}
	return true;
}

template<typename T>
bool matrix<T>::are_rows_equal(int row1, int row2)
{
	if (row1 >= m_rows || row2 >= m_rows) return false;

	for (size_t i = 0; i < m_columns; ++i)
	{
		if (m_values[row1][i] != m_values[row2][i]) return false;
	}
	return true;
}

template<typename T>
bool matrix<T>::are_columns_equal(int col1, int col2)
{
	if (col1 >= m_columns || col2 >= m_columns) return false;

	for (size_t i = 0; i < m_rows; ++i)
	{
		if (m_values[i][col1] != m_values[i][col2]) return false;
	}
	return true;
}

template<typename T>
T matrix<T>::calculate_determinante(std::vector<std::vector<T>> mat, int n)
{
	if (n == 1) return mat[0][0];

	T determinante = 0;
	std::vector<std::vector<T>> cofactor_storage;
	int sign = 1;

	for (size_t i = 0; i < n; ++i)
	{
		cofactor_storage = get_cofactor(mat, 0, i, n);
		determinante += sign * mat[0][i] * calculate_determinante(cofactor_storage, n - 1);
		sign *= -1;
	}
	return determinante;
}

template<typename T>
std::vector<std::vector<T>> matrix<T>::get_cofactor(std::vector<std::vector<T>> mat, int cf_row, int cf_col, int n)
{
	auto i = 0;
	auto j = 0;

	std::vector<std::vector<T>> result;

	for (size_t row = 0; row < n; ++row)
	{
		for (size_t col = 0; col < n; ++col)
		{
			if (row != cf_row && col != cf_col)
			{
				result[i][j++] = mat[row][col];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}

	return result;
}

#endif