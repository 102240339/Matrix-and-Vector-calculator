#include "matrix.h"
#include "vector.h"

//initialize
void Matrix::zeros() const {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = 0.0;
		}
	}
}

void Matrix::ones() const {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = 1.0;
		}
	}
}

void Matrix::eye() const {
	assert(row == col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = 0.0;
		}
	}
	for (int i = 0; i < row; ++i) {
		entries[i][i] = 1.0;
	}

}

//////////////////
void Matrix::random() const {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = 1 + rand() % 10;
		}
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
	const double& val) {
	entries[r][c] = val;
}

double Matrix::getEntry(const int& r, const int& c) const {
	return entries[r][c];
}
	
////////////operator //////////////

// =, -
Matrix& Matrix::operator = (const Matrix& mat) {
	assert(row == mat.getRow() && col == mat.getCol());
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = mat(i, j);
		}
	}
	return *this;
}
Matrix& Matrix::operator - () {
	Matrix mat(row,col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat(i, j) = -entries[i][j];
		}
	}
	return mat;
}

Matrix& Matrix::operator ++() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] = entries[i][j] + 1;
		}
	}
	return *this;
}

// *=, +=
Matrix& Matrix::operator += (const Matrix& mat) {
	assert(row == mat.getRow() && col == mat.getCol());
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] += mat(i, j);
		}
	}
	return *this;
}
Matrix& Matrix::operator += (const double& val) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			entries[i][j] += val;
		}
	}
	return *this;
}
Matrix& Matrix::operator *= (const Matrix& mat) {
	assert(col == mat.getRow());
	double temp = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			for (int k = 0; k < col;++k) {
				temp += entries[i][k] * mat(k, j);
			}
			this -> entries[i][j] = temp;
		}
	}
	return *this;
}

// +, -, *
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

Vector Matrix::operator * (const Vector& v) {
	assert(getCol() == v.getSize());

	Vector result(getRow());
	result.zeros();

	for (int i = 0; i < getRow(); ++i) {
		double sum = 0.0;
		for (int j = 0; j < getCol(); ++j) {
			sum += (*this)(i, j) * v(j);
		}
		result(i) = sum;
	}
	return result;
}

