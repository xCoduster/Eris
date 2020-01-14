#pragma once

#include <string>
#include "er/Types.h"

namespace er {

	struct vec3
	{
		int32 x, y, z;

		vec3();
		vec3(int32 scalar);
		vec3(int32 x, int32 y, int32 z);

		vec3& Add(const vec3& other);
		vec3& Subtract(const vec3& other);
		vec3& Multiply(const vec3& other);
		vec3& Divide(const vec3& other);

		vec3& Add(int32 value);
		vec3& Subtract(int32 value);
		vec3& Multiply(int32 value);
		vec3& Divide(int32 value);

		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		friend vec3 operator+(vec3 left, int32 value);
		friend vec3 operator-(vec3 left, int32 value);
		friend vec3 operator*(vec3 left, int32 value);
		friend vec3 operator/(vec3 left, int32 value);

		bool operator==(const vec3& other) const;
		bool operator!=(const vec3& other) const;

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		vec3& operator+=(int32 value);
		vec3& operator-=(int32 value);
		vec3& operator*=(int32 value);
		vec3& operator/=(int32 value);

		bool operator<(const vec3& other) const;
		bool operator<=(const vec3& other) const;
		bool operator>(const vec3& other) const;
		bool operator>=(const vec3& other) const;

		int32 Distance(const vec3& other) const;

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
	};

}