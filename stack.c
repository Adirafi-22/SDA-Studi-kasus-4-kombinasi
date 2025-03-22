#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Inisialisasi stack kosong
void CreateStack(Stack *S) {
    S->Top = NULL;
}

// Push: Tambah makanan ke pesanan
void Push(Stack *S, Makanan X) {
    addressS P = (addressS)malloc(sizeof(ElmtStack));
    if (P != NULL) {
        P->info = X;
        P->next = S->Top;
        S->Top = P;
    }
}

// Print pesanan
void PrintStack(Stack S) {
    addressS P = S.Top;
    printf("Pesanan Anda:\n");
    while (P != NULL) {
        printf("- %s (%d)\n", P->info.nama_makanan, P->info.harga);
        P = P->next;
    }
}

