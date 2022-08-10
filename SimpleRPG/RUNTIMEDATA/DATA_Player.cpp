#include "DATA_Player.h"
DATA_Player::DATA_Player()
{
	Swordsman = GameObject("Swordsman",
		"Average attack and defend.",
		30,
		15,
		8,
		1);
	ShieldSoldier = GameObject("ShieldSoldier",
		"Great at defend.",
		40,
		8,
		8,
		3);
	Pikemen = GameObject("Pikemen",
		"Great at defend.",
		20,
		17,
		5,
		5);
}

DATA_Player::~DATA_Player()
{
}
