#include <stdio.h>
#include <curses.h>     // gives control of curser in console
#include <panel.h>      // gives control of curser in console
#include <windows.h>
#include <mmsystem.h>   // Allows us to play wav files in console without any externl music player
#include "TicTacToe.h"
#include "ttt.h"



void creditAnim();
void mainAnim();
void playerStat(char *word);
void playAgainFunc();
void audioMain();
void audioOnClick();
void playLogic();
void HowToPlay();


 char player1[10],player2[10];


int main()
{

  screenSize();                   /**Purpose : Sets screen size of the console to fixed and no scroll bar **/



  int i=0;

/**Purpose : Initial Screen Flicks and Anumations **/

        for (i=0;i<=100;i++)
        {
            system("cls");
            mainAnim();

        }
/**Function : Home Screen Menu **/

        int choice=0;

        printf("\n\n\t\t\t1.Start");
        printf("\n\n\t\t\t2.How To Play");
        printf("\n\n\t\t\t3.Credits");
        printf("\n\n\t\t\t4.Exit\t\t\t\t\t(Sounds:ON )\n\t\t\t\t:");
        scanf("%d",&choice);
        audioOnClick();

        switch(choice)
        {

        case 1:
            {
                printf("\t\tName of Player 1 ( X ) :");
                scanf("%s",&player1);

                printf("\t\tName of Player 2 ( O ) :");
                scanf("%s",&player2);

                audioOnClick();


                goto GameOn;
                break;
            }
        case 2:
            {
                system("cls");
                audioCredits();
                //printf("Tips to play this game");
                HowToPlay();
                getchar();           /*Function  : Returns back to main   */
                main();

            }

        case 3:
            {
                int i=0;
                audioCredits();        /*Function : Plays a wav file designated for Credits */


                for (i=0;i<=250;i++)  /*Function : Animations, Color Changing and Screen Flicks for Credits */
                  {creditAnim();}


                audioCredits();
                getchar();           /*Function  : Returns back to main   */
                main();

                break;
            }

        case 4:
            {
                exit(1);
            }

        default:
            {
               getchar();          /*Function  : Error Handling  */
               main();
               break;
            }
        }

GameOn:

    playLogic();



    return (0);

}


/**Purpose : Basic Initializations needed to game to work **/

void playLogic()
{
    int keepPlaying;
        do
                {

                    initCurses();
                    drawboard();
                    playGame(player1,player2);

                    keepPlaying = playGame(player1,player2);



                } while(keepPlaying == 3);
                endwin();
}

void HowToPlay()
{
    printf("\n\n\n\n================================================================================\n");
    printf("================================HOW TO PLAY=====================================\n");
    printf("INTRODUCTION\n");
    printf("\n\n  Tic-tac-toe (or Noughts and crosses, Xs and Os) is a game for two players,\n  X and O, who take turns marking the spaces in a 3 by 3 grid.\n\n  The player who succeeds in placing three respective marks in a horizontal,\n  vertical, or diagonal row wins the game.");
    printf("\n\n\n\nCONTROLS\n");
    printf("\n\n  Select a Box using the Arrow Keys and Press Spacebar to mark that Box\n\n\n\n\n\n");
    printf("================================================================================\n");
    printf("================================================================================\n");
    printf("\npress any key to continue\n");



}

