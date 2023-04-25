#pragma once

#include <iostream>

template <typename T>

class Vector {
private:
	T* array = nullptr;
	size_t dim;

public:
	Vector(size_t vector_dim) : dim(vector_dim) {
		this->array = new T[dim];
	}

	Vector(T* other, size_t vector_dim) : Vector(vector_dim) {
		for (size_t i = 0; i < this->dim; i++) {
			this->array[i] = other[i];
		}
	}

	//Vector() : this-vector_dim(0) {}

	Vector(const Vector<T>& other) : dim(other.dim) {
		this->array = new T[this->dim];
		for (size_t i = 0; i < this->dim; i++) {
			this->array[i] = other.array[i];
		}
	}

	~Vector() {
		delete[] this->array;
	}


	T& operator[] (size_t index) const {
		return this->array[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
		for (size_t i = 0; i < vector.dim; i++) {
			os << vector[i] << " ";
		}
		return os;
	}

	Vector<T> operator+ (const Vector<T>& other) {
		Vector<T> res(other.dim);
		for (size_t i = 0; i < res.dim; i++) {
			res[i] = (*this)[i] + other[i];
		}

		return res;
	}

	Vector<T> operator+ (T term) {
		Vector<T> res(this->dim);
		for (size_t i = 0; i < res.dim; i++) {
			res[i] = (*this)[i] + term;
		}

		return res;
	}

	Vector<T> operator- (const Vector<T>& other) {
		Vector<T> res(other.dim);
		for (size_t i = 0; i < res.dim; i++) {
			res[i] = (*this)[i] - other[i];
		}

		return res;
	}

	Vector<T> operator- (T term) {
		Vector<T> res(this->dim);
		for (size_t i = 0; i < res.dim; i++) {
			res[i] = (*this)[i] - term;
		}

		return res;
	}

	Vector<T> operator* (T mult) {
		Vector<T> res(this->dim);
		for (size_t i = 0; i < res.dim; i++) {
			res[i] = (*this)[i] * mult;
		}

		return res;
	}

	T operator* (const Vector<T>& other) {
		T res = 0;
		for (size_t i = 0; i < this->dim; i++) {
			res += (*this)[i] * other[i];
		}

		return res;
	}
};
