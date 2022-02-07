#pragma once
#include"IActorController.h"
class GameObjectController :public Engine::IActorController {

public:

	virtual void control_go_choose();

};