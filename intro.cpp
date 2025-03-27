#include "intro.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void set(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position);
}

void show_intro()
{
    int a = 1;
    string intro = R"(
$$$$$$$$\         $$\               $$\                                   $$\
\__$$  __|        $$ |              \__|                                  \__|  
   $$ | $$$$$$\ $$$$$$\    $$$$$$\  $$\ $$$$$$\$$$$\   $$$$$$\  $$$$$$$\  $$\  $$$$$$\
   $$ |$$  __$$\\_$$  _|  $$  __$$\ $$ |$$  _$$  _$$\  \____$$\ $$  __$$\ $$ | \____$$\
   $$ |$$$$$$$$ | $$ |    $$ |  \__|$$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ |$$ | $$$$$$$ |
   $$ |$$   ____| $$ |$$\ $$ |      $$ |$$ | $$ | $$ |$$  __$$ |$$ |  $$ |$$ |$$  __$$ |
   $$ |\$$$$$$$\  \$$$$  |$$ |      $$ |$$ | $$ | $$ |\$$$$$$$ |$$ |  $$ |$$ |\$$$$$$$ |
   \__| \_______|  \____/ \__|      \__|\__| \__| \__| \_______|\__|  \__|\__| \_______|
)";
    cout << "\033[2J\033[H";
    while (!_kbhit())
    {
        set(3, 10);
        cout << intro << endl;
        a % 50 > 24 ? cout << "                              Press any key to continue..." << endl : cout << "                                                             " << endl;
        Sleep(10);
        a++;
    }
    char ch = _getch();
    Sleep(100);
    cout<<"\033[2J\033[H";
}

bool show_exit()
{
    int a = 1;
    string intro = R"(
    ______    ______   __       __  ________         ______   __     __  ________  _______
    /      \  /      \ |  \     /  \|        \       /      \ |  \   |  \|        \|       \
   |  $$$$$$\|  $$$$$$\| $$\   /  $$| $$$$$$$$      |  $$$$$$\| $$   | $$| $$$$$$$$| $$$$$$$\
   | $$ __\$$| $$__| $$| $$$\ /  $$$| $$__          | $$  | $$| $$   | $$| $$__    | $$__| $$
   | $$|    \| $$    $$| $$$$\  $$$$| $$  \         | $$  | $$ \$$\ /  $$| $$  \   | $$    $$
   | $$ \$$$$| $$$$$$$$| $$\$$ $$ $$| $$$$$         | $$  | $$  \$$\  $$ | $$$$$   | $$$$$$$\
   | $$__| $$| $$  | $$| $$ \$$$| $$| $$_____       | $$__/ $$   \$$ $$  | $$_____ | $$  | $$
    \$$    $$| $$  | $$| $$  \$ | $$| $$     \       \$$    $$    \$$$   | $$     \| $$  | $$
     \$$$$$$  \$$   \$$ \$$      \$$ \$$$$$$$$        \$$$$$$      \$     \$$$$$$$$ \$$   \$$   
)";
    cout << "\033[2J\033[H";
    while (!_kbhit())
    {
        set(3, 10);
        cout << intro << endl;
        a % 50 > 24 ? cout << "                                            Press q to exit..." << endl : cout << "                                                                          " << endl;
        Sleep(10);
        a++;
    }
    char ch = _getch();
    Sleep(100);
    cout<<"\033[2J\033[H";
    if (ch == 'q')
    {
        return true;
    }
    return false;
}

void show_instructions()
{
    while (!_kbhit())
    {
        set(3, 10);
        cout << "Instructions:" << endl<<endl;
        cout << "1. Use arrow keys(left and right) to move the piece." << endl;
        cout << "2. Use up arrow key to rotate the piece." << endl;
        cout << "3. Use space key to hard drop the piece and down arrow key to soft drop." << endl;
        cout << "4. Press esc to exit the game." << endl;
    }
    char ch = _getch();
    Sleep(100);
}