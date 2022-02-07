#include "collision.h"
#include <math.h>
namespace Engine {

	collision::collision() {

		timer = 15000;
	}
	collision::~collision() {

		//delete player;
		for (int i = 0; i < counters.size(); i++)
		{
			delete counters.at(i);

		}
		for (int j = 0; j < world_object.size(); j++)
		{
			delete world_object.at(j);

		}
	}
	float collision::getTimer()
	{
		return timer;
	}
	bool collision::finding_separation(GameObject& a, GameObject& b)
	{
		bool bSeparationX = fabs(a.getCenter().getX() - b.getCenter().getX())
			<= a.getExtend().getX() + b.getExtend().getX();

		bool bSeparationY = fabs(a.getCenter().getY() - b.getCenter().getY())
			<= a.getExtend().getY() + b.getExtend().getY();

		return bSeparationX && bSeparationY;

	}

	bool collision::isCollide()
	{
		for (int i = 0; i < world_object.size(); i++)
		{

			for (int j = 1; j < world_object.size(); j++)
			{
				if (j != i)
				{
					if (world_object.at(j)->getName() == "Player")
					{
						if (finding_separation(*world_object.at(i), *world_object.at(j)))
						{


							world_object.at(j)->setPosition(0, 0);


							return true;

						}
					}
				}
			}
		}
		return false;
	}

}