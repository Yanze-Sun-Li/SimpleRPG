#pragma once
#include "../DATASTRUCTURE/GameObject.h"
#include <list>
#include <vector>
#include "./DATA_Enemy.h"

class Level
{
public:
	DATA_Enemy enemy;
	std::list<std::vector<GameObject>> Level_One;
	std::list<std::vector<GameObject>> Level_Two;
	std::list<std::vector<GameObject>> Level_Three;

	std::vector<GameObject> Level_One_First;
	std::vector<GameObject> Level_One_Second;
	std::vector<GameObject> Level_One_Third;
	std::vector<GameObject> Level_Two_First;
	std::vector<GameObject> Level_Two_Second;
	std::vector<GameObject> Level_Two_Third;
	std::vector<GameObject> Level_Three_First;
	std::vector<GameObject> Level_Three_Second;
	std::vector<GameObject> Level_Three_Third;
	Level();
};

