#include "Random.h"

Random::Random()
{
    srand(time(NULL));
}

int Random::random(int maxi)
{
    return rand() % maxi;
}
