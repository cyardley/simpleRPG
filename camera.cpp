//camera.cpp
#include "camera.h"


Camera::Camera(int x, int y){
    resX = x;
    resY = y;
    disp = SDL_SetVideoMode(resX,resY,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    mUp = false;
    mDown = false;
    mLeft = false;
    mRight = false;
}

Camera::~Camera(){
    SDL_FreeSurface(disp); 
}

SDL_Surface* Camera::display(){
    return disp;
}

void Camera::draw(SDL_Surface* s){
    SDL_Rect rect;
            rect.x = 0;
            rect.y = 0;
            rect.w = resX; 
            rect.h = resY;
    SDL_BlitSurface(s, NULL, disp, &rect);
}

int Camera::getResX(){
    return resX;
}
int Camera::getResY(){
    return resY;
}

bool Camera::isUp(){
    return mUp;
}
bool Camera::isDown(){
    return mDown;
}
bool Camera::isLeft(){
    return mLeft;
}
bool Camera::isRight(){
    return mRight;
}
void Camera::setUp(bool x){
    mUp = x;
}
void Camera::setDown(bool x){
    mDown = x;
}
void Camera::setLeft(bool x){
    mLeft = x;
}
void Camera::setRight(bool x){
    mRight = x;
}
