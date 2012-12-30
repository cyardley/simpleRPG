#include "input.h"

//Mouse
Mouse::Mouse(){
    LB = false;
    RB = false;
    X = 0;
    Y = 0;
    click = 0;

    mouseItem = new invenNode;
    mouseItem->item = BLANK_ITEM;
    mouseItem->num = 0;
}
void Mouse::putX(int x){
    this->X = x;
}
void Mouse::putY(int y){
    this->Y = y;
}
int Mouse::getX(){
    return X;
}
int Mouse::getY(){
    return Y;
}
void Mouse::putRB(bool x){
    RB = x;
}
void Mouse::putLB(bool x){
    LB = x;
}
bool Mouse::getRB(){
    return RB;
}
bool Mouse::getLB(){
    return LB;
}
void Mouse::clickPut(int x){
    click = x;
}
int Mouse::clickGet(){
   return click;
}

Item Mouse::getMouseItem(){
    return mouseItem->item;
}

int Mouse::getMouseItemNum(){
    return mouseItem->num;
}

void Mouse::setMouseItem(Item i, int n){
    mouseItem->item = i;
    mouseItem->num = n;
}

void Mouse::clearMouseItem(){
    mouseItem->item = BLANK_ITEM;
    mouseItem->num = 0;
}

//Keys
Keys::Keys(){
    ctrl = false;
    space = false;
}

void Keys::setCtrl(bool x){
    ctrl = x;
}
    
bool Keys::getCtrl(){
    return ctrl;
}

void Keys::setSpace(bool x){
    space = x;
}

bool Keys::getSpace(){
    return space;
}


