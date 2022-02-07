#pragma once
namespace Engine {
	class Point2D {

	public:
		Point2D(float, float);
		Point2D();
		void setX(float);
		void setY(float);

		float getX() const;
		float getY() const;

		bool operator==(Point2D const&) const;

		bool operator!=(Point2D const&) const;

		Point2D operator+(Point2D);

		Point2D operator-(Point2D);

		Point2D operator * (Point2D);

		Point2D operator / (Point2D);

		Point2D operator * (float);

		Point2D operator / (float);



		friend Point2D operator * (float, Point2D);

	

		Point2D operator-();

		Point2D& operator+=(Point2D);
		Point2D& operator-=(Point2D);

		Point2D& operator*=(float);
		Point2D& operator/=(float);

	private:
		float _x, _y;


	};
}