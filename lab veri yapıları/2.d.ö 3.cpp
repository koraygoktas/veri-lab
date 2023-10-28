#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ogrenci yapısı
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// ogrenci listesine yeni ogrenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = head;
    return yeniOgrenci;
}

//ogrenci adına gore arama yapma fonksiyonu
struct Ogrenci* ogrenciAraAd(struct Ogrenci* head, const char* hedefAd) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            return gecici; 
        }
        gecici = gecici->next;
    }
    return NULL; // Eklenme bulunamadı  NULL döndür
}

int main() {
    struct Ogrenci* liste = NULL;

    // ��renci kay�tlar� 
    liste = ogrenciEkle(liste, 1, "gülşah");
    liste = ogrenciEkle(liste, 2, "mehmet");
    liste = ogrenciEkle(liste, 3, "koray");
    liste = ogrenciEkle(liste, 4, "tuğberk");

    // Kullan�c�dan aranacak ��rencinin ad�
    char arananAd[50];
    printf("Aranacak ogrencinin adini girin: ");
    scanf("%s", arananAd);

    // ��renci ad�na g�re arama yap
    struct Ogrenci* sonuc = ogrenciAraAd(liste, arananAd);

    if (sonuc != NULL) {
        printf("Ogrenci Bulundu: Ogrenci No %d, Ad�: %s\n", sonuc->ogrenciNo, sonuc->ad);
    } else {
        printf("Ogrenci Bulunamadi: %s\n", arananAd);
    }

    // Bellegi temizle
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}