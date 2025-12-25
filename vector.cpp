# include "vector.h"
//initialize
void Vector::zeros() const {
	for (int i = 0; i < size; ++i) {entry[i] = 0.0;}
}
void Vector::ones() const {
	for (int i = 0; i < size; ++i) {entry[i] = 1.0;}
}
void Vector::random() const {
	for (int i = 0; i < size; ++i) {
		entry[i] = 1 + rand() % 10;
	}
}
void Vector::print(string name) {
	cout << "Vector " << name << ": ";
	for (int i = 0; i < size; ++i) {
		cout << entry[i] << ", ";
	}
	cout << endl;
}
double Vector::norm(const int& p) {
	double temp = 0;
	for (int i = 0; i < size; ++i) {
		temp += pow(entry[i], p);
	}
	return pow(temp, 1.0 / p);
}

void Vector::setEntry(const int& s, const double& val) {
	entry[s] = val;
}
double Vector::getEntry(const int& s) const {
	return entry[s];
}
////////////operator //////////////
Vector& Vector::operator = (const Vector& vec) {
	assert(size == vec.getSize());
	for (int i = 0; i < size; ++i) {
		entry[i] = vec(i);
	}
	return *this;
}
Vector Vector::operator + (const Vector& vec) {
	assert(size == vec.getSize());
	Vector vec2(size);
	vec2.zeros();
	for (int i = 0; i < size; ++i) {
		vec2(i) = entry[i] + vec(i);
	}
	return vec2;
}
Vector Vector::operator - (const Vector& vec) {
	assert(size == vec.getSize());
	Vector vec2(size); vec2.zeros();
	for (int i = 0; i < size; ++i) {
		vec2(i) = entry[i] - vec(i);
	}
	return vec2;
}
Vector Vector::operator * (const double& val) {
	Vector v(size);
	for (int i = 0; i < size; ++i) {
		v(i) = entry[i] * val;
	}
	return v;
}
Vector Vector::operator * (const Vector& vec) {
	assert(vec.getSize() == 3 && size == 3);
	Vector v(3);
	v(0) = entry[1] * vec(2) - entry[2] * vec(1);
	v(1) = entry[2] * vec(0) - entry[0] * vec(2);
	v(2) = entry[0] * vec(1) - entry[1] * vec(0);
	return v;
}
