#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include <mmsystem.h>
#include "TicTacToe.h"
#include "ttt.h"

//char player1[10],player2[10];
void clearscreen()
{
    system("cls");
}

void playerStat(char *p1)
{
    printf("%s",p1);
    return p1;
}


void initCurses()
{
    initscr();
    cbreak ();
    noecho();
    //keypad();
    keypad(stdscr,TRUE);
}

/*************************************************************
Function : drawboard
Purpose : draws and refreshes grid
*************************************************************/

void drawboard()
{

    int i;
    int h;

    for(i=2;i<9;i++)
    {

         mvaddch(i,32,'|');
         mvaddch(i,36,'|');
         mvaddch(i,40,'|');
         mvaddch(i,44,'|');


        if (i%2 ==0)//(i%4 square becomes big)
        {
            for(h=32;h<=44;h++)
            {

                mvaddch(i,h,'_');
            }

        }
       move(1,2);



    }
    refresh();


}

/*************************************************************
Function : initboard
Purpose : fills the ARRAY BOARD DATA SO THAT WE CAN RESTART THE GAME IF SOMEONE WINS
*************************************************************/

void initBoard(int *boardData)
{
    int i;
    for(i=0;i<=8;i++)
    {
        boardData[i] = i+2;
    }
}

/*************************************************************
Function : playgame
Purpose :  allows the user to move the arrow keys and  place a marker.
*************************************************************/

int playGame(char *p1,char *p2)
{
    int boardData[9];
    int playerNum = 1;
    int inputChar;
    int x=34,y=3;//x=2,y=1;
    int didWin = 0;
    int canWeMove = 0;
    int nMoves = 0;

    initBoard(boardData);

    mvprintw(14,0,"%s's turn to place and (X)                       ",p1);
    move(y,x);
    refresh();

    while (inputChar !='q')
    {

        if(nMoves == 9)
        {


            audioOnOver();
            Draw();
            inputChar = getch();
            erase();
            drawboard();
            return 3;
        }
        inputChar = getch();

        /* If they arent placing a marker they are moving */

        if (inputChar !=' ')
        {

            switch(inputChar)
            {
                 case KEY_UP:
                    if(y==5 || y==7)
                    {
                        move(y=y-2,x);
                    }
                    break;
                case KEY_DOWN:
                    if(y==3 || y==5)
                    {
                        move(y=y+2,x);
                    }
                    break;
                case KEY_LEFT:
                    if(x==42 || x==38)
                    {
                        move(y,x=x-4);
                    }
                    break;
                case KEY_RIGHT:
                    if(x==34 || x==38)
                    {
                        move(y,x=x+4);
                    }
                    break;
              }

            }
            else if(playerNum==1 && inputChar == ' ')
            {
                getyx(stdscr,y,x);

                canWeMove = updateBoardData(boardData,x,y,1);

                if(canWeMove==5)
                {
                    audioOnClick();
                    mvaddch(y,x,'X');
                    didWin = checkWin(boardData);
                    //didWin is a function that checks for winnning scenarios .It returns 1 if the last move caused a win to occur//

                    if (didWin == 1)
                    {

                        play1Win();

                        int i=0;

                        audioOnWin();
                         for(i=0;i<250;i++)
                         {

                            system("COLOR 4C");

                            system("COLOR BC");

                            system("COLOR FC");

                         }

                        mvprintw(31,0,"\t\t\t\t\t\t\t %s Wins !",p1);

                        playAgain:

                        mvprintw(33,0,"Play Again ?(Y/N)                            ");
                        inputChar=getch();

                        switch(inputChar)
                        {
                         case 'Y':
                            {

                                break;
                            }
                        case 'y':
                            {

                                break;
                            }

                        case'N':
                            {

                            system("cls");
                            audioOnOver();
                            gameOver();
                            getch();
                            exit(1);

                            break;
                            }
                        case'n':
                            {

                            system("cls");
                            audioOnOver();
                            gameOver();
                            getch();
                            exit(1);

                            break;
                            }
                        default:
                            {
                                goto playAgain;

                            }

                        }


                        erase();
                        drawboard();
                        return 3;

                    }
                    nMoves = nMoves +1;

                    //if player 1 has moved and did not win, it must be player 2's turn

                playerNum = 2;
                mvprintw(14,0,"%s's turn to place an (O)                ",p2);
                move (y,x);
                refresh();
                }

            }
            else if (playerNum == 2 && inputChar == ' ')
            {
                audioOnError();
                getyx(stdscr,y,x);

                canWeMove = updateBoardData(boardData,x,y,0);


                if (canWeMove ==5)
                {
                    audioOnClick();
                    mvaddch(y,x,'O');// not clear if O or 0

                    didWin = checkWin(boardData);

                    if(didWin == 1)
                    {
                        play2Win();

                        int i=0;

                        audioOnWin();

                         for(i=0;i<250;i++)
                         {

                            system("COLOR 4C");

                            system("COLOR BC");

                            system("COLOR FC");

                         }

                        mvprintw(31,0,"\t\t\t\t\t\t\t %s Wins !",p2);

                        playAgain2:


                        mvprintw(33,0,"Play Again ?(Y/N)                                ");
                        inputChar=getch();


                        switch(inputChar)
                        {
                         case 'Y':
                            {

                                break;
                            }
                        case 'y':
                            {
                                break;
                            }

                        case'N':
                            {

                            system("cls");
                            audioOnOver();
                            gameOver();
                            getch();
                            exit(1);

                            break;
                            }
                        case'n':
                            {

                            system("cls");
                            audioOnOver();
                            gameOver();
                            getch();
                            exit(1);


                            break;
                            }

                        default:
                            {

                                goto playAgain2;

                            }

                        }


                        erase();
                        drawboard();
                        return 3;
                    }
                    nMoves = nMoves +1;

                    playerNum = 1;
                    mvprintw(14,0,"%s's turn to place an (X)                  ",p1);
                    move(y,x);
                    refresh();

                }
            }
            refresh();


        }


        system("cls");
        gameOver();
        getch();
        return 0;
        endwin();


}

