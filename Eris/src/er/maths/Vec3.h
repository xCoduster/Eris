#pragma once

#include <string>
#include "er/Types.h"

namespace er {

	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(float scalar);
		vec3(float x, float y, float z);

		vec3& Add(const vec3& other);
		vec3& Subtract(const vec3& other);
		vec3& Multiply(const vec3& other);
		vec3& Divide(const vec3& other);

		vec3& Add(float value);
		vec3& Subtract(float value);
		vec3& Multiply(float value);
		vec3& Divide(float value);

		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		friend vec3 operator+(vec3 left, float value);
		friend vec3 operator-(vec3 left, float value);
		friend vec3 operator*(vec3 left, float value);
		friend vec3 operator/(vec3 left, float value);

		bool operator==(const vec3& other) const;
		bool operator!=(const vec3& other) const;

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		vec3& operator+=(float value);
		vec3& operator-=(float value);
		vec3& operator*=(float value);
		vec3& operator/=(float value);

		bool operator<(const vec3& other) const;
		bool operator<=(const vec3& other) const;
		bool operator>(const vec3& other) const;
		bool operator>=(const vec3& other) const;

		float Distance(const vec3& other) const;

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
	};

}