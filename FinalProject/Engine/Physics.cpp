#include "Physics.h"

namespace Engine {

	namespace Physics {
	
		void player::playerMovement(GameObject* player,float dt)
		{
			
			Point2D accelation = player->getForce() / mass;

			Point2D currentVelocity = player->getVelocity();

			Point2D currentPosition = player->getPosition();

			currentVelocity = currentVelocity + accelation * dt;
			
			currentPosition = currentPosition + currentVelocity * dt;


		}

	}
}