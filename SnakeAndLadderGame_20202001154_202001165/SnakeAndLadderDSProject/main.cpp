#include <iostream>
#include <time.h>
#include "BoardDataTable.h"
#include "Board.h"
#include "Dice.h"
#include "Game.h"

int main()
{
    cout << "\t\t\t\t\t\t\t\t\t****************************************************\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t\tWELCOME                                     \n";
    cout << "\t\t\t\t\t\t\t\t\t****************************************************\n";

    Game G;
    G.get_instruction();
    cout << "GAME STARTING...\n\n";
    BoardDataTable t;
    cout << "Please select level, by pressing corresponding number:)\n\t1. LEVEL-1\n\t2. LEVEL-2\n\t3. LEVEL-3\n\n";
    int level;
    cin >> level;
    getchar();
    t.CreateTable(level);
    Board b;
    Dice d;

    int f = 1;
    int idx1 = 1, idx2 = 1;

    G.setNames();
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t starttime, endtime;
    time(&starttime);
    while (1)
    {
    	int move = d.randomRoll();

        int flag = 0;
    	if( idx1 >= 95 && f == 1 )
        {
            int temp = 100 - idx1;
            if(move <= temp) idx1 += move;
            else move = 0;
            if(idx1 == 100)
            {
                b.DisplayBoard(level);
                G.get_player_turn(f);
                cout << "\n\n" << G.getName(f) << " scored on the Dice: " << endl ;
                b.showDie(move);
                cout << endl;

                cout << "PLAYER 1 : " << G.getName(1) << "\n";
                cout << "PLAYER 2 : " << G.getName(2) << "\n";

                cout << "\n";
                cout << G.getName(1) << " is at index : " << idx1 << "\n";
                cout << G.getName(2) << " is at index : " << idx2 << "\n";
                cout << "Congrats!!\n" << G.getName(1) << " you won the Game.\n";
                break;
            }
            if(flag == 1)continue;
            if(move == 0)
            {
                f  =2;
//                cout << "Sorry " << G.getName(1) << " bad luck :((\nFor now you cannot make a move. Please try in next turn.\n";
                continue;

            }
        }
        if(idx2>=95 && f == 2)
        {
            int temp = 100 - idx2;
            move = move%temp;
            idx2 += move;
            if(idx2 == 100)
            {
                b.DisplayBoard(level);
                G.get_player_turn(f);
                cout << "\n\n" << G.getName(f) << " scored on the Dice: " << endl ;
                b.showDie(move);
                cout << endl;

                cout << "PLAYER 1 : " << G.getName(1) << "\n";
                cout << "PLAYER 2 : " << G.getName(2) << "\n";

                cout << "\n";
                cout << G.getName(1) << " is at index : " << idx1 << "\n";
                cout << G.getName(2) << " is at index : " << idx2 << "\n";
                cout << "Congrats!!\n" << G.getName(1) << " you won the Game.\n";
                break;
            }
            if(flag == 1)continue;
            if(move == 0)
            {
                f = 1;
//                cout << "Sorry " << G.getName(2) << " bad luck :((\nFor now you cannot make a move. Please try in next turn.\n";
                continue;
            }
        }

        b.DisplayBoard(level);
    	G.get_player_turn(f);
		cout << "\n\n" << G.getName(f) << " scored on the Dice: " << endl ;
		b.showDie(move);
		cout << endl;

        cout << "PLAYER 1 : " << G.getName(1) << "\n";
        cout << "PLAYER 2 : " << G.getName(2) << "\n";

        cout << "\n";
        cout << G.getName(1) << " is at index : " << idx1 << "\n";
        cout << G.getName(2) << " is at index : " << idx2 << "\n";

        cout << "Please press ANY KEY to roll the dice: :)\n\n";
        getchar();

        if (f == 1) // p;ayer X logic
        {
            idx1 += move;
            b.updateBoard(1, idx1);
            b.DisplayBoard(level);
            if (t.getSnakeTail(idx1) != -1)
            {
                idx1 = t.getSnakeTail(idx1);
                b.updateBoard(1, idx1);
                b.DisplayBoard(level);
                cout << "\n";
                cout << "Player : " << G.getName(1) << " got the Snake :((\n";
                cout<< "\n";
                f = 2;
            }
            else
            {
                f = 2;
            }
            if (t.getLadderEnd(idx1) != -1)
            {
                idx1 = t.getLadderEnd(idx1);
                b.updateBoard(1, idx1);
                b.DisplayBoard(level);
                cout << "\nPlayer : " << G.getName(1) << " got the The ladder :))\n";
                f = 2;
            }
            if (move == 6)
            {
                f = 1;
            }
            else
                f = 2;
        }
        else // player 2 logic
        {
            idx2 += move;
            b.updateBoard(2, idx2);
            b.DisplayBoard(level);
            if (t.getSnakeTail(idx2) != -1)
            {
                idx2 = t.getSnakeTail(idx2);
                b.updateBoard(2, idx2);
                b.DisplayBoard(level);
                cout << "\nPlayer : " << G.getName(2) << " got the Snake :((\n";
                if(t.getSnakeTail(idx2)!=-1)
				f = 1;
            }
            else
            {
                f = 1;
            }
            if (t.getLadderEnd(idx2) != -1)
            {
                idx2 = t.getLadderEnd(idx2);
                b.updateBoard(2, idx2);
                b.DisplayBoard(level);
                cout << "\nPlayer : " << G.getName(2) << " got the Ladder :((\n";
                f = 1;
            }
            if (move == 6)
            {
                f = 2;
            }
            else
                f = 1;
        }
    }
        time(&endtime);

        double timeTaken = double(endtime - starttime);
        cout << "\n\n\tThe game took " << timeTaken << "s to conclude. \n";
    return 0;
}
