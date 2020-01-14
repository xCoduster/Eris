#include "er/erpch.h"
#include "vec4.h"

namespace er {

	vec4::vec4()
		: x(0), y(0), z(0), w(0)
	{
	}

	vec4::vec4(int32 scalar)
		: x(scalar), y(scalar), z(scalar), w(scalar)
	{
	}

	vec4::vec4(int32 x, int32 y, int32 z, int32 w)
		: x(x), y(y), z(z), w(w)
	{
	}

	vec4& vec4::Add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	vec4& vec4::Subtract(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	vec4& vec4::Multiply(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}

	vec4& vec4::Divide(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}

	vec4& vec4::Add(int32 value)
	{
		x += value;
		y += value;
		z += value;
		w += value;

		return *this;
	}

	vec4& vec4::Subtract(int32 value)
	{
		x -= value;
		y -= value;
		z -= value;
		w -= value;

		return *this;
	}

	vec4& vec4::Multiply(int32 value)
	{
		x *= value;
		y *= value;
		z *= value;
		w *= value;

		return *this;
	}

	vec4& vec4::Divide(int32 value)
	{
		x /= value;
		y /= value;
		z /= value;
		w /= value;

		return *this;
	}

	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.Add(right);
	}

	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.Subtract(right);
	}

	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.Multiply(right);
	}

	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.Divide(right);
	}

	vec4 operator+(vec4 left, int32 value)
	{
		return vec4(left.x + value, left.y + value, left.z + value, left.w + value);
	}

	vec4 operator-(vec4 left, int32 value)
	{
		return vec4(left.x - value, left.y - value, left.z - value, left.w - value);
	}

	vec4 operator*(vec4 left, int32 value)
	{
		return vec4(left.x * value, left.y * value, left.z * value, left.w * value);
	}

	vec4 operator/(vec4 left, int32 value)
	{
		return vec4(left.x / value, left.y / value, left.z / value, left.w / value);
	}

	bool vec4::operator==(const vec4& other) const
	{
		return (x == other.x && y == other.y && z == other.z && w == other.w);
	}

	bool vec4::operator!=(const vec4& other) const
	{
		return (x != other.x && y != other.y && z != other.z && w != other.w);
	}

	vec4& vec4::operator+=(const vec4& other)
	{
		return Add(other);
	}

	vec4& vec4::operator-=(const vec4& other)
	{
		return Subtract(other);
	}

	vec4& vec4::operator*=(const vec4& other)
	{
		return Multiply(other);
	}

	vec4& vec4::operator/=(const vec4& other)
	{
		return Divide(other);
	}

	vec4& vec4::operator+=(int32 value)
	{
		return Add(value);
	}

	vec4& vec4::operator-=(int32 value)
	{
		return Subtract(value);
	}

	vec4& vec4::operator*=(int32 value)
	{
		return Multiply(value);
	}

	vec4& vec4::operator/=(int32 value)
	{
		return Divide(value);
	}

	bool vec4::operator<(const vec4& other) const
	{
		return (x < other.x && y < other.y && z < other.z && w < other.w);
	}

	bool vec4::operator<=(const vec4& other) const
	{
		return (x <= other.x && y <= other.y && z <= other.z && w <= other.w);
	}

	bool vec4::operator>(const vec4& other) const
	{
		return (x > other.x && y > other.y && z > other.z && w > other.w);
	}

	bool vec4::operator>=(const vec4& other) const
	{
		return (x >= other.x && y >= other.y && z >= other.z && w >= other.w);
	}

	int32 vec4::Distance(const vec4& other) const
	{
		int32 a = x - other.x;
		int32 b = y - other.y;
		int32 c = z - other.z;
		int32 d = w - other.w;

		double diagonal = sqrt(a * a + b * b);
		double spaceDiagonal = sqrt(diagonal * diagonal + c * c);

		return (int32)sqrt(spaceDiagonal * spaceDiagonal + d * d);
	}

	std::string vec4::ToString() const
	{
		std::stringstream result;
		result << "vec4: (" << x << ", " << y << ", " << z << ", " << w << ")";
		return result.str();
	}

	std::ostream& operator<<(std::ostream& stream, const vec4& vector)
	{
		stream << vector.ToString();
		return stream;
	}

}