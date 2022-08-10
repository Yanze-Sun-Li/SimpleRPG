#include "DATA_Player.h"
DATA_Player::DATA_Player()
{
	Swordsman = GameObject("Swordsman",
		"Average attack and defend.",
		25,
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
		15,
		17,
		3,
		5);
}

DATA_Player::~DATA_Player()
{
}
