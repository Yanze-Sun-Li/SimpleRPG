#include "DATA_Enemy.h"

DATA_Enemy::DATA_Enemy()
{
 Slime = GameObject("Slime", 
		"Soft and harmless.", 
		10,
		5, 
		0, 
		1);
 Goblins = GameObject("Goblins",
		"Eat everything.",
		25,
		7,
		5,
		3);
GreyWolf = GameObject("Grey wolf",
		"Big wolf!",
		50,
		15,
		2,
		5);
Viper = GameObject("Viper",
		"Posion! Dangerous!",
		15,
		50,
		1,
		10);
Boar = GameObject("Boar",
		"Pig, but can kill you!",
		100,
		20,
		10,
		1);
LittleDevil = GameObject("Little Devil",
		"Envy and annoy.",
		52,
		15,
		5,
		10);

Vampire = GameObject("Vampire",
		"Want blood!",
		100,
		50,
		20,
		15);
Tauren = GameObject("Tauren",
		"He use you as an axe.",
		250,
		35,
		20,
		5);

}

DATA_Enemy::~DATA_Enemy()
{
}
