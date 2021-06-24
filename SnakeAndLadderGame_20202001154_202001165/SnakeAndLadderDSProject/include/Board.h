#ifndef BOARD_H
#define BOARD_H
#include <iostream>

using namespace std;

class Board
{
    private:        char X[101], Y[101];

    public:
        Board();
        virtual ~Board();
        void DisplayBoard();
        /****************************
        first param gives the player number. i.e., 1 for X and 2 for Y
        and second param gives the index at which updation is to be done
        ****************************/
        void updateBoard(int, int);
        void showDie(int); // will take number on die as parameter

        /******************************************
        Testing code for LEVEL implementation
        ******************************************/
        void DisplayBoard(int level);
};

#endif // BOARD_H
