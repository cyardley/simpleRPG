#SIMPLE RPG MAKEFILE

#RPG
rpg: rpg.o towns.o maps.o display.o sprite.o camera.o user.o items.o inventory.o input.o npc.o
	g++ -o rpg towns.o rpg.o maps.o display.o sprite.o camera.o user.o items.o inventory.o input.o npc.o -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf
rpg.o: rpg.cpp maps.h sprite.h display.h camera.h user.h items.h inventory.h input.h towns.h npc.h
	g++ -c rpg.cpp -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf

#NPC
npc.o: npc.cpp npc.h
	g++ -c npc.cpp

#Towns
towns.o: towns.cpp towns.h maps.h
	g++ -c towns.cpp

#Maps
maps.o: maps.cpp maps.h input.h
	g++ -c maps.cpp

#Display
display.o: display.cpp display.h maps.h sprite.h input.h inventory.h camera.h
	g++ -c display.cpp

#Sprite
sprite.o: sprite.cpp sprite.h
	g++ -c sprite.cpp

#camera
camera.o: camera.cpp camera.h
	g++ -c camera.cpp

#user
user.o: user.cpp user.h maps.h sprite.h inventory.h
	g++ -c user.cpp

#items
items.o: items.cpp items.h sprite.h
	g++ -c items.cpp

#inventory
inventory.o: inventory.cpp inventory.h items.h
	g++ -c inventory.cpp

#input
input.o: input.cpp input.h items.h inventory.h
	g++ -c input.cpp

#clean:
clean:
	rm -rf *.o *~ rpg test

#test
test: test.o maps.o display.o sprite.o camera.o user.o items.o inventory.o
	g++ -o test test.o maps.o display.o sprite.o camera.o user.o items.o inventory.o -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf
test.o: test.cpp maps.h sprite.h display.h camera.h user.h items.h inventory.h
	g++ -c test.cpp -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf
