#pragma once
#include <assert.h>
namespace Engine {
	class Vector4
	{
	public:
		Vector4();

		Vector4(float x, float y, float z, float w);

		//Vector4(const Vector4& i_other);

		float getX() const;
		float getY() const;
		float getZ() const;
		float getW() const;

		void setX(float x);
		void setY(float y);
		void setZ(float z);
		void setW(float w);

		//natural semantic usage
		Vector4& operator=(const Vector4& rhs);


		Vector4& operator+=(const Vector4& rhs);
		Vector4& operator-=(const Vector4& rhs);

		Vector4& operator*=(float value);
		Vector4& operator/=(float value);

		Vector4 operator-();





	private:

		float _x, _y, _z, _w;


	};

	Vector4 operator+(const Vector4& lhs, const Vector4& rhs);
	Vector4 operator-(const Vector4& lhs, const Vector4& rhs);

	Vector4 operator*(const Vector4& lhs, float rhs);
	Vector4 operator/(const Vector4& lhs, float rhs);

	bool operator==(const Vector4& lhs, const Vector4& rhs);
	bool operator!=(const Vector4& lhs, const Vector4& rhs);

	float dot(const Vector4& lhs, const Vector4& rhs);


}

