//sprite.h
#ifndef SPRITE_H
#define SPRITE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

//Special "Map Tile" sprites
class Tiles{
public:
    Tiles(int x, int p);
    ~Tiles();
    SDL_Surface* getTile(int x);
    bool colide();
    int getPix();
private:
    SDL_Surface** images;
    int pixles;
    int num;
};

//A sprite
class Sprite{
public:
    Sprite(std::string s, int x, int y);
    Sprite(Sprite &x);
    ~Sprite();
    int getX();
    int getY();
    int getW();
    int getH();
    SDL_Surface* getSprite();
private:
    int X;
    int Y;
    int W;
    int H;
    SDL_Surface* image;
};

/*
//A Rotating Sprite
class rotatingSprite{
public:
    rotatingSprite(std::string s, int x, int y);
    ~rotatingSprite();
    int getX();
    int getY();
    int getW();
    int getH();
    SDL_Surface* getUpSprite();
    SDL_Surface* getDownSprite();
    SDL_Surface* getLeftSprite();
    SDL_Surface* getRightSprite();
private:
    int X;
    int Y;
    int W;
    int H;
    SDL_Surface* imageUp;
    SDL_Surface* imageDown;
    SDL_Surface* imageLeft;
    SDL_Surface* imageRight;
};
*/
#endif
