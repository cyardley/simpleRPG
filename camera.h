//camera.h
#ifndef CAMERA_H
#define CAMERA_H
#include "SDL/SDL.h"

class Camera{
public:
    Camera(int x, int y);
    ~Camera();
    SDL_Surface* display();
    void draw(SDL_Surface* s);
    int getResX();
    int getResY();
    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();
    void setUp(bool x);
    void setDown(bool x);
    void setLeft(bool x);
    void setRight(bool x);
private:
    SDL_Surface* disp;
    int resX;
    int resY;
    bool mUp;
    bool mDown;
    bool mLeft;
    bool mRight;
};

#endif
