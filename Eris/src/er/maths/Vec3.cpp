#include "er/erpch.h"
#include "vec3.h"

namespace er {

	vec3::vec3()
		: x(0), y(0), z(0)
	{
	}

	vec3::vec3(int32 scalar)
		: x(scalar), y(scalar), z(scalar)
	{
	}

	vec3::vec3(int32 x, int32 y, int32 z)
		: x(x), y(y), z(z)
	{
	}

	vec3& vec3::Add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::Subtract(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::Multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::Divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	vec3& vec3::Add(int32 value)
	{
		x += value;
		y += value;
		z += value;

		return *this;
	}

	vec3& vec3::Subtract(int32 value)
	{
		x -= value;
		y -= value;
		z -= value;

		return *this;
	}

	vec3& vec3::Multiply(int32 value)
	{
		x *= value;
		y *= value;
		z *= value;

		return *this;
	}

	vec3& vec3::Divide(int32 value)
	{
		x /= value;
		y /= value;
		z /= value;

		return *this;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.Add(right);
	}

	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.Subtract(right);
	}

	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.Multiply(right);
	}

	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.Divide(right);
	}

	vec3 operator+(vec3 left, int32 value)
	{
		return vec3(left.x + value, left.y + value, left.z + value);
	}

	vec3 operator-(vec3 left, int32 value)
	{
		return vec3(left.x - value, left.y - value, left.z - value);
	}

	vec3 operator*(vec3 left, int32 value)
	{
		return vec3(left.x * value, left.y * value, left.z * value);
	}

	vec3 operator/(vec3 left, int32 value)
	{
		return vec3(left.x / value, left.y / value, left.z / value);
	}

	bool vec3::operator==(const vec3& other) const
	{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool vec3::operator!=(const vec3& other) const
	{
		return (x != other.x && y != other.y && z != other.z);
	}

	vec3& vec3::operator+=(const vec3& other)
	{
		return Add(other);
	}

	vec3& vec3::operator-=(const vec3& other)
	{
		return Subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other)
	{
		return Multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other)
	{
		return Divide(other);
	}

	vec3& vec3::operator+=(int32 value)
	{
		return Add(value);
	}

	vec3& vec3::operator-=(int32 value)
	{
		return Subtract(value);
	}

	vec3& vec3::operator*=(int32 value)
	{
		return Multiply(value);
	}

	vec3& vec3::operator/=(int32 value)
	{
		return Divide(value);
	}

	bool vec3::operator<(const vec3& other) const
	{
		return (x < other.x && y < other.y && z < other.z);
	}

	bool vec3::operator<=(const vec3& other) const
	{
		return (x <= other.x && y <= other.y && z <= other.z);
	}

	bool vec3::operator>(const vec3& other) const
	{
		return (x > other.x && y > other.y && z > other.z);
	}

	bool vec3::operator>=(const vec3& other) const
	{
		return (x >= other.x && y >= other.y && z >= other.z);
	}

	int32 vec3::Distance(const vec3& other) const
	{
		int32 a = x - other.x;
		int32 b = y - other.y;
		int32 c = z - other.z;
		double diagonal = sqrt(a * a + b * b);

		return (int32)sqrt(diagonal * diagonal + c * c);
	}

	std::string vec3::ToString() const
	{
		std::stringstream result;
		result << "vec3: (" << x << ", " << y << ", " << z << ")";
		return result.str();
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << vector.ToString();
		return stream;
	}

}