#include "GameObject.h"
#include <string.h>

using namespace std;
namespace Engine {
	
	Point2D GameObject::getCenter() {

		return boundingBox.center;


	}

	Point2D GameObject::getExtend()
	{
		return boundingBox.extend;

	}

	SmartPtr<GameObject> GameObject::CreateObject(string s, Point2D p) {

		return SmartPtr<GameObject>(new GameObject(s, p));

	}


	GameObject::GameObject(string name, Point2D position)
	{
		
		point = position;
		name[0] = '\0';

		position = Point2D(0, 0);
		velocity = Point2D(0, 0);
		f = Point2D(0, 0);
		acc = Point2D(0, 0);

		mass = 10.0f;

		friction = 1.0f;
		if(name == "Monster")
			friction = 0.0f;
		d = Point2D(0, 0);
		up = false;
		down = false;
		left = false;
		right = false;
		
		boundingBox.extend.setX(35.0f);
		boundingBox.extend.setY(40.0f);
	}
	GameObject::GameObject() {
		name = '\0';
		
		position = Point2D(0, 0);
		velocity = Point2D(0, 0);
		f = Point2D(0, 0);
		acc = Point2D(0, 0);
		
		mass = 3.0f;
		
		friction = 1.0f;

		d = Point2D(0, 0);
		up = false;
		down = false;
		left = false;
		right = false;
		if (name == "Monster")
			friction = 0.0f;
		boundingBox.extend.setX(35.0f);
		boundingBox.extend.setY(40.0f);
	}

	void GameObject::setPosition(float x, float y)
	{
		point.setX(x);
		point.setY(y);

	}

	Point2D GameObject::getLocation()
	{
		return point;

	}


	void GameObject::setName(std::string input)
	{
		name = input;
	}


	std::string GameObject::getName()
	{
		return name;
	}

	Point2D GameObject::getVelocity() {

		return velocity;
	}
	Point2D GameObject::getPosition() {

		return point;
	}
	Point2D GameObject::getForce() {

		return f;
	}

	void GameObject::setVelocity(Point2D v) {

		velocity = v;
	}

	void GameObject::addForce(Point2D newF) {

		f += newF;

	}
	void GameObject::physic(float dt)
	{
		if (up) {
			addForce(Point2D(0, 1));

		}
		if (down) {
			addForce(Point2D(0, -1));
		}

		if (left) {
			addForce(Point2D(-1, 0));

		}
		if (right) {
			addForce(Point2D(1, 0));

		}
		if (up && right) {
			addForce(Point2D(1, 1));

		}
		if (up && left) {
			addForce(Point2D(-1, 1));

		}

		if (down && right) {
			addForce(Point2D(1, -1));

		}

		if (down && left) {
			addForce(Point2D(-1, -1));

		}
		Point2D currentVelocity = getVelocity();

		Point2D currentPosition = getPosition();

		float velocity_X = currentVelocity.getX() >= 0 ? currentVelocity.getX() * currentVelocity.getX() : -(currentVelocity.getX() * currentVelocity.getX());
		float velocity_Y = currentVelocity.getY() >= 0 ? currentVelocity.getY() * currentVelocity.getY() : -(currentVelocity.getY() * currentVelocity.getY());

		Point2D drag = Point2D(velocity_X, velocity_Y) * (-friction);

		Point2D force = getForce() + drag;

		Point2D accelation = force / mass;

		Point2D next = currentVelocity + (accelation * dt);

		Point2D average = (currentVelocity + next) / 2.0f;

		d = drag;
		acc = accelation;
		float x = currentPosition.getX() + average.getX() * dt;
		float y = currentPosition.getY() + average.getY() * dt;
		
		setPosition(x, y);
		setVelocity(next);
		f = Point2D(0, 0);
		//if (this->name == "Monster")
		//{
		//	this->setVelocity(Point2D(0, 0));
		//}
		/*const size_t	lenBuffer = 65;
		char			Buffer[lenBuffer];
		sprintf_s(Buffer, lenBuffer, " %f\n", getVelocity().getY());
		OutputDebugStringA(Buffer);*/
	}
		void GameObject::render(){

			if (pGoodGuy)
			{
				static float			moveDist = .01f;
				static float			moveDir = moveDist;

				static GLib::Point2D	Offset = { 0.0f, 0.0f };

				Offset.x += getPosition().getX();
				Offset.y += getPosition().getY();
				//Offset.x += moveDir;

				// Tell GLib to render this sprite at our calculated location
				GLib::Render(*pGoodGuy, Offset, 0.0f, 0.0f);
				Offset = { 0.0f,0.0f };
			}
			boundingBox.center.setX(getPosition().getX());
			boundingBox.center.setY(getPosition().getY()-30);
		}
		GameObject::~GameObject() 
		{
			GLib::Release(pGoodGuy);
		}
		
}