#include "pieces.h"
#include <iostream>
using namespace std;

int** Pieces::get_shape()
{   
    // square of size 4
    int po1[4][4] = {{0,0,0,0},{0,1,2,0},{0,2,1,0},{0,0,0,0}};
    int po2[4][4] = {{0,0,0,0},{0,2,1,0},{0,1,2,0},{0,0,0,0}};
    int po3[4][4] = {{0,0,0,0},{0,1,2,0},{0,2,1,0},{0,0,0,0}};
    int po4[4][4] = {{0,0,0,0},{0,2,1,0},{0,1,2,0},{0,0,0,0}};


    // line of size 4
    int pi1[4][4] = {{0,0,1,0},{0,0,2,0},{0,0,1,0},{0,0,2,0}};
    int pi2[4][4] = {{0,0,0,0},{1,2,1,2},{0,0,0,0},{0,0,0,0}};
    int pi3[4][4] = {{0,2,0,0},{0,1,0,0},{0,2,0,0},{0,1,0,0}};
    int pi4[4][4] = {{0,0,0,0},{0,0,0,0},{2,1,2,1},{0,0,0,0}};

    // S
    int ps1[4][4] = {{0,0,0,0},{0,1,2,0},{1,2,0,0},{0,0,0,0}};
    int ps2[4][4] = {{0,0,0,0},{2,0,0,0},{1,2,0,0},{0,1,0,0}};
    int ps3[4][4] = {{0,0,0,0},{0,0,0,0},{0,2,1,0},{2,1,0,0}};
    int ps4[4][4] = {{0,0,0,0},{0,1,0,0},{0,2,1,0},{0,0,2,0}};

    // Z
    int pz1[4][4] = {{0,0,0,0},{1,2,0,0},{0,1,2,0},{0,0,0,0}};
    int pz2[4][4] = {{0,0,0,0},{0,2,0,0},{2,1,0,0},{1,0,0,0}};
    int pz3[4][4] = {{0,0,0,0},{0,0,0,0},{2,1,0,0},{0,2,1,0}};
    int pz4[4][4] = {{0,0,0,0},{0,0,1,0},{0,1,2,0},{0,2,0,0}};

    // L
    int pl1[4][4] = {{0,0,0,0},{0,1,0,0},{0,2,0,0},{0,1,2,0}};
    int pl2[4][4] = {{0,0,0,0},{0,0,2,0},{1,2,1,0},{0,0,0,0}};
    int pl3[4][4] = {{0,0,0,0},{2,1,0,0},{0,2,0,0},{0,1,0,0}};
    int pl4[4][4] = {{0,0,0,0},{0,0,0,0},{1,2,1,0},{2,0,0,0}};

    // J
    int pj1[4][4] = {{0,0,0,0},{0,1,0,0},{0,2,0,0},{2,1,0,0}};
    int pj2[4][4] = {{0,0,0,0},{0,0,0,0},{1,2,1,0},{0,0,2,0}};
    int pj3[4][4] = {{0,0,0,0},{0,1,2,0},{0,2,0,0},{0,1,0,0}};
    int pj4[4][4] = {{0,0,0,0},{2,0,0,0},{1,2,1,0},{0,0,0,0}};


    // T
    int pt1[4][4] = {{0,0,0,0},{0,0,0,0},{1,2,1,0},{0,1,0,0}};
    int pt2[4][4] = {{0,0,0,0},{0,1,0,0},{0,2,1,0},{0,1,0,0}};
    int pt3[4][4] = {{0,0,0,0},{0,1,0,0},{1,2,1,0},{0,0,0,0}};
    int pt4[4][4] = {{0,0,0,0},{0,1,0,0},{1,2,0,0},{0,1,0,0}};

    int** re = new int*[4];
    for (int i = 0; i < 4; i++)
    {
        re[i] = new int[4]();
    }

    
    for(int i = 0; i < 4; i++) {
       
        for(int j = 0; j < 4; j++) {
            if(shape == 1){
                if(orientation == 1) re[i][j] = po1[i][j];
                if(orientation == 2) re[i][j] = po2[i][j];
                if(orientation == 3) re[i][j] = po3[i][j];
                if(orientation == 4) re[i][j] = po4[i][j];
            }
            if(shape == 2){
                if(orientation == 1) re[i][j] = pi1[i][j];
                if(orientation == 2) re[i][j] = pi2[i][j];
                if(orientation == 3) re[i][j] = pi3[i][j];
                if(orientation == 4) re[i][j] = pi4[i][j];
            }
            if(shape == 3){
                if(orientation == 1) re[i][j] = ps1[i][j];
                if(orientation == 2) re[i][j] = ps2[i][j];
                if(orientation == 3) re[i][j] = ps3[i][j];
                if(orientation == 4) re[i][j] = ps4[i][j];
            }
            if(shape == 4){
                if(orientation == 1) re[i][j] = pz1[i][j];
                if(orientation == 2) re[i][j] = pz2[i][j];
                if(orientation == 3) re[i][j] = pz3[i][j];
                if(orientation == 4) re[i][j] = pz4[i][j];
            }
            if(shape == 5){
                if(orientation == 1) re[i][j] = pl1[i][j];
                if(orientation == 2) re[i][j] = pl2[i][j];
                if(orientation == 3) re[i][j] = pl3[i][j];
                if(orientation == 4) re[i][j] = pl4[i][j];
            }
            if(shape == 6){
                if(orientation == 1) re[i][j] = pj1[i][j];
                if(orientation == 2) re[i][j] = pj2[i][j];
                if(orientation == 3) re[i][j] = pj3[i][j];
                if(orientation == 4) re[i][j] = pj4[i][j];
            }
            if(shape == 7){
                if(orientation == 1) re[i][j] = pt1[i][j];
                if(orientation == 2) re[i][j] = pt2[i][j];
                if(orientation == 3) re[i][j] = pt3[i][j];
                if(orientation == 4) re[i][j] = pt4[i][j];
            }
        }
    }
    return re;
}

Pieces::Pieces(int shape , int orientation)
{
    this->shape = shape;
    this->orientation = orientation;
}
Pieces::Pieces()
{
    this->shape = 1;
    this->orientation = 1;
}

string Pieces::color_body(int n)
{
    string white_bg = "\033[47m";
    string red_bg = "\033[41m";
    string reset = "\033[0m";

    if(n==1) return white_bg+"  "+reset;
    else if(n==2) return red_bg+"  "+reset;
    return "  ";
}