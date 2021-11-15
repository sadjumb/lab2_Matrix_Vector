#include <stdio.h>
//#include "Matrix.h"
#include "Matrix.h"
#include "Vector.h"

int main()
{
	Vector<int> vec(5);
	vec = vec + 5;
	std::cout << vec << std::endl;
	vec = vec * 5;
	std::cout << vec << std::endl;
	Matrix<int> m1(5);
	Matrix<int> m2(5);
	m1[0] = vec;
	m2 = m2 - m1;
	std::cout << m1 << std::endl;
	std::cout << m2;
	
	return 0;
}
