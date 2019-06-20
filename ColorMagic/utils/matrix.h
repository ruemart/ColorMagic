#ifndef __MATRIX_H
#define __MATRIX_H

#include <vector>

template <typename T> class matrix
{
public:
	//! Default constructor.
	/*!
	* Sets the matrix size (row and column count) to 0.
	*/
	matrix()
	{
		m_values.resize(0);
	}

	//! Default constructor for rectangular matrices.
	/*!
	* \param rows The number of rows.
	* \param columns The number of columns.
	*/
	matrix(size_t rows, size_t columns) : m_rows(rows), m_columns(columns)
	{
		m_values.resize(m_rows);
		for (size_t i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(m_columns);
		}
	}

	//! Default constructor for rectangular matrices.
	/*!
	* \param rows The number of rows.
	* \param columns The number of columns.
	* \param initial_value The default value to fill the matrix with.
	*/
	matrix(size_t rows, size_t columns, T initial_value) : m_rows(rows), m_columns(columns)
	{
		m_values.resize(m_rows);
		for (size_t i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(m_columns, initial_value);
		}
	}

	//! Default constructor for quadatic matrices.
	/*!
	* \param size The number of rows and columns.
	*/
	matrix(size_t size) : m_rows(size), m_columns(size)
	{
		m_values.resize(size);
		for (size_t i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(size);
		}
	}

	//! Default constructor for quadatic matrices.
	/*!
	* \param size The number of rows and columns.
	* \param initial_value The default value to fill the matrix with.
	*/
	matrix(size_t size, T initial_value) : m_rows(size), m_columns(size)
	{
		m_values.resize(size);
		for (size_t i = 0; i < m_values.size(); i++)
		{
			m_values[i].resize(size, initial_value);
		}
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
	T& operator() (size_t row, size_t column) { return m_values[row][column]; }
	//! Accessment operator
	const T& operator() (size_t row, size_t column) const { return m_values[row][column]; }

	//! Assignment operator
	matrix<T>& operator= (const matrix<T>& other);

	//! Add two matrices
	matrix<T> operator+(const matrix<T>& other);
	//! Add a matrix to this one
	matrix<T>& operator+=(const matrix<T>& other);
	//! Subtract two matrices
	matrix<T> operator-(const matrix<T>& other);
	//! Subtract a matrix from this one
	matrix<T>& operator-=(const matrix<T>& other);
	//! Multiply two matrices
	matrix<T> operator*(const matrix<T>& other);
	//! Multiply a matrix with this one
	matrix<T>& operator*=(const matrix<T>& other);

	//! Add T to each element of this matrix
	matrix<T> operator+(const T& other);
	//! Subtract T from each element of this matrix
	matrix<T> operator-(const T& other);
	//! Multiply T with each element of this matrix
	matrix<T> operator*(const T& other);
	//! Divide each element of this matrix through T
	matrix<T> operator/(const T& other);
	
	//! Multiply this matrix with a vector.
	/*!
	* Multiply this matrix with a vector.
	* /param other The vector to multiply this matrix with.
	*/
	std::vector<T> operator*(const std::vector<T>& other);

	//! Transpose this matrix.
	/*!
	* Transpose this matrix. Swaps rows and columns.
	*/
	matrix<T> transpose();

	//! Calculate the determinante of this matrix.
	/*!
	* Calculate the determinante of this matrix.
	*/
	T determinante();

	//! Invert this matrix.
	/*!
	* Invert this matrix.
	*/
	matrix<T> invert();

	//! Insert a vector of values into this matrix.
	/*!
	* Insert a vector of values into this matrix. The 
	* vector needs to have the same size as this matrix.
	* Otherwise no change to this matrix is done.
	* /param values A vector containing the values to insert.
	*/
	matrix<T>& insert(std::vector<T>& values);

	//! Check if all values in the given row are 0.
	bool is_row_null(int row_index);

	//! Check if all values in the given column are 0.
	bool is_column_null(int col_index);

	//! Check if all values of both rows are equal.
	bool are_rows_equal(int row1, int row2);

	//! Check if all values of both columns are equal.
	bool are_columns_equal(int col1, int col2);

	//! Return the number of rows this matrix has.
	size_t rows() const { return m_rows; }
	//! Return the number of columns this matrix has.
	size_t columns() const { return m_columns; }
	//! Return the number of elements this matrix has.
	size_t size() const { return m_rows * m_columns; }
	//! Return the values of this matrix as a two dimensional vector.
	std::vector<std::vector<T>> values() const { return m_values; }
	
private:
	//! Calculate the determinante of this matrix.
	/*!
	* Calculate the determinante of this matrix.
	*/
	T calculate_determinante(std::vector<std::vector<T>> mat, int n);

	//! Calculate a cofactor matrix.
	/*!
	* Calculate a cofactor matrix.
	*/
	std::vector<std::vector<T>> get_cofactor(std::vector<std::vector<T>> mat, int cf_row, int cf_col, int n);

	size_t m_rows;
	size_t m_columns;
	std::vector<std::vector<T>> m_values;
};

#include "matrix.cpp"

#endif