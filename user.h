//user.h
#ifndef USER_H
#define USER_H
#include <iostream>
#include "SDL/SDL.h"
#include "maps.h"
#include "camera.h"
#include "sprite.h"
#include "input.h"
#include "inventory.h"
#include "display.h"

bool colide(int locX, int locY, Maps & map, Camera & screen, Sprite & player);
void doMove(Camera & screen, Maps & world, Tiles & mapTiles, Sprite & player);
void clickInvenMouse(Mouse & mouse, Keys & keyboard, Inventory & inven);

#endif
