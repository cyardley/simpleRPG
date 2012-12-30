//items.h
#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include "SDL/SDL.h"
#include "sprite.h"

class Item{
public:
    Item();
    Item(std::string name, std::string s, int x, int y, int val, int mDur, int Dur);
    ~Item();
    void setItem(Item &x);
    std::string getName();
    Sprite* getSprite();
    int getValue();
    int getMDur();
    int getDur();
    //change the durability to x
    void changeDur(int x);
    //add x to the durability
    ///pass a negative x to subtract
    void addDur(int x);

    bool operator==(Item x);
private:
    std::string name;
    std::string imagePath;
    Sprite *image;
    int value;
    int maxDurability;
    int durability;
    //effect?
};
#endif
