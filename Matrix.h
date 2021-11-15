#pragma once
#include "Vector.h"


template <class T>
class Matrix
{
public:
	Matrix() : size(0), vec(0, 0) {}
	Matrix(size_t _size)
	{
		size = _size;
		vec = std::move(Vector<Vector<T>>{_size, 0});
		for (size_t i = 0; i < size; ++i)
		{
			vec[i] = std::move(Vector<T>{size - i, 0});
		}
	}
	Matrix(const Matrix<T>& copy) : size(copy.size), vec(copy.vec){}
	
	Matrix<T>& operator=(const Matrix<T>& r)
	{
		if (this == &r)
			return *this;
		size = r.size;
		vec = r.vec;
		return *this;
	}

	Matrix operator+(const Matrix& v)
	{
		if (size != v.size)
			throw "no equal size";
		Matrix tmp(*this);
		for(size_t i = 0; i < size; ++i)
		{
			tmp.vec[i] = vec[i] + v.vec[i];
		}
		return tmp;
	}
	Matrix operator-(const Matrix& v)
	{
		if (size != v.size)
			throw "no equal size";
		Matrix tmp(*this);
		for (size_t i = 0; i < size; ++i)
		{
			tmp.vec[i] = vec[i] - v.vec[i];
		}
		return tmp;
	}

	//Matrix operator*(const Matrix& v)
	//{
	//	if (size != v.size)
	//		throw "no equal size";
	//	Matrix tmp(*this);
	//
	//	
	//}
	
	
	Vector<T>& operator[](int index)
	{
		if (index < 0 || index > size - 1)
			throw std::out_of_range("start is negative");
		return vec[index];
	}


private:
	size_t size;
	Vector<Vector<T>> vec;

private:
	friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& r)
	{
		for (size_t i = 0; i < r.size; ++i)
		{
			out << r.vec[i] << std::endl;
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const Matrix<T>& r)
	{
		for (size_t i = 0; i < r.size; ++i)
		{
			in >> r.vec[i];
		}
		return in;
	}

};

