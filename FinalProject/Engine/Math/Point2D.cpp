#include "Point2D.h"

namespace Engine{
Point2D::Point2D() {
	_x = 0;
	_y = 0;

}
Point2D::Point2D(float x, float y) {

	_x = x;
	_y = y;


}

void Point2D::setX(float x) {


	_x = x;


}

void Point2D::setY(float y) {


	_y = y;

}

float Point2D::getX() const{

	return _x;
}
float Point2D::getY() const{

	return _y;
}

bool Point2D::operator==(Point2D const& point) const
{
	if (_x == point.getX() && _y == point.getY())
	{
		return true;
	}
	return false;
}

bool Point2D::operator!=(Point2D const& point) const
{
	if (_x != point.getX() && _y != point.getY())
	{
		return true;
	}
	return false;
}

Point2D Point2D::operator+(Point2D point)
{
	
	float x = point.getX() + _x;
	float y = point.getY() + _y;
	return Point2D(x, y);


}

Point2D Point2D::operator-(Point2D  point)
{

	float x = _x- point.getX() ;
	float y = _y-point.getY() ;
	return Point2D(x, y);


}

Point2D Point2D::operator*(Point2D  point)
{

	float x = point.getX() * _x;
	float y = point.getY() * _y;
	return Point2D(x, y);


}
Point2D Point2D::operator/(Point2D  point)
{

	float x = _x / point.getX() ;
	float y =_y / point.getY();
	return Point2D(x, y);


}

Point2D Point2D::operator*(float point)
{

	float x = point * _x;
	float y = point * _y;
	return Point2D(x, y);


}
Point2D Point2D::operator / (float point)
{

	float x = _x/point ;
	float y = _y/point ;
	return Point2D(x, y);


}
Point2D operator* (float newInt, Point2D point)
{
	float x = newInt * point.getX();
	float y = newInt * point.getY();

	return Point2D(x, y);

}

Point2D Point2D::operator-() 
{
	float x = -_x;
	float y = -_y;

	return Point2D(x, y);
}

Point2D& Point2D::operator+=(Point2D point) {
	_x = _x + point.getX();
	_y = _y + point.getY();

	return *this;
}
Point2D& Point2D::operator-=(Point2D point) {
	_x = _x - point.getX();
	_y = _y - point.getY();

	return *this;
}

Point2D& Point2D::operator*=(float point) {
	_x = _x * point;
	_y = _y * point;

	return *this;
}

Point2D& Point2D::operator/=(float point) {
	_x = _x / point;
	_y = _y / point;

	return *this;
}
}