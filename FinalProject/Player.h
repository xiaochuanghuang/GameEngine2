#pragma once
#include "GameObject.h"
#include "Exports/GLib/GLib.h"


class Player :public Engine::GameObject
{

public:
	Player();
	void render();

	bool up;
	bool down;
	bool left;
	bool right;

	void physic(float);

private:

	GLib::Sprite* pGoodGuy;
};

