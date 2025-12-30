#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*struct bt_dugum
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
}----------------------------------------------------------------------------------------------------------*/

/*
Hash tablosu ile ilgili veri tanımlaması solda
verilmektedir. Buna göre parametre olarak
anahtarı verilen düğümün bulunduğu
listedeki anahtarı en küçük olan düğümü
silen ve tanımlaması aşağıda verilen
fonksiyonu yazınız? (25 puan)*/

/*struct cell
{
    char *anahtar;
    struct cell *next;
};
struct table_node
{
    int count;
    struct cell *header;
};
struct hash_tablosu
{
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
};
unsigned int hash(char *s, int multiplier, int table_size)
{
    int i = 0;
    unsigned int value = 0;
    while (s[i] != '\0')
    {
        value = (s[i] + multiplier * value) % table_size;
        i++;
    }
    return value;
}
void liste_sil(struct hash_tablosu *htable, char *anahtar);
int main()
{
    return 0;
}

void liste_sil(struct hash_tablosu *htable, char *anahtar)
{
    if (htable == NULL)
        return;

    // 1. İlgili indeksi (bucket) bul
    int index = hash(anahtar, htable->multiplier, htable->tablo_uzunlugu);

    // İşlem kolaylığı için o indeksteki yapıya işaretçi alalım
    struct table_node *kutu = (htable->tablo_basi + index);
    struct cell *iter = kutu->header;

    // Liste boşsa çık
    if (iter == NULL)
        return;

    // 2. EN KÜÇÜK ELEMANI BUL (Senin yazdığın kısım, burası doğruydu)
    struct cell *min_dugum = iter; // Şu anki en küçük aday

    while (iter != NULL)
    {
        // Eğer iter, min_dugum'den daha küçükse (negatifse) yeni min odur
        if (strcmp(iter->anahtar, min_dugum->anahtar) < 0)
        {
            min_dugum = iter;
        }
        iter = iter->next;
    }

    // 3. SİLME İŞLEMİ (Burayı düzelttik)

    // DURUM A: Silinecek eleman EN BAŞTA ise
    if (min_dugum == kutu->header)
    {
        kutu->header = min_dugum->next; // Başlangıcı bir yana kaydır
        free(min_dugum);
    }
    // DURUM B: Silinecek eleman ARADA veya SONDA ise
    else
    {
        // Silinecek düğümün BİR ÖNCEKİNİ bulmamız lazım
        struct cell *prev = kutu->header;

        // prev->next bizim sileceğimiz düğüm olana kadar ilerle
        while (prev->next != min_dugum)
        {
            prev = prev->next;
        }

        // Bağlantıyı atlat: Öncekinin next'i, silinenin next'i olsun
        prev->next = min_dugum->next;
        free(min_dugum);
    }

    // (Opsiyonel ama iyi olur) Eleman sayısını azalt
    kutu->count--;
}
---------------------------------------------------------------------------------------------------------*/
/*
struct dugum
{
    int anahtar;
    struct dugum *sol_link, *sag_link;
};
int main() { return 0; }
int tek_cocuklu_dugum_sayisi(struct dugum *kok)
{
    if (kok == NULL)
        return 0;
    if ((kok->sag_link == NULL && kok->sol_link != NULL) || (kok->sag_link != NULL && kok->sol_link == NULL))
        return 1 + tek_cocuklu_dugum_sayisi(kok->sol_link) + tek_cocuklu_dugum_sayisi(kok->sag_link);
    if (kok->sag_link != NULL && kok->sol_link != NULL)
        return 0 + tek_cocuklu_dugum_sayisi(kok->sag_link) + tek_cocuklu_dugum_sayisi(kok->sol_link);

    return 0;
}--------------------------------------------------------------------------------------------------------*/

struct cell
{
    char *anahtar;
    struct cell *next;
};

struct table_node
{
    int count;
    struct cell *header;
};

struct hash_tablosu
{
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
};

unsigned int hash(char *s, int multiplier, int table_size)
{
    int i = 0;
    unsigned int value = 0;
    while (s[i] != '\0')
    {
        value = (s[i] + multiplier * value) % table_size;
        i++;
    }
    return value;
};
int main()
{
    return 0;

}
void listeyi_hash_tablosuna_donusturme(struct hash_tablosu *htable, struct cell **liste_basi){}
