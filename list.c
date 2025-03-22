#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Inisialisasi daftar meja
void CreateListMeja(ListMeja *L) {
    L->First = NULL;
}

// Tambah meja ke dalam daftar
void TambahMeja(ListMeja *L, char kode[]) {
    addressL P = (addressL)malloc(sizeof(ElmtList));
    if (P != NULL) {
        strcpy(P->info.kode, kode);
        P->info.tersedia = true;
        P->next = L->First;
        L->First = P;
    }
}

// Menampilkan meja dalam bentuk grid
void TampilkanMejaTersedia(ListMeja L) {
    char baris[] = "ABCDE";  // Baris A - E
    int i = 0;
    
    printf("\n+----+----+----+----+----+\n");
    
    while (i < 5) {  // 5 Baris
        printf("|");
        int j = 1;
        while (j <= 5) {  // 5 Kolom
            char kode[3];
            sprintf(kode, "%c%d", baris[i], j);

            addressL P = L.First;
            boolean tersedia = false;

            while (P != NULL) {
                if (strcmp(P->info.kode, kode) == 0) {
                    tersedia = P->info.tersedia;
                    break;
                }
                P = P->next;
            }

            if (tersedia) {
                printf(" %s |", kode);  // Tampilkan kode meja yang tersedia
            } else {
                printf(" -- |");  // Jika tidak tersedia, tampilkan "--"
            }
            
            j++;
        }
        printf("\n+----+----+----+----+----+\n");
        i++;
    }
}

// Pilih meja jika tersedia
boolean PilihMeja(ListMeja *L, char kode[]) {
    addressL P = L->First;
    while (P != NULL) {
        if (strcmp(P->info.kode, kode) == 0 && P->info.tersedia) {
            P->info.tersedia = false;
            return true;
        }
        P = P->next;
    }
    return false;
}

