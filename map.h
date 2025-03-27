#ifndef MAP_H
#define MAP_H

#include "pieces.h"
#include <iostream>
using namespace std;

class Map 
{
    private:
        int** map;
        int height;
        int width;
        Pieces p, np;
        int** static_map;
        int score;
        int speed;
        int next;
    public:
        int px;
        int py;
        Map(int h, int w);
        void print_map();
        bool move(int direction);
        void rotate();
        void update();
        void run();
        void pr();
        bool is_allowed(int x, int y, int orientation, int shape);
        void update_static();
        bool new_piece();
        void game_over();
        void clear_lines();
        void t_ground();
        void clear();
        string side_board(int i);

        
};
#endif