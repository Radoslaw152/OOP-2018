#include "Matrix.h"
#include <iostream>
Matrix::Matrix(unsigned int rows, unsigned int columns) : m_Rows(rows), m_Columns(columns)
{
	m_Matrix = new int*[m_Rows];
	for (int i = 0; i < m_Columns; ++i)
	{
		m_Matrix[i] = new int[m_Columns];
	}
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& rhs): m_Rows(rhs.m_Rows), m_Columns(rhs.m_Columns)
{
	m_Matrix = new int*[m_Rows];
	for (int i = 0; i < m_Columns; ++i)
	{
		m_Matrix[i] = new int[m_Columns];
	}
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Matrix[i][j] = rhs.m_Matrix[i][j];
		}
	}
}
Matrix& Matrix::operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < m_Columns; ++i)
		{
			delete[] m_Matrix[i];
		}
		delete[] m_Matrix;

		m_Rows = rhs.m_Rows;
		m_Columns = rhs.m_Columns;
		m_Matrix = new int*[m_Rows];
		for (int i = 0; i < m_Columns; ++i)
		{
			m_Matrix[i] = new int[m_Columns];
		}
		for (int i = 0; i < m_Rows; ++i)
		{
			for (int j = 0; j < m_Columns; ++j)
			{
				m_Matrix[i][j] = rhs.m_Matrix[i][j];
			}
		}
	}
	return *this;
}
Matrix::~Matrix()
{
	for (int i = 0; i < m_Columns; ++i)
	{
		delete[] m_Matrix[i];
	}
	delete[] m_Matrix;
}

void Matrix::Multiply(int lambda)
{
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Matrix[i][j] *= lambda;
		}
	}
}
Matrix Matrix::Multiply(const Matrix& rhs) const
{
	if (m_Columns != rhs.m_Rows)
	{
		std::cout << "ERROR!\n";
		return Matrix(1,1);
	}
	Matrix tempMatrix(m_Rows, rhs.m_Columns);
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < rhs.m_Columns; ++j)
		{
			for (int u = 0; u < m_Columns; ++u)
			{
				tempMatrix.m_Matrix[i][j] += m_Matrix[i][u] * rhs.m_Matrix[u][j];
			}
		}
	}
	return tempMatrix;
}
Matrix Matrix::Transpose() const
{
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Matrix[i][j] = m_Matrix[j][i];
		}
	}
}
int Matrix::GetElement(unsigned int i, unsigned int j) const
{
	if (i < m_Rows || j < m_Columns)
	{
		return 0;
	}
	return m_Matrix[i][j];
}

void Matrix::InputMatrix()
{
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			std::cin >> m_Matrix[i][j];
		}
	}
}
void Matrix:: PrintMatrix() const
{
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			std::cout << m_Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}