#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"

typedef struct {
    char nama[30];
} Pelanggan;

typedef struct tElmtQueue *addressQ;
typedef struct tElmtQueue {
    Pelanggan info;
    addressQ next;
} ElmtQueue;

typedef struct {
    addressQ First;
    addressQ Last;
} Queue;

void CreateQueue(Queue *Q);
boolean IsEmptyQueue(Queue Q);
void Enqueue(Queue *Q, Pelanggan X);
Pelanggan Dequeue(Queue *Q);
void PrintQueue(Queue Q);

#endif

