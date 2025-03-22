#ifndef LIST_H
#define LIST_H

#include "boolean.h"

typedef struct {
    char kode[3]; // Contoh: "A1", "B2"
    boolean tersedia;
} Meja;

typedef struct tElmtList *addressL;
typedef struct tElmtList {
    Meja info;
    addressL next;
} ElmtList;

typedef struct {
    addressL First;
} ListMeja;

void CreateListMeja(ListMeja *L);
void TambahMeja(ListMeja *L, char kode[]);
void TampilkanMejaTersedia(ListMeja L);
boolean PilihMeja(ListMeja *L, char kode[]);

#endif

