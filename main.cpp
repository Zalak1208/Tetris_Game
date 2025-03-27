#include <iostream>
#include "map.h"
#include "pieces.h"
#include "intro.h"
#include <time.h>
#include <windows.h>
using namespace std;
int height = 20;
int width = 10;

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Hide cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

int main()
{
    hideCursor();
    show_intro();
    show_instructions();
    srand(time(0));
    while (true)
    {
        Map map(height, width);
        map.clear();
        map.run();
    }

    return 0;
}
