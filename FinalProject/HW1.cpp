//#include <assert.h>

#include <Windows.h>
#include <DirectXColors.h>
#include <crtdbg.h>
#include "collision.h"
#include "JobSystem.h"
#include "GLib.h"
#include "Engine/Timing.h"
#include "GameObject.h"
#include "Engine/SmartPtr.h"
#include "GameObjectJSON.cpp"
#include <chrono>
//#include <thread>
#include <time.h>

using namespace Engine;
using namespace Timing;


SmartPtr<GameObject> monster;
SmartPtr<GameObject> monster2;
SmartPtr<GameObject> monster3;
//SmartPtr<GameObject> monster4;
float GetFrameTime();
void callRandom(SmartPtr<GameObject> input);
void ballMoving(SmartPtr<GameObject> input);
void input(uint8_t in);
void releaseInput(uint8_t in);
bool bQuit;
collision* collision_pointer;
float timer;

void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
{
#ifdef _DEBUG
	//const size_t	lenBuffer = 65;
	//char			Buffer[lenBuffer];

	//sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	//OutputDebugStringA(Buffer);
	if (bWentDown)
	{
		input(i_VKeyID);
	}
	else {
		releaseInput(i_VKeyID);
	}

#endif // __DEBUG
}
void input(uint8_t in) {



	if (in == 65)
	{
		collision::getCollisionInstance()->player->left = true;

	}
	if (in == 68)
	{
		collision::getCollisionInstance()->player->right = true;
	}
	if (in == 83)
	{
		collision::getCollisionInstance()->player->down = true;
	}
	if (in == 87)
	{
		collision::getCollisionInstance()->player->up = true;
	}


}
void releaseInput(uint8_t in) {


	if (in == 65)
	{
		collision::getCollisionInstance()->player->left = false;
	}
	if (in == 68)
	{
		collision::getCollisionInstance()->player->right = false;
	}
	if (in == 83)
	{
		collision::getCollisionInstance()->player->down = false;
	}
	if (in == 87)
	{
		collision::getCollisionInstance()->player->up = false;
	}

}


collision* collision::collision_instance = nullptr;


