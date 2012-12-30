//inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "items.h"
#include "sprite.h"

//A blank item. Used to fill in spaces
const Item BLANK_ITEM("blank", "/items/blank.png", 0, 0, 0, 0, 0);

//Each item (and number of duplicates)
struct invenNode{
    Item item;
    int num;
};

class Inventory{
public:
    //Constructor (guiX, guiY, rows, colums, image path)
    Inventory(int x, int y, int r, int c, std::string str);
    ~Inventory();
    //Create and Add a new item (NOT RELIABLE)
    //ex: playerInven.add(1, "NEW_ITEM_1", "/items/1.png", 1, 10, 10);
    bool add(int NN, std::string name, std::string s, int val, int mDur, int Dur);
    //Add an existing item
    bool add(Item &x, int n);
    //Remove an item based on parameters
    bool remove(int NN, std::string name, std::string s, int val, int mDur, int Dur);
    //Remove a defined item
    bool remove(Item x, int n);
    //Returns true if Item x is in the inventory
    bool contains(Item x);
    //Returns number of items (not including duplicates) in the inventory
    int getSize();
    //Returns the maximum number of items allowed in the inventory
    int getMaxSize();
    //Returns an item based on its position in the inventory
    Item getItem(int x);
    //Returns the number of duplicates of an item based on its position in the inventory
    int getItemNum(int x);
    //Retursn the number of rows
    int getRows();
    //Returns the number of colums
    int getColums();
    //Returns the x coordinate of the GUI
    int getX();
    //Returns the y coordiante of the GUI
    int getY();
    //Dev-Only; prints out the inventory onto the command line
    void dump();
    //Returns the GUI sprite
    Sprite* getGUI();
private:
    Sprite* gui;
    //Linked List (old):
    /*struct invenNode{
        Item item;
        int num;
        invenNode* next;
    };
    invenNode* head;*/
    int invenSize;
    int maxinvenSize;
    //Array:
    invenNode* inven;
    int X;
    int Y;
    int rows;
    int colums;
};

#endif
