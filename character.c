#include "character.h"

// goal: creates a Character struct given the name of this character
// param name: char* representing the name of the character 
struct Character* character(char* name){
	struct Character* ch = NULL;
	ch = (struct Character*) malloc(sizeof(struct Character));
	
	(*ch).name = name;		
	return ch;
}

// goal: move the Character namely character to the room (current)
void move_character(struct Room* current, char* character){
	(*current).character = character;
}

