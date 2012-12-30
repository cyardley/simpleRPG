#include "inventory.h"
using namespace std;



Inventory::Inventory(int x, int y, int r, int c, string str){
    rows = r;
    colums = c;
    X = x;
    Y = y;
    gui = new Sprite(str, X, Y);
    maxinvenSize = r*c;
    invenSize = 0;
    inven = new invenNode[maxinvenSize+1];
    for(int i=0; i<maxinvenSize; i++){
        (&inven[i])->item = BLANK_ITEM;
        (&inven[i])->num = 0;
    }
}
Inventory::~Inventory(){
    delete [] inven;
}

bool Inventory::add(int NN, std::string name, std::string s, int val, int mDur, int Dur){
    //Item t(name, s, 0, 0, val, mDur, Dur);
    //return add(t, NN);
    //return true;
}
bool Inventory::add(Item &x, int n){
    //Check to see if the item is in the Inventory yet
    for(int i=0; i<maxinvenSize; i++){
        if((&inven[i])->item == x){
            (&inven[i])->num += n;
            return true;
        }
    }
    //find an empty space
    for(int i=0; i<maxinvenSize; i++){
        if((&inven[i])->item==BLANK_ITEM){
            (&inven[i])->item = x;
            (&inven[i])->num = n;
            invenSize++;
            return true;
        }
    }
    //no spaces
    return false;
}

bool Inventory::remove(int NN, std::string name, std::string s, int val, int mDur, int Dur){
    Item t(name, s, 0, 0, val, mDur, Dur);
    return remove(t, NN);
}
bool Inventory::remove(Item x, int n){
    //Find the item
    for(int i=0; i<maxinvenSize; i++){
        if((&inven[i])->item == x){
            //more then enough items
            if((&inven[i])->num >n){
                (&inven[i])->num -=n;
                return true;
            }else if((&inven[i])->num==n){//enough items
                 invenSize--;
                (&inven[i])->item=BLANK_ITEM;
                (&inven[i])->num=0;
                return true;
            }else{//not enough
                return false;
            }
        }
    }
    //did not find item
    return false;
}
bool Inventory::contains(Item x){
    for(int i=0; i<maxinvenSize; i++){
        if((&inven[i])->item == x){
            return true;
        }
    }
    return false;
}
void Inventory::dump(){ //for dev only
    cout << "Inventory (name, quantity)" << endl;
    for(int i=0; i<maxinvenSize; i++){
        if(!((&inven[i])->item == BLANK_ITEM)){
            cout << (&inven[i])->item.getName() << ", " << (&inven[i])->num << endl;
        }
    }
    cout << "===============\n";
}

Sprite* Inventory::getGUI(){
    return gui;
}

int Inventory::getMaxSize(){
    return maxinvenSize;
}

int Inventory::getSize(){
    return invenSize;
}

Item Inventory::getItem(int x){
    return (&inven[x])->item;
}

int Inventory::getItemNum(int x){
    return (&inven[x])->num;
}

int Inventory::getRows(){
    return rows;
}

int Inventory::getColums(){
    return colums;
}

int Inventory::getX(){
    return X;
}

int Inventory::getY(){
    return Y;
}

/*
============================================================
============================================================
============================================================
============================================================
*/




//IGNORE THIS
/*
Inventory::Inventory(){
    head = NULL;
}

bool Inventory::add(int NN, std::string name, std::string s, int val, int mDur, int Dur){
    Item t(name, s, 0, 0, val, mDur, Dur);
    return add(t, NN);
}

bool Inventory::add(Item &x, int n){
    //already there?
    invenNode* search = head;
    while(search!=NULL){
        if(search->item == x){
            search->num += n;
            return true;
        }
        search = search->next;
    }
    //empty Inventory
    if(head==NULL){
        head = new invenNode;
        head->next = NULL;
        head->item.setItem(x);
        head->num = n;
        return true;
    }
    //everything else
    invenNode* second = head;
    head = new invenNode;
    head->next = second;
    head->item.setItem(x);
    head->num = n;
    return true;    
}

bool Inventory::remove(int NN, std::string name, std::string s, int val, int mDur, int Dur){
    Item t(name, s, 0, 0, val, mDur, Dur);
    return remove(t, NN);
}

bool Inventory::remove(Item x, int n){
    //none
    if(head==NULL){
        return false;
    }
    //in first node
    if(head->item == x){
       if(head->num > n){//more then enough items (just subtract n)
           head->num -= n;
           return true;
       }else if(head->num == n){ //exactly enough (totally remove node)
           if(head->next==NULL){//if only one node
               delete head;
               head = NULL;
               return true;
           }else{//more then one node
               invenNode* d = head;
               head = head->next;
               delete d;
               return true;
          }
       }else{//not enough
           return false;
       }
    }
    //everything else
    invenNode* prev = head;
    invenNode* search = head;
    while(search!=NULL){
        if(search->item == x){
            if(search->num > n){//more then enough items (just subtract n)
                search->num -= n;
                return true;
            }else if(search->num == n){ //exactly enough (totally remove node)
                prev->next = search->next;
                delete search;
                return true;
            }else{// not enough
                return false;
            }
        }
        prev = search;
        search = search->next;
    }
    return false;
}
bool Inventory::contains(Item x){
    invenNode* search = head;
    while(search!=NULL){
       if(search->item == x){
           return true;
       }
        search = search->next;
    }
    return false;
}
void Inventory::dump(){ //for dev only
    if(head==NULL){
        cout << "Empty Inventory\n";
        cout << "=====\n";
        return;
    }
    invenNode* search = head;
    while(search!=NULL){
        cout << search->item.getName() << ", " << search->num << endl;
        search = search->next;
    }
    cout << "=====\n";
}
*/
