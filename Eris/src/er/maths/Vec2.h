#pragma once

#include <string>
#include "er/Types.h"

namespace er {

	struct vec2
	{
		int32 x, y;

		vec2();
		vec2(int32 scalar);
		vec2(int32 x, int32 y);

		vec2& Add(const vec2& other);
		vec2& Subtract(const vec2& other);
		vec2& Multiply(const vec2& other);
		vec2& Divide(const vec2& other);

		vec2& Add(int32 value);
		vec2& Subtract(int32 value);
		vec2& Multiply(int32 value);
		vec2& Divide(int32 value);

		friend vec2 operator+(vec2 left, const vec2& right);
		friend vec2 operator-(vec2 left, const vec2& right);
		friend vec2 operator*(vec2 left, const vec2& right);
		friend vec2 operator/(vec2 left, const vec2& right);

		friend vec2 operator+(vec2 left, int32 value);
		friend vec2 operator-(vec2 left, int32 value);
		friend vec2 operator*(vec2 left, int32 value);
		friend vec2 operator/(vec2 left, int32 value);

		bool operator==(const vec2& other) const;
		bool operator!=(const vec2& other) const;

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		vec2& operator+=(int32 value);
		vec2& operator-=(int32 value);
		vec2& operator*=(int32 value);
		vec2& operator/=(int32 value);

		bool operator<(const vec2& other) const;
		bool operator<=(const vec2& other) const;
		bool operator>(const vec2& other) const;
		bool operator>=(const vec2& other) const;

		int32 Distance(const vec2& other) const;

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
	};

}