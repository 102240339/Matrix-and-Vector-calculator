#pragma once
#include <cassert>
#include <cstdlib>
#include <random>
#include <string>
#include <iostream>
#include <cmath>
#include "matrix.h"
using namespace std;
class Vector {
private:
	int size;
	double* entry;
public:
	//getSize - set/get entry
	int getSize() const {
		return size;
	}
	void setEntry(const int& s, const double& val);
	double getEntry(const int& s) const;
	//member - function
	void zeros() const;
	void random() const;
	void print(string name);
	//operator
	double& operator () (const int& s) {
		assert(s > -1 && s < size); return entry[s];
	}
	double operator () (const int& s) const {
		assert(s > -1 && s < size); return entry[s];
	}
	Vector& operator = (const Vector& vec);
	Vector operator + (const Vector& vec);
	Vector operator - (const Vector& vec);
	Vector operator * (const double& val);
	Vector operator * (const Vector& vec);
	//constructor and destructor
	Vector(const int& s) {
		size = s; entry = new double[size];
	}
	Vector(const int& s, const int& val) : Vector(s) {
		for (int i = 0; i < size; ++i) { entry[i] = val; }
	}
	~Vector() { delete[] entry; }
	Vector(const Vector& vec) {
		size = vec.getSize(); entry = new double[size];
		for (int i = 0; i < size; ++i) {
			entry[i] = vec(i);
		}
	}
	//non - member
	friend double dot(const Vector& v1, const Vector& v2) {
		assert(v1.getSize() == v2.getSize());
		double v = 0;
		for (int i = 0; i < v1.getSize(); ++i) {
			v += v1(i) * v2(i);
		}
		return v;
	}
};
