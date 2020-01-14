#pragma once

#include <string>
#include "er/Types.h"

namespace er {

	struct vec4
	{
		int32 x, y, z, w;

		vec4();
		vec4(int32 scalar);
		vec4(int32 x, int32 y, int32 z, int32 w);

		vec4& Add(const vec4& other);
		vec4& Subtract(const vec4& other);
		vec4& Multiply(const vec4& other);
		vec4& Divide(const vec4& other);

		vec4& Add(int32 value);
		vec4& Subtract(int32 value);
		vec4& Multiply(int32 value);
		vec4& Divide(int32 value);

		friend vec4 operator+(vec4 left, const vec4& right);
		friend vec4 operator-(vec4 left, const vec4& right);
		friend vec4 operator*(vec4 left, const vec4& right);
		friend vec4 operator/(vec4 left, const vec4& right);

		friend vec4 operator+(vec4 left, int32 value);
		friend vec4 operator-(vec4 left, int32 value);
		friend vec4 operator*(vec4 left, int32 value);
		friend vec4 operator/(vec4 left, int32 value);

		bool operator==(const vec4& other) const;
		bool operator!=(const vec4& other) const;

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		vec4& operator+=(int32 value);
		vec4& operator-=(int32 value);
		vec4& operator*=(int32 value);
		vec4& operator/=(int32 value);

		bool operator<(const vec4& other) const;
		bool operator<=(const vec4& other) const;
		bool operator>(const vec4& other) const;
		bool operator>=(const vec4& other) const;

		int32 Distance(const vec4& other) const;

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
	};

}