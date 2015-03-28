#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.
int screenSize()//int argc, char* argv[]
{
    //change the screen size
    system("mode 80,38");

    // Change the window title:
    SetConsoleTitle("TIC TAC TOE - Team Alpha");

     PlaySound((LPCSTR) "mario.wav", NULL, SND_FILENAME | SND_ASYNC);
    //getchar();
    // Exit
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
