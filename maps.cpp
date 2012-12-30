//Maps.cpp
#include "maps.h"
using namespace std;

Maps::Maps(string st, int x, int y){
    ifstream f;
    f.open(st.c_str());
    if(f.fail()){
        cerr << "Could not open file!\n";
        exit(1);
    }
    path = st;
    //start position
    this->X = x;
    this->Y = y;
    //get width and height
    string str;
    getline(f, str);
    width = atoi(str.c_str());
    getline(f, str);
    height = atoi(str.c_str());
    //get the map data
    tile = new int*[height];
    for(int y=0; y<height; y++){
        tile[y] = new int[width];
        for(int x=0; x<width; x++){
            getline(f, str);
            tile[y][x] = atoi(str.c_str());
        }
    }
 /*   //item data
    item = new int*[height];
    for(int y=0; y<height; y++){
        item[y] = new int[width];
        for(int x=0; x<width; x++){
            item[x][y] = 0;
        }
    }
    //colision data
    col = new int*[height];
    for(int y=0; y<height; y++){
        col[y] = new int[width];
        for(int x=0; x<width; x++){
            col[x][y] = 0;
        }
    }*/
    f.close();
}

Maps::~Maps(){
    for(int y=0; y<height; y++){
        delete[] tile[y];
        //delete[] item[y];
        //delete[] col[y];
    }
    delete[] tile;
    //delete[] item;
    //delete[] col;
}

int Maps::getTileN(int x, int y){
    return tile[x][y];
}

void Maps::putTileN(int x, int y, int i){
    tile[x][y] = i;
}

/*int Maps::getItem(int x, int y){
    return item[x][y];
}*/
/*int Maps::getCol(int x, int y){
    return col[x][y];
}*/

int Maps::getX(){
    return X;
}
int Maps::getY(){
    return Y;
}

int Maps::getHeight(){
    return height;
}
int Maps::getWidth(){
    return width;
}

void Maps::changeX(int x){
    this->X = x;
}
void Maps::changeY(int y){
    this->Y = y;
}


//Dev-Displays
void Maps::editMap(Mouse & mouse, int i){
    int y = getY()+(mouse.getY()/32);
    int x = getX()+(mouse.getX()/32);
    if(mouse.getLB()){
        putTileN(y, x, i);
    }
}

void Maps::saveMap(){
    ofstream f;
    f.open(path.c_str());
    f << width << '\n' << height << '\n';
    if(f.fail()){
        cerr << "Could not open file!\n";
        exit(1);
    }
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            f << tile[y][x] << '\n';
        }
    }
    f.close();
    cout << path << " ...saved\n";
}

