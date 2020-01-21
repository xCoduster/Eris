#pragma once

#include <string>
#include "er/Types.h"

namespace er {

	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(float scalar);
		vec4(float x, float y, float z, float w);

		vec4& Add(const vec4& other);
		vec4& Subtract(const vec4& other);
		vec4& Multiply(const vec4& other);
		vec4& Divide(const vec4& other);

		vec4& Add(float value);
		vec4& Subtract(float value);
		vec4& Multiply(float value);
		vec4& Divide(float value);

		friend vec4 operator+(vec4 left, const vec4& right);
		friend vec4 operator-(vec4 left, const vec4& right);
		friend vec4 operator*(vec4 left, const vec4& right);
		friend vec4 operator/(vec4 left, const vec4& right);

		friend vec4 operator+(vec4 left, float value);
		friend vec4 operator-(vec4 left, float value);
		friend vec4 operator*(vec4 left, float value);
		friend vec4 operator/(vec4 left, float value);

		bool operator==(const vec4& other) const;
		bool operator!=(const vec4& other) const;

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		vec4& operator+=(float value);
		vec4& operator-=(float value);
		vec4& operator*=(float value);
		vec4& operator/=(float value);

		bool operator<(const vec4& other) const;
		bool operator<=(const vec4& other) const;
		bool operator>(const vec4& other) const;
		bool operator>=(const vec4& other) const;

		float Distance(const vec4& other) const;

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
	};

}