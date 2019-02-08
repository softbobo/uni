//implementation of hashtable-tutorial on https://github.com/jamesroutley/write-a-hash-table#contents
//softbobo 190131

#define HT_PRIME_1 173
#define HT_PRIME_2 181
#define HT_INITIAL_BASE_SIZE 50

//data structure for every single entry
typedef struct {
    char* key;
    char* value;
} ht_item;

//structure for the whole hash table
typedef struct {
    long long size;
    long long count;
    long long base_size;
    ht_item** items;
} ht_hash_table;

void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* h, const char* key);
