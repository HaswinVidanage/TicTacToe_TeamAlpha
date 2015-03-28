#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>



HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.
int screenSize()
{

    //change the screen size
    system("mode 80,40");

    // Change the window title:
    SetConsoleTitle("TIC TAC TOE - Team Alpha");

    PlaySound((LPCSTR) "mario.wav", NULL, SND_FILENAME | SND_ASYNC);

    return 0;
}

//AUDIO

void audioMain()
{
    system("cls");
    PlaySound((LPCSTR) "mario.wav", NULL, SND_FILENAME | SND_ASYNC);
    getchar();
}

void audioOnClick()
{

    PlaySound((LPCSTR) "beep.wav", NULL, SND_FILENAME | SND_ASYNC);

}

void audioCredits()
{

    PlaySound((LPCSTR) "credits.wav", NULL, SND_FILENAME | SND_ASYNC);
    getchar();

}

void audioOnError()
{

    PlaySound((LPCSTR) "error.wav", NULL, SND_FILENAME | SND_ASYNC);


}

void audioOnWin()
{
    PlaySound((LPCSTR) "gameWin.wav", NULL, SND_FILENAME | SND_ASYNC);

}

void audioOnOver()
{
    PlaySound((LPCSTR) "gameOver.wav", NULL, SND_FILENAME | SND_ASYNC);

}
