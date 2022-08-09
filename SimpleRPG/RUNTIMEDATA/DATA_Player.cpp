#include "DATA_Player.h"
DATA_Player::DATA_Player()
{
	Swordsman = GameObject("Swordsman",
		"Average level at attack and defend.",
		100,
		20,
		20,
		1);
	ShieldSoldier = GameObject("ShieldSoldier",
		"Great at defend.",
		120,
		12,
		28,
		3);
	Pikemen = GameObject("Pikemen",
		"Great at defend.",
		80,
		28,
		12,
		5);
}

DATA_Player::~DATA_Player()
{
}
