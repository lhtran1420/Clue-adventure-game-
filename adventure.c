#include<stdio.h>
#include<stdlib.h>

#include "item.h"
#include "character.h"


void main() {
	int x = rand()%3 + 1;
	int y = rand()%3 + 1;
	int *ansx = &x;
	int *ansy = &y;


	struct Room* rm[9];
	// The list of 9 rooms in the matrix
	char rom[9][12]={"room1","room2","room3","room4","room5","room6","room7","room8","room9"};
	int dd[9]={0};

	// Randomly choose the position of each room in the 3x3 matrix
	for(int i=0; i<=8; i++) {
		int numb = rand()%9;
		while(1) {
			if(dd[numb]==0) {
				rm[i] = room(rom[numb],NULL,NULL,NULL,NULL,NULL,NULL);
				dd[numb] = 1;
				break;
			}

			numb = (numb+1)%9;
		}
	}

	// Set the direction of each room in the 3x3 matrix
	(*rm[0]).east = rm[1]; (*rm[0]).south = rm[3];
	(*rm[1]).south = rm[4]; (*rm[1]).east = rm[2]; (*rm[1]).west = rm[0]; 

	(*rm[2]).south = rm[5]; (*rm[2]).west = rm[1]; 

	(*rm[3]).south = rm[6];	(*rm[3]).north = rm[0]; (*rm[3]).east = rm[4]; 

	(*rm[4]).north = rm[1]; (*rm[4]).east = rm[5]; (*rm[4]).west = rm[3]; (*rm[4]).south = rm[7];
	(*rm[5]).north = rm[2]; (*rm[5]).west = rm[4]; (*rm[5]).south = rm[8];

	(*rm[6]).north = rm[3]; (*rm[6]).east = rm[7]; (*rm[7]).east = rm[8]; (*rm[7]).west = rm[6]; 
	(*rm[7]).north = rm[4]; (*rm[8]).west = rm[7]; (*rm[8]).north = rm[5];

	// randomly choose the starting position in the matrix
	int random11 = rand()%9+1;
	struct Room* position = rm[random11];

	// randomly choose the room as the answer
	int random = rand()%9+1;
	struct Room* RoomAns = rm[random];

	// Inventory starting with item heading
	struct Item* heading = NULL;

	// The list of item in the matrix
	struct Item* it[6] ;
	
	it[0] = item("Pen",NULL);
	it[1] = item("Book",NULL);
	it[2] = item("Computer",NULL);
	it[3] = item("Phone",NULL);
	it[4] = item("TV",NULL);
	it[5] = item("Shoes",NULL);

	// Randomly set the item in each room 
	int chek[9]={0};
	for(int i=0; i<5; i++) {
		int rd = rand()%9;
		while(1) {
			if(chek[rd]==0) {
				(*rm[rd]).item = it[i];
				chek[rd] = 1;
				break;
			}

			rd = (rd+1)%9;
		}
	}

	// The list of character
	char ch[5][12]={"Messi","Ronaldo","Neymar","Lewandowski","Suarez"};

	// Randomly set the character in each room 
	int arr[9]={0};
	for(int i=0; i<4; i++) {
		int rd = rand()%9;
		while(1) {
			if(arr[rd]==0) {
				(*rm[rd]).character = ch[i];
				arr[rd] = 1;
				break;
			}

			rd = (rd+1)%9;
		}
	}

	// randomly choose the character as the answer
	int random1 = rand() % 5;
	struct Character* characterAns = character(ch[random1]);

	// randomly choose the item as the answer
	int random2 = rand()%6;
	struct Item* itemAns = it[random2];

	int count = 0;

	// print the 3x3 matrix with 9 rooms
	int count1 = 0;
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			printf("  %s |", (*rm[count1]).description);
			count1++;
		}

		printf("\n");
		printf("______________________________\n");
	}

	// display the list of character for the user to see clearly
	printf("The list of character: \n");
	for(int i=0; i<5; i++) {
		printf("%d. %s\n", i+1, ch[i]);
	} 
	// display the list of item for the user to see clearly
	printf("----------------------\n");
	printf("The list of Item: \n");
	for(int i=0; i<6; i++) {
		printf("%d. %s\n", i+1, (*it[i]).name);
	}

 	int checking = 0;
	while(1) {	
		printf("---------------------\n");
		printf("Your position is at %s\n", (*position).description);
		
		printf("___________________________\n");
		if(checking>0) {
			int counting1 = 0;
			for(int i=1; i<=3; i++) {
				for(int j=1; j<=3; j++) {
					printf("  %s |", (*rm[counting1]).description);
					counting1++;
				}

				printf("\n");
				printf("___________________________\n");
			}
		}

		// The list of option for the user to choose
		printf("Help\n");
		printf("Make your choice\n");
		printf("Go direction\n");
		printf("1. Go North\n"); printf("2. Go South\n"); printf("3. Go East\n"); printf("4. Go West\n"); printf("5. Take Item\n"); printf("6. Drop Item\n");
		printf("7. Check Inventory\n"); printf("8. clue Character\n");

		// Now, the user will take 1 of 8 choice
		int choice;
		printf("Your choice is number ");
		scanf("%d", &choice);

		printf("\n");
		// Choice 1: the user chooses to go to north direction
		if(choice==1) {
			if((*position).north==NULL) printf("Try again. You cannot move this direction\n\n");
			else position = (*position).north;
				
		}

		// Choice 2: the user chooses to go to south direction
		else if(choice==2) {
			if((*position).south==NULL) printf("Try again. You cannot move this direction\n\n");
			else position = (*position).south;

		}

		// Choice 3: the user chooses to go to east direction
		else if(choice == 3) {
			if((*position).east==NULL) printf("Try again. You cannot move this direction\n\n");
			else position = (*position).east;
		}

		// Choice 4: the user chooses to go to west direction
		else if(choice == 4) {
			if((*position).west==NULL) printf("Try again. You cannot move this direction\n\n");
			else position = (*position).west;
		}	

		// Choice 5: the user chooses to pick item in the current room and the item will be added to the inventory
		else if(choice == 5) {
			if((*position).item==NULL) printf("Try again. This room does not have item\n");
			if(heading==NULL) heading = (*position).item;
			else AddItem(heading, (*position).item);
		}

		// Choice 6: the user chooses to drop item in the inventory and this item will be added to the current room
		else if(choice == 6) {
			int cnt = 1;

			struct Item* itm = heading;
			if(itm==NULL) printf("We have nothing to remove");
			else {
				// display the list of item in the inventory, so that the user can choose which item they want to remove.
				while(itm!=NULL) {
					printf("%d: ",cnt);
					printf("%s ", (*itm).name);
					printf("\n");
					itm = (*itm).next;
					cnt++;
				}
				
				int rem, cnt1 = 0;
				printf("The item you want to remove is number ");
				
				
				scanf("%d\n", &rem); 

				rem = rem - 1;
				struct Item* itmm = heading;
				while(itm!=NULL && cnt1<rem) {
					itmm = (*itmm).next;
					cnt1++;
				}


				// remove the item from the inventory
				if( strcmp((*heading).name,(*itmm).name) ==0 ) heading = (*heading).next;
				else RemoveItem(heading, itmm);;

				// Add the item to the current room
				if((*position).item==NULL) (*position).item = itmm;
				else AddItem((*position).item, itmm); 
			}
		}

		// display all the items in the inventory
		else if(choice == 7) {
			struct Item* itm = heading;
			// If there is nothing in the bag, we have nothing to display
			if(itm==NULL) printf("We have nothing in the Inventory\n");
			else {
				while(itm!=NULL) {
					printf("%s ", (*itm).name);
					printf("\n");
					itm = (*itm).next;
				}
			}
		}

		// check whether the room, character, or item match of unmatch => Win or lose 
		else if(choice == 8) {
			count++;

			// display the list of character to clue for the user
			printf("1. Messi\n"); printf("2. Ronaldo\n"); printf("3. Neymar\n"); printf("4. Lewandowski\n"); printf("5. Suarez\n");


			int choose;
			int bit1=0,bit2=0,bit3=0;
			printf("Your choice is character ");			
			scanf(" %d", &choose);

			// check whether the current room is the room as answer or not
			if(strcmp((*position).description, (*RoomAns).description) == 0) {
				printf("Room Match\n");
				bit1 = 1; // room match
			}

			else printf("Room Unmatch\n");

			move_character(position,ch[choose-1]);
			// check whether the current character is the character as answer or not
			if(strcmp((*position).character,(*characterAns).name)==0) {
				printf("Character Match\n");
				bit2 = 1; // character match
			}
			else printf("Character Unmatch\n");

			struct Item* itt = heading;
			int check = 0;

			// check whether the current item is the item as answer or not
			while(itt!=NULL && check==0) {
				if(strcmp((*itt).name,(*itemAns).name)==0) {
					check = 1;
					break;
				}

				itt = (*itt).next;
			}

			if(check==1) {
				printf("Item Match\n");
				bit3 = 1; // item match
			}

			else printf("Item Unmatch\n");

			// If room,character, and item are matched => we win the game
			if(bit1==1 && bit2==1 && bit3==1) {
				 printf("You win the game\n");
				 break;
			}
	
			// If we clue character for 10 times or more, we will lose
			if(count>10) {
				printf("You lose the game. Try again\n");
				break;
			}

		}	

		checking ++;
	}

	// goal: frees a list of items
	while(heading!=NULL) {
		free(heading);
		heading = (*heading).next;
	}

	// goal: frees a list of items in 9 rooms
	for(int i=0; i<=8; i++) {
		struct Item* items = (*rm[i]).item;
		while(items!=NULL) {
			free(items);
			items = (*items).next;
		}
	}

}