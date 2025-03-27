#ifndef PIECES_H
#define PIECES_H

#include <iostream>
using namespace std;

class Pieces
{
    public:
        int shape;
        int orientation;
        Pieces(int shape , int orientation);
        Pieces();
        string color_body(int n);
        int** get_shape();

};

#endif