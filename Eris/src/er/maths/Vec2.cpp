#include "er/erpch.h"
#include "vec2.h"

namespace er {

	vec2::vec2()
		: x(0), y(0)
	{
	}

	vec2::vec2(int32 scalar)
		: x(scalar), y(scalar)
	{
	}

	vec2::vec2(int32 x, int32 y)
		: x(x), y(y)
	{
	}

	vec2& vec2::Add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::Subtract(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	vec2& vec2::Multiply(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	vec2& vec2::Divide(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}

	vec2& vec2::Add(int32 value)
	{
		x += value;
		y += value;

		return *this;
	}

	vec2& vec2::Subtract(int32 value)
	{
		x -= value;
		y -= value;

		return *this;
	}

	vec2& vec2::Multiply(int32 value)
	{
		x *= value;
		y *= value;

		return *this;
	}

	vec2& vec2::Divide(int32 value)
	{
		x /= value;
		y /= value;

		return *this;
	}

	vec2 operator+(vec2 left, const vec2& right)
	{
		return left.Add(right);
	}

	vec2 operator-(vec2 left, const vec2& right)
	{
		return left.Subtract(right);
	}

	vec2 operator*(vec2 left, const vec2& right)
	{
		return left.Multiply(right);
	}

	vec2 operator/(vec2 left, const vec2& right)
	{
		return left.Divide(right);
	}

	vec2 operator+(vec2 left, int32 value)
	{
		return vec2(left.x + value, left.y + value);
	}

	vec2 operator-(vec2 left, int32 value)
	{
		return vec2(left.x - value, left.y - value);
	}

	vec2 operator*(vec2 left, int32 value)
	{
		return vec2(left.x * value, left.y * value);
	}

	vec2 operator/(vec2 left, int32 value)
	{
		return vec2(left.x / value, left.y / value);
	}

	bool vec2::operator==(const vec2& other) const
	{
		return (x == other.x && y == other.y);
	}

	bool vec2::operator!=(const vec2& other) const
	{
		return (x != other.x && y != other.y);
	}

	vec2& vec2::operator+=(const vec2& other)
	{
		return Add(other);
	}

	vec2& vec2::operator-=(const vec2& other)
	{
		return Subtract(other);
	}

	vec2& vec2::operator*=(const vec2& other)
	{
		return Multiply(other);
	}

	vec2& vec2::operator/=(const vec2& other)
	{
		return Divide(other);
	}

	vec2& vec2::operator+=(int32 value)
	{
		return Add(value);
	}

	vec2& vec2::operator-=(int32 value)
	{
		return Subtract(value);
	}

	vec2& vec2::operator*=(int32 value)
	{
		return Multiply(value);
	}

	vec2& vec2::operator/=(int32 value)
	{
		return Divide(value);
	}

	bool vec2::operator<(const vec2& other) const
	{
		return (x < other.x && y < other.y);
	}

	bool vec2::operator<=(const vec2& other) const
	{
		return (x <= other.x && y <= other.y);
	}

	bool vec2::operator>(const vec2& other) const
	{
		return (x > other.x && y > other.y);
	}

	bool vec2::operator>=(const vec2& other) const
	{
		return (x >= other.x && y >= other.y);
	}

	int32 vec2::Distance(const vec2& other) const
	{
		int32 a = x - other.x;
		int32 b = y - other.y;

		return (int32)sqrt(a * a + b * b);
	}

	std::string vec2::ToString() const
	{
		std::stringstream result;
		result << "vec2: (" << x << ", " << y << ")";
		return result.str();
	}

	std::ostream& operator<<(std::ostream& stream, const vec2& vector)
	{
		stream << vector.ToString();
		return stream;
	}

}