Overview
At the beginning, I will randomly choose the position of 9 rooms in the 3x3 matrix. After that, I will randomly choose
the room, item,character as the answer and a room for starting point. I will display the list of item and character 
at first. Moreover, I also have 8 choices for the user in the project including 4 positions players can move, taking item, dropping item, checking inventory, and clue character

After each choice, it will display the current position for the user  and the 3x3 matrixso that they can know which 
direction that the want to move in the next choice. When the current room,item,character match the answer, we will win
the game and after 10 times that we clue character, we will lose

Code requirement
1. I have use the structs to create item,room, and character in this project. 
2. In each struct(item,room, character), I also have some params such as name, next so that the pointer can choose it
3. In this project, I have used dynamic allocation using malloc. I use it the item.c, character.c, and room.c to 
create the struct.
4. I deallocate memory using free at the end of adventure.c

Below is the link of my video that show how my game runs
https://www.youtube.com/watch?v=JVwYvfZVSl0&t=6s&fbclid=IwAR29zcm2EkpDl9OkI69l3p9Fcq8zRSYuhQqmY0UQ4E1BBecSCyJm9Q8xGao
