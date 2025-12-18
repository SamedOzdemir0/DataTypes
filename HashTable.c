#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    unsigned int value = 0;
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
    (*hash_table)->table_size = table_size;
    (*hash_table)->multiplier = multiplier;
    (*hash_table)->table_root = (struct Node *)malloc(sizeof(struct Node) * table_size); // Hash table array created!
    for (i = 0; i < table_size; i++)
    {
        ((((*hash_table)->table_root) + i)->counter) = 0;
        ((((*hash_table)->table_root) + i)->header) = NULL;
    }
}
int insert(char *key, struct CELL **l)
{
    if (*l == NULL)
    {
        *l = (struct CELL *)malloc(sizeof(struct CELL));
        (*l)->key = (char *)malloc(sizeof(char) * (strlen(key) + 1));
        strcpy((*l)->key, key);
        (*l)->next = NULL;
        return 1;
    }
    else if (strcmp(key, (*l)->key) != 0)
        return insert(key, &((*l)->next));
    else
        return 0;
}
void insert_hash_table(struct HashTable *HashTable, char *key)
{
    unsigned int hash_index = hash(key, HashTable->multiplier, HashTable->table_size);
    if (insert(key, &(((HashTable->table_root) + hash_index)->header)))
        ((HashTable->table_root) + hash_index)->counter++;
}
void print_hash_table(struct HashTable *HashTable)
{
    if (HashTable != NULL)
    {
        int i;
        int table_size = HashTable->table_size;
        printf("\n----------------Hash Table--------------------");
        for (i = 0; i < table_size; i++)
        {
            printf("\n(%d)  ", (HashTable->table_root + i)->counter);
            print_hash_chain((HashTable->table_root + i)->header);
            printf("\n");
        }
        printf("\n");
        return;
    }
    printf("Hash Table is empty");
    return;
}
void print_hash_chain(struct CELL *l)
{
    while (l != NULL)
    {
        printf("{%s}  ", l->key);
        l = l->next;
    }
    return;
}
void hashtable_enlargement(struct HashTable **HashTab, int new_size, int new_multipler)
{
    int index;
    struct HashTable *newHashTable = NULL;
    struct CELL *iter;
    initialize_hash_table(&newHashTable, new_size, new_multipler);
    for (index = 0; index < (*HashTab)->table_size; index++)
    {
        iter = ((*HashTab)->table_root + index)->header;
        while (iter != NULL)
        {
            insert_hash_table(newHashTable, iter->key);
            iter = iter->next;
        }
    }
}
void destroy_HashTable(struct HashTable **hashtable)
{

    int i = 0;
    for (i; i < (*hashtable)->table_size; i++)
    {
        destroy_linked_list(((*hashtable)->table_root + i)->header);
    }
    free((*hashtable)->table_root);
    free(*hashtable);
    *hashtable = NULL;
}
void destroy_linked_list(struct CELL **list)
{
    struct CELL *back;

    while (*list != NULL)
    {
        back = *list;
        *list = (*list)->next;
        free(back->key);
        free(back);
    }
}
int main()
{
    struct HashTable *HashTab = NULL;
    initialize_hash_table(&HashTab, 5, 3);
    insert_hash_table(HashTab, "Samed");
    insert_hash_table(HashTab, "Ozdemir");
    insert_hash_table(HashTab, "Istanbul");
    insert_hash_table(HashTab, "Amerika");
    insert_hash_table(HashTab, "Paris");
    print_hash_table(HashTab);

    return 0;
}