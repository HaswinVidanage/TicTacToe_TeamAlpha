#include <stdio.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include <mmsystem.h>



void initCurses();
void drawboard();
void initBoard(int *);
int playGame(char *word1,char *word2);
int updateBoardData(int *,int,int,int);
int checkWin(int *);

char player1[10],player2[10];


