#include "Matrix4x4.h"
#include <math.h>
namespace Engine {



	Matrix4x4::Matrix4x4(float inputx1x1, float input1x2, float input1x3, float input1x4,
		float input2x1, float input2x2, float input2x3, float input2x4,
		float input3x1, float input3x2, float input3x3, float input3x4,
		float input4x1, float input4x2, float input4x3, float input4x4) :
		matrix1x1(inputx1x1), matrix1x2(input1x2), matrix1x3(input1x3), matrix1x4(input1x4),
		matrix2x1(input2x1), matrix2x2(input2x2), matrix2x3(input2x3), matrix2x4(input2x4),
		matrix3x1(input3x1), matrix3x2(input3x2), matrix3x3(input3x3), matrix3x4(input3x4),
		matrix4x1(input4x1), matrix4x2(input4x2), matrix4x3(input4x3), matrix4x4(input4x4)
	{



	}
	Matrix4x4::Matrix4x4(const Matrix4x4& input) :
		matrix1x1(input.matrix1x1), matrix1x2(input.matrix1x2), matrix1x3(input.matrix1x3), matrix1x4(input.matrix1x4),
		matrix2x1(input.matrix2x1), matrix2x2(input.matrix2x2), matrix2x3(input.matrix2x3), matrix2x4(input.matrix2x4),
		matrix3x1(input.matrix3x1), matrix3x2(input.matrix3x2), matrix3x3(input.matrix3x3), matrix3x4(input.matrix3x4),
		matrix4x1(input.matrix4x1), matrix4x2(input.matrix4x2), matrix4x3(input.matrix4x3), matrix4x4(input.matrix4x4)
	{

	}
	Matrix4x4& Matrix4x4::operator=(const Matrix4x4& input)
	{

		matrix1x1 = input.matrix1x1; matrix1x2 = input.matrix1x2;  matrix1x3 = input.matrix1x3; matrix1x4 = input.matrix1x4;
		matrix2x1 = input.matrix2x1; matrix2x2 = input.matrix2x2; matrix2x3 = input.matrix2x3; matrix2x4 = input.matrix2x4;
		matrix3x1 = input.matrix3x1; matrix3x2 = input.matrix3x2; matrix3x3 = input.matrix3x3; matrix3x4 = input.matrix3x4;
		matrix4x1 = input.matrix4x1; matrix4x2 = input.matrix4x2; matrix4x3 = input.matrix4x3; matrix4x4 = input.matrix4x4;


		return *this;


	}
	bool Matrix4x4::operator==(const Matrix4x4& input) {

		return(matrix1x1 == input.matrix1x1 && matrix1x2 == input.matrix1x2 && matrix1x3 == input.matrix1x3 && matrix1x4 == input.matrix1x4
			&& matrix2x1 == input.matrix2x1 && matrix2x2 == input.matrix2x2 && matrix2x3 == input.matrix2x3 && matrix2x4 == input.matrix2x4
			&& matrix3x1 == input.matrix3x1 && matrix3x2 == input.matrix3x2 && matrix3x3 == input.matrix3x3 && matrix3x4 == input.matrix3x4
			&& matrix4x1 == input.matrix4x1 && matrix4x2 == input.matrix4x2 && matrix4x3 == input.matrix4x3 && matrix4x4 == input.matrix4x4);
	}
	Vector4 Matrix4x4::col(size_t c) {

		if (c == 0) {
			return Vector4(matrix1x1, matrix2x1, matrix3x1, matrix4x1);
		}
		if (c == 1) {
			return Vector4(matrix1x2, matrix2x2, matrix3x2, matrix4x2);
		}
		if (c == 2) {
			return Vector4(matrix1x3, matrix2x3, matrix3x3, matrix4x3);
		}
		if (c == 3) {
			return Vector4(matrix1x4, matrix2x4, matrix3x4, matrix4x4);
		}

		return Vector4(matrix1x1, matrix1x1, matrix1x1, matrix1x1);
	}
	Vector4 Matrix4x4::row(size_t r) {

		if (r == 0) {
			return Vector4(matrix1x1, matrix1x2, matrix1x3, matrix1x4);
		}
		if (r == 1) {
			return Vector4(matrix2x1, matrix2x2, matrix2x3, matrix2x4);
		}
		if (r == 2) {
			return Vector4(matrix3x1, matrix3x2, matrix3x3, matrix3x4);
		}
		if (r == 3) {
			return Vector4(matrix4x1, matrix4x2, matrix4x3, matrix4x4);
		}

		return Vector4(matrix1x1, matrix1x1, matrix1x1, matrix1x1);
	}