/*******************************************************************************************
FUNCTION : updateBoardData

PUPORSE  : update the board data  and to match.

********************************************************************************************/

int updateBoardData(int *boardData,int x,int y,int XorO)
        {

            if((y == 3 && x == 34)&& (boardData[0] !=1 && boardData[0] != 0 ))
            {
                boardData[0] = XorO;
                return 5;
            }
            if((y == 3 && x == 38)&& (boardData[1] != 1 && boardData[1] != 0))
            {
                boardData[1] = XorO;
                return 5;
            }

            if((y == 3 && x == 42)&& (boardData[2] != 1 && boardData[2] != 0))
            {
                boardData[2] = XorO;
                return 5;
            }
            if((y == 5 && x == 34)&& (boardData[3] != 1 && boardData[3] != 0))
            {
                boardData[3] = XorO;
                return 5;
            }
            if((y == 5 && x == 38)&& (boardData[4] != 1&& boardData[4] != 0))
            {
                boardData[4] = XorO;
                return 5;
            }
            if((y == 5 && x == 42)&& (boardData[5] != 1&& boardData[5] != 0))
            {
                boardData[5] = XorO;
                return 5;
            }
            if((y == 7 && x == 34)&& (boardData[6] != 1&& boardData[6] != 0))
            {
                boardData[6] = XorO;
                return 5;
            }
            if((y == 7 && x == 38)&& (boardData[7] != 1&& boardData[7] != 0))
            {
                boardData[7] = XorO;
                return 5;
            }
            if((y == 7 && x == 42)&& (boardData[8] != 1&& boardData[8] != 0))
            {
                boardData[8] = XorO;
                return 5;
            }
            else {return 0;
            }


}
/********************************************************************************************
FUNCTION : checkWin
PURPOSE  : Looks for all possible winning scenarios

*********************************************************************************************/

int checkWin(int *boardData)
{
    if ((boardData[0]==boardData[1]) && (boardData[1] == boardData[2])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[3]==boardData[4]) && (boardData[4] == boardData[5])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[6]==boardData[7]) && (boardData[7] == boardData[8])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[0]==boardData[3]) && (boardData[3] == boardData[6])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[1]==boardData[4]) && (boardData[4] == boardData[7])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[2]==boardData[5]) && (boardData[5] == boardData[8])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[0]==boardData[4]) && (boardData[4] == boardData[8])){/*checking rows for a win*/
        return 1;
    }
    if ((boardData[2]==boardData[4]) && (boardData[4] == boardData[6])){/*checking rows for a win*/
        return 1;
    }
    else{return 0;
    }
}





