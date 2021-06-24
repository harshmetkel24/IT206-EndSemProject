#ifndef BOARDDATATABLE_H
#define BOARDDATATABLE_H
#include <iostream>

using namespace std;

class Cell
{
public:
    int index;
    int snakeHead;
    int snakeTail;
    int ladderStart;
    int ladderEnd;
    Cell()
    {
        snakeHead = snakeTail = ladderEnd = ladderStart = -1;
    }
};

class BoardDataTable:private Cell
{
    private:        Cell* table;
        /******************************************************
        Member Functions to assign the head-tails informations
        ******************************************************/
        void addSnakeHead(int); // here int param represents index value.
        void addSnakeTail(int, int);    // here first param shows index and second given the index of tail of corresponding snake.
        void addLadderStart(int); // here int param represents index value.
        void addLadderEnd(int, int);    // here first param shows index and second given the index of end of corresponding ladder.

    public:
        BoardDataTable();
        virtual ~BoardDataTable();
        void CreateTable(int level);
        void DisplayTableInformation();
        int getSnakeTail(int i);
        int getLadderEnd(int i);
};

#endif // BOARDDATATABLE_H
