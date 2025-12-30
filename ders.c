#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bt_dugum
{ // ikili arama ağacı
    int anahtar;
    struct bt_dugum *sol, *sag;
};
struct ls_dugum
{ // bağlantılı liste
    struct bt_dugum *dugum;
    struct ls_dugum *sonraki;
};
void liste_olustur(struct bt_dugum *kok, int anahtar, struct ls_dugum **liste_basi);

int main()
{
    return 0;
}
void liste_olustur(struct bt_dugum *kok, int anahtar, struct ls_dugum **liste_basi)
{
    if (kok == NULL)
        return;
    (*liste_basi) = (struct ls_dugum *)malloc(sizeof(struct ls_dugum));
    (*liste_basi)->dugum = kok;
    (*liste_basi)->sonraki = NULL;
    if (kok->anahtar == anahtar)
        return;

    else if (kok->anahtar > anahtar)
        liste_olustur(kok->sol, anahtar, &((*liste_basi)->sonraki));

    else
        liste_olustur(kok->sag, anahtar, &((*liste_basi))->sonraki);
}