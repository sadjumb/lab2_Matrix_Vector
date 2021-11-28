#include <stdio.h>
//#include "Matrix.h"
#include "TMatrix.h"
#include "TVector.h"

int main()
{
	TMatrix<int>* arr = new TMatrix<int>(3);
	(*arr)[1][1] = 5;
	std::cout << arr[0];
	return 0;
}
