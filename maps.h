//Maps.h
#ifndef MAPS1_H
#define MAPS1_H
//A map that the player moves around on....
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "input.h"

class Maps{
public:
    Maps(std::string st, int x, int y);
    Maps(int x);
    ~Maps();
    int getTileN(int x, int y);
    void putTileN(int x, int y, int i);
    //int getItem(int x, int y);
    //int getCol(int x, int y);
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    void changeX(int x);
    void changeY(int y);
    void editMap(Mouse & mouse, int i);
    void saveMap();
private:
    std::string path;
    int width;
    int height;
    int X;
    int Y;
    int** tile;
    //int** item;
    //int** col;
};

#endif
