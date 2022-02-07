#pragma once
#include "Math/Point2D.h"
#include "GameObject.h"
namespace Engine {

	namespace Physics {

		class player {
		public:
			Engine::Point2D velocity;

			void playerMovement(GameObject* player, float dt);


			//double friction = 0.2;

			float mass = 3;

			float force = 5;

	

		};

	}

}