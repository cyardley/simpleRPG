//towns.h
#ifndef TOWNS_H
#define TOWNS_H
#include "maps.h"


//EXAMPLE: (change params in CAPS) 
////door(py, px, PY, PX, CY, CX, *MAP, LOC, location, *map);

//Go through the doors
////(Player X, Player Y, Lo. 1 X, Loc. 1 Y, Loc. 2 X, Loc. 2 Y, Map to go to, Map ID Change, Map ID container, Map pointer)
void door(int x, int y, int py, int px, int cy, int cx, Maps & building, int locn ,int & location, Maps & map);

//Door of 2 width
//Madness (no, THIS IS SPARTA) // Second x parameter
void door(int y, int x, int py, int px, int px2, int cy, int cx, Maps & building, int locn, int & location, Maps & map);

//Use Doors
void useDoors(int px, int py, int & location, Maps & map);

#endif
