//Requires MakeFile
//run make ex19
//run ./ex19
/*
 You enter the The Great Hall.

 > l
 You can go:
 NORTH

 > n
 You go north into:
 The Throne Room.

 > l
 You can go:
 SOUTH
 EAST
 WEST

 > e
 You go east into:
 Kitchen, You have the knife now.

 > l
 You can go:
 WEST

 > w
 You go west into:
 The Throne Room.

 > l
 You can go:
 SOUTH
 EAST
 WEST

 > w
 You go west into:
 The Arena with the Minatour.

 > a
 You attack The Evil Minatour!
 It is still alive

 > a
 You attack The Evil Minatour!
 It is still alive

 > a
 You attack The Evil Minatour!
 It is still alive

 > a
 You attack The Evil Minatour!
 It is still alive

 > a
 You attack The Evil Minatour!
 It is still alive

 > a
 You attack The Evil Minatour!
 It is still alive

 > a
 You attack The Evil Minatour!
 It is dead

 > Giving up? You Suck

 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"
int Monster_attack(void *self,int damage)
{
	Monster *monster=self;
	printf("You attack %s!\n",monster->_(description));
	monster->hit_points -= damage;
	if(monster->hit_points>0){
		printf("It is still alive\n");
		return 0;
	}
	else {
		printf("It is dead\n");
		return 1;
	}
}
int Monster_init(void *self)
{
	Monster *monster=self;
	monster->hit_points=10;
	return 1;
}
Object MonsterProto={
	.init=Monster_init,
	.attack= Monster_attack
};

void *Room_move(void *self,Direction direction)
{
	Room *room=self;
	Room *next=NULL;
	if(direction == NORTH && room->north){
		printf("You go north into:\n");
		next= room->north;
	}
	else if(direction == SOUTH && room->south){
		printf("You go south into:\n");
		next= room->south;
	}
	else if(direction == EAST && room->east){
		printf("You go east into:\n");
		next= room->east;
	}
	else if(direction == WEST && room->west){
		printf("You go west into:\n");
		next= room->west;
	}
	else {
		printf("You cant go that direction\n");
		next=NULL;
	}
	if(next){
		next->_(describe)(next);
	}
	return next;
}
int Room_attack(void *self,int damage)
{
	Room *room=self;
	Monster *monster=room->bad_guy;
	if(monster){
		monster->_(attack)(monster,damage);
		return 1;
	}
	else {
		printf("You frail in the air at nothing idiot\n");
		return 0;
	}
}

Object RoomProto={
	.move= Room_move,
	.attack=Room_attack
};

void *Map_move(void *self,Direction direction)
{
	Map *map=self;
	Room *location=map->location;
	Room *next=NULL;
	next=location->_(move)(location,direction);
	if(next){
		map->location=next;
	}
	return next;
}
int Map_attack(void *self,int damage)
{
	Map *map=self;
	Room *location=map->location;
	return location->_(attack)(location,damage);
}
int Map_init(void *self)
{
	Map *map=self;
	Room *hall= NEW(Room, "The Great Hall");
	Room *throne = NEW(Room, "The Throne Room");
	Room *arena = NEW(Room, "The Arena with the Minatour");
	Room *kitchen = NEW(Room, "Kitchen, You have the knife now");
	arena->bad_guy= NEW(Monster, "The Evil Minatour");

	hall->north=throne;
	throne->west=arena;
	throne->south=hall;
	arena->east=throne;
	throne->east=kitchen;
	kitchen->west=throne;

	map->start=hall;
	map->location=hall;
	return 1;
}

Object MapProto={
	.init= Map_init,
	.move= Map_move,
	.attack= Map_attack
};

int process_input(Map *game)
{
	printf("\n> ");
	char ch=getchar();
	//eat enter
	getchar();
	int damage=rand()%4;
	switch(ch){
		case -1:
			printf("Giving up? You Suck\n");
			return 0;
			break;
		case 'n':
			game->_(move)(game,NORTH);
			break;
		case 's':
			game->_(move)(game,SOUTH);
			break;
		case 'e':
			game->_(move)(game,EAST);
			break;
		case 'w':
			game->_(move)(game,WEST);
			break;
		case 'a':
			game->_(attack)(game,damage);
			break;
		case 'l':
			printf("You can go:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east) printf("EAST\n");
			if(game->location->west) printf("WEST\n");
			break;

		default:
			printf("What? %d\n",ch);
			break;
	}
	return 1;

}
int main(int argc, const char *argv[])
{
	srand(time(NULL));
	Map *game=NEW(Map, "The Hall of the Minatour");
	printf("You enter the ");
	game->location->_(describe)(game->location);
	while(process_input(game)){
	}
	return 0;
}
