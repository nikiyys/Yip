#pragma once

#include "Foundation.h"
#include <string>
#include <format>

namespace Yip {
namespace Math {

#pragma region TVector4

template<typename Scalar>
class FOUNDATION_API TVector4
{
public:
	using Type = TVector4<Scalar>;

	inline TVector4() = default;
	inline TVector4(const Type& other) = default;
	inline Type& operator=(const Type& other) = default;

	//! \brief ctor
	inline TVector4(Scalar x, Scalar y, Scalar z, Scalar w)
		: x(x), y(y), z(z), w(w)
	{
	}

	inline bool operator==(const Type& other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}
	inline bool operator!=(const Type& other)
	{
		return !(*this == other);
	}
	
	inline Type operator+(const Type& other)
	{
		return Type(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	inline void operator+=(const Type& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
	}

	inline Type operator-(const Type& other)
	{
		return Type(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	inline void operator-=(const Type& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
	}

	template<typename ScaleScalar>
	inline Type operator*(const ScaleScalar& scale)
	{
		return Type(x * scale, y * scale, z * scale, w * scale);
	}

	template<typename ScaleScalar>
	inline void operator*=(const ScaleScalar& scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		w *= scale;
	}

	template<typename ScaleScalar>
	inline Type operator/(const ScaleScalar& scale)
	{
		return Type(x / scale, y / scale, z / scale, w / scale);
	}

	template<typename ScaleScalar>
	inline void operator/=(const ScaleScalar& scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		w /= scale;
	}

	std::string ToString() const
	{
		return std::format("Vector4({}, {}, {}, {})", x, y, z, w);
	}

public:
	Scalar x, y, z, w;
};


#pragma endregion TVector4

} // namespace Math
} // namespace Yip
