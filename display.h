//display.h
#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_image.h"
#include "maps.h"
#include "sprite.h"
#include "camera.h"
#include "inventory.h"
#include "input.h"

const int ITEM_PX = 32;

//Draw Text
void drawText(std::string str, int X, int Y, int RED, int GREEN, int BLUE, int SIZE, Camera & screen);

//Apply Surface!
void apply_surface(int x, int y, SDL_Surface * back, SDL_Surface * front);

//Draw Map
void drawMap(Camera & screen, Tiles &tile, Maps &map);

//Draw Sprite
void drawSprite(Camera & screen, Sprite &spr);

//Draw Inventory
void drawInven(Camera & screen, Inventory &inven, Mouse & mouse);

//Draw Mouse Inventory
void drawMouseInven(Camera & screen, Mouse & mouse);

//for testing only
//void testDraw(SDL_Surface *& screen, Tiles &tile);

//Developer Displays
void drawMouseXY(Camera & screen, Mouse & mouse);
void drawTileXY(Camera & screen, Maps & map, Sprite & player);
void drawMiniMap(Camera & screen, Maps & map);
void drawMouseTile(Camera & screen, Mouse & mouse, Maps & map, int drawTile);
#endif
