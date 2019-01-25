// implementation for the lemminge task, specified in pdf
// softbobo 190125

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

int main() {
    input();

    return 0;
}

struct board* input() {
/*func takes args from STDIN and passes them to single list entries, till '0 0' is entered*/
    struct board* game;
    unsigned temp_left = 1;
    unsigned temp_pos = 1;

    while(temp_left && temp_pos) {
        scanf("%u", &temp_pos);
        scanf("%u", &temp_left);

    }
    return game;
}