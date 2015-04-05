/***********************************************************************
 * File Name: structs.h
 * 
 * Description:
 * Tutorial on using a struct in C programming
 * 
 * Author: Tom Olenik
 * Copyright (C) 2015 SpazzTech LLC
 * Version: 1.0
 * Last Revision: 2015-03-28
 * ********************************************************************/
#include <stdio.h>
#include <string.h>

struct Position //Position is the label of the struct. 
{
	unsigned int x; // x coordinate in world space
	unsigned int y; // y coordinate in world space
	unsigned int z; // z coordinate in world space
};

struct Player
{
	char name[25]; 				// Name of player
	struct Position position;	// Position of player in world pace
	unsigned int health; 		// Health of player
}lukeSkywalker;

int main()
{

	strcpy(lukeSkywalker.name, "Luke Skywalker");
	lukeSkywalker.position.x = 1;
	lukeSkywalker.position.y = 1;
	lukeSkywalker.position.z = 1;
	lukeSkywalker.health = 100;
	
	printf("The player, %s", lukeSkywalker.name);
	printf(", is located at %u x %u x %u ",
		lukeSkywalker.position.x,
		lukeSkywalker.position.y,
		lukeSkywalker.position.z);
	printf(" with %d health.\n", lukeSkywalker.health);
	
	struct Player harryPotter;
	strcpy(harryPotter.name, "Harry Potter");
	struct Position hogwarts;
	hogwarts.x = 8;
	hogwarts.y = 9;
	hogwarts.z = 10;
	harryPotter.position = hogwarts;
	harryPotter.health = 50;
	
	printf("The player, %s", harryPotter.name);
	printf(", is located at %u x %u x %u ",
		harryPotter.position.x,
		harryPotter.position.y,
		harryPotter.position.z);
	printf(" with %d health.\n", harryPotter.health);
	
	printf("The player, %s", lukeSkywalker.name);
	printf(", is located at %u x %u x %u ",
		lukeSkywalker.position.x,
		lukeSkywalker.position.y,
		lukeSkywalker.position.z);
	printf(" with %d health.\n", lukeSkywalker.health);
	
	return 0;
}
