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

#endif