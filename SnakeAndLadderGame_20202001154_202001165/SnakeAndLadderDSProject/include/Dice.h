#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <time.h>

using namespace std;

class Dice
{
    private:

    public:
        Dice();
        ~Dice();
        int randomRoll();
};

#endif // DICE_H