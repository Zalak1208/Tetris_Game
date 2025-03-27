#include "map.h"
#include "pieces.h"
#include "intro.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

Map::Map(int h, int w)
{
    height = h;
    width = w;
    score = 0;
    speed = 100;
    map = new int *[height];
    static_map = new int *[height];
    for (int i = 0; i < height; i++)
    {
        map[i] = new int[width];
        static_map[i] = new int[width];
        for (int j = 0; j < width; j++)
        {
            if (i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = -1;
                static_map[i][j] = -1;
            }
            else
            {
                map[i][j] = 0;
                static_map[i][j] = 0;
            }
        }
    }
    srand(time(NULL));
    int random = rand() % 7 + 1;
    next = rand() % 7 + 1;
    p = Pieces(random, 1);
    px = (width / 2) - 2;
    py = 0;
}

void Map::print_map()
{
    string cyan_bg = "\033[46m";
    string reset = "\033[0m";
    string str = "";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == 0)
                str += "  ";
            else if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 11 || map[i][j] == 12)
            {
                str += p.color_body(map[i][j] % 10);
            }
            else if (map[i][j] == -1)
            {
                str += cyan_bg + "  " + reset;
            }
        }
        if (12 > i)
            str += side_board(i);
        str += "\n";
    }
    cout << str;
}

bool Map ::move(int direction)
{
    int new_px;
    int new_py;

    if (direction == 0)
    {
        new_px = px;
        new_py = py + 1;
    }
    else if (direction == 1)
    {
        new_px = px + 1;
        new_py = py;
    }
    else if (direction == -1)
    {
        new_px = px - 1;
        new_py = py;
    }
    else
    {
        return false;
    }

    if (is_allowed(new_px, new_py, p.orientation, p.shape))
    {
        px = new_px;
        py = new_py;
        return true;
    }
    else
    {
        return false;
    }
}

void Map::rotate()
{
    p.orientation = (p.orientation % 4) + 1;
}

void Map::update()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = static_map[i][j];
        }
    }

    int **shape = p.get_shape();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (shape[j][i] == 1 | shape[j][i] == 2)
            {
                if (py + j < height && px + i < width && py + j >= 0 && px + i >= 0)
                    map[py + j][px + i] = shape[j][i];
            }
        }
    }
}

void Map::run()
{
    cout << "\033[2J\033[H";
    int k = 0;
    bool flag = true;
    while (flag)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == 27)
            {
                exit(0);
            }
            else if (c == 32)
            {
                bool con = true;
                while (con)
                {
                    if (!move(0))
                    {
                        t_ground();
                        con = false;
                        if(!new_piece())
                        {
                            flag = false;
                        }
                    }
                    update();
                    cout << "\033[2J\033[H";
                    print_map();
                }
            }
            else if (c == -32 || c == 224)
            {
                char c = _getch();
                if (c == 72)
                {
                    if (is_allowed(px, py, (p.orientation % 4) + 1, p.shape))
                        rotate();
                }
                else if (c == 77)
                {
                    move(1);
                }
                else if (c == 75)
                {
                    move(-1);
                }
                else if (c == 80)
                {
                    if (!move(0))
                    {
                        t_ground();
                        break;
                    }
                }
            }
        }
        if (k % (10000 / speed) == 0)
            if (!move(0))
            {
                t_ground();
                break;
            }
        update();
        // pr();
        cout << "\033[2J\033[H";
        print_map();
        Sleep(3);
        k++;
    }
}

void Map::pr()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << static_map[i][j] << " | ";
        }
        cout << endl;
    }
}

bool Map::is_allowed(int x, int y, int orientation, int shape_g)
{
    int org_or = p.orientation;
    int org_sh = p.shape;
    p.orientation = orientation;
    p.shape = shape_g;
    int **shape = p.get_shape();
    p.orientation = org_or;
    p.shape = org_sh;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((shape[j][i] == 1 | shape[j][i] == 2) && (map[y + j][x + i] == -1 | map[y + j][x + i] == 11 | map[y + j][x + i] == 12))
            {
                return false;
            }
        }
    }
    return true;
}

void Map::update_static()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == -1)
            {
                static_map[i][j] = -1;
                continue;
            }
            else if (map[i][j] == 0)
            {
                static_map[i][j] = 0;
                continue;
            }
            else if (map[i][j] > 10)
            {
                static_map[i][j] = map[i][j];
                continue;
            }
            static_map[i][j] = map[i][j] + 10;
        }
    }
    update();
    print_map();
}

bool Map::new_piece()
{
    if (is_allowed((width / 2) - 2, 0, 1, next))
    {
        int random = rand() % 7 + 1;
        p = Pieces(next, 1);
        next = random;
        px = (width / 2) - 2;
        py = 0;
        return true;
    }
    return false;
}

void Map::game_over()
{
    if (show_exit())
        exit(0);
}

void Map::clear()
{
    map = new int *[height];
    static_map = new int *[height];
    for (int i = 0; i < height; i++)
    {
        map[i] = new int[width];
        static_map[i] = new int[width];
        for (int j = 0; j < width; j++)
        {
            if (i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = -1;
                static_map[i][j] = -1;
            }
            else
            {
                map[i][j] = 0;
                static_map[i][j] = 0;
            }
        }
    }
}

void Map::clear_lines()
{
    for (int i = 0; i < height - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < width; j++)
        {
            if (static_map[i][j] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            score++;
            speed = 100 + 25 * score;
            for (int k = 0; k < width; k++)
            {
                for (int j = i; j > 0; j--)
                {
                    static_map[j][k] = static_map[j - 1][k];
                }
            }
        }
    }
}

void Map::t_ground()
{
    update_static();
    clear_lines();
    p.shape = 0;
    update();
    if (!new_piece())
        game_over();
}

string Map::side_board(int i)
{
    string cyan_bg = "\033[46m";
    string reset = "\033[0m";
    string to_ret = "";
    string white_bg = "\033[47m";
    string red_bg = "\033[41m";
    if (i == 0 || i == 11)
        to_ret += cyan_bg + "                  " + reset;
    else if (i == 2)
    {
        to_ret += " Score:         " + cyan_bg + "  " + reset;
        string num = to_string(score);
        for (int i = 0; i < num.size(); i++)
        {
            to_ret[7 + i] = num[i];
        }
    }
    else if (i == 4)
        to_ret += "    Next:       " + cyan_bg + "  " + reset;
    else if (i == 1 || i == 3 || i == 5 || i == 10)
        to_ret += "                " + cyan_bg + "  " + reset;
    else if (i > 5 && i < 10)
    {
        np = Pieces(next, 1);
        int **shape = np.get_shape();
        for (int j = 0; j < 16; j++)
        {
            if ((j > 3 && j < 12) && (shape[i - 6][j / 2 - 2] == 1))
                to_ret += white_bg + " " + reset;
            else if ((j > 3 && j < 12) && (shape[i - 6][j / 2 - 2] == 2))
                to_ret += red_bg + " " + reset;
            else
                to_ret += " ";
        }
        to_ret += cyan_bg + "  " + reset;
    }
    return to_ret;
}