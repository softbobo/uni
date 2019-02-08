// implementation for the lemminge task, specified in pdf
// softbobo 190125

#include<stdlib.h>
#include<stdio.h>

#include"lemminge.h"

/* to do next:
- make *first point to the first list entry
- write input() that needs to:
    - take two unsigned numbers (scanf) until EOL
    - allocate a new pole struct
    - write pole pos (first number), left end (second number) and right end (second - number - 1)
    to new struct
    - redirect *next pointer of new struct to next list entry
    - terminate, when '0 0' is entered
*/

pole* head;                 //global head

int main() {
     

    return 0;
}


pole* lk_new_pole(pole* next, unsigned pos, unsigned left) {
    /*allocate new list entry for every input pair of numbers, set pointer
    to next list entry*/
    pole* item = (pole*)malloc(sizeof(pole));
    if(item == NULL) {
    //error check if malloc wasn't successful
        printf("No memory left!");
        exit(0);
    }
    item->pos = pos;
    item->left = left;
    item->right = left+1;
    item->next = next;

    return item;
}

board* lk_add_pole(board* game, unsigned pos, unsigned left) {
    //creates new list entry and redirects head to it
    pole* item = lk_new_pole(head, pos, left);
    game->head = item;
    return game;
}

board* lk_input() {
    /* input function takes first number, then pairs of numbers and writes
    these to the list */
    board* game = (board*)malloc(sizeof(board));
    
    unsigned temp_pos = 1;
    unsigned temp_left = 1;

    scanf("%d", game->le_ming);
    while(temp_left > 0 && temp_pos > 0) {
        scanf("%d %d", temp_pos, temp_left);
        lk_add_pole(game->head, temp_pos, temp_left);
    }
    return game;
}

int* lk_output_printer(int* output) {

}

int* lk_output(board* game) {
    /* allocates array with and populates it with the numbers
    of vertical poles every lemming will exit. */
    int* output = (int*)malloc((game->le_ming + 1) * sizeof(int));



    for(unsigned i = 1; i <= game->le_ming; i++) {
        lk_output_calc(game, i);
    }
    return output;
}

int* lk_output_calc(board* game, unsigned i) {
    /* calculates the exit point for a single lemming by traversing
    the list and passes it back to lk_output */
}



void lk_delete_list(){

}

 