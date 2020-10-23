#include "item.h"

// goal: creates a Item struct given the name and next item of the current item
// param name: char* representing the name of the item
// param next: struct* representing the next item of the item in the inventory
struct Item* item(char* name, struct Item* next) {
	struct Item* itm = NULL;
	itm = (struct Item*) malloc(sizeof(struct Item));
	
	(*itm).name = name;
	(*itm).next = next;
	
	return itm;
}

// add item(item1) to the inventory with the starting item in the inventory(item)
void AddItem(struct Item* itm, struct Item* item1){
	struct Item* temp= itm;

	while((*temp).next!=NULL) {
		temp = (*temp).next;
	}

	(*temp).next = item1; 
	
}	

// remove item(item1) in the inventory with the starting item in the inventory(item)
void RemoveItem(struct Item* item, struct Item* item1) {
	struct Item* temp= item;
	while((*temp).next!=NULL) {
		if(strcmp( (*(*temp).next).name,(*item1).name)==0) {
			(*temp).next = (*(*temp).next).next;
		}
		
		temp = (*temp).next;
		
	}	

}
