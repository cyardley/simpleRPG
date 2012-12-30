#include <iostream>

//SDL
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_image.h"

#include "inventory.h"
using namespace std;

int main(){
    inventory test(47);
    Item aa("A", "/items/test.png", 50, 50, 500, 100, 100);
    Item bb("B", "/items/test.png", 50, 50, 500, 100, 100);
    Item cc("C", "/items/test.png", 50, 50, 500, 100, 100);
    Item dd("D", "/items/test.png", 50, 50, 500, 100, 100);
    test.add(aa, 1);
    test.add(bb, 5);
    test.add(cc, 3);
    test.add(bb, 2);
    test.dump();
    test.remove(bb, 7);
    test.add(6, "pie", "/items/test.png", 500, 100, 100);
    test.add(1, "pie", "/items/test.png", 500, 100, 100);
    test.add(1, "pie", "/items/test.png", 500, 1300, 100);
    test.dump();
}
