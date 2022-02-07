#include "Player.h"
#include <Windows.h>
#include <DirectXColors.h>
#include "Engine/Math/Point2D.h"

using namespace Engine;
GLib::Sprite* Createsprite(const char*);
void* Loadfile(const char*, size_t&);
Player::Player()
{
	pGoodGuy = Createsprite("data\\GoodGuy.dds");

	mass = 10.0f;
	friction = 0.3f;

	up = false;
	down = false;
	left = false;
	right = false;

}

void Player::physic(float dt)
{
	if (up) {
		setVelocity(Point2D(0, 1));

	}
	if (down) {
		setVelocity(Point2D(0, -1));
	}

	if (left) {
		setVelocity(Point2D(-1, 0));

	}
	if (right) {
		setVelocity(Point2D(1, 0));

	}
	if (up && right) {
		setVelocity(Point2D(1, 1));

	}
	if (up && left) {
		setVelocity(Point2D(-1, 1));

	}

	if (down && right) {
		setVelocity(Point2D(1, -1));

	}

	if (down && left) {
		setVelocity(Point2D(-1, -1));

	}

	Point2D currentVelocity = getVelocity();

	Point2D currentPosition = getPosition();

	Point2D drag = currentVelocity * -friction;

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


}
void Player::render() {

	if (pGoodGuy)
	{
		static float			moveDist = .01f;
		static float			moveDir = moveDist;

		static GLib::Point2D	Offset = { -180.0f, -100.0f };

		Offset.x += getPosition().getX();
		Offset.y += getPosition().getY();
		//Offset.x += moveDir;

		// Tell GLib to render this sprite at our calculated location
		GLib::Render(*pGoodGuy, Offset, 0.0f, 0.0f);
		Offset = { 0.0f,0.0f };
	}

}
GLib::Sprite* Createsprite(const char* i_pFilename)
{
	assert(i_pFilename);

	size_t sizeTextureFile = 0;

	// Load the source file (texture data)
	void* pTextureFile = Loadfile(i_pFilename, sizeTextureFile);

	// Ask GLib to create a texture out of the data (assuming it was loaded successfully)
	GLib::Texture* pTexture = pTextureFile ? GLib::CreateTexture(pTextureFile, sizeTextureFile) : nullptr;

	// exit if something didn't work
	// probably need some debug logging in here!!!!
	if (pTextureFile)
		delete[] pTextureFile;

	if (pTexture == nullptr)
		return nullptr;

	unsigned int width = 0;
	unsigned int height = 0;
	unsigned int depth = 0;

	// Get the dimensions of the texture. We'll use this to determine how big it is on screen
	bool result = GLib::GetDimensions(*pTexture, width, height, depth);
	assert(result == true);
	assert((width > 0) && (height > 0));

	// Define the sprite edges
	GLib::SpriteEdges	Edges = { -float(width / 2.0f), float(height), float(width / 2.0f), 0.0f };
	GLib::SpriteUVs	UVs = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f } };
	GLib::RGBA							Color = { 255, 255, 255, 255 };

	// Create the sprite
	GLib::Sprite* pSprite = GLib::CreateSprite(Edges, 0.1f, Color, UVs, pTexture);

	// release our reference on the Texture
	GLib::Release(pTexture);

	return pSprite;
}

void* Loadfile(const char* i_pFilename, size_t& o_sizeFile)
{
	assert(i_pFilename != NULL);

	FILE* pFile = NULL;

	errno_t fopenError = fopen_s(&pFile, i_pFilename, "rb");
	if (fopenError != 0)
		return NULL;

	assert(pFile != NULL);

	int FileIOError = fseek(pFile, 0, SEEK_END);
	assert(FileIOError == 0);

	long FileSize = ftell(pFile);
	assert(FileSize >= 0);

	FileIOError = fseek(pFile, 0, SEEK_SET);
	assert(FileIOError == 0);

	uint8_t* pBuffer = new uint8_t[FileSize];
	assert(pBuffer);

	size_t FileRead = fread(pBuffer, 1, FileSize, pFile);
	assert(FileRead == FileSize);

	fclose(pFile);

	o_sizeFile = FileSize;

	return pBuffer;
}