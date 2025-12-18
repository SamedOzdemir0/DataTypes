#include <stdio.h>
#include <stdlib.h>
struct CELL
{
    char *key;
    struct CELL *next;
};
struct Node
{
    int counter;
    struct CELL *header;
};
struct HashTable
{
    struct Node *table_root;
    int table_size;
    int multiplier;
};
unsigned hash(char *key, int multiplier, int table_size) // Hash key creating;
{
    unsigned int value;
    int i = 0;
    while (key[i] != '\0')
    {
        value = (key[i] + multiplier * value) % table_size;
        i++;
    }

    return value;
}
void initialize_hash_table(struct HashTable **hash_table, int table_size, int multiplier)
{
    *hash_table = (struct HashTable *)malloc(sizeof(struct HashTable));
    int i;
    (*hash_table)->table_root = (struct Node *)malloc(sizeof(struct Node) * table_size); // Hash table array created!
    for (i = 0; i < table_size; i++)
    {
        ((((*hash_table)->table_root) + i)->counter) = 0;
        ((((*hash_table)->table_root) + i)->header) = NULL;

    }
}
int main()
{
    return 0;
}