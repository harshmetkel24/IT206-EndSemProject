#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <time.h>

using namespace std;

class Dice
{
    private:        int n;

    public:
        Dice();
        ~Dice();
        int randomRoll();
};

#endif // DICE_H
