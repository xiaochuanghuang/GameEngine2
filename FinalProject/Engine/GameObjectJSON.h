#pragma once
#include "json.hpp"
#include "GameObject.h"
#include "SmartPtr.h"
#include <string>
#include <stdint.h>

class GameObjectJSON
{

	vector<uint8_t> LoadFile(const std::string& i_Filename);
};

