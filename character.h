#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "room.h"

// Struct representing Character
struct Character {
	char* name;
};

// goal: creates a Character struct given the name of this character
// param name: char* representing the name of the character 
struct Character* character(char* name);

// goal: move the Character namely character to the room (current)
void move_character(struct Room* current, char* character);
