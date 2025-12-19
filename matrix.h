#pragma once
#include <cassert>
#include <cstdlib>
#include <random>
#include <string>
#include <iostream>
using namespace std;

class Vector;

class Matrix {
private:
	int row;
	int col;
	double** entries;
public:

	//constructor and destructor
	Matrix(const int& r, const int& c) {
		row = r;
		col = c;
		entries = new double* [row];
		for (int i = 0; i < row; ++i) {
			entries[i] = new double[col];
		}
	}
	Matrix(const int& r, const int& c,
		const double& val) : Matrix(r, c) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				entries[i][j] = val;
			}
		}
	}
	
	~Matrix() {
		for (int i = 0; i < row; ++i) {
			delete[] entries[i];
		}
		delete[] entries;
	}

	//getRow, getcol
	int getRow() const {
		return row;
	}
	int getCol() const {
		return col;
	}

	// set/get entry
	void setEntry(const int& r, const int& c,
		const double& val);
	double getEntry(const int& r, const int& c) const;

	// some other member methods
	//initialize
	void zeros() const;
	void ones() const;
	void eye() const;

	///////////////////////////////////////
	void random() const;
	void print(string name);

	//operator

	// ()
	double& operator () (const int& i, const int& j)
	{
		assert(i > -1 && i < row);
		assert(j > -1 && j < col);
		return entries[i][j];
	}
	double operator () (const int& i, const int& j) const
	{
		assert(i > -1 && i < row);
		assert(j > -1 && j < col);
		return entries[i][j];
	}

	//constructor
	Matrix(const Matrix& mat) {
		row = mat.getRow();
		col = mat.getCol();
		entries = new double* [row];
		for (int i = 0; i < row; ++i)
			entries[i] = new double[col];
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				entries[i][j] = mat(i, j);
			}
		}
	}

	// assignment
	
	// =, -, ++
	Matrix& operator = (const Matrix& mat);
	Matrix& operator - ();
	Matrix& operator ++();

	// *=, +=
	Matrix& operator += (const Matrix& mat);
	Matrix& operator += (const double& val);
	Matrix& operator *= (const Matrix& mat);

	// +, -, *
	Matrix operator + (const Matrix& mat);
	Matrix operator - (const Matrix& mat);
	Matrix operator * (const Matrix& mat);
	Matrix operator * (const double& val);
	Vector operator*(const Vector& v);
	

	//non - member
	friend Matrix transpose(const Matrix& A) {
		int new_rows = A.col;
		int new_cols = A.row;
		Matrix B(new_rows, new_cols);
		for (int i = 0; i < A.row; ++i) {
			for (int j = 0; j < A.col; ++j) {
				B.entries[j][i] = A.entries[i][j];
			}
		}
		return B;
	}

};