	Matrix4x4 Matrix4x4::rowXRotation(float input) {

		return Matrix4x4(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, cosf(input), sinf(input), 0.0f,
			0.0f, -sinf(input), cosf(input), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);

	}

	Matrix4x4 Matrix4x4::rowYRotation(float input) {
		return Matrix4x4(
			cosf(input), 0.0f, -sinf(input), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			sinf(input), 0.0f, cosf(input), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

	}

	Matrix4x4 Matrix4x4::rowZRotation(float input) {
		return Matrix4x4(
			cosf(input), sinf(input), 0.0f, 0.0f,
			-sinf(input), cosf(input), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f

		);

	}

	Matrix4x4 Matrix4x4::colXRotation(float input) {

		return Matrix4x4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, cosf(input), -sinf(input), 0.0f,
			0.0f, sinf(input), cosf(input), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f

		);

	}
	Matrix4x4 Matrix4x4::colYRotation(float input) {

		return Matrix4x4(
			cosf(input), 0.0f, sinf(input), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			-sinf(input), 0.0f, cosf(input), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f

		);

	}
	Matrix4x4 Matrix4x4::colZRotation(float input) {

		return Matrix4x4(
			cosf(input), -sinf(input), 0.0f, 0.0f,
			sinf(input), cosf(input), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f

		);

	}
	Matrix4x4 Matrix4x4::rowTranslation(float x, float y, float z) {
		return Matrix4x4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			x, y, z, 1.0f);
	}

	Matrix4x4 Matrix4x4::colTranslation(float x, float y, float z) {
		return Matrix4x4(
			1.0f, 0.0f, 0.0f, x,
			0.0f, 1.0f, 0.0f, y,
			0.0f, 0.0f, 1.0f, z,
			0.0f, 0.0f, 0.0f, 1.0f);
	}
	Matrix4x4 Matrix4x4::Scale(float x, float y, float z)
	{
		return Matrix4x4(
			x, 0.0f, 0.0f, 0.0f,
			0.0f, y, 0.0f, 0.0f,
			0.0f, 0.0f, z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);

	}

	void Matrix4x4::inverse() {


	}

	void Matrix4x4::tranSpose() {
		float swap;
		swap = matrix2x1; matrix2x1 = matrix1x2; matrix1x2 = swap;
		swap = matrix3x1; matrix3x1 = matrix1x3; matrix1x3 = swap;
		swap = matrix4x1; matrix4x1 = matrix1x4; matrix1x4 = swap;
		swap = matrix3x2; matrix3x2 = matrix2x3; matrix2x3 = swap;
		swap = matrix4x2; matrix4x2 = matrix2x4, matrix2x4 = swap;
		swap = matrix4x3; matrix4x3 = matrix3x4; matrix3x4 = swap;
	}

	void Matrix4x4::Multiply(const Matrix4x4& other, Matrix4x4& out) {



	}

	Vector4 Matrix4x4::multiplyCol(const Vector4& v) {
		return Vector4(
			v.getX() * matrix1x1 + v.getY() * matrix2x1 + v.getZ() * matrix3x1 + v.getW() * matrix4x1,
			v.getX() * matrix1x2 + v.getY() * matrix2x2 + v.getZ() * matrix3x2 + v.getW() * matrix4x2,
			v.getX() * matrix1x3 + v.getY() * matrix2x3 + v.getZ() * matrix3x3 + v.getW() * matrix4x3,
			v.getX() * matrix1x4 + v.getY() * matrix2x4 + v.getZ() * matrix3x4 + v.getW() * matrix4x4);
	}

	Vector4 Matrix4x4::multiplyRow(const Vector4& v) {
		return Vector4(
			v.getX() * matrix1x1 + v.getY() * matrix1x2 + v.getZ() * matrix1x3 + v.getW() * matrix1x4,
			v.getX() * matrix2x1 + v.getY() * matrix2x2 + v.getZ() * matrix2x3 + v.getW() * matrix2x4,
			v.getX() * matrix3x1 + v.getY() * matrix3x2 + v.getZ() * matrix3x3 + v.getW() * matrix3x4,
			v.getX() * matrix4x1 + v.getY() * matrix4x2 + v.getZ() * matrix4x3 + v.getW() * matrix4x4);

	}


}
