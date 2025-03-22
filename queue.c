#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// Inisialisasi queue kosong
void CreateQueue(Queue *Q) {
    Q->First = Q->Last = NULL;
}

// Mengecek apakah queue kosong
boolean IsEmptyQueue(Queue Q) {
    return (Q.First == NULL);
}

// Enqueue: Tambahkan pelanggan ke antrian
void Enqueue(Queue *Q, Pelanggan X) {
    addressQ P = (addressQ)malloc(sizeof(ElmtQueue));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
        if (IsEmptyQueue(*Q)) {
            Q->First = Q->Last = P;
        } else {
            Q->Last->next = P;
            Q->Last = P;
        }
    }
}

// Dequeue: Hapus pelanggan dari antrian
Pelanggan Dequeue(Queue *Q) {
    addressQ P = Q->First;
    Pelanggan X = P->info;
    Q->First = P->next;
    if (Q->First == NULL) {
        Q->Last = NULL;
    }
    free(P);
    return X;
}

// Cetak Antrian
void PrintQueue(Queue Q) {
    addressQ P = Q.First;
    if (IsEmptyQueue(Q)) {
        printf("Antrian kosong.\n");
        return;
    }
    while (P != NULL) {
        printf("%s\n", P->info.nama);
        P = P->next;
    }
}

