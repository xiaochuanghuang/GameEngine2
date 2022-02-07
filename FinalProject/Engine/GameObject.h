#pragma once
#include <iostream>
#include "Math/Point2D.h"
#include "SmartPtr.h"
#include "../Exports/GLib/GLib.h"

using namespace std;
namespace Engine
{
	struct aabb {

		Point2D center;
		Point2D extend;

	};

	/*struct Collision_Adaptable
	{
		WeakPtr<GameObject> go;
		aabb boundingBox;

	};*/
	class GameObject {

	public:
		static SmartPtr<GameObject> CreateObject(string, Point2D);
		GameObject();
		~GameObject();

		GameObject(string, Point2D);
	
		Point2D point;
		Point2D getCenter();
		Point2D getExtend();

		Point2D getLocation();

		void setPosition(float, float);

		void setName(std::string);

		void setVelocity(Point2D);

		std::string getName();

		Point2D getVelocity();
		Point2D getPosition();
		Point2D getForce();

		void addForce(Point2D);
		Point2D acc;

		float friction;

		float mass;

		Point2D d;
		void render();

		bool up;
		bool down;
		bool left;
		bool right;
		Point2D f;
		void physic(float);
		GLib::Sprite* pGoodGuy;
		aabb boundingBox;
		std::string name;
	private:
		
		Point2D velocity;
		Point2D position;
		
		



	};
}