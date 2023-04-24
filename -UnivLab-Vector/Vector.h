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

	Vector(const Vector& other) : dim(other.dim) {
		this->array = new T[this->dim];
		for (size_t i = 0; i < this->dim; i++) {
			this->array[i] = other.array[i];
		}
	}

	~Vector() {
		delete[] this->array;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& vector) {
		for (size_t i = 0; i < vector.dim; i++) {
			os << vector.array[i] << " ";
		}
		return os;
	}
};

