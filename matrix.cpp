#include "matrix.h"

//initialize
void Matrix::zeros() const {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {entries[i][j] = 0.0;}
	}
}
void Matrix::random() const {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {entries[i][j] = 1 + rand() % 10;}
	}
}
void Matrix::print(string name) {
	cout << "Matrix " << name << ":" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << entries[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}
// set|get entries
void Matrix::setEntry(const int& r, const int& c,
	const double& val) {entries[r][c] = val;}

double Matrix::getEntry(const int& r, const int& c) const {
	return entries[r][c];
}
////////////operator //////////////
Matrix& Matrix::operator = (const Matrix& mat) {
	assert(row == mat.getRow() && col == mat.getCol());
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = mat(i, j);
		}
	}
	return *this;
}
Matrix Matrix::operator - (const Matrix& mat) {
	assert(row == mat.getRow() && col == mat.getCol());
	Matrix mat2(row, col); mat2.zeros();
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat2(i, j) = entries[i][j] - mat(i, j);
		}
	}
	return mat2;
}
Matrix Matrix::operator + (const Matrix& mat) {
	assert(row == mat.getRow() && col == mat.getCol());
	Matrix mat2(row,col);
	mat2.zeros();
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat2(i, j) = entries[i][j] + mat(i,j);
		}
	}
	return mat2;
}
Matrix Matrix::operator * (const Matrix& mat) {
	assert(col == mat.getRow());
	int newRow = row;
	int newCol = mat.getCol();
	Matrix mat2(newRow, newCol); mat2.zeros();
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < newCol; ++j) {
			for (int k = 0; k < col;++k) {
				mat2(i, j) += entries[i][k] * mat(k, j);
			}
		}
	}
	return mat2;
}
Matrix Matrix::operator * (const double& val) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = entries[i][j] * val;
		}
	}
	return *this;
}


