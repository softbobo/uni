//main to tryout the project

#include<stdio.h>

#include"hashtable.h"

int main() {
    ht_hash_table* ht = ht_new();
    ht_insert(ht, 3, "hallo");
    puts(ht_search(ht, 3));

    ht_del_hash_table(ht);
    return 0;
}