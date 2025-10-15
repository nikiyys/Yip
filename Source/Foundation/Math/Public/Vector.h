#pragma once

#include <string>
#include <format>
#include "Foundation.h"

namespace Yip {
namespace Math {

template<typename Scalar>
class FOUNDATION_API Vector3
{
public:
	Vector3(Scalar x, Scalar y, Scalar z) : x(x), y(y), z(z) {}
	std::string ToString() const
	{
		return std::format("Vector3({}, {}, {})", x, y, z);
	}

private:
	Scalar x, y, z;
};


template class FOUNDATION_API Vector3<float>;
template class FOUNDATION_API Vector3<double>;

} // namespace Math
} // namespace Yip
