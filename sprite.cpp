//tile.cpp
#include <iostream>
#include <sstream>
#include "sprite.h"
using namespace std;

//TILES
Tiles::Tiles(int x, int p){
    pixles = p;
    num = x;
    images = new SDL_Surface*[x];
    for(int i=0; i<x; i++){
        ostringstream sin;
        sin << i; string s = sin.str();
        string out = "data/images/tiles/" + s + ".png";
        images[i] = IMG_Load(out.c_str());
    }
}

Tiles::~Tiles(){
    for(int i=0; i<num; i++){
        SDL_FreeSurface(images[i]);
    }
}

SDL_Surface* Tiles::getTile(int x){
    return images[x];
}

int Tiles::getPix(){
    return pixles;
}

//SPRITE
Sprite::Sprite(std::string s, int x, int y){
    string out = "data/images/" + s;
    image = IMG_Load(out.c_str());
    if(!image){ //FUCK
        cerr << "Could not load image " << out << endl;
        exit(1);
    }
    this->X = x;
    this->Y = y;
    W = image->w;
    H = image->h;
}

Sprite::Sprite(Sprite &s){

    image = s.getSprite();
    X = s.getX();
    Y = s.getY();
    W = s.getW();
    H = s.getH();
}
 

Sprite::~Sprite(){
    SDL_FreeSurface(image);
}
int Sprite::getX(){
    return X;
}
int Sprite::getY(){
    return Y;
}
int Sprite::getW(){
    return W;
}
int Sprite::getH(){
    return H;
}
SDL_Surface* Sprite::getSprite(){
    return image;
}

//PROBABLY WILL NEVER USE THIS CODE
//SDL GFX HAS A BETTER ROTATION LOL
/*
//ROTATING SPRITE
rotatingSprite::rotatingSprite(std::string sU, std::string sD, std::string sL, std::string sR, int x, int y){
    string out = "data/images/" + sU;
    imageUp = IMG_Load(out.c_str());
    out = "data/images/" + sD;
    imageDown = IMG_Load(out.c_str());
    string out = "data/images/" + sL;
    imageLeft = IMG_Load(out.c_str());
    string out = "data/images/" + sR;
    imageRight = IMG_Load(.c_str());
    this->X = x;
    this->Y = y;
    W = imageUp->w;
    H = imageUp->h;
}

Sprite::~Sprite(){
    SDL_FreeSurface(image);
}
int Sprite::getX(){
    return X;
}
int Sprite::getY(){
    return Y;
}
int Sprite::getW(){
    return W;
}
int Sprite::getH(){
    return H;
}
SDL_Surface* Sprite::getSprite(){
    return image;
}
*/
