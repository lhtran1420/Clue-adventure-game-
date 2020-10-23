#include "room.h"

// goal: creates a Room struct given the description, item, character, north,east,south,west
// param description: char* representing the description
// param item: struct* representing the item in the room
// param character: char* representing the character in the room

// param norht: char* representing the norht direction of the room
// param east: char* representing the east direction of the room
// param south: char* representing the south direction of the room
// param west: char* representing the west direction of the room

// return: a Room struct pointer  with the specified fields
struct Room* room(char* description, struct Item* item, char* character, 
	struct Room* north, struct Room* south, struct Room* east, struct Room* west) {

	struct Room* rm = NULL;
	rm = (struct Room*) malloc(sizeof(struct Room));

	(*rm).description = description;
	(*rm).item = item;
	(*rm).character = character;
	(*rm).north = north;
	(*rm).east = east;
	(*rm).south = south;
	(*rm).west = west;

	return rm;
}

