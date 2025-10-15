#include <iostream>
#include "Vector.h"

using namespace Yip;

int main()
{
	Math::Vector3<float> vec(0, 1, 0);
	std::cout << "Hello " << vec.ToString() << std::endl;
}