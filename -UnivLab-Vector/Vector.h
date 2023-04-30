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
		if (this->array == nullptr) {
			throw std::bad_alloc();
		}
	}

	Vector(T* other, size_t vector_dim) : Vector(vector_dim) {
		for (size_t i = 0; i < this->dim; i++) {
			this->array[i] = other[i];
		}
	}


	Vector(const Vector<T>& other) : dim(other.dim) {
		this->array = new T[this->dim];
		if (this->array == nullptr) {
			throw std::bad_alloc();
		}

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

	bool operator== (const Vector<T>& other) {
		if (this->dim != other.dim) return false;

		for (size_t i = 0; i < this->dim; i++) {
			if ((*this)[i] != other[i]) return false;
		}

		return true;
	}

	bool operator!= (const Vector<T>& other) {
		return !((*this) == other);
	}

	Vector& operator+= (const Vector<T>& other) {
		if (this->dim != other.dim) {
			throw std::range_error("Vectors sizes not equal");
		}

		for (size_t i = 0; i < this->dim; i++) {
			(*this)[i] += other[i];
		}

		return *this;
	}

	Vector& operator+= (T num) {
		for (size_t i = 0; i < this->dim; i++) {
			(*this)[i] += num;
		}

		return *this;
	}

	Vector& operator++ () {		/*++Vector*/
		(*this) += 1;
		return *this;
	}

	Vector operator++ (int) {		/*Vector++*/
		Vector temp = *this;
		++(*this);
		return temp;
	}


	Vector& operator-= (const Vector<T>& other) {
		if (this->dim != other.dim) {
			throw std::range_error("Vectors sizes not equal");
		}

		for (size_t i = 0; i < this->dim; i++) {
			(*this)[i] -= other[i];
		}

		return *this;
	}

	Vector& operator-= (T num) {
		for (size_t i = 0; i < this->dim; i++) {
			(*this)[i] -= num;
		}

		return *this;
	}

	Vector& operator-- () {		/*++Vector*/
		(*this) -= 1;
		return *this;
	}

	Vector operator-- (int) {		/*Vector++*/
		Vector temp = *this;
		--(*this);
		return temp;
	}
 
	void push_back(T elem) {
		T* resized_array = new T[this->dim + 1];
		if (resized_array == nullptr) {
			throw std::bad_alloc();
		}

		memcpy(resized_array, this->array, this->dim * sizeof(T));
		resized_array[this->dim] = elem;
		delete[] this->array;
		this->array = resized_array;
		this->dim++;
	}

	void push_front(T elem) {
		T* resized_array = new T[this->dim + 1];
		if (resized_array == nullptr) {
			throw std::bad_alloc();
		}

		resized_array[0] = elem;
		memcpy(resized_array+1, this->array, this->dim * sizeof(T));
		delete[] this->array;
		this->array = resized_array;
		this->dim++;
	}
};