int WINAPI wWinMain(_In_ HINSTANCE i_hInstance, _In_opt_ HINSTANCE i_hPrevInstance, _In_  LPWSTR i_lpCmdLine, _In_ int i_nCmdShow)
{
	clock_t start = clock();
	//Engine::Timing::tick_t gameTime = Engine::Timing::GetCurrentCounter();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc=585;
	// IMPORTANT: first we need to initialize GLib
	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600, true);
	collision_pointer = collision_pointer->getCollisionInstance();
	monster = CreatGameObject("Engine/Monster.json");
	monster->setPosition(-250, -250);
	monster->setVelocity(Point2D(0, 0));

	monster2 = CreatGameObject("Engine/Monster2.json");
	monster2->setPosition(-250, 150);
	monster2->setVelocity(Point2D(0, 0));

	monster3 = CreatGameObject("Engine/Monster3.json");
	monster3->setPosition(250, 150);
	monster3->setVelocity(Point2D(0, 0));

	//monster4 = CreatGameObject("Engine/Monster4.json");
	//monster4->setPosition(250, -250);
	//monster4->setVelocity(Point2D(0, 0));

	if (bSuccess)
	{
		Engine::Timing::Init();
		JobSystem::Init();
		// IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
		GLib::SetKeyStateChangeCallback(TestKeyCallback);

		//Create Game Object from Json


		const char* playerName = "Loader";
		Engine::HashedString queueName = JobSystem::CreateQueue(playerName, 2);
		JobSystem::RunJob(queueName, std::bind(CreatGameObject, "Engine/Player.json"));
		//JobSystem::RunJob(queueName, std::bind(CreatGameObject, "Engine/Monster.json"));

		bQuit = false;
		do
		{
			collision::getCollisionInstance()->find_player();

			// IMPORTANT: We need to let GLib do it's thing. 

			GLib::Service(bQuit);

			float i_dt = GetFrameTime();

			if (!bQuit)
			{

				// IMPORTANT: Tell GLib that we want to start rendering
				GLib::BeginRendering(DirectX::Colors::BlueViolet);

				// Tell GLib that we want to render some sprites
				GLib::Sprites::BeginRendering();

				for (int i = 0; i < collision::getCollisionInstance()->world_object.size(); i++)
				{
					collision::getCollisionInstance()->world_object.at(i)->physic(i_dt);
					collision::getCollisionInstance()->world_object.at(i)->render();
				}
				if (collision::getCollisionInstance()->player)
				{
					float positionX = collision::getCollisionInstance()->player->getPosition().getX();
					float positionY = collision::getCollisionInstance()->player->getPosition().getY();
					if (positionX >= 370)
					{
						collision::getCollisionInstance()->player->setPosition(370, positionY);
						positionX = 370;
					}
					else if (positionX < -370)
					{
						collision::getCollisionInstance()->player->setPosition(-370, positionY);
						positionX = -370;
					}
					if (positionY <= -300)
					{
						collision::getCollisionInstance()->player->setPosition(positionX, -300);
						positionY = -300;
					}
					else if (positionY > 200)
					{
						collision::getCollisionInstance()->player->setPosition(positionX, 200);
						positionY = 200;
					}

					ballMoving(monster);
					ballMoving(monster2);
					ballMoving(monster3);
					//ballMoving(monster4);



				}


				// Tell GLib we're done rendering sprites
				GLib::Sprites::EndRendering();
				// IMPORTANT: Tell GLib we're done rendering
				GLib::EndRendering();
				collision_pointer->isCollide();

			}


			clock_t endTime = clock();
			if (collision_pointer->isCollide() == true)
			{
				start = clock();
				endTime = clock();
				monster->setPosition(-250, -250);
				monster2->setPosition(-250, 150);
				monster3->setPosition(250, 150);
				monster->setVelocity(Point2D(0, 0));
				monster2->setVelocity(Point2D(0, 0));
				monster3->setVelocity(Point2D(0, 0));
			}
			float timer = (float)(endTime - start);
			if (timer == 2000 || timer == 4000 || timer == 6000 || timer == 8000 || timer == 10000 || timer == 12000 || timer == 14000)
			{
				callRandom(monster);
				callRandom(monster2);
				callRandom(monster3);
				//callRandom(monster4);
			}
			if (timer >= 15000)
			{
				const size_t bufferSize = 65;
				char buffer[bufferSize];
				sprintf_s(buffer, bufferSize, "Congratulation! You Win!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
				OutputDebugStringA(buffer);
				bQuit = true;
			}

		} while (bQuit == false);




		// IMPORTANT:  Tell GLib to shutdown, releasing resources.
		JobSystem::RequestShutdown();
		GLib::Shutdown();
		delete collision_pointer;

	}

}


void ballMoving(SmartPtr<GameObject> input) {
	float positionX = input->getPosition().getX();
	float positionY = input->getPosition().getY();
	if (positionX >= 370)
	{
		input->setPosition(-370, positionY);
		positionX = -370;
	}
	else if (positionX < -370)
	{
		input->setPosition(370, positionY);
		positionX = 370;
	}
	if (positionY <= -300)
	{
		input->setPosition(positionX, 200);
		//positionY = 200;
	}
	else if (positionY > 200)
	{
		input->setPosition(positionX, -300);
		//positionY = -370;
	}

}
void callRandom(SmartPtr<GameObject> input)
{
	int random = rand() % 8 + 1;
	switch (random)
	{
	case 8:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(2, 0));
		break;
	case 1:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(-2, 0));

		break;
	case 2:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(0, 2));

		break;
	case 3:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(0, -2));

		break;
	case 4:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(2, 2));

		break;
	case 5:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(2, -2));

		break;
	case 6:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(-2, 2));

		break;
	case 7:
		input->setVelocity(Point2D(0, 0));
		input->setVelocity(Point2D(-2, -2));
		break;
	}




}



float GetFrameTime() {

	static tick_t lastFrameStartTick = 0;

	float frameTime;

	tick_t currentFrameStartTick = Timing::GetCurrentCounter();

	frameTime = (lastFrameStartTick == 0) ? (1.0f / 60.0f) : (Timing::GetTimeDifferent(currentFrameStartTick, lastFrameStartTick) / 1000.0f);

	lastFrameStartTick = currentFrameStartTick;

	return IsDebuggerPresent() ? (1.0f / 60.0f) : frameTime;
}
