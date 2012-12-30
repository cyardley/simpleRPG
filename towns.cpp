#include "towns.h"


//Map Files
//Note: rpg.cpp externally references these.
Maps world("data/maps/world.map", 103, 30); //file, startY, startX
Maps town1("data/maps/town1.map", 10, 10);
Maps house1("data/maps/house1.map", 10, 10);
Maps town2("data/maps/town2.map", 10, 10);
Maps house2("data/maps/house2.map", 10, 10);

void door(int y, int x, int py, int px, int cy, int cx, Maps & building, int locn, int & location, Maps & map){
    if(y==py && x==px){
        map = building; location = locn;
        map.changeY(cy); map.changeX(cx);
    }
}

//Door of 2 width
void door(int y, int x, int py, int px, int px2, int cy, int cx, Maps & building, int locn, int & location, Maps & map){
    if(y==py && (x==px || x == px2)){
        map = building; location = locn;
        map.changeY(cy); map.changeX(cx);
    }
}

//Use the Doors
void useDoors(int px, int py, int & location, Maps & map){
    switch(location){
        //===World Map===:
        case 0:
            door(py, px, 24, 14, 17, 24, town1, 10, location, map); //Enter Town 1
            door(py, px, 36, 103, 80, 43, town2, 20, location, map); //Enter Town 2
            break;
        //===Town 1===:
        case 10:
            door(py, px, 17, 25, 24, 15, world, 0, location, map); //Enter World map
            door(py, px, 24, 12, 25, 49, house1, 11, location, map); //Enter Inn
            door(py, px, 8, 18, 9, 8, house1, 11, location, map); //Enter House
            door(py, px, 14, 5, 72, 8, house1, 11, location, map); //Enter Shop
            break;
        //===Town 1 Buildings===:
        case 11:
            door(py, px, 26, 49, 50, 25, 12, town1, 10, location, map); //Exit Inn
            door(py, px, 10, 8, 9, 9, 18, town1, 10, location, map); //Exit House
            door(py, px, 73, 8, 15, 5, town1, 10, location, map); //Exit Shop
            door(py, px, 23, 60, 39, 65, house1, 11, location, map); //Inn Go Upstairs                 
            door(py, px, 38, 65, 22, 60, house1, 11, location, map); //Inn Go Downstairs
            break;
        //===Town 2 ===:
        case 20:
            door(py, px, 81, 43, 37, 103, world, 0, location, map); // Enter World Map
            door(py, px, 74, 33, 29, 20, house2, 21, location, map); // Enter Inn
            door(py, px, 72, 15, 13, 171, house2, 21, location, map); // Enter Item Shop
            door(py, px, 60, 8, 64, 110, house2, 21, location, map); // Enter Left House
            door(py, px, 44, 1, 14, 112, house2, 21, location, map); // Enter Armor Shop
            door(py, px, 24, 16, 86, 17, house2, 21, location, map); // Enter Big House Front
            door(py, px, 14, 30, 58, 42, house2, 21, location, map); // Enter Big House Back
            door(py, px, 38, 41, 42, 125, house2, 21, location, map); // Enter Weapon Shop
            door(py, px, 45, 53, 10, 142, house2, 21, location, map); // Enter Right House
            door(py, px, 70, 61, 47, 156, house2, 21, location, map); // Enter Magic Shop
            break;
        case 21:
            door(py, px, 30, 20, 21, 75, 33, town2, 20, location, map); // Exit Inn
            door(py, px, 4, 57, 9, 81, house2, 21, location, map); // Inn Go Upstairs
            door(py, px, 10, 81, 5, 57, house2, 21, location, map); // Inn Go Downstairs
            door(py, px, 14, 171, 73, 15, town2, 20, location, map); // Exit Item Shop
            door(py, px, 65, 110, 61, 8, town2, 20, location, map); // Exit Left House
            door(py, px, 15, 112, 113, 45, 1, town2, 20, location, map); // Exit Armor Shop
            door(py, px, 87, 17, 18, 25, 16, town2, 20, location, map); // Exit Big House Front
            door(py, px, 59, 42, 15, 30, town2, 20, location, map); // Exit Big House Back
            door(py, px, 43, 125, 126, 39, 41, town2, 20, location, map); // Exit Weapon Shop
            door(py, px, 11, 142, 143, 46, 53, town2, 20, location, map); // Exit Right House
            door(py, px, 48, 156, 71, 61, town2, 20, location, map); // Exit Magic Shop
            break;
    }
}
