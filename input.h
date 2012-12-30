//input.h
#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include "items.h"
#include "inventory.h"


//Mouse
class Mouse{
public:
    Mouse();
    void putX(int x);
    void putY(int y);
    int getX();
    int getY();
    void putRB(bool x);
    void putLB(bool x);
    bool getRB();
    bool getLB();
    void clickPut(int x);
    int clickGet();

    Item getMouseItem();
    int getMouseItemNum();
    void setMouseItem(Item i, int n);
    void clearMouseItem();
private:
    int X;
    int Y;
    bool LB;
    bool RB;
    int click;

    invenNode* mouseItem;
};

//Keys
class Keys{
public:
    Keys();
    void setCtrl(bool x);
    bool getCtrl();
    void setSpace(bool x);
    bool getSpace();
private:
    bool ctrl;
    bool space;
};

#endif
