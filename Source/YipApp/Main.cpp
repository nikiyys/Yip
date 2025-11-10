#include <iostream>
#include "MathCommon.h"

using namespace Yip::Math;

int main()
{
	Vector4 row0(1.0f, 0.0f, 0.0f, 0.0f);
	Vector4 row1(0, 1, 0, 0);
	Vector4 row2(0, 0, 1, 0);
	Vector4 row3(0, 0, 0, 1);
	Matrix4 mat(row0, row1, row2, row3);
	std::cout << "Hello " << mat.GetZAxis().ToString() << mat.ToString() << std::endl;
}