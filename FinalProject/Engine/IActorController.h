//#ifndef __IACTOR_CONTROLLER_H
//#define __IACTOR_CONTROLLER_H
#pragma once
#include "GameObject.h"
//#include"../Player.h"
namespace Engine
{

class GameObject;

class IActorController 
{
public:
	IActorController();
	virtual ~IActorController() { }

	virtual void UpdateActor(GameObject& i_Actor ) = 0;
};

} // namespace Engine

#include "IActorController-inl.h"

//#endif // __IACTOR_CONTROLLER_H