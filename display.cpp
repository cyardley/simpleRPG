//display.cpp
#include "display.h"
using namespace std;

/*
const SDL_Color Col_White = { 255, 255, 255 }; 
const SDL_Color Col_Black = { 0, 0, 0 };
const SDL_Color Col_Red = { 255, 0, 0 };
const SDL_Color Col_Green = { 0, 255, 0 };
const SDL_Color Col_Blue = { 0, 0, 255 }; 
const SDL_Color Col_Grey = { 100, 100, 100 };
*/


void drawText(string str, int X, int Y, int RED, int GREEN, int BLUE, int SIZE, Camera & screen){
    SDL_Color COLOR = { RED, GREEN, BLUE };
    TTF_Font *font = TTF_OpenFont( "data/Purisa.ttf", SIZE ); 
    SDL_Surface* text = TTF_RenderText_Solid(font, str.c_str(), COLOR);
    apply_surface(X, Y, text, screen.display());
    SDL_FreeSurface(text); 
    TTF_CloseFont(font);
}

void apply_surface(int x, int y, SDL_Surface * back, SDL_Surface * front){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_BlitSurface(back, NULL, front, &rect);
}

void drawMap(Camera & screen, Tiles &tile, Maps &map){
    int wx = map.getX();
    int wy = map.getY();
    int px = tile.getPix();
    for(int y=0; y<=(screen.getResY()/px); y++){
        for(int x=0; x<=(screen.getResX()/px); x++){
            apply_surface(x*px, y*px, tile.getTile(map.getTileN(y+wy, x+wx)), screen.display());
        }
    }
}

void drawSprite(Camera & screen, Sprite & spr){
   apply_surface((spr.getX()-spr.getW()/2), spr.getY(), spr.getSprite(), screen.display());
}

void drawInven(Camera & screen, Inventory & inven, Mouse & mouse){
    int iX = inven.getX();
    int iY = inven.getY();
    //Background
    apply_surface((*inven.getGUI()).getX(), (*inven.getGUI()).getY(),
                  (*inven.getGUI()).getSprite(), screen.display());
    //Draw Inventory Items
    int invenSize = (inven.getSize());
    int count = 0;

    for(int x=0; x<inven.getColums(); x++){
        for(int y=0; y<inven.getRows(); y++){
            int dx = iX+55+(x*ITEM_PX)+x*5;
            int dy = iY+55+(y*ITEM_PX)+y*5;
            apply_surface(dx, dy,
                          (*(inven.getItem(count)).getSprite()).getSprite(), screen.display());
            if(inven.getItemNum(count)>0){
                stringstream out;
                out << inven.getItemNum(count);
                string str = out.str();
                drawText(str, dx+ITEM_PX-12, dy+ITEM_PX-12, 225, 0, 0, 12, screen);
            }
            count++;
        }
    }
    //mouse hover
    if(mouse.getX()> iX+40 && mouse.getX() < iX+360 
       && mouse.getY() > iY+40  && mouse.getY() < iY+380){
        //get item
        int c = inven.getColums();
        int ix = (mouse.getX()-(iX+55))/(32+5);
        int iy = (mouse.getY()-(iY+55))/(32+5);
        int num = ix*c + iy;
        if(num<inven.getMaxSize() && num>=0){
            if(!(inven.getItem(num)==BLANK_ITEM)){
                drawText((inven.getItem(num)).getName(), iX+60, 410, 225, 0, 0, 25, screen);
                stringstream val;
                val << (inven.getItem(num)).getValue();
                string vstr = val.str();
                drawText("Value: "+vstr, iX+60, 440, 225, 0, 0, 15, screen);
                stringstream dur;
                dur << (inven.getItem(num)).getDur() << " / " << (inven.getItem(num)).getMDur();
                string dstr = dur.str();
                drawText("Durability: "+dstr, iX+60, 470, 225, 0, 0, 15, screen);
            }
        }
    }
}

void drawMouseInven(Camera & screen, Mouse & mouse){
//Draw Mouse Item
    apply_surface(mouse.getX(), mouse.getY(),
                   (*(mouse.getMouseItem()).getSprite()).getSprite(), screen.display());
    int mouseNum = mouse.getMouseItemNum();
    if(mouseNum>0){
        stringstream out;
        out << mouse.getMouseItemNum();
        string str = out.str();
        drawText(str, mouse.getX()+ITEM_PX-12, mouse.getY()+ITEM_PX-12, 225, 0, 0, 12, screen);
    }
}

//Developer Displays
void drawMouseXY(Camera & screen, Mouse & mouse){
    ostringstream out;
    out << mouse.getX() << ", " << mouse.getY();
    string str = out.str();
    drawText("Mouse: "+str, 0, 0, 225, 0, 0, 38, screen);
}
void drawTileXY(Camera & screen, Maps & map, Sprite & player){
    ostringstream out;
    out << map.getY()/*+(player.getY()/player.getH())*/ << ", " << map.getX() /*+ (player.getX()/player.getW())*/;
    string str = out.str();
    drawText("Tile: "+str, 0, 40, 225, 0, 0, 38, screen);
}
void drawMiniMap(Camera & screen, Maps & map){
    int ofX = 100;
    int ofY = 0;
    int tile;
    for(int x=0; x<map.getWidth(); x++){
        for(int y=0; y<map.getHeight(); y++){
            tile = map.getTileN(x, y);
            if ((tile >=  6 && tile <= 42)
             || (tile >= 79 && tile <= 86) || (tile == 77)
             || (tile >= 88 && tile <= 96)
             || (tile >= 101 && tile <=105) ){
                pixelRGBA(screen.display(), ofY+y, ofX+x, 0, 0, 0, 255); 
            }else{
                pixelRGBA(screen.display(), ofY+y, ofX+x, 250, 250, 250, 255);
            }
        }
    }
    boxRGBA(screen.display(), ofY+map.getX()+12, ofX+map.getY()+9, ofY+map.getX()+14, ofX+map.getY()+11, 250, 0, 0, 255);
}

void drawMouseTile(Camera & screen, Mouse & mouse, Maps & map, int drawTile){
    ostringstream out;
    out << map.getTileN(map.getY()+(mouse.getY()/32), map.getX()+(mouse.getX()/32))
        << " (" << drawTile << ")";
    string str = out.str();
    drawText("Mouse Tile#: "+str, 350, 0, 225, 0, 0, 38, screen);
}
