#include "Dice.h"

Dice::Dice()
{

}

Dice::~Dice()
{

}

int Dice::randomRoll()
{
    int rnd;
    for(int i=0; i<10; i++)
    {
        srand(time(0));
        rnd = 1+rand()%6;
    }
    return rnd;
}
