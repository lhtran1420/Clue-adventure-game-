#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct representing Item
struct Item {
	char* name;
	struct Item* next;
};

// goal: creates a Item struct given the name and next item of the current item
// param name: char* representing the name of the item
// param next: struct* representing the next item of the item in the inventory

struct Item* item(char* name, struct Item* next);

// add item(item1) to the inventory with the starting item in the inventory(item)
void AddItem(struct Item* item, struct Item* item1);

// remove item(item1) in the inventory with the starting item in the inventory(item)
void RemoveItem(struct Item* item, struct Item* item1);
