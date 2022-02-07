#include "Vector4.h"
namespace Engine
{
	Vector4::Vector4(float x, float y, float z, float w) :
		_x(x), _y(y), _z(z), _w(w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Vector4::Vector4()
	{
		_x = 0;
		_y = 0;
		_z = 0;
		_w = 0;

	}

	float Vector4::getX() const {

		return _x;
	}
	float Vector4::getY() const {
		return _y;
	}
	float Vector4::getZ() const {
		return _z;
	}
	float Vector4::getW() const {

		return _w;
	}

	void Vector4::setX(float x) {
		_x = x;
	}
	void Vector4::setY(float y) {
		_y = y;
	}
	void Vector4::setZ(float z) {
		_z = z;
	}
	void Vector4::setW(float w) {
		_w = w;
	}


	Vector4& Vector4::operator=(const Vector4& rhs) {

		_x = rhs._x;
		_y = rhs._y;
		_z = rhs._z;
		_w = rhs._w;

		return *this;
	}

	Vector4& Vector4::operator+=(const Vector4& rhs)
	{
		_x += rhs._x;
		_y += rhs._y;
		_z += rhs._z;
		_w += rhs._w;

		return *this;

	}

	Vector4& Vector4::operator-=(const Vector4& rhs)
	{
		_x -= rhs._x;
		_y -= rhs._y;
		_z -= rhs._z;
		_w -= rhs._w;

		return *this;

	}

	Vector4& Vector4::operator*=(float value)
	{

		_x *= value;
		_y *= value;
		_z *= value;
		_w *= value;

		return *this;

	}

	Vector4& Vector4::operator/=(float value)
	{

		_x /= value;
		_y /= value;
		_z /= value;
		_w /= value;

		return *this;

	}

	Vector4 Vector4::operator-() {


		return Vector4(-_x, -_y, -_z, -_w);

	}

	Vector4 operator+(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY(), lhs.getZ() + rhs.getZ(), lhs.getW() + rhs.getW());

	}


	Vector4 operator-(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY(), lhs.getZ() - rhs.getZ(), lhs.getW() - rhs.getW());

	}

	Vector4 operator*(const Vector4& lhs, float rhs)
	{
		return Vector4(lhs.getX() * rhs, lhs.getY() * rhs, lhs.getZ() * rhs, lhs.getW() * rhs);

	}

	Vector4 operator/(const Vector4& lhs, float rhs)
	{
		return Vector4(lhs.getX() / rhs, lhs.getY() / rhs, lhs.getZ() / rhs, lhs.getW() / rhs);

	}

	bool operator==(const Vector4& lhs, const Vector4& rhs)
	{

		if (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY() && lhs.getZ() == rhs.getZ() && lhs.getW() == rhs.getW())
		{

			return true;
		}
		return false;

	}


	bool operator!=(const Vector4& lhs, const Vector4& rhs)
	{

		if (lhs.getX() != rhs.getX() || lhs.getY() != rhs.getY() || lhs.getZ() != rhs.getZ() || lhs.getW() != rhs.getW())
		{

			return true;
		}
		return false;

	}

	float dot(const Vector4& lhs, const Vector4& rhs)
	{

		return (lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY() + lhs.getZ() * rhs.getZ() + lhs.getW() * rhs.getW());

	}
}
