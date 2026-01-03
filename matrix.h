#pragma once
#include <cassert>
#include <cstdlib>
#include <random>
#include <string>
#include <iostream>
using namespace std;

class Matrix {
private:
	int row;
	int col;
	double** entries;
public:
	//getRow, getcol / set
	int getRow() const {return row;}
	int getCol() const {return col;}
	void setEntry(const int& r, const int& c,
		const double& val);
	double getEntry(const int& r, const int& c) const;
	//member - function
	void zeros() const;
	void random() const;
	void print(string name);
	//operator
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
	Matrix& operator = (const Matrix& mat);
	Matrix& operator - ();
	Matrix operator + (const Matrix& mat);
	Matrix operator - (const Matrix& mat);
	Matrix operator * (const Matrix& mat);
	Matrix operator * (const double& val);
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
	//constructor
	Matrix(const Matrix& mat) {
		row = mat.getRow();
		col = mat.getCol();
		entries = new double* [row];
		for (int i = 0; i < row; ++i)
			entries[i] = new double[col];
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {entries[i][j] = mat(i, j);}
		}
	}
	Matrix(const int& r, const int& c) {
		row = r;
		col = c;
		entries = new double* [row];
		for (int i = 0; i < row; ++i) {entries[i] = new double[col];}
	}
	Matrix(const int& r, const int& c,
		const double& val) : Matrix(r, c) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {entries[i][j] = val;}
		}
	}
	~Matrix() {
		for (int i = 0; i < row; ++i) {
			delete[] entries[i];
		}
		delete[] entries;
	}
};
