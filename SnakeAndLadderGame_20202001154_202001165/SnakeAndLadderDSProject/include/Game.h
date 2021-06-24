#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

class Game
{
private:
    string name1;
    string name2;

public:
    Game();
    ~Game();
    void get_instruction();
    /**********************************
    1st param index
    2nd moves
    returns the final index of player p
    **********************************/
    int makeAMove(int i, int m);
    void setNames();
    string getName(int); // it takes the player index
    void get_player_turn(int);
};

#endif // GAME_H
