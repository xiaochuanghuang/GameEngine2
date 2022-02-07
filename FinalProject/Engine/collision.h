#pragma once
#include "GameObject.h"
#include <vector>
namespace Engine{
	
class collision
{
	static collision* collision_instance;
public:
	float timer;
	bool finding_separation(GameObject &a, GameObject &b);
	
	vector<GameObject*> world_object;
	vector<Counters*> counters;
	collision();
	~collision();
	bool isCollide();
	float getTimer();
	 GameObject *player;
	static inline collision* getCollisionInstance()
	{
		if (!collision_instance) {
		
			collision_instance = new collision();
		}
		return collision_instance;
	}
	inline void find_player() {
		if(!player)
		{
		for (int i = 0; i < world_object.size(); i++)
		{
			if (world_object.at(i)->name == "Player") {
				player = world_object.at(i);
			}
	
		}
		}
	}
	void ConservationofMomentum(GameObject& a, GameObject& b) {
		float velocity_goAX = (a.mass - b.mass) / (a.mass + b.mass) * a.getVelocity().getX()
			+ (2 * b.mass) / (a.mass + b.mass) * b.getVelocity().getX();
		float velocity_goAY = (a.mass - b.mass) / (a.mass + b.mass) * a.getVelocity().getY()
			+ (2 * b.mass) / (a.mass + b.mass) * b.getVelocity().getY();
		a.setVelocity(Point2D(velocity_goAX, velocity_goAY));
		float velocity_goBX = (b.mass - a.mass) / (a.mass + b.mass) * b.getVelocity().getX()
			+ (2 * a.mass) / (a.mass + b.mass) * a.getVelocity().getX();
		float velocity_goBY = (b.mass - a.mass) / (a.mass + b.mass) * b.getVelocity().getY()
			+ (2 * a.mass) / (a.mass + b.mass) * a.getVelocity().getY();
		b.setVelocity(Point2D(velocity_goBX, velocity_goBY));
	}
private:
	
};
}