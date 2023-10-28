#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Ogrenci {
    int ogrenciNo;
    char isim[50];
    int yas;
    struct Ogrenci* next;
};

// Yeni bir ogrenci dugumu olusturan fonksiyon
struct Ogrenci* yeniOgrenci(int ogrenciNo, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->ogrenciNo = ogrenciNo;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->next = NULL;
    return ogrenci;
}

// ogrenci dugumunu liste sonuna ekleyen fonksiyon
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int ogrenciNo, const char* isim, int yas) {
    struct Ogrenci* ogrenci = yeniOgrenci(ogrenciNo, isim, yas);
    if (head == NULL) {
        return ogrenci;
    }

    struct Ogrenci* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ogrenci;
    return head;
}

// ogrenci bilgilerini dolasan ve ekrana yazan fonksiyon
void ogrenciBilgileriniYazdir(struct Ogrenci* head) {
    struct Ogrenci* current = head;
    int ogrenciSayisi = 0;

    while (current != NULL) {
        printf("ogrenci No: %d, isim: %s, Yaş: %d\n", current->ogrenciNo, current->isim, current->yas);
        ogrenciSayisi++;
        current = current->next;
    }

    printf("Toplam ogrenci Sayisi: %d\n", ogrenciSayisi);
}

int main() {
    struct Ogrenci* head = NULL;
    int ogrenciSayisi;

    printf("Kac ogrenci eklemek istersiniz? ");
    scanf("%d", &ogrenciSayisi);

    for (int i = 0; i < ogrenciSayisi; i++) {
        int ogrenciNo, yas;
        char isim[50];

        printf("ogrenci No: ");
        scanf("%d", &ogrenciNo);
        printf("�sim: ");
        scanf("%s", isim);
        printf("Yas: ");
        scanf("%d", &yas);

        head = ogrenciEkle(head, ogrenciNo, isim, yas);
    }

    // ogrenci bilgilerini dolasarak ekrana yazdıran
    ogrenciBilgileriniYazdir(head);

    // Bellegi temizle
    while (head != NULL) {
        struct Ogrenci* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
