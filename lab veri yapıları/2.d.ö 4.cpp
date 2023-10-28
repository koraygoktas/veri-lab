#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ogrenci yapisi
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// Yeni ogrenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = NULL;

    if (head == NULL) {
        return yeniOgrenci;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeniOgrenci;

    return head;
}

// ogrenci listesini ekrana yazdıran fonksiyon
void ogrenciListesiYazdir(struct Ogrenci* head) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        printf("Ogrenci No: %d, Ad: %s\n", gecici->ogrenciNo, gecici->ad);
        gecici = gecici->next;
    }
}

// ogrenci silme fonksiyonu
struct Ogrenci* ogrenciSilSonraki(struct Ogrenci* head, const char* hedefAd) {
    if (head == NULL) {
        printf("Liste boş. Silme islemi yapilamaz.\n");
        return head;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            struct Ogrenci* silinecek = gecici->next;
            gecici->next = silinecek->next;
            free(silinecek);
            printf("%s adlı ogrencinin sonraki ogrencisi silindi.\n", hedefAd);
            return head;
        }
        gecici = gecici->next;
    }

    printf("%s adli ogrenci bulunamadi veya listenin sonunda bulunuyor.\n", hedefAd);
    return head;
}

int main() {
    struct Ogrenci* liste = NULL;

    // ogrenci kayıtları ekleniyor
    liste = ogrenciEkle(liste, 1, "koray");
    liste = ogrenciEkle(liste, 2, "azra");
    liste = ogrenciEkle(liste, 3, "mert");
    liste = ogrenciEkle(liste, 4, "enes");

    // ogrenci listesini ekrana yazdır
    printf("Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Kullanıcıdan silinecek ogrencinin adını al
    char silinecekAd[50];
    printf("Hangi ogrenciden sonraki ogrenciyi silmek istersiniz? ��renci adini girin: ");
    scanf("%s", silinecekAd);

    // ogrenci silme islemi
    liste = ogrenciSilSonraki(liste, silinecekAd);

    // Guncellenmis ogrenci listesini ekrana yazdır
    printf("Guncellenmis Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Belleği temizle (serbest birak)
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}