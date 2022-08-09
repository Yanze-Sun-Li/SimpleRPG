#include "Level.h"

Level::Level()
{
	enemy = DATA_Enemy();

	Level_One = std::list<std::vector<GameObject>>();
	Level_Two = std::list<std::vector<GameObject>>();
	Level_Three = std::list<std::vector<GameObject>>();

	Level_One_First = std::vector<GameObject>();
	Level_One_Second = std::vector<GameObject>();
	Level_One_Third = std::vector<GameObject>();

	Level_Two_First = std::vector<GameObject>();
	Level_Two_Second = std::vector<GameObject>();
	Level_Two_Third = std::vector<GameObject>();

	Level_Three_First = std::vector<GameObject>();
	Level_Three_Second = std::vector<GameObject>();
	Level_Three_Third = std::vector<GameObject>();

	Level_One_First.push_back(enemy.Slime);
	Level_One_First.push_back(enemy.Slime);
	Level_One_First.push_back(enemy.Slime);

	Level_One_Second.push_back(enemy.Slime);
	Level_One_Second.push_back(enemy.Goblins);
	Level_One_Second.push_back(enemy.Slime);

	Level_One_Third.push_back(enemy.Goblins);
	Level_One_Third.push_back(enemy.GreyWolf);
	Level_One_Third.push_back(enemy.Goblins);

	Level_One.push_back(Level_One_First);
	Level_One.push_back(Level_One_Second);
	Level_One.push_back(Level_One_Third);



	Level_Two_First.push_back(enemy.GreyWolf);
	Level_Two_First.push_back(enemy.GreyWolf);
	Level_Two_First.push_back(enemy.GreyWolf);
		 
	Level_Two_Second.push_back(enemy.LittleDevil);
	Level_Two_Second.push_back(enemy.Viper);
	Level_Two_Second.push_back(enemy.GreyWolf);
		  
	Level_Two_Third.push_back(enemy.Viper);
	Level_Two_Third.push_back(enemy.Boar);
	Level_Two_Third.push_back(enemy.LittleDevil);
	
		
	Level_Two.push_back(Level_Two_First);
	Level_Two.push_back(Level_Two_Second);
	Level_Two.push_back(Level_Two_Third);




	Level_Three_First.push_back(enemy.LittleDevil);
	Level_Three_First.push_back(enemy.Boar);
	Level_Three_First.push_back(enemy.LittleDevil);

	Level_Three_Third.push_back(enemy.Boar);
	Level_Three_Third.push_back(enemy.Tauren);
	Level_Three_Third.push_back(enemy.Boar);


	Level_Three_Second.push_back(enemy.GreyWolf);
	Level_Three_Second.push_back(enemy.Vampire);
	Level_Three_Second.push_back(enemy.GreyWolf);


	Level_Three.push_back(Level_Three_First);
	Level_Three.push_back(Level_Three_Second);
	Level_Three.push_back(Level_Three_Third);








}
