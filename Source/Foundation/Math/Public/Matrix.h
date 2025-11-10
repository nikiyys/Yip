#pragma once

#include "Foundation.h"
#include "Vector.h"
#include "Vector4.h"
#include <cassert>
#include <string>
#include <format>

namespace Yip {
namespace Math {

#pragma region Matrix4x4

template<typename Scalar>
class FOUNDATION_API TMatrix4x4
{
public:
	using Type = TMatrix4x4<Scalar>;
	static constexpr uint32_t Row = 4;
	static constexpr uint32_t Col = 4;

	inline TMatrix4x4() = default;
	inline TMatrix4x4(const Type&) = default;
	inline Type& operator=(const Type&) = default;

	//! \ctor
	template<typename OtherScalar>
	inline TMatrix4x4(const TMatrix4x4<OtherScalar>& other)
	{
		m00 = Scalar(other.m00); m01 = Scalar(other.m01); m02 = Scalar(other.m02); m03 = Scalar(other.m03);
		m10 = Scalar(other.m10); m11 = Scalar(other.m11); m12 = Scalar(other.m12); m13 = Scalar(other.m13);
		m20 = Scalar(other.m20); m21 = Scalar(other.m21); m12 = Scalar(other.m22); m23 = Scalar(other.m23);
		m30 = Scalar(other.m30); m31 = Scalar(other.m31); m22 = Scalar(other.m32); m33 = Scalar(other.m33);
	}

	//! \ctor
	inline TMatrix4x4(const TVector4<Scalar>& row0, const TVector4<Scalar>& row1, const TVector4<Scalar>& row2, const TVector4<Scalar>& row3)
	{
		m00 = row0.x; m01 = row0.y; m02 = row0.z; m03 = row0.w;
		m10 = row1.x; m11 = row1.y; m12 = row1.z; m13 = row1.w;
		m20 = row2.x; m21 = row2.y; m22 = row2.z; m23 = row2.w;
		m30 = row3.x; m31 = row3.y; m32 = row3.z; m33 = row3.w;
	}

	//!\ operator()(row, col)
	inline Scalar& operator()(uint32_t row, uint32_t col)
	{
		assert(row < Row && col < Col);
		return __array().m[row][col];
	}

	inline const Scalar& operator()(uint32_t row, uint32_t col) const
	{
		assert(row < Row && col < Col);
		return __array().m[row][col];
	}

	//! \brief x axis
	inline const TVector3<Scalar>& GetXAxis() const
	{
		return *(const TVector3<Scalar>*)(&__array().m[0][0]);
	}

	//! \brief y axis
	inline const TVector3<Scalar>& GetYAxis() const
	{
		return *(const TVector3<Scalar>*)(&__array().m[1][0]);
	}

	//! \brief z axis
	inline const TVector3<Scalar>& GetZAxis() const
	{
		return *(const TVector3<Scalar>*)(&__array().m[2][0]);
	}

	//! \brief ToString
	inline std::string ToString() const
	{
		return std::format("Matrix4x4([{}, {}, {}, {}], [{}, {}, {}, {}], [{}, {}, {}, {}], [{}, {}, {}, {}])",
			m00, m01, m02, m03,
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33);
	}

private:
	struct as_array
	{
		Scalar m[Row][Col];
	};
	inline as_array& __array()
	{
		return *(as_array*)this;
	}
	inline const as_array& __array() const
	{
		return *(const as_array*)this;
	}

public:
	Scalar m00, m01, m02, m03;
	Scalar m10, m11, m12, m13;
	Scalar m20, m21, m22, m23;
	Scalar m30, m31, m32, m33;
};

#pragma endregion Matrix4x4

}
}
