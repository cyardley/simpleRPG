#include "items.h"
using namespace std;

Item::Item(){
    name = "Empty Item";
    image = new Sprite("items/test.png", 0, 0);
    imagePath = "items/test.png";
    value = 0;
    maxDurability = 0;
    durability = 0;
}

Item::Item(std::string name, std::string s, int x, int y, int val, int mDur, int Dur){
    this->name = name;
    image = new Sprite(s, x, y);
    imagePath = s;
    value = val;
    maxDurability = mDur;
    durability = Dur;
}

Item::~Item(){
}

void Item::setItem(Item &x){
    name = x.name;
    image = x.image;
    value = x.value;
    maxDurability = x.maxDurability;
    durability = x.durability;
}

string Item::getName(){
    return name;
}

Sprite* Item::getSprite(){
    return image;  
}

int Item::getValue(){
    return value;
}

int Item::getMDur(){
    return maxDurability;
}

int Item::getDur(){
    return durability;
}

void Item::changeDur(int x){
    durability = x;
    if(durability > maxDurability){
        durability = maxDurability;
    }
}

void Item::addDur(int x){
    durability +=x;
    if(durability > maxDurability){
        durability = maxDurability;
    }
}

bool Item::operator==(Item x){
    return (this->name == x.name &&
            this->imagePath == x.imagePath && //takes place of actual sprite; easier!
            this->value == x.value &&
            this->maxDurability == x.maxDurability &&
            this->durability == x.durability );
}
