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
    struct CELL *next;
};
struct HashTable
{
    struct Node *table_root;
    int table_size;
    int multiplier;
};
unsigned hash(char *key, int multiplier, int table_size) //Hash key creating;
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

int main()
{
    return 0;
}