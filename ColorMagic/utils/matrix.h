/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once
#include <vector>
#include <stdexcept>

template <typename T> class matrix
{
public:
	//! Default constructor.
	/*!
	* Sets the matrix size (row and column count) to 0.
	*/
	matrix() : m_rows(0), m_columns(0), m_values(std::vector<std::vector<T>>())
	{
	}

	//! Default constructor for rectangular matrices.
	/*!
	* \param rows The number of rows.
	* \param columns The number of columns.
	*/
	matrix(int rows, int columns) : m_rows(rows), m_columns(columns)
	{
		m_values.resize(m_rows);
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(m_columns);
		}
	}

	//! Default constructor for rectangular matrices.
	/*!
	* \param rows The number of rows.
	* \param columns The number of columns.
	* \param data The data to fill this matrix with.
	*/
	matrix(int rows, int columns, std::vector<T> data) : m_rows(rows), m_columns(columns)
	{
		m_values.resize(m_rows);
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(m_columns);
		}
		insert(data);
	}

	//! Default constructor for rectangular matrices.
	/*!
	* \param rows The number of rows.
	* \param columns The number of columns.
	* \param initial_value The default value to fill the matrix with.
	*/
	matrix(int rows, int columns, T initial_value) : m_rows(rows), m_columns(columns)
	{
		m_values.resize(m_rows);
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(m_columns, initial_value);
		}
	}

	//! Default constructor for square matrices.
	/*!
	* \param size The number of rows and columns.
	*/
	matrix(int size) : m_rows(size), m_columns(size)
	{
		m_values.resize(size);
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(size);
		}
	}

	//! Default constructor for square matrices.
	/*!
	* \param size The number of rows and columns.
	* \param data The data to fill this matrix with.
	*/
	matrix(int size, std::vector<T> data) : m_rows(size), m_columns(size)
	{
		m_values.resize(size);
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(size);
		}
		insert(data);
	}

	//! Default copy constructor.
	/*!
	* \param other The matrix to copy.
	*/
	matrix(const matrix<T>& other)
	{
		m_rows = other.rows();
		m_columns = other.columns();
		m_values = other.values();
	}

	//! Default destructor.
	~matrix()
	{
	}

	//! Accessment operator
	T& operator() (int row, int column)
	{
		if (row >= m_rows) throw std::out_of_range(std::string("Matrix: %d is >= row count of matrix.", row));
		if (column >= m_columns) throw std::out_of_range(std::string("Matrix: %d is >= column count of matrix.", column));
		return m_values[row][column];
	}

	//! Accessment operator
	const T& operator() (int row, int column) const
	{
		if (row >= m_rows) throw std::out_of_range(std::string("Matrix: %d is >= row count of matrix.", row));
		if (column >= m_columns) throw std::out_of_range(std::string("Matrix: %d is >= column count of matrix.", column));
		return m_values[row][column];
	}

	//! Assignment operator
	matrix<T>& operator= (const matrix<T>& other)
	{
		if (this == &other) return *this;

		int new_rows = other.rows();
		int new_cols = other.columns();

		m_values.resize(new_rows);
		for (int i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(new_cols);
		}

		for (int i = 0; i < new_rows; i++)
		{
			for (int j = 0; j < new_cols; j++)
			{
				m_values[i][j] = other(i, j);
			}
		}
		m_rows = new_rows;
		m_columns = new_cols;

		return *this;
	}

	//! Equality operator
	bool operator==(const matrix<T>& other)
	{
		return m_rows == other.rows() && m_columns == other.columns() && m_values == other.values();
	}

	//! Equality operator
	bool operator==(const matrix<T>& other) const
	{
		return m_rows == other.rows() && m_columns == other.columns() && m_values == other.values();
	}

	//! Add two matrices
	matrix<T> operator+(const matrix<T>& other)
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[i][j] + other(i, j);
			}
		}

		return result;
	}

	//! Add a matrix to this one
	matrix<T>& operator+=(const matrix<T>& other)
	{
		matrix result = (*this) + other;
		(*this) = result;
		return *this;
	}

	//! Subtract two matrices
	matrix<T> operator-(const matrix<T>& other)
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[i][j] - other(i, j);
			}
		}

		return result;
	}

	//! Subtract a matrix from this one
	matrix<T>& operator-=(const matrix<T>& other)
	{
		matrix result = (*this) - other;
		(*this) = result;
		return *this;
	}

	//! Multiply two matrices
	matrix<T> operator*(const matrix<T>& other)
	{
		int rows = other.rows();
		int cols = other.columns();
		matrix result(rows, cols);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				for (int k = 0; k < rows; k++)
				{
					result(i, j) += this->m_values[i][k] * other(k, j);
				}
			}
		}

		return result;
	}

	//! Multiply a matrix with this one
	matrix<T>& operator*=(const matrix<T>& other)
	{
		matrix result = (*this) * other;
		(*this) = result;
		return *this;
	}

	//! Add T to each element of this matrix
	matrix<T> operator+(const T& other)
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[i][j] + other;
			}
		}

		return result;
	}

	//! Subtract T from each element of this matrix
	matrix<T> operator-(const T& other)
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[i][j] - other;
			}
		}

		return result;
	}

	//! Multiply T with each element of this matrix
	matrix<T> operator*(const T& other)
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[i][j] * other;
			}
		}

		return result;
	}

	//! Divide each element of this matrix through T
	matrix<T> operator/(const T& other)
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[i][j] / other;
			}
		}

		return result;
	}

	//! Multiply this matrix with a vector.
	/*!
	* Multiply this matrix with a vector.
	* /param other The vector to multiply this matrix with.
	*/
	std::vector<T> operator*(const std::vector<T>& other)
	{
		std::vector<T> result(other.size());

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result[i] += this->m_values[i][j] * other[j];
			}
		}

		return result;
	}

	//! Create a identity matrix of the given size.
	/*!
	* Create a identity matrix of the given size.
	*/
	static matrix<T> create_idendity(int rows)
	{
		matrix id(rows, rows, 0);
		for (int i = 0; i < id.rows(); ++i)
		{
			id(i, i) = 1;
		}
		return id;
	}

	//! Transpose this matrix.
	/*!
	* Transpose this matrix. Swaps rows and columns.
	*/
	matrix<T> transpose()
	{
		matrix result(m_rows, m_columns);

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				result(i, j) = this->m_values[j][i];
			}
		}

		return result;
	}

	//! Calculate the determinante of this matrix.
	/*!
	* Calculate the determinante of this matrix.
	*/
	T determinante()
	{
		// First check special cases to shorten calculation for this cases:
		// -------------------------------------------------------------------------

		// 1. Is the matrix quadratic (NxN)? If not calculating the determinante is impossible -> return 0.
		if (m_rows != m_columns) return 0;

		// 2. Do we have a 1x1 matrix (just one value)? -> Determinante = value
		if (m_rows == 1) return m_values[0][0];

		// 3. Is one of the rows filled with 0? -> Determinante = 0
		bool row_is_null = false;
		for (int row = 0; row < m_rows; ++row)
		{
			row_is_null = is_row_null(row);
			if (row_is_null) break;
		}
		if (row_is_null) return 0;

		// 4. Is one of the columns filled with 0? -> Determinante = 0
		bool col_is_null = false;
		for (int col = 0; col < m_rows; ++col)
		{
			col_is_null = is_column_null(col);
			if (col_is_null) break;
		}
		if (col_is_null) return 0;

		// 5. Are two rows equal? -> Determinante = 0
		bool rows_equal = false;
		for (int i = 0; i < m_rows; ++i)
		{
			if (rows_equal) break;
			for (int j = i + 1; j < m_rows; ++j)
			{
				rows_equal = are_rows_equal(i, j);
				if (rows_equal) break;
			}
		}
		if (rows_equal) return 0;

		// 6. Are two columns equal? -> Determinante = 0
		bool cols_equal = false;
		for (int i = 0; i < m_rows; ++i)
		{
			if (cols_equal) break;
			for (int j = i + 1; j < m_rows; ++j)
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

	//! Create adjoint of this matrix.
	/*!
	* Create adjoint of this matrix.
	*/
	matrix<T> adjoint()
	{
		if (m_rows != m_columns) return *this; // Cannot create adjoint of non quadratic matrices.

		matrix adj(m_rows, m_rows, 0);
		if (m_rows == 1)
		{
			// Return 1 if the matrix is one dimensional.
			adj(0, 0) = 1;
			return adj;
		}

		int sign = 1;
		std::vector<std::vector<T>> cofactor_storage;

		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_rows; ++j)
			{
				cofactor_storage = get_cofactor(m_values, i, j, m_rows);
				sign = ((i + j) % 2 == 0) ? 1 : -1;
				adj(j, i) = sign * calculate_determinante(cofactor_storage, m_rows - 1);
			}
		}

		return adj;
	}

	//! Invert this matrix.
	/*!
	* Invert this matrix.
	*/
	matrix<T> invert()
	{
		auto det = determinante();

		if (det == 0) return *this;

		matrix adj = adjoint();
		matrix inverse(m_rows, m_rows);
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_rows; ++j)
			{
				inverse(i, j) = adj(i, j) / ((float)det);
			}
		}

		return inverse;
	}

	//! Change all entries of this matrix to the given value.
	/*!
	* Change all entries of this matrix to the given value.
	* /param value The value to fill this matrix with.
	* /return This modified matrix.
	*/
	matrix<T>& fill(T value)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_columns; j++)
			{
				m_values[i][j] = value;
			}
		}
		return *this;
	}

	//! Insert a vector of values into this matrix.
	/*!
	* Insert a vector of values into this matrix. The
	* vector needs to have the same size as this matrix.
	* Otherwise no change to this matrix is done.
	* /param values A vector containing the values to insert.
	* /return This modified matrix.
	*/
	matrix<T>& insert(std::vector<T>& values)
	{
		if (values.size() == this->size())
		{
			for (int i = 0; i < m_rows; i++)
			{
				for (int j = 0; j < m_columns; j++)
				{
					this->m_values[i][j] = values[i * m_rows + j];
				}
			}
		}
		return *this;
	}

	//! Resize this matrix.
	/*!
	* Resize this matrix.
	* /param new_row_count The new number of rows.
	* /param new_col_count The new number of columns.
	* /param fill_value If the matrix size increases this value will be set for the new entries.
	* /return This modified matrix.
	*/
	matrix<T>& resize(int new_row_count, int new_col_count, T fill_value = 0)
	{
		// resize the matrix.
		m_values.resize(new_row_count);
		for (int i = 0; i < new_row_count; ++i)
		{
			m_values[i].resize(new_col_count);
		}

		// fill new entries with fill_value
		for (int row = 0; row < new_row_count; ++row)
		{
			for (int col = 0; col < new_col_count; ++col)
			{
				if (row >= m_rows || col >= m_columns)
				{
					m_values[row][col] = fill_value;
				}
			}
		}

		// update m_rows and m_columns
		m_rows = new_row_count;
		m_columns = new_col_count;

		return *this;
	}

	//! Check if all values in the given row are 0.
	bool is_row_null(int row_index)
	{
		if (row_index >= m_rows) return false;

		for (int i = 0; i < m_columns; ++i)
		{
			if (m_values[row_index][i] != 0) return false;
		}
		return true;
	}

	//! Check if all values in the given column are 0.
	bool is_column_null(int col_index)
	{
		if (col_index >= m_columns) return false;

		for (int i = 0; i < m_rows; ++i)
		{
			if (m_values[i][col_index] != 0) return false;
		}
		return true;
	}

	//! Check if all values of both rows are equal.
	bool are_rows_equal(int row1, int row2)
	{
		if (row1 >= m_rows || row2 >= m_rows) return false;

		for (int i = 0; i < m_columns; ++i)
		{
			if (m_values[row1][i] != m_values[row2][i]) return false;
		}
		return true;
	}

	//! Check if all values of both columns are equal.
	bool are_columns_equal(int col1, int col2)
	{
		if (col1 >= m_columns || col2 >= m_columns) return false;

		for (int i = 0; i < m_rows; ++i)
		{
			if (m_values[i][col1] != m_values[i][col2]) return false;
		}
		return true;
	}

	//! Return the number of rows this matrix has.
	int rows() const { return m_rows; }
	//! Return the number of columns this matrix has.
	int columns() const { return m_columns; }
	//! Return the number of elements this matrix has.
	int size() const { return m_rows * m_columns; }
	//! Return the values of this matrix as a two dimensional vector.
	std::vector<std::vector<T>> values() const { return m_values; }

private:
	//! Calculate the determinante of this matrix.
	/*!
	* Calculate the determinante of this matrix.
	*/
	T calculate_determinante(std::vector<std::vector<T>> mat, int n)
	{
		if (n == 1) return mat[0][0];

		T determinante = 0;
		std::vector<std::vector<T>> cofactor_storage;
		int sign = 1;

		for (int i = 0; i < n; ++i)
		{
			cofactor_storage = get_cofactor(mat, 0, i, n);
			determinante += sign * mat[0][i] * calculate_determinante(cofactor_storage, n - 1);
			sign *= -1;
		}
		return determinante;
	}

	//! Calculate a cofactor matrix.
	/*!
	* Calculate a cofactor matrix.
	*/
	std::vector<std::vector<T>> get_cofactor(std::vector<std::vector<T>> mat, int cf_row, int cf_col, int n)
	{
		auto i = 0;
		auto j = 0;

		std::vector<std::vector<T>> result;
		result.resize(mat.size());
		for (int i = 0; i < result.size(); ++i)
		{
			result[i].resize(mat[i].size());
		}

		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < n; ++col)
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

	int m_rows;
	int m_columns;
	std::vector<std::vector<T>> m_values;
};
