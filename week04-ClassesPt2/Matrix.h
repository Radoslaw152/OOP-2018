#pragma once

class Matrix
{
private:
	int m_Rows;
	int m_Columns;
	int** m_Matrix;
public:
	Matrix(unsigned int,unsigned int);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	~Matrix();
	void InputMatrix();
	void PrintMatrix() const;
	void Multiply(int);
	Matrix Multiply(const Matrix&) const;
	Matrix Transpose() const;
	int GetElement(unsigned int, unsigned int) const;
};