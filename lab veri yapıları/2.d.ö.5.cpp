#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Kayit {
    char isim[50];
    struct Kayit *sonraki;
};


struct Kayit *yeniKayitOlustur(char isim[]) {
    struct Kayit *yeni = (struct Kayit *)malloc(sizeof(struct Kayit));
    if (yeni != NULL) {
        strcpy(yeni->isim, isim);
        yeni->sonraki = NULL;
    }
    return yeni;
}


void kayitEkle(struct Kayit **baslangic, char isim[]) {
    struct Kayit *yeni = yeniKayitOlustur(isim);
    if (*baslangic == NULL) {
        *baslangic = yeni;
    } else {
        struct Kayit *gecici = *baslangic;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

// En uzun ismi  bul
struct Kayit *enUzunIsimliKaydiBul(struct Kayit *baslangic) {
    if (baslangic == NULL) {
        return NULL;
    }

    struct Kayit *enUzunIsimliKayit = baslangic;
    int enUzunIsimUzunlugu = strlen(baslangic->isim);

    while (baslangic != NULL) {
        int isimUzunlugu = strlen(baslangic->isim);
        if (isimUzunlugu > enUzunIsimUzunlugu) {
            enUzunIsimliKayit = baslangic;
            enUzunIsimUzunlugu = isimUzunlugu;
        }
        baslangic = baslangic->sonraki;
    }

    return enUzunIsimliKayit;
}

int main() {
    struct Kayit *liste = NULL;
    int ogrenciSayisi;

    printf("Kac ogrenci gireceksiniz: ");
    scanf("%d", &ogrenciSayisi);

    for (int i = 0; i < ogrenciSayisi; i++) {
        char isim[50];
        printf("%d. ogrencinin ismini girin: ", i + 1);
        scanf("%s", isim);
        kayitEkle(&liste, isim);
    }

    struct Kayit *enUzunIsimliKayit = enUzunIsimliKaydiBul(liste);

    if (enUzunIsimliKayit != NULL) {
        printf("En uzun isim: %s\n", enUzunIsimliKayit->isim);
    } else {
        printf("Liste bos.\n");
    }

    // Belleği temizle
    while (liste != NULL) {
        struct Kayit *gecici = liste;
        liste = liste->sonraki;
        free(gecici);
    }

    return 0;
}