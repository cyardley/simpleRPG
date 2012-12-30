#include "user.h"
using namespace std;

//Collide
bool colide(int locX, int locY, Maps & map, Sprite & player){
    int tile = map.getTileN(locY+(player.getY()/player.getH()), locX + (player.getX()/player.getW()));
    //List of tiles that you can not move onto
    if (        (tile >=  6 && tile <= 42)
             || (tile >= 79 && tile <= 86) || (tile == 77)
             || (tile >= 88 && tile <= 96)
             || (tile >= 101 && tile <=105) ){
        return true;
    }else{
        return false;
    }
}

//move
void doMove(Camera & screen, Maps & world, Tiles & mapTiles, Sprite & player){
    int mpix = ITEM_PX;
    int wX = world.getX();
    int wY = world.getY();
    int wW = world.getWidth();
    int wH = world.getHeight();
    int rX = screen.getResX();
    int rY = screen.getResY();

    if(screen.isUp() && wY>0 && !colide(wX, wY-1, world, player)){
        world.changeY(wY-1);
    }
    if(screen.isDown() && wY+(rY/mpix)<wH-1 && !colide(wX, wY+1, world, player)){
        world.changeY(wY+1);
    }
    if(screen.isLeft() && wX>0 && !colide(wX-1, wY, world, player)){
        world.changeX(wX-1);
    }
    if(screen.isRight() && wX+(rX/mpix)<wW && !colide(wX+1, wY, world, player)){
        world.changeX(wX+1);
    }
}

//Mouse Inventory
void clickInvenMouse(Mouse & mouse, Keys & keyboard, Inventory & inven){
    if(mouse.getX()> inven.getX()+40 && mouse.getX() < inven.getX()+360 
       && mouse.getY() > inven.getY()+40  && mouse.getY() < inven.getY()+380){
        if(mouse.clickGet()==1){
            if(mouse.getMouseItem()==BLANK_ITEM){
                //get item
                int c = inven.getColums();
                int ix = (mouse.getX()-(inven.getX()+55))/(32+5);
                int iy = (mouse.getY()-(inven.getY()+55))/(32+5);
                int num = ix*c + iy;
                int amount = inven.getItemNum(num);
                if(keyboard.getCtrl()){
                    amount = 1;
                }
                if(!(inven.getItem(num)==BLANK_ITEM)){
                    mouse.setMouseItem(inven.getItem(num), amount);
                    inven.remove(inven.getItem(num), amount);
                }
            }else{
                //drop item
                Item i = mouse.getMouseItem();
                int n = mouse.getMouseItemNum();
                inven.add(i, n);
                mouse.setMouseItem(BLANK_ITEM, 0);
            }
        }
    }
}
