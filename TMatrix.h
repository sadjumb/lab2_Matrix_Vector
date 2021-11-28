#pragma once
#include "TVector.h"

template <class T>
class TMatrix
{
public:
	TMatrix() : size(0), vec(0, 0) {}
	TMatrix(size_t _size)
	{
		size = _size;
		vec = (TVector<TVector<T>>{_size, 0});
		for (size_t i = 0; i < size; ++i)
		{
			vec[i] = (TVector<T>{size - i, 0});
		}
	}
	TMatrix(const TMatrix<T>& copy) : size(copy.size), vec(copy.vec) {}

	TMatrix<T>& operator=(const TMatrix<T>& r)
	{
		if (this == &r)
			return *this;
		size = r.size;
		vec = r.vec;
		return *this;
	}

	TMatrix operator+(const TMatrix& v)
	{
		if (size != v.size)
			throw "no equal size";
		TMatrix tmp(*this);
		for (size_t i = 0; i < size; ++i)
		{
			tmp.vec[i] = vec[i] + v.vec[i];
		}
		return tmp;
	}
	TMatrix operator-(const TMatrix& v)
	{
		if (size != v.size)
			throw "no equal size";
		TMatrix tmp(*this);
		for (size_t i = 0; i < size; ++i)
		{
			tmp.vec[i] = vec[i] - v.vec[i];
		}
		return tmp;
	}

	TMatrix operator*(const TMatrix& v)
	{
		if (size != v.size)
			throw "no equal size";
		TMatrix tmp(size);
		for (size_t i = 0; i < size; ++i)
			for (size_t j = 0; j < vec[i].get_size(); ++j)
				for (size_t k = 0; k < size - j && k < vec[i].get_size(); ++k)
					tmp.vec[i][j] += vec[i][k] * v.vec[k][j];
		return tmp;
	}


	TVector<T>& operator[](int index)
	{
		if (index < 0 || index > size - 1)
			throw std::out_of_range("start is negative");
		return vec[index];
	}
	size_t get_size() const
	{
		return size;
	}

private:
	size_t size;
	TVector<TVector<T>> vec;

private:
	friend std::ostream& operator<<(std::ostream& out, const TMatrix<T>& r)
	{
		for (size_t i = 0; i < r.size; ++i)
		{
			out << r.vec[i] << std::endl;
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const TMatrix<T>& r)
	{
		for (size_t i = 0; i < r.size; ++i)
		{
			in >> r.vec[i];
		}
		return in;
	}

};

