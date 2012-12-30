//rpg.cpp                 |
//start: April 22, 2009   |
//=========================
//Setup |
//=======
//Standard
#include <iostream>
//SDL
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_image.h"
//Project Specific
#include "maps.h"
#include "npc.h"
#include "towns.h"
#include "display.h"
#include "sprite.h"
#include "camera.h"
#include "user.h"
#include "items.h"
#include "inventory.h"
#include "input.h"
using namespace std;

//INFORMATION |
//=============
const string TITLE = "Simple RPG";
const string VERSION = "0.04-dev";
const string COPYMSG = "Copyright 2009";
const string WEBSITE = "";
const string WINDOWTITLE = TITLE + " -&/- " + VERSION;

//GLOBAL    |
//===========
bool DEVELOPER = true;
int DELAY = 0; //milliseconds
const int ResX = 800;
const int ResY = 606;

//MAP FILES |
//===========
//Note: Declared externally in towns.cpp
extern Maps world; //file, startY, startX
extern Maps town1;
extern Maps house1;
extern Maps town2;
extern Maps house2;

//MAIN |
//======
int main(int argc, char *argv[]){

//Command Line Options |
//======================
     for(int i = 0; i < argc; i++){
         string str = argv[i];
         if(str=="-dev") DEVELOPER = !DEVELOPER;
         if(str=="-delay") DELAY = atoi(argv[i+1]);
     }

//STARTUP MESSAGE |
//=================
    cout << TITLE << " version " << VERSION << endl
         << COPYMSG << endl << WEBSITE << endl;


//INITALIZE SDL |
//===============
    Camera screen(ResX, ResY);
    SDL_WM_SetCaption( WINDOWTITLE.c_str(), NULL ); 
    atexit(SDL_Quit);
    TTF_Init(); atexit(TTF_Quit);
    //SDL_EnableUNICODE( SDL_ENABLE ); ////get unicode from key events: (event.key.keysym.unicode)


//OBJECTS |
//=========
    //Setup
    Mouse mouse;
    Keys keyboard;
    Tiles mapTiles(106, 32); //mapTiles (tiles#, widthPix)
    //Maps
    Maps map = world;
    //Sprites
    Sprite player("characters/player.png", screen.getResX()/2, (screen.getResY()/2)-(mapTiles.getPix()/4));
    //Inventories
    Inventory playerInven(400, 0, 8, 8, "gui/inventory.png");
    Inventory testInven(0,0, 8, 8, "gui/inventory.png");
    //Items
    Item test("Test Item", "items/test.png", 0, 0, 500, 100, 100);
    Item sword1("Sword #1", "items/sword1.png", 0, 0, 500, 100, 100);
    Item sword2("Sword #2", "items/sword1.png", 0, 0, 500, 100, 100);
    playerInven.add(sword1, 1);
    playerInven.add(sword2, 2);
    playerInven.add(test, 5);
    testInven.add(sword1, 1);


//VARIABLES |
//===========
    bool run = true;
    int gameMode = 1;
    int location = 0;

    //Dev Variables
    bool dMouseXY = DEVELOPER;
    bool dCamXY = DEVELOPER;
    bool dMiniM = DEVELOPER;
    bool devKeys = DEVELOPER;
    bool dMouseTile = DEVELOPER;
    int drawTile = 1;
    bool editMap = false;

//MAIN LOOP |
//===========
    while(run){


//SDL EVENTS |
//============
        SDL_Event event; 
        while (SDL_PollEvent(&event)){
            //Quit
            if (  (event.type==SDL_QUIT)      //Quit if you press X button
               || (  (event.type==SDL_KEYDOWN)//or escape key
                  && (event.key.keysym.sym==SDLK_ESCAPE) )){
               run = false;
            }
            //Mouse Motion
            if(event.type==SDL_MOUSEMOTION){
                mouse.putX(event.motion.x);
                mouse.putY(event.motion.y);
            }
            //Mouse Buttons
            if(event.type==SDL_MOUSEBUTTONDOWN){ //Down
                //Left Button
                if(event.button.button==SDL_BUTTON_LEFT){
                    mouse.putLB(true);
                }
                //Right Button
                if(event.button.button==SDL_BUTTON_RIGHT){
                    mouse.putRB(true);
                }
            }
            if(event.type==SDL_MOUSEBUTTONUP){ //UP
                //Left Button
                if(event.button.button==SDL_BUTTON_LEFT){
                     mouse.putLB(false);
                }
                //Right Button
                if(event.button.button==SDL_BUTTON_RIGHT){
                     mouse.putRB(false);
                }
            }
            ////Mouse Wheel Up
            //if(event.type==SDL_BUTTON_WHEELUP){
            //    cout << "wheel up\n";
            //}
            ////Mouse Wheel Down
            //if(event.type==SDL_BUTTON_WHEELDOWN){
            //    cout << "wheel down\n";
            //}
            //Key Down
            if(event.type==SDL_KEYDOWN){
                if(event.key.keysym.sym==SDLK_UP)screen.setUp(true);
                if(event.key.keysym.sym==SDLK_DOWN)screen.setDown(true);
                if(event.key.keysym.sym==SDLK_LEFT)screen.setLeft(true);
                if(event.key.keysym.sym==SDLK_RIGHT)screen.setRight(true);
                if(event.key.keysym.sym==SDLK_LCTRL)keyboard.setCtrl(true);
                if(event.key.keysym.sym==SDLK_SPACE)keyboard.setSpace(true);
                //dev-keys
                if(devKeys){
                    if(event.key.keysym.sym==SDLK_w)(map).changeY((map).getY()-1);
                    if(event.key.keysym.sym==SDLK_s)(map).changeY((map).getY()+1);
                    if(event.key.keysym.sym==SDLK_a)(map).changeX((map).getX()-1);
                    if(event.key.keysym.sym==SDLK_d)(map).changeX((map).getX()+1);
                    if(event.key.keysym.sym==SDLK_0)gameMode = 0;
                    if(event.key.keysym.sym==SDLK_1)gameMode = 1;
                    if(event.key.keysym.sym==SDLK_2)gameMode = 2;
                }
            }
            if(event.type==SDL_KEYUP){
                if(event.key.keysym.sym==SDLK_UP)screen.setUp(false);
                if(event.key.keysym.sym==SDLK_DOWN)screen.setDown(false);
                if(event.key.keysym.sym==SDLK_LEFT)screen.setLeft(false);
                if(event.key.keysym.sym==SDLK_RIGHT)screen.setRight(false);
                if(event.key.keysym.sym==SDLK_LCTRL)keyboard.setCtrl(false);
                if(event.key.keysym.sym==SDLK_SPACE)keyboard.setSpace(false);
            }
        }


//Tasks! |
//========
        //Mouse
        if(mouse.getLB()){
           switch(mouse.clickGet()){
               case 0: mouse.clickPut(1); break;
               case 1: mouse.clickPut(2); break;
               default: break;
            }
        }else{ mouse.clickPut(0); }
        //Input mode:
        if(gameMode == 0){
            SDL_FillRect(screen.display(), NULL, SDL_MapRGB(screen.display()->format, 120, 120, 120));
            drawText("COMMAND LINE", 0, 200, 225, 0, 0, 90, screen);
            SDL_Flip(screen.display());
            string s;
            cout << "Enter a Command:\n>> ";
            cin >> s;
            if(s=="invendump") playerInven.dump();
            if(s=="mousetest") mouse.setMouseItem(sword1, 1);
            if(s=="dMouseXY") dMouseXY = !dMouseXY;
            if(s=="dCamXY") dCamXY = !dCamXY;
            if(s=="dMiniM") dMiniM = !dMiniM;
            if(s=="devKeys") devKeys = !devKeys;
            if(s=="changeTile") {cout << ">> "; cin >> drawTile;}
            if(s=="editMap") editMap = !editMap;
            if(s=="saveMap") map.saveMap();
            if(s=="dMouseTile") dMouseTile = !dMouseTile;
            cout << "Back to Game\n===============\n";
            gameMode = 1;
        }
        //Move mode:
        if(gameMode == 1){
            doMove(screen, map, mapTiles, player);
            drawMap(screen, mapTiles, map);
            drawSprite(screen, player);
            useDoors(map.getX(), map.getY(), location, map);
        }
        //inventory Mode:
        if(gameMode == 2){
            SDL_FillRect(screen.display(), NULL, SDL_MapRGB(screen.display()->format, 120, 120, 120));
            drawInven(screen, playerInven, mouse);
            clickInvenMouse(mouse, keyboard, playerInven);
            drawInven(screen, testInven, mouse);
            clickInvenMouse(mouse, keyboard, testInven);
            drawMouseInven(screen, mouse);
        }
        //Deveoloper Displays
        if(DEVELOPER){
            if(dMouseXY)drawMouseXY(screen, mouse);
            if(dCamXY)drawTileXY(screen, map, player);
            if(dMiniM)drawMiniMap(screen, map);
            if(editMap){map.editMap(mouse, drawTile); 
                drawText(">>Tile Edit Mode", 0, 500, 250, 0, 0, 85, screen);}
            if(dMouseTile)drawMouseTile(screen, mouse, map, drawTile);
        }
        //Display
        SDL_Flip(screen.display());
        //Wait
        SDL_Delay(DELAY);
    }
//CLEANUP |
//=========
    TTF_Quit();
    SDL_Quit();
    cout << "Thanks for playing!\n";
    exit(0);     
}
