#include "BoardDataTable.h"

BoardDataTable::BoardDataTable()
{
    table = new Cell[101];
}

BoardDataTable::~BoardDataTable()
{
    delete table;
}

void BoardDataTable::addSnakeHead(int i)
{
    table[i].snakeHead = i;
    return;
}

void BoardDataTable::addSnakeTail(int i, int p)
{
    table[i].snakeTail = p;
    return;
}

void BoardDataTable::addLadderStart(int i)
{
    table[i].ladderStart = i;
    return;
}

void BoardDataTable::addLadderEnd(int i, int p)
{
    table[i].ladderEnd = p;
    return;
}

/*************************************
        IMPROVE THIS FURTHER
*************************************/

void BoardDataTable::CreateTable(int level)
{
    if(level == 1)
    {
        // Adding all heads of sankes;
        addSnakeHead(25);
        addSnakeHead(46);
        addSnakeHead(74);
        addSnakeHead(88);

        // Adding all tails of snakes:
        addSnakeTail(25, 65);
        addSnakeTail(46, 12);
        addSnakeTail(74, 52);
        addSnakeTail(88, 76);

        // Adding all starts of ladders:
        addLadderStart(19);
        addLadderStart(32);
        addLadderStart(61);
        addLadderStart(73);

        // Adding all ends of ladders:
        addLadderEnd(19, 66);
        addLadderEnd(32, 53);
        addLadderEnd(61, 100);
        addLadderEnd(73, 91);
    }
    else if(level == 2)
    {
        // Adding all heads of sankes;
        addSnakeHead(17);
        addSnakeHead(54);
        addSnakeHead(62);
        addSnakeHead(64);
        addSnakeHead(87);
        addSnakeHead(93);
        addSnakeHead(95);
        addSnakeHead(98);

        // Adding all tails of snakes:
        addSnakeTail(17, 7);
        addSnakeTail(54, 34);
        addSnakeTail(62, 19);
        addSnakeTail(64, 60);
        addSnakeTail(87, 36);
        addSnakeTail(93, 73);
        addSnakeTail(95, 75);
        addSnakeTail(98, 79);

        // Adding all starts of ladders:
        addLadderStart(4);
        addLadderStart(9);
        addLadderStart(21);
        addLadderStart(28);
        addLadderStart(51);
        addLadderStart(72);
        addLadderStart(80);

        // Adding all ends of ladders:
        addLadderEnd(4 , 14);
        addLadderEnd(9, 31);
        addLadderEnd(21, 42);
        addLadderEnd(28, 84);
        addLadderEnd(51, 67);
        addLadderEnd(72, 91);
        addLadderEnd(80, 99);
    }
    else if(level == 3)
    {
        // Adding all heads of sankes;
        addSnakeHead(48);
        addSnakeHead(52);
        addSnakeHead(57);
        addSnakeHead(64);
        addSnakeHead(68);
        addSnakeHead(84);
        addSnakeHead(88);
        addSnakeHead(93);
        addSnakeHead(98);

        // Adding all tails of snakes:
        addSnakeTail(48, 9);
        addSnakeTail(52, 11);
        addSnakeTail(57, 17);
        addSnakeTail(64, 24);
        addSnakeTail(68, 35);
        addSnakeTail(84, 21);
        addSnakeTail(88, 51);
        addSnakeTail(93, 37);
        addSnakeTail(98, 13);

        // Adding all starts of ladders:
        addLadderStart(8);
        addLadderStart(19);
        addLadderStart(21);
        addLadderStart(28);
        addLadderStart(50);
        addLadderStart(61);
        addLadderStart(66);
        addLadderStart(77);

        // Adding all ends of ladders:
        addLadderEnd(8, 26);
        addLadderEnd(19, 38);
        addLadderEnd(21, 79);
        addLadderEnd(28, 49);
        addLadderEnd(50, 91);
        addLadderEnd(61, 99);
        addLadderEnd(66, 87);
        addLadderEnd(77, 96);
    }
    return;
}

void BoardDataTable::DisplayTableInformation()
{
    for(int i=1; i<101; i++)
    {
        if(table[i].snakeHead == -1 && table[i].ladderStart == -1)
            continue;
        else if(table[i].snakeHead != -1)
        {
            cout << "Snake mouth at index: " << table[i].index << " which will lead the player to index: " << table[i].snakeTail << ".\n";
        }
        else if(table[i].ladderStart != -1)
        {
            cout << "Ladder start at index: " << table[i].index << " which will lead the player to index: " << table[i].ladderEnd << ".\n";
        }
    }
    return;
}

int BoardDataTable::getSnakeTail(int idx)
{
    int f=-1;
    if(table[idx].snakeHead != -1)
    {
        f = table[idx].snakeTail;
    }
    return f;
}

int BoardDataTable::getLadderEnd(int idx)
{
    int f = -1;
    if(table[idx].ladderStart != -1) f = table[idx].ladderEnd;
    return f;
}


