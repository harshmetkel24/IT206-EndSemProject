#include "Game.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::setNames()
{
    string s1, s2;
    cout << "Enter the name of the First Player : ";
    getline(cin, s1);
    cout << "\n";
    cout << "Enter the name of the Second Player : ";
    getline(cin, s2);

    cout << "\n";

    name1 = s1;
    name2 = s2;
}


void Game::get_player_turn(int k)
{
	cout << "Turn of : "<<getName(k)<<"\n";
	return;
}

string Game::getName(int ind)
{
    if (ind == 1)
    {
        return name1;
    }
    else
    {
        return name2;
    }
}

void Game::get_instruction()
{
	cout << "SET OF RULES and GENERAL INSTRUCTIONS:\n\n";
	cout << "\tRULES:\n\n";
	cout << "\t\t->Whenever any of player visits the Cell, consisting of snake mouth, then that player will be degraded to Cell containing tail of that snake.\n";
	cout << "\t\t->In the similar manner, whenever any player visits the cell, containing ladder start, then that player will be promoted to cell containing ladder end of that particular Ladder.\n";
    cout << "\tINSTRUCTIONS:\n\n";
	cout << "\t\t->This is Snake And Ladder Game for two player.\n\t\t->Here there are total of 100 cells, and in each cell is NUMBER denoting the position of Cell.\n\t\t->Here snake mouth is  defined  as SIS, also SIE stand for snake tail where I stands for the Snake number.\n\t\t->For ladders, Ladder start is defined as LIS Ladder start position and LIE as Ladder end position, here also I stands for Ladder number.\n\n";
	return;
}

int Game::makeAMove(int i, int m)
{
    return i + m;
}
