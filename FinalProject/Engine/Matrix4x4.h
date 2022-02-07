#pragma once
#include "Vector4.h"
namespace Engine {
	class Matrix4x4
	{
	public:
		Matrix4x4(float inputx1x1, float input1x2, float input1x3, float input1x4,
			float input2x1, float input2x2, float input2x3, float input2x4,
			float input3x1, float input3x2, float input3x3, float input3x4,
			float input4x1, float input4x2, float input4x3, float input4x4);
		Matrix4x4(const Matrix4x4& input);
		Matrix4x4& operator=(const Matrix4x4& input);

		Vector4 row(size_t r);
		Vector4 col(size_t c);
		Matrix4x4 rowXRotation(float input);
		Matrix4x4 rowYRotation(float input);
		Matrix4x4 rowZRotation(float input);

		Matrix4x4 colXRotation(float input);
		Matrix4x4 colYRotation(float input);
		Matrix4x4 colZRotation(float input);

		Matrix4x4 rowTranslation(float x, float y, float z);
		Matrix4x4 colTranslation(float x, float y, float z);

		bool operator==(const Matrix4x4& input);

		Matrix4x4 Scale(float x, float y, float z);



		void tranSpose();
		void inverse();

		void Multiply(const Matrix4x4& other, Matrix4x4& out);


		Vector4 multiplyCol(const Vector4& v);
		Vector4 multiplyRow(const Vector4& v);



	private:
		float matrix1x1, matrix1x2, matrix1x3, matrix1x4,
			matrix2x1, matrix2x2, matrix2x3, matrix2x4,
			matrix3x1, matrix3x2, matrix3x3, matrix3x4,
			matrix4x1, matrix4x2, matrix4x3, matrix4x4;
	};

}

