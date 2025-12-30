#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct cell
// {
//     char *anahtar;
//     struct cell *next;
// };

// struct table_node
// {
//     int count;
//     struct cell *header;
// };

// struct hash_tablosu
// {
//     struct table_node *tablo_basi;
//     int tablo_uzunlugu;
//     int multiplier;
// };

// unsigned int hash(char *s, int multiplier, int table_size)
// {
//     int i = 0;
//     unsigned int value = 0;
//     while (s[i] != '\0')
//     {
//         value = (s[i] + multiplier * value) % table_size;
//         i++;
//     }
//     return value;
// }
// void listeyi_hash_tablosuna_donusturme(struct hash_tablosu *htable, struct cell **liste_basi);
// void listeyi_hash_tablosuna_donusturme(struct hash_tablosu *htable, struct cell **liste_basi)
// {
//     if ((*liste_basi) == NULL)
//         return;

//     int val = hash((*liste_basi)->anahtar, htable->multiplier, htable->tablo_uzunlugu);
//     struct cell *temp = (*liste_basi)->next;
//     (*liste_basi)->next = (htable->tablo_basi + val)->header;
//     (htable->tablo_basi + val)->header = *liste_basi;
//     (htable->tablo_basi + val)->count++;
//     listeyi_hash_tablosuna_donusturme(htable, &temp);
// }
//------------------------------------------------------ Heap Data Struct -----------------------------------------
struct dugum
{
    int anahtar;
    struct dugum *parent, *sol_link, *sag_link;
};
struct heap
{
    struct dugum *kok;
    struct dugum *en_son_eklenen;
};
int main()
{
    struct heap *heap_type = NULL;

    return 0;
}
void heap_insert(struct heap *heap, int key)
{
    struct dugum geri;
    heap->en_son_eklenen = heap->kok;
    while(heap->en_son_eklenen!=NULL)
    {
        geri=heap->en_son_eklenen;
        heap->en_son_eklenen=heap->en_son_eklenen->
    }
}