#pragma once
#include <iostream>

template<class T>
class Vector
{
public:
	Vector() : size(0), start(0), pArr(nullptr){}
	Vector(size_t _size, size_t _start = 0) : size(_size), start(_start), pArr(new T[size]{ T{} }) {}
	Vector(const Vector<T>& copy) : size(copy.size), start(copy.start), pArr(new T[size])
	{
		for(size_t i = 0; i < size; ++i)
		{
			pArr[i] = copy.pArr[i];
		}
	}
	~Vector()
	{
		delete[] pArr;
		pArr = nullptr;
	}

	T& operator[](size_t index) const
	{
		if (index - start < 0 || start < 0 || start < 0)
			throw std::out_of_range("start is negative");

		return pArr[index - start];
	}
	T& operator[](size_t index)
	{
		if (index - start < 0 || index - start > size - 1 || start < 0)
			throw std::out_of_range("start is negative");
		return pArr[index - start];
	}


	Vector<T>& operator=(const Vector<T>& r)
	{
		if (this == &r)
			return *this;
		size = r.size;
		start = r.start;
		delete[] pArr;
		pArr = new T[size]{ T{} };


		for (size_t i = 0; i < size; ++i)
		{
			pArr[i] = r.pArr[i];
		}
		return *this;
	}	
	Vector<T>& operator=(Vector<T>&& r)
	{
		if (this == &r)
			return *this;
		std::swap(size, r.size);
		std::swap(start, r.start);
		std::swap(pArr, r.pArr);
		
		return *this;
	}

	bool operator==(const Vector& v) const
	{
		if (this == &v)
			return true;
		if (size != v.size)
			return false;
		for (size_t i = 0; i < size; i++)
			if (pArr[i] != v.pArr[i])
				return false;
		return true;
	}
	bool operator!=(const Vector& v) const
	{
		return !(*this == v);
	}

	Vector operator+(const T& val)
	{
		Vector<T> tmp(*this);
		for (int i = 0; i < size; i++)
		{
			tmp.pArr[i] += val;
		}
		return tmp;
	}
	Vector operator-(const T& val)
	{
		Vector<T> tmp(*this);
		for (int i = 0; i < size; i++)
		{
			tmp.pArr[i] -= val;
		}
		return tmp;
	}
	Vector operator*(const T& val)
	{
		Vector<T> tmp(*this);
		for (int i = 0; i < size; i++)
		{
			tmp.pArr[i] *= val;
		}
		return tmp;
	}
	
	Vector operator+(const Vector& v)
	{
		if (size != v.size || start != v.start)
			throw "no equal size";
		Vector<T> tmp(*this);
		for (int i = 0; i < size; i++)
		{
			tmp.pArr[i] += v.pArr[i];
		}
		return tmp;
	}
	Vector operator-(const Vector& v)
	{
		if (size != v.size || start != v.start)
			throw "no equal size";
		Vector<T> tmp(*this);
		for (int i = 0; i < size; i++)
		{
			tmp.pArr[i] -= v.pArr[i];
		}
		return tmp;
	}
	T operator*(const Vector& v)
	{
		if (size != v.size || start != v.start)
			throw "no equal size";
		T res = 0;
		for (int i = 0; i < size; i++)
		{
			res += pArr[i] * v.pArr[i];
		}
		return res;
	}


	
private:
	size_t size;
	size_t start;
	T* pArr;
private:
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& r)
	{
		for (size_t i = 0; i < r.size; ++i)
		{
			out << r.pArr[i] << " ";
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const Vector<T>& r)
	{
		for (size_t i = 0; i < r.size; ++i)
		{
			in >> r[i];
		}
		return in;
	}
};



