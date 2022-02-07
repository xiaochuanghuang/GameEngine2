#include "GameObjectJSON.h"
#include "collision.h"
using namespace std;
namespace Engine {
	void* Loadfile(const char* i_pFilename, size_t& o_sizeFile);
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
	vector<uint8_t> LoadFile(const std::string& i_Filename){
	vector<uint8_t> Contents;
	if (!i_Filename.empty())
	{
		FILE* pFile = nullptr;

		errno_t fopenError = fopen_s(&pFile, i_Filename.c_str(), "rb");
		if (fopenError == 0)
		{
			assert(pFile != nullptr);

			int FileIOError = fseek(pFile, 0, SEEK_END);
			assert(FileIOError == 0);

			long FileSize = ftell(pFile);
			assert(FileSize >= 0);

			FileIOError = fseek(pFile, 0, SEEK_SET);
			assert(FileIOError == 0);

			Contents.reserve(FileSize);
			Contents.resize(FileSize);

			size_t FileRead = fread(&Contents[0], 1, FileSize, pFile);
			assert(FileRead == FileSize);

			fclose(pFile);
		}
	}

	return Contents;
}


	SmartPtr<GameObject> CreateGameObjectFromJSON(nlohmann::json& i_JSONData)
	{
		using json = nlohmann::json;

		Point2D GOInitialPosition = Point2D(0.0f, 0.0f);
		string GOName = "unknown";
		SmartPtr<GameObject> NewGameObject;
		
	
	
		NewGameObject = GameObject::CreateObject(GOName, GOInitialPosition);
		if (i_JSONData.contains("renderable"))
		{
			std::string sprite = i_JSONData["renderable"]["sprite"];
			NewGameObject->pGoodGuy = Createsprite(sprite.c_str());
		
		}
		if (i_JSONData.contains("name"))
		{
			std::string current_name = i_JSONData["name"];
			NewGameObject->name = current_name;


		}
		if (i_JSONData.contains("initial_position"))
		{
			float PositionX = i_JSONData["initial_position"]["PositionX"];
			float PositionY = i_JSONData["initial_position"]["PositionY"];
			/*assert(Position["PositionX"].is_number()&&Position["PositionY"].is_number());
			Point2D ObjectionPosition = Point2D(Position["PositionX"], Position["PositionY"]);*/
			NewGameObject->setPosition(PositionX, PositionY);
		}
		if (i_JSONData.contains("mass"))
		{
			float current_mass = i_JSONData["mass"];
			NewGameObject->mass = current_mass;

		}

		return NewGameObject;
	}


	SmartPtr<GameObject> CreatGameObject(const string& i_JSONFileName)
	{
		
		SmartPtr<GameObject> NewObject;

		vector<uint8_t> Contents = LoadFile(i_JSONFileName);
		
		if (!Contents.empty())
		{

			nlohmann::json JSON = nlohmann::json::parse(Contents);
			NewObject = CreateGameObjectFromJSON(JSON);
		}
		collision::getCollisionInstance()->world_object.push_back(NewObject.mptr);
		collision::getCollisionInstance()->counters.push_back(NewObject.count);
	
		return NewObject;

		

	}




